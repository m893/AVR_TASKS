#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include  "../MCAL/SPI/SPI_interface.h"
#include  "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include  "../HAL/LM35/LM_interface.h"
#define  F_CPU 8000000UL


u32 main (void)
{
	LCD_voidInit();
	ADC_VoidInit();
	DIO_voidSetPinDirection(DIO_PORTB,PIN5,OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN7,OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,INPUT);
	DIO_voidSetPinDirection(DIO_PORTB,PIN6,PULLUP);

	SPI_VoidSlaveInit();


			u16 temp ;
			Lm_t lm1;
			lm1.Lm_Port=DIO_PORTA ;
			lm1.Lm_pin=PIN0 ;
			LM_VoidInit(&lm1);




	while(1)
	{

					temp=Lm_U8ReturnTemperture(&lm1);
					LCD_voidGoToXY(0,0);
					LCD_voidSendNumber(temp);
					SPI_u8SendReceive(temp);

	}

	return 0 ;

}
