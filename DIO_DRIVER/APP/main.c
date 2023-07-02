/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include  "../MCAL/DIO/DIO_private.h"
#include <util/delay.h>


void main (void)
{		/*
        u8 Local_Returned_Value = 0;

		DIO_voidSetPinDirection(DIO_PORTA,PIN3,INPUT);
		DIO_VoidSetPinValue(DIO_PORTA,PIN4,PULLUP);
		DIO_voidSetPinDirection(DIO_PORTB,PIN4,OUTPUT);

	while(1)
	{
		Local_Returned_Value = DIO_VoidGetPinValue(DIO_PORTA,PIN3);
		 switch(Local_Returned_Value)
		 {
		   case HIGH :
			   DIO_VoidSetPinValue(DIO_PORTB,PIN4,LOW);
			   break;
		   case LOW :
			   DIO_VoidSetPinValue(DIO_PORTB,PIN4,HIGH);
			   break ;
		 }

	}*/
	while(1)
	{
	SET_REG(DDRA);
	ASSIGN_REG(PORTA,0b00111111);
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b00000110);
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01011011);
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01001111);//3
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01100110);
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01101101);//5
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01111101);//6
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01000111);
	_delay_ms(1000);//7
	ASSIGN_REG(PORTA,0b01111111);
	_delay_ms(1000);
	ASSIGN_REG(PORTA,0b01101111);
	_delay_ms(1000);


	}



}


