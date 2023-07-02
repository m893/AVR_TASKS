/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   4 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         4 APR, 2023      Hossam M. Elzhar          Initial Creation
*********************************************/

#ifndef POV_PRIVATE_H
#define POV_PRIVATE_H

//ICU Call Back -> Hesham
static void Clock_voidGetLastRotationTime(void);

//Timer 2 Compare Match Call Back -> Moaz
static void Clock_voidUpdateThePosition(void);

//Timer 0 Compare Match Call Back -> Akram
static void Clock_voidGetTheCurrentTime(void);

#endif