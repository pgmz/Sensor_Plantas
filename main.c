/*
 * File:   main.c
 * Author: Patricio Gomez
 *
 * Created on 22 de abril de 2017, 05:01 PM
 */

#include "config.h"
#include "ADC.h"
#include "xc.h"

#define ADC_VOLT(x)             (x*3.3)/(0xFFC0)

#define LM35_TEMP(x)            (ADC_VOLT(x))*(100)

#define LDR_LUX(x)              (ADC_VOLT(x))

#define AN0_LM35                0
#define AN1_LDR                 1
#define AN4_YL69                4

int main(void) {
    ADC_init();

    float LM35_Data = 0;
    float LDR_DATA = 0X00;
    float YL69_DATA = 0x00;
    
    for (;;) {
        LM35_Data = ADC_Read_ANx(AN0_LM35);
        
        LDR_DATA = ADC_Read_ANx(AN1_LDR);
      
        YL69_DATA = ADC_Read_ANx(AN4_YL69);

    }

    return 0;
}
