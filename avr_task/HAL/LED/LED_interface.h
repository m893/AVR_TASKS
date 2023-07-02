/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   29 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         29 MAR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


typedef struct
{
	u8  port;
	u8  pin;
	u8  ON_VOLT_LEVEL;

}LED_t;

void LED_voidInit(const LED_t* Copy_pLed);
void LED_voidON(const LED_t* Copy_pLed);
void LED_voidOFF(const LED_t* Copy_pLed);


#endif /* LED_H_ */
