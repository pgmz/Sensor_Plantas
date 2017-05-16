/*
 * File:   Secondary_Data_Types_Definitions.c
 * Author: Patricio Gomez
 *
 * Created on 9 de mayo de 2017, 05:30 PM
 */


#include "Secondary_Data_Types_Definitions.h"

void Float_To_String(float float_data, char char_data[11]){
      
    char_data[1] = (int)(float_data/1000) + '0';
    char_data[2] = (int)((float_data - (char_data[1] - '0')*1000)/100) + '0';
    char_data[3] = (int)((float_data - (char_data[1] - '0')*1000 - (char_data[2] - '0')*100)/10) + '0';
    char_data[4] = (int)((float_data - (char_data[1] - '0')*1000 - (char_data[2] - '0')*100
            - (char_data[3] - '0')*10)) + '0';
    char_data[5] = '.';
    char_data[6] = (int)((float_data - (char_data[1] - '0')*1000 - (char_data[2] - '0')*100
            - (char_data[3] - '0')*10 - (char_data[4] - '0'))*10) + '0';
    
   
}
