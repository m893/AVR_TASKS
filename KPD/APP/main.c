/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_interface.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/KPD/KPD_config.h"
#include  "../HAL/KPD/KPD_interface.h"

void main (void)
{
	u8 var ;
	LCD_voidInit();
	KPD_VoidIntit();
	while(1)
	{
		do
		{
			var=KPD_U8GetPressedKey();

		}while(var==255);

		LCD_VoidSendData(var);
	}


}
