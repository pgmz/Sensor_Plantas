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


#include "Data_Types_Definitions.h"
#include <xc.h> // include processor files - each processor file is guarded.  
#define FCY 20000000UL
#include "libpic30.h"

typedef struct{
    uint8 Sensor_Status :2;
    float ADC_Sensor_Value;
    char String_Sensor_Value[11];
}Sensor_Data_Type;

typedef struct{
    uint8 Sensor_Status :2;
    uint16 Humidity_uint16;
    uint16 Temperature_uint16;
    float Humidity_f;
    float Temperature_f;
    char String_Humidity_Value[11];
    char String_Temperaure_Value[11];
}DHT11_Data_Type;

void Float_To_String(float float_data, char char_data[11]);

#endif	/* XC_SECONDARY_DATA_TYPES_DEFINITIONS_HEADER_H */

