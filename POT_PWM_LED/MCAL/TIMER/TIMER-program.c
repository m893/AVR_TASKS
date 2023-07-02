/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/TIMER/TIMER_interface.h"
#include "../../MCAL/TIMER/TIMER_config.h"
#include "../../MCAL/TIMER/TIMER_private.h"


static void (*Global_pvOVFNotificationFunction)(void) = NULL;
static void (*Global_pvOCNotificationFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
		/* Set Normal Mode for timer0*/ 
	#if TIMER0_MODE == NORMAL_MODE
		CLEAR_BIT(TCCR0,TCCR0_WGM00);
		CLEAR_BIT(TCCR0,TCCR0_WGM01);
		/* Set CTC Mode for timer0 */
	#elif TIMER0_MODE == CTC_MODE
			CLEAR_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			/* set fast mode */
	#elif TIMER0_MODE == FAST_PWM_MODE
            SET_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01); 
			/* set PHASE CORRECT  mode */      
	#elif TIMER0_MODE == PHASE_CORRECT_MODE
			SET_BIT(TCCR0,TCCR0_WGM00);
			CLEAR_BIT(TCCR0,TCCR0_WGM01);
	#else

	#endif

	/*Set The Prescaler to be 8*/
		TCCR0 &= PRESCALER_MASK ;
		TCCR0 |= TIMER0_PRESCALER ;

}
void TIMER1_voidInit(void)
{
	/*SELECT MODE 14*/
	CLEAR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*SET NON INVERTED MODE*/
	CLEAR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLEAR_BIT(TCCR1A,TCCR1A_COM1A1);

	/*SET PRESCALER */
	CLEAR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLEAR_BIT(TCCR1B,TCCR1B_CS12);

}
void TIMER1_VoidSetICR1Value(u16 Copy_U16ICR2Value)
{
	ICR1=Copy_U16ICR2Value;
}
void TIMER1_VoidSetOCR1AValue(u16 Copy_U16OCR1A)
{
	OCR1A =Copy_U16OCR1A;
}



void TIMER2_voidInit(void)
{
		/* Set Normal Mode for timer2*/ 
	#if TIMER2_MODE == NORMAL_MODE
		CLEAR_BIT(TCCR2,TCCR2_WGM20);
		CLEAR_BIT(TCCR2,TCCR2_WGM21);
		/* Set CTC Mode for timer0 2*/
	#elif TIMER2_MODE == CTC_MODE
			CLEAR_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21);
			/* set fast mode FOR TIMER 2*/
	#elif TIMER2_MODE == FAST_PWM_MODE
            SET_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21); 
			/* set PHASE CORRECT  mode  FOR TIMER 2*/      
	#elif TIMER2_MODE == PHASE_CORRECT_MODE
			SET_BIT(TCCR2,TCCR2_WGM20);
			CLEAR_BIT(TCCR2,TCCR2_WGM21);
	#else

	#endif

	/*Set The Prescaler to be 8*/
		TCCR2 &= PRESCALER_MASK ;
		TCCR2 |= TIMER2_PRESCALER ;

}

void TIMER0_VoidSetModeForFastmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case FAST_OC0_DISCONNECTED :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case FAST_SET_ON_TOP :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	case FAST_CLEAR_ON_TOP :
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	default:
		break;
	}
}

void TIMER0_VoidSetModeForPhaseCorrectmode(u8 Copy_U8Mode)
{
	switch (Copy_U8Mode)
	{
	case PHASE_OC0_DISCONNECTED :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		CLEAR_BIT(TCCR0,TCCR0_COM01);
		break;
	case PHASE_SET_OC0_ON_COMAPRE :
		CLEAR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	case PHASE_CLEAR_OC0_ON_COMPARE :
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		break;
	default:
		break;
	}
}
void TIMER2_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT2 = Copy_u8Value ;
}
void TIMER2_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOVFNotificationFunction = pvNotificationFunction;
}
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOCNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		SET_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		SET_BIT(TIMSK,TIMSK_OCIE0);
	}
}
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode == NORMAL_MODE)
	{
		CLEAR_BIT(TIMSK,TIMSK_TOIE0);
	}
	else if(Copy_u8Mode == CTC_MODE)
	{
		CLEAR_BIT(TIMSK,TIMSK_OCIE0);
	}
}

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLEAR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetPreloadValue(6);
	u32 Number_of_OVF = ((u32)(Copy_u32Time*1000)) / 250;

	u32 Counter = 0;

	while(Counter < Number_of_OVF)
	{
		while(GET_BIT(TIFR , TIFR_TOV0) == 0);
		SET_BIT(TIFR , TIFR_TOV0);
		Counter++;
		TIMER0_voidSetPreloadValue(6);
	}
}
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time)
{
	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLEAR_BIT(TCCR0, TCCR0_CS02);

	TIMER0_voidSetOCMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32Time*1000)) / 250;
	u32 Number_Of_OCF = ((u32)Copy_u32Time * 1000UL) / 250UL;

	u32 Local_u32Counter = 0;

	while(Local_u32Counter <= Number_Of_OCF)
	{
		while(GET_BIT(TIFR , TIFR_OCF0) == 0);
		SET_BIT(TIFR , TIFR_OCF0);
		Local_u32Counter++;
	}
}

