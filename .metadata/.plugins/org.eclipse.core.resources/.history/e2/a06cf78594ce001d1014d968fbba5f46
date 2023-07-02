/*

 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"



#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"



void main (void)
{
	DIO_VoidSetPortDirection(DIO_PORTA,OUTPUT);
	while(1)
	{

		 volatile s8 counter ;
		for(counter = 0 ; counter < 8 ; counter++)
		{
			DIO_VoidSetPinValue(DIO_PORTA,counter , HIGH);
			_delay_ms(300);
			DIO_VoidSetPinValue(DIO_PORTA,counter , LOW);
			_delay_ms(300);

		}
		for(counter = 7 ; counter <= 0 ; counter-- )
		{
			DIO_VoidSetPinValue(DIO_PORTA,counter,1);
			_delay_ms(300);
			DIO_VoidSetPinValue(DIO_PORTA,counter,0);
			_delay_ms(300);

		}

	}
}




