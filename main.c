/*
 * File:   main.c
 * Author: Patricio Gomez
 *
 * Created on 22 de abril de 2017, 05:01 PM
 */

#include "config.h"
#include "ADC.h"
#include "xc.h"

int main(void) {
    ADC_init();
    
    uint16 ADC_Data = 0xF00F;
    
    for(;;)
    {
        ADC_Start();
        while(AD1CON1_DONE_COMPLETED != ADC_Read_Done_Flag());
        ADC_Data = ADC_Buffer();
    }
    
    return 0;
}
