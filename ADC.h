/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_ADC_HEADER_H
#define	XC_ADC_HEADER_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "Secondary_Data_Types_Definitions.h"
#include "Data_Types_Definitions.h"

#define AD1PCFGL_ANALOG_MODE            0
#define AD1PCFGL_DIGITAL_MODE           1

typedef enum{
    AVDD_AVSS, EXT_AVSS, AVDD_EXT, EXT_EXT
}eAD1CON2_VCFG_Type;

typedef enum{
    CH0, CH0_CH1, CH0_CH1_CH2_CH3
}eAD1CON2_CHPS_Type;

#define AD1CON1_SSRC_AUTO_CONVERT       7    

#define TAD_0                           0

typedef enum{
    INTEGER, SIGNED_INTEGER, FRACTIONAL, SIGNED_FRACTIONAL
}eAD1CON1_FORM_Type;

#define AD1CON1_ADON_ON                 1
#define AD1CON1_ADON_OFF                0

#define AD1CON1_AD12B_10_BIT_4_CH       0
#define AD1CON1_AD12B_12_BIT_1_CH       1

#define AD1CON1_SAMP_ENABLE             1
#define AD1CON1_CONV_START              0

#define AD1CON1_DONE_COMPLETED          1
#define AD1CON1_DONE_NOT_COMPLETED      0


uint8 ADC_init();
void ADC_Start();
uint8 ADC_Read_Done_Flag();
void ADC_Clear_Done_Flag();
uint16 ADC_Buffer();

// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_ADC_HEADER_H */

