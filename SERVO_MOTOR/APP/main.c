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
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"


u32 main (void)
{
	TIMER1_voidInit();
	DIO_voidSetPinDirection(DIO_PORTD,PIN5,OUTPUT);
	TIMER1_VoidSetICR1Value(20000);
	TIMER1_VoidSetOCR1AValue(1000);
	u16 counter = 0;                                                                                                             ;

	while(1)
	{

		TIMER1_VoidSetOCR1AValue(1000);
		/*for(counter= 1000 ; counter <= 2000 ; counter +=50)
			{
					TIMER1_VoidSetOCR1AValue(counter);

			}
		for(counter= 1000 ; counter <= 2000 ; counter +=50)
				{
					TIMER1_VoidSetOCR1AValue(3000 - counter);

				}*/


	}
}
