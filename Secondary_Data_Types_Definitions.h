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
#ifndef XC_SECONDARY_DATA_TYPES_DEFINITIONS_HEADER_H
#define	XC_SECONDARY_DATA_TYPES_DEFINITIONS_HEADER_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define PIN_INPUT                   1
#define PIN_OUTPUT                  0
#define PIN_HIGH                    1
#define PIN_LOW                     0
#define SET_PIN(DATA, PIN)          DATA << PIN
#define READ_PIN(REG, PIN)          ((REG & (1<<BIT)) == false)?(false):(true)

typedef enum{
    PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7, PIN_8, PIN_9, PIN_10,
            PIN_11, PIN_12, PIN_13, PIN_14, PIN_15
}ePIN_NUMBER_Type;

// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_SECONDARY_DATA_TYPES_DEFINITIONS_HEADER_H */

