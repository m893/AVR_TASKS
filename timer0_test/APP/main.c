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

#define F_CPU	8000000UL
#include <util/delay.h>
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../HAL/LCD/LCD_interface.h"



	volatile u16 c = 0 ;
u32 main (void)
{
		u16 x , y ;
	DIO_voidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	GIE_VoidEnabledGlobalInterrupt();
	//LCD_voidInit();
	TCNT0=0;
	TIMER0_VoidIntit2(normal_mode,timer0_scaler_8);
	TIMER0_voidEnableInterrupt(0);
	//TCNT0=0;
	//_delay_us(100);
	//x = TCNT0 ;
	//y=c ;

	//LCD_voidSendNumber(x);
	//LCD_VoidGoToXY(1,0);
	//LCD_VoidSendNumber(y);




	while(1)
	{






	}
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	c++;

	if(c==1953)
	{
		DIO_VoidTogglePinValu(DIO_PORTA,PIN0);
		c=0 ;
	}
}

