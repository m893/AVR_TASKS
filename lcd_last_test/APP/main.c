#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#define  F_CPU 8000000UL


u32 main (void)
{
	LCD_voidInit();
	u8 customChar[] = {0x0E,
			  0x04,
			  0x0E,
			  0x15,
			  0x04,
			  0x0A,
			  0x11,
			  0x00

					};
			u8 customChar2[]= {
					 0x0E,
					  0x04,
					  0x15,
					  0x0E,
					  0x04,
					  0x1A,
					  0x11,
					  0x00
			};
			u8 customChar3[] = {
					 0x0E,
					  0x04,
					  0x15,
					  0x0E,
					  0x04,
					  0x1A,
					  0x11,
					  0x00
			};

			u8 arr[]="my name is";
			u8 arr2[]=" mohammed";
	//LCD_VoidSendCustomCharacter(arr,0,0,1);

			LCD_voidSendNumber(7);

	while(1)
	{

		//LCD_VoidSendNumber(5);








	}

	return 0 ;

}
