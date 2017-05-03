/*
 * File:   ADC.c
 * Author: Patricio Gomez
 *
 * Created on 22 de abril de 2017, 05:12 PM
 */


#include "xc.h"
#include "ADC.h"

uint8 ADC_init(){
    
    AD1CON1bits.AD12B = AD1CON1_AD12B_10_BIT_4_CH;  //Determine 10-bit to 4 channel config of ADC
    AD1CON2bits.CHPS = CH0_CH1_CH2_CH3;             //Select active channels
    AD1CON2bits.VCFG = AVDD_AVSS;                    //Select that low voltage reference is internal VSS
                                                    //Select that high voltage reference is internal VSS
    
    AD1CON3bits.ADCS = 2;
    //Select pot pins as analog inputs (AD1PCGGH 15 - 0 or AD1PCFGL15-0)
    
    AD1PCFGL = AD1PCFGL_ANALOG_MODE;
    
    //Select how conversion results are presented in bugger AD1CON1 9-8
    
    AD1CON1bits.FORM = FRACTIONAL;    
    
    //Determine how many S/H channels AD1CON2 9-8, AD1PCFGH 15-0, AD1PCFGL 15-0
    
    
    AD1PCFGL = ~AD1PCFGL_ANALOG_MODE;
    AD1PCFGLbits.PCFG0 = AD1PCFGL_ANALOG_MODE;
    AD1PCFGLbits.PCFG1 = AD1PCFGL_ANALOG_MODE;
    AD1PCFGLbits.PCFG2 = AD1PCFGL_ANALOG_MODE;
        
    //Select sample/conversion sequence AD1CON1 7-5, AD1CON3 12-8
    
    AD1CON1bits.SSRC = AD1CON1_SSRC_AUTO_CONVERT;
    AD1CON3bits.SAMC = TAD_0;
    
    AD1CHS123 = 0;
    AD1CHS0 = 0;
    
    //Turn on ADC module AD1CON1 15
    
    AD1CON1bits.ADON = AD1CON1_ADON_ON;
    
    //Interrupt if needed:
    //Clear AD1F bit
    //Select ADC interrupt priority    
    return 0;
}

void ADC_Start(){
    AD1CON1bits.SAMP = AD1CON1_SAMP_ENABLE;
}

uint8 ADC_Read_Done_Flag(){
    return AD1CON1bits.DONE;
}

void ADC_Clear_Done_Flag(){
    AD1CON1bits.DONE = AD1CON1_DONE_NOT_COMPLETED;
}

uint16 ADC_Buffer(){
    return (int)&ADC1BUF0;
}