/*
 * File:   DHT11_driver.c
 * Author: Patricio Gomez
 *
 * Created on 11 de mayo de 2017, 03:25 PM
 */


#include "DHT11_driver.h"
#include "xc.h"
#define FCY 20000000UL
#include "libpic30.h"

uint8 bits[5];

uint8 DHT11_driver_read() {
    
    uint8 TimeOut_Count;
    uint8 Bit_index;
    uint8 aindex = 0;
    uint8 bcount = 7;        
    
    TRISBbits.TRISB5 = 0;
    LATBbits.LATB5 = 0;
    
    __delay_ms(20);
    
    LATBbits.LATB5 = 1;
    TRISBbits.TRISB5 = 1;

    __delay_us(60);

    // Wait for response from DHT11 max 80 uS low
	TimeOut_Count = 1;
	while (!PORTBbits.RB5) {
		if (!TimeOut_Count++){
			return DHT11_READ_FAIL;
        }
	}
    
	// Wait for response from DHT11 max 80 uS high
	TimeOut_Count = 1;
	while (PORTBbits.RB5) {
		if (!TimeOut_Count++){
			return DHT11_READ_FAIL;
        }
	}
    
    for(Bit_index = 0; Bit_index < 40; Bit_index++){
        TimeOut_Count = 1;
        while (!PORTBbits.RB5) {
            if (!TimeOut_Count++)
                 return DHT11_READ_FAIL;
        }
	// If after 50 uS the pin is low we're on the start of another bit
        __delay_us(40);
        if (!PORTBbits.RB5) {
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
		while (PORTBbits.RB5) {
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

uint8 DHT11_Read_uint16(uint16 * temp, uint16 * hum)
{
	// Read operation

	// Read operation
	uint8 DHT11_succeded = DHT11_driver_read();
	if (DHT11_succeded != DHT11_READ_SUCCESS)
		return DHT11_succeded;
	// Checksum comprobation
	unsigned char chksum = bits[0] + bits[1] + bits[2] + bits[3];
	if (chksum != bits[4])
		return DHT11_READ_CHECKSUM_ERROR;
	// Copy results
	* hum = bits[0];
	* temp = bits[2];
	// Return Ok code
    return DHT11_READ_SUCCESS;

}