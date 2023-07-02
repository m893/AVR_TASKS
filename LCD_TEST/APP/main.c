/***********
 * Author :   Mohammed Akram
 * Date  :   13 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              13 April, 2023               Mohammed Akram
***************************************************************************/

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"



u32 main (void)
{

	LCD_voidInit();
	LCD_voidSendNumber(50);


	while(1)
	{

		// State 1
				/*LCD_voidGoToXY(0,0);
				LCD_voidSendData('A');
				_delay_ms(1000);
				LCD_voidClearDisplay();
				// State 2
				LCD_voidGoToXY(0,1);
				LCD_voidSendData('A');
				_delay_ms(1000);
				LCD_voidClearDisplay();
				// State 3
				LCD_voidGoToXY(1,1);
				LCD_voidSendData('A');
				_delay_ms(1000);
				LCD_voidClearDisplay();
				// State 4
				LCD_voidGoToXY(1,0);
				LCD_voidSendData('A');
				_delay_ms(1000);
				LCD_voidClearDisplay();*/




	}
}
