/*

 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <avr/interrupt.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTERNAL_INTERRUPT/EXTI_interface.h"


void main (void)
{
	sei();
	EXTI_VoidTriggerEdge(EXTI_INT0,FALLING_EDGE);
	EXTI_VoidEnable(EXTI_INT0);
	DIO_voidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	DIO_VoidSetPinValue(DIO_PORTA,PIN0,LOW);
	while(1);
}
ISR(INT0_vect)
{
	DIO_VOidTogglePortValue(DIO_PORTA);

}



