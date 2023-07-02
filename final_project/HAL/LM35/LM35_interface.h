/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   6 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         6 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

typedef struct
{
    u8 Port;
    u8 Pin;

}LM35_t;


void LM35_voidInit(LM35_t * LM35);
u8  LM35_u8GetTemp(LM35_t * LM35);

#endif
