/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   9 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         9 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/
#ifndef MCAL_WDT_PRIVATE_H_
#define MCAL_WDT_PRIVATE_H_


#define SCALER_CLEAR_MASK       0XF8
#define DISABLE_MASK            0X18
#define ZERO                    0X00

#define     WDTCR               (*(volatile u8*)0x41)
/* 3-BITS Reserved*/
#define     WDTCR_WDTOE         4
#define     WDTCR_WDE           3
#define     WDTCR_WDP2          2
#define     WDTCR_WDP1          1
#define     WDTCR_WDP0          0

#endif 
