/***********
 * Author :   Mohammed Akram
 * Date  :    25 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              25 April, 2023               Mohammed Akram
***************************************************************************/
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include  "../MCAL/TWI/TWI_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"

#define  F_CPU 8000000UL


u32 main (void)
{	/*u8 data = 0 ;
	LCD_voidInit();
	TWI_voidMasterInit(0x20);
	EEPROM_voidSendDataByte(0x02,8);
	EEPROM_voidReceiveDataByte(0x02,&data);
	DIO_voidSetPinDirection(DIO_PORTD,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD,PIN7,OUTPUT);
	LCD_voidSendString("number is : ");
	LCD_voidGoToXY(0,13);
	LCD_voidSendNumber(data);*/
	DIO_voidSetPinDirection(DIO_PORTA ,PIN0 , OUTPUT);

	while(1)
	{
			DIO_VoidSetPinValue(DIO_PORTA , PIN0 , HIGH);
			_delay_ms(1000);
			DIO_VoidSetPinValue(DIO_PORTA , PIN0 , LOW);
			_delay_ms(1000);
	}


	return 0 ;

}
