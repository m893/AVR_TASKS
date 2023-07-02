/***********
 * Author :   Mohammed Akram
 * Date  :   7 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              7 April, 2023               Mohammed Akram
***************************************************************************/

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER0_interface.h"


u32 main (void)
{
	u16 Local_u16Counter =0 ;
	DIO_voidSetPinDirection(DIO_PORTB,PIN3,OUTPUT);
	TIMER0_voidInit();

	while(1)
	{
		for(Local_u16Counter = 0 ; Local_u16Counter <= 255 ; Local_u16Counter++ )
		{
				TIMER0_voidSetOCMatchValue(Local_u16Counter);
				   _delay_ms(100);
		}
		for(Local_u16Counter = 0 ; Local_u16Counter <= 255 ; Local_u16Counter++ )
		{
					TIMER0_voidSetOCMatchValue(255 - Local_u16Counter);
					  _delay_ms(100);
		}


	}
}
