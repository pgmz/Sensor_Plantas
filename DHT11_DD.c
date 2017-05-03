/*
 * File:   DHT11_DD.c
 * Author: Patricio Gomez
 *
 * Created on 2 de mayo de 2017, 11:13 PM
 */


#include "DHT11_DD.h"

uint8 DHT11_read(DHT11_Data_Type *DHT11_Data) {
    
    
    DHT11_start();
    
    return 0;
}

uint8 DHT11_start(){
    
    TRISBbits.TRISB15 = PIN_OUTPUT;
    LATBbits.LATB15 = PIN_HIGH;
    
    return TRUE;
    
}