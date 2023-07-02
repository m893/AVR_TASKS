#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#define  F_CPU 8000000UL


u32 main (void)
{
	u8  local_receive =0 ;
	DIO_voidSetPinDirection(DIO_PORTA, PIN0 , OUTPUT);
	/* tx pin */
	DIO_voidSetPinDirection(DIO_PORTD , PIN1 , OUTPUT);
	/* rx pin */
	DIO_voidSetPinDirection(DIO_PORTD , PIN0 , INPUT);

	UART_VoidInit();


	while(1)
	{
			 UART_u8ReceiveDataSynchronous(&local_receive);
			 UART_VoidTransmitDataSynchronous(local_receive);

			 if(local_receive == 'A')
			 {
				 DIO_VoidSetPinValue(DIO_PORTA ,PIN0 , HIGH);
			 }
			 else if (local_receive == 'B')
			 {
				 DIO_VoidSetPinValue(DIO_PORTA ,PIN0 , LOW);

			 }
			 else
			 {
				 /**/
			 }


	}

	return 0 ;

}
