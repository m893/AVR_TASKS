/*

 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Dell
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

void main (void)
{


	u8 Local_u8PressedKey;
		LCD_voidInit();
		KPD_VoidIntit();
		while(1)
		{
			do
			{
				Local_u8PressedKey = KPD_U8GetPressedKey();
			}while(Local_u8PressedKey == 255);

	
			LCD_VoidSendData(Local_u8PressedKey);

		}

}


