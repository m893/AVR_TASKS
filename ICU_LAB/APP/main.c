/***********
 * Author :   Mohammed Akram
 * Date  :   15 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              15 April, 2023               Mohammed Akram
***************************************************************************/

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include <util/delay.h>
#include  "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include  "../HAL/LCD/LCD_interface.h"

void ICU_HW(void);

volatile u16 R1;
volatile u16 R2;
volatile u16 R3;
volatile u16 on_time = 0;
volatile u16 Period_time = 0;

u32 main (void)
{
	GIE_VoidEnabledGlobalInterrupt(); // ENABLE GLOBALE INTERRUPT
	DIO_voidSetPinDirection(DIO_PORTB,PIN3,OUTPUT);//SET PIN OC0 AS OUTPUT OF TIMER0
	DIO_voidSetPinDirection(DIO_PORTD,PIN6,INPUT);//SET INPUT CAPTURE OIN AS INPUT

	LCD_voidInit();

	TIMER0_voidInit(); //INIT  TIMER ZERO TO PWD FAST MODE
	TIMER0_VoidSetModeForFastmode(FAST_SET_ON_TOP); // SET FST MODE TO SET ON TOP CLEAR ON COMAPE
	TIMER0_voidSetOCMatchValue(50); // SET COPMARE VALUE TO 50 ON TIME
	ICU_VoidSetTriggerSignal(ICU_RISING_EDGE); //SET ICU PIN ACTIVATE IN RISING EDGE
	ICU_VoidEnableIntrrupt(ICU_INTERRUPT_ENABLE); // ENABLE ICU INTERRUPT
	ICU_VoidSetCallBack(&ICU_HW); // CALL FUNCTION TO CALCULATE THE PWD
	TIMER1_voidInit(); // INIT TIMER 1  AS NORMAL MODE BEST FOR ICU




	while(1)
	{
		// STUCK UNTIL THE VALU OF ON TIME AND PERIOD TIME CHANGE
				while(on_time == 0 || Period_time == 0);
				LCD_voidGoToXY(0,0);
				LCD_voidSendString("period_t = ");
				LCD_voidSendNumber(Period_time);
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("on_time = ");
				LCD_voidSendNumber(on_time);





	}
}
void ICU_HW(void)
{
	static u8 Local_u8Counter = 0;
		Local_u8Counter++;
		if(Local_u8Counter == 1)
		{
			R1 = ICU_U16GetICRRegister(); // READ ICR1 REGISTER AT RISING EDGE
			ICU_VoidSetTriggerSignal(ICU_FALLING_EDGE); //CHANGE EGDE TO READ VALUE IN FALLING EDGE
		}
		else if(Local_u8Counter == 2) // ENTER WHEN FALLING EGDE INTERRUPT OCCUR
		{
			//READ ICR1 REGISTER IN FALLING EDGE
			R2 = ICU_U16GetICRRegister();
			//CALCILATE ON TIME DIFFERECE BETWEEN TIME OF RISING AND TIME OF FALLING
			on_time= R2 - R1 - 1;
		}
		else if(Local_u8Counter == 3) //ENETR WHEN FALLING INTERRUPT OCCUR AGIAN
		{
			// RAED ICR1 REGISTER
			R3 = ICU_U16GetICRRegister();
			//CALCULATE PERIOD TIME DIFFERENCE BETWEEN FALLING AND FALLING
			Period_time = R3 - R2 - 1;
			//DISABLED INTERRUPT FOR ICU
			ICU_VoidEnableIntrrupt(ICU_INTERRUPT_DISABLE);

			Local_u8Counter = 0;
		}
}
