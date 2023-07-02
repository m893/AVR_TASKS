/*
 * DIO_interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Hossam Elzhar
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_


#define DIO_PORTA 	0
#define DIO_PORTB 	1
#define DIO_PORTC 	2
#define DIO_PORTD 	3

#define PIN0 		0
#define PIN1 		1
#define PIN2 		2
#define PIN3 		3
#define PIN4 		4
#define PIN5 		5
#define PIN6 		6
#define PIN7 		7

#define INPUT  	    0
#define OUTPUT      1
#define IN_PULL_UP  2

#define LOW 		0
#define HIGH 		1




void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8Stat);
void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);
void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 Copy_u8Stat);
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection);
void DIO_voidSetBitsInPort(u8 Copy_u8PortName, u8 Copy_u8SpecificValue, u8 Copy_u8Mask);
u8 DIO_u8ReadPort(u8 Copy_u8PortName);
void DIO_voidWritePin(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 Copy_u8Stat);
u8 DIO_voidReadPin(u8 Copy_u8PortName, u8 Copy_u8Pin);
void DIO_voidTogglePin(u8 Copy_u8PortName, u8 Copy_u8Pin);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
