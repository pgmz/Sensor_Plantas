/*
 * File:   DHT11_driver.c
 * Author: Patricio Gomez
 *
 * Created on 11 de mayo de 2017, 03:25 PM
 */


#include "DHT11_driver.h"
#include "xc.h"

uint8 bits[5];

uint8 DHT11_driver_read() {
    
    uint8 TimeOut_Count;
    uint8 Bit_index;
    uint8 aindex = 0;
    uint8 bcount = 7;        
    
    PIN_TRIS_SET(PORT_B, PIN_0, PIN_OUTPUT);
    PIN_LAT_SET(PORT_B, PIN_0, PIN_LOW);
    __delay_ms(20);
    
    PIN_LAT_SET(PORT_B, PIN_0, PIN_HIGH);
    PIN_TRIS_SET(PORT_B, PIN_0, PIN_INPUT);
    __delay_us(60);

    // Wait for response from DHT11 max 80 uS low
	TimeOut_Count = 1;
	while (!PIN_PORT_READ(PORT_B, PIN_0)) {
		if (!TimeOut_Count++){
			return DHT11_READ_FAIL;
        }
	}
    
	// Wait for response from DHT11 max 80 uS high
	TimeOut_Count = 1;
	while (PIN_PORT_READ(PORT_B, PIN_0)) {
		if (!TimeOut_Count++){
			return DHT11_READ_FAIL;
        }
	}
    
    for(Bit_index = 0; Bit_index < 40; Bit_index++){
        TimeOut_Count = 1;
        while (!PIN_PORT_READ(PORT_B, PIN_0)) {
            if (!TimeOut_Count++)
                 return DHT11_READ_FAIL;
        }
	// If after 50 uS the pin is low we're on the start of another bit
        __delay_us(40);
        if (!PIN_PORT_READ(PORT_B, PIN_0)) {
            if (bcount == 0) {
                bcount = 7;
                aindex++;
            } else {
                bcount--;
            }
            continue;
        }
		// If pin is high after 50 us we're receiving logic high
		TimeOut_Count = 1;
		while (PIN_PORT_READ(PORT_B, PIN_0)) {
			if (!TimeOut_Count++)
				return DHT11_READ_FAIL;
		}
		// Set the bit and shift left
		bits[aindex] |= (1 << bcount);
		if (bcount == 0) {
			bcount = 7;
			aindex++;
		} else {
			bcount--;
        }
    }
    return DHT11_READ_SUCCESS;
}

uint8 DHT11_Read(float * temp, float * hum)
{
	// Read operation
	uint8 DHT11_succeded = DHT11_driver_read();
	if (DHT11_READ_FAIL == DHT11_succeded){
        		return DHT11_READ_FAIL;
    }
	// Checksum comprobation
	unsigned char chksum = bits[0] + bits[1] + bits[2] + bits[3];
	if (chksum != bits[4])
		return DHT11_READ_CHECKSUM_ERROR;
	// Copy results
	* hum = 0.1 * (((bits[0] << 8) + bits[1]) & 0x7FFF);
	if (bits[2] & 0x80) {
		*temp = -0.1 * ((bits[2] << 8) + bits[3]);
	} else {
		*temp = 0.1 * ((bits[2] << 8) + bits[3]);
	}
	// Return Ok code
	return DHT11_READ_SUCCESS;
}