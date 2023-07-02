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

#ifndef MCAL_WDT_INTERFACE_H_
#define MCAL_WDT_INTERFACE_H_

#define WDT_SLEEP_16_3_MS       0X00
#define WDT_SLEEP_32_5_MS       0X01
#define WDT_SLEEP_65_MS         0X02
#define WDT_SLEEP_0_13_S        0X03
#define WDT_SLEEP_0_27_S        0X04
#define WDT_SLEEP_0_52_S        0X05
#define WDT_SLEEP_1_0_S         0X06
#define WDT_SLEEP_2_1_S         0X07


void WDT_voidEnable(void);
void WDT_voidSetTime(u8 Copy_u8Scaler);
void WDT_voidDisable(void);

#endif
