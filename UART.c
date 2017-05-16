/*
 * File:   UART.c
 * Author: Patricio Gomez
 *
 * Created on 7 de mayo de 2017, 03:43 AM
 */


#include "xc.h"
#define FCY 20000000UL
#include "libpic30.h"
#include "UART.h"

unsigned int i;

uint8 UART_init() {
    U1MODEbits.STSEL = 0; // 1-Stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-Data bits
    U1MODEbits.ABAUD = 0; // Auto-Baud disabled
    U1MODEbits.BRGH = 0; // Standard-Speed mode
    U1BRG = 129; // Baud Rate setting for 9600

    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1; // Enable UART TX
    
    RPOR4bits.RP8R = U1TX;
            
    /* Wait at least 105 microseconds (1/9600) before sending first char */
    __delay_us(105);
    UART_printString("Init1"); // Transmit one character

     return 0;
}

void UART_printString(char *data){
    while(*data)
    {
       UART_printChar(*data++); 
    }
}

void UART_printChar(char data){
    U1TXREG = data;
    while (IFS0bits.U1TXIF == 0);
    IFS0bits.U1TXIF = 0;
}