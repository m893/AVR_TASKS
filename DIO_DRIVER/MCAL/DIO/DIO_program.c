/*
 * DIO_program.c
 *
 *  Created on: ??�/??�/????
 *      
 */
/*Library Inclusions*/
#include "../../LIB/STD_TYPES.h"
#include "../..//LIB/BIT_MATH.h"
/*lower layer Inclusion  if iam in  HAL  include MCAL*/
/*Self files INclusions in the same sequence  */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
void 	DIO_voidSetPinDirection(u8 Copy_U8PortNmame , u8 Copy_u8PinNumber , u8 Copy_u8Direction)
{
	switch (Copy_U8PortNmame)
	{
		case DIO_PORTA:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRA , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRA , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTB:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRB , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRB , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTC:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRC , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRC , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
		case DIO_PORTD:
			if(Copy_u8Direction == OUTPUT)
			{
				SET_BIT(DDRD , Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == INPUT)
			{
				CLEAR_BIT(DDRD , Copy_u8PinNumber);
			}
			else 
			{
				// no thing
			}
		break;
	
	default:
			//do no thing 
		break;
	}
}

void DIO_VoidSetPinValue(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_U8PinState)
{
	switch (Copy_u8PortNumber)
	{
		case DIO_PORTA :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTA , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTA , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTB :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTB , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTB , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTC :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTC , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTC , Copy_u8PinNumber );
				break;
			}
		break;
		case DIO_PORTD :
			switch(Copy_U8PinState)
			{
				case LOW :
					CLEAR_BIT(PORTD , Copy_u8PinNumber );
				break;
				case HIGH :
					SET_BIT(PORTD , Copy_u8PinNumber );
				break;
			}
		break;
	
	default:
			// Do nothing 
		break;
	}
}

u8  DIO_VoidGetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue =0 ;
	switch (Copy_u8PortName)
	{
		case DIO_PORTA :
			Local_u8PinValue=GET_BIT(PORTA,Copy_u8PinNumber);
		break;
		case DIO_PORTB :
			Local_u8PinValue=GET_BIT(PORTB,Copy_u8PinNumber);
		break;
		case DIO_PORTC :
			Local_u8PinValue=GET_BIT(PORTC,Copy_u8PinNumber);
		break;
		case DIO_PORTD :
			Local_u8PinValue=GET_BIT(PORTD,Copy_u8PinNumber);
		break;
	
		default:
				//Do nothing
			break;
	}
}


 

