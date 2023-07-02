/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Dell
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LM35/LM_interface.h"

int main (void)
{

	LCD_voidInit();
	ADC_VoidInit();
	while(1)
	{

		u16 temp ;
		Lm_t lm1;
		lm1.Lm_Port=DIO_PORTA ;
		lm1.Lm_pin=PIN0 ;
		LM_VoidInit(&lm1);

		temp=Lm_U8ReturnTemperture(&lm1);
		LCD_VoidGoToXY(0,0);
		LCD_VoidSendNumber(temp);


	}
}
