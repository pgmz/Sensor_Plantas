/*
 * File:   PORT.c
 * Author: Patricio Gomez
 *
 * Created on 11 de mayo de 2017, 03:34 PM
 */

#include "xc.h"
#include "PORT.h"

void PIN_TRIS_SET(ePORT_Type port, ePIN_NUMBER_Type pin, uint8 state)
{
    switch(port){
        case PORT_A:
            TRISA = TRISA & ~(state << pin);
            TRISA = TRISA | (state << pin);
            break;
            
        case PORT_B:
            TRISB = TRISB & ~(state << pin);
            TRISB = TRISB | (state << pin);
            break;
    }
}

void PIN_LAT_SET(ePORT_Type port, ePIN_NUMBER_Type pin, uint8 state){
        switch(port){
        case PORT_A:
            LATA = PORTA & ~(state << pin);
            LATA = PORTA | (state << pin);
            break;
            
        case PORT_B:
            LATB = PORTB & ~(state << pin);
            LATB = PORTB | (state << pin);
            break;
    }
}

uint8 PIN_PORT_READ(ePORT_Type port, ePIN_NUMBER_Type pin){
    switch(port){
        case PORT_A:
            return (PIN_LOW == (PORTA & (1 << pin)))?(PIN_LOW):(PIN_HIGH);
            break;
            
        case PORT_B:
            return (PIN_LOW == (PORTB & (1 << pin)))?(PIN_LOW):(PIN_HIGH);
            break;

    }
}