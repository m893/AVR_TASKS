#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include  "../MCAL/SPI/SPI_interface.h"
#include  "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/EXTERNAL_INTERRUPT/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/LM35/LM_interface.h"

volatile u8 flag  ;
void  readvalue(void);

#define  F_CPU 8000000UL


u32 main (void)
{
	GIE_VoidEnabledGlobalInterrupt();
	LCD_voidInit();
	DIO_voidSetPinDirection(DIO_PORTD,PIN2,INPUT);
	DIO_VoidSetPinValue(DIO_PORTD,PIN2,PULLUP);

	EXTI_VoidIntit(EXTI_INT0);
	EXTI_VoidTriggerEdge(EXTI_INT0,FALLING_EDGE);
	EXTI_VoidEnable(EXTI_INT0);
	EXTI_VoidINT0SetCallBack(&readvalue);

	DIO_voidSetPinDirection(DIO_PORTB,PIN5,OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN7,OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,PULLUP);

	SPI_VoidMAsterInit();

	//SPI_u8SendReceive(10);

	//_delay_ms(500);
	//SPI_u8SendReceive(20);


	while(1)
	{
			u8 temp = 0 ;

			if(flag ==1 )
			{
					LCD_voidClearDisplay();
					flag =0 ;
					temp = SPI_u8SendReceive(255);
					LCD_voidSendNumber(temp);
			}







	}

	return 0 ;

}

void  readvalue(void)
{


		flag = 1 ;

}