/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   9 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         9 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../GIE/GIE_interface.h"

#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"



void Timer0_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode)
{
    /*Set Timer0 Mode*/
    switch (Copy_u8Mode)
    {
    case TIMER0_NORMAL_MODE:
        CLEAR_BIT(TCCR0, TCCR0_WGM00);
        CLEAR_BIT(TCCR0, TCCR0_WGM01);
        break;
    case TIMER0_PHASE_CORRECT_MODE:
        SET_BIT(TCCR0, TCCR0_WGM00);
        CLEAR_BIT(TCCR0, TCCR0_WGM01);
        break;
    case TIMER0_CTC_MODE:
        CLEAR_BIT(TCCR0, TCCR0_WGM00);
        SET_BIT(TCCR0, TCCR0_WGM01);
        break;
    case TIMER0_FAST_MODE:
        SET_BIT(TCCR0, TCCR0_WGM00);
        SET_BIT(TCCR0, TCCR0_WGM01);
        break;
    
    default:
        break;
    }

    /*Set OCR Mode*/
    TCCR0 &= OC0_CLEAR_MASK;
    TCCR0 |= Copy_u8OCRMode;

    /*Set Timer0 Prescaler*/
    TCCR0 &= CLOCK_SELECT_MASK;
    TCCR0 |= Copy_u8Scaler;
}

void Timer0_voidSetPreloadValue(u8 Copy_u8Value)
{
    TCNT0 = Copy_u8Value;
}

void Timer0_voidSetCompareMatchValue(u8 Copy_u8Value)
{
    OCR0 = Copy_u8Value;
}

void Timer0_voidDelay_Sec(u8 Copy_u8Second)
{
    Timer0_voidDelay_ms(Copy_u8Second * MILLI_SECOND);
}

void Timer0_voidDelay_ms(u32 Copy_u32MilliSec)
{
    f32 Local_f32OVCounts = ((f32)Copy_u32MilliSec * 1000.0)/ 256.0;
    u32 Local_u32Counts = (u32)Local_f32OVCounts;
    u32 Local_u32Remender = Local_f32OVCounts - (u32)Local_f32OVCounts;
    u8 Local_u8PreloadValue = 0;

    if(Local_u32Remender != 0)
    {
        Local_u8PreloadValue = 256 * (1 - Local_u32Remender);
        Local_u32Counts += 1;
    }


    Timer0_voidSetPreloadValue(Local_u8PreloadValue);

    while(Local_u32Counts--)
    {
        while(GET_BIT(TIFR, TIFR_TOV0) == 0);
        SET_BIT(TIFR, TIFR_TOV0);
    }
}

void Timer0_voidDelay_us(u32 Copy_u16MicroSec)
{
    f32 Local_f32OVCounts = (f32)Copy_u16MicroSec/ 256.0;
    u16 Local_u16Counts = (u8) Local_f32OVCounts;
    u32 Local_u32Remender = Local_f32OVCounts - (s32)Local_f32OVCounts;
    u8 Local_u8PreloadValue = 0;

    if(Local_u32Remender != 0)
    {
        Local_u8PreloadValue = 256 * (1 - Local_u32Remender);
        Local_u16Counts += 1;
    }
    
    
    Timer0_voidSetPreloadValue(Local_u8PreloadValue);

    while(Local_u16Counts--)
	{
		while(GET_BIT(TIFR, TIFR_TOV0) == 0);
		SET_BIT(TIFR, TIFR_TOV0);
	}
    
}

void Timer0_void_OVF_InterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_TOIE0);
}

void Timer0_void_OVF_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_TOIE0);
}

void Timer0_void_OCR_InterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_OCIE0);
}

void Timer0_void_OCR_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_OCIE0);
}


void Timer0_voidTOVSetCallBack(void (*NotifiFunction)(void))
{
    Timer0_TOV_NotificationFunc = NotifiFunction;
}

void Timer0_voidOCRSetCallBack(void (*NotifiFunction)(void))
{
    Timer0_OCR_NotificationFunc = NotifiFunction;
}

ISR(TIMER0_OVF_vect)
{
    if(Timer0_TOV_NotificationFunc)
    {
        Timer0_TOV_NotificationFunc();
    }
}

ISR(TIMER0_COMP_vect)
{
    if(Timer0_OCR_NotificationFunc)
    {
        Timer0_OCR_NotificationFunc();
    }
}



/************************************Timer1***********************************/
void Timer1_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCR1AMode, u8 Copy_u8OCR1BMode)
{   
    /*Set Timer1 Mode*/
    switch (Copy_u8Mode)
    {
        case TIMER1_NORMAL_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_CTC_TOP_OCR1A_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_CTC_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_PHASECORRECT_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_PHASECORRECT_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_PHASE_FREQ_CORRECT_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_PHASE_FREQ_CORRECT_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            CLEAR_BIT(TCCR1A, TCCR1A_WGM11);
            CLEAR_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_FASTPWM_TOP_ICR1_MODE:
            CLEAR_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
        case TIMER1_FASTPWM_TOP_OCR1A_MODE:
            SET_BIT(TCCR1A, TCCR1A_WGM10);
            SET_BIT(TCCR1A, TCCR1A_WGM11);
            SET_BIT(TCCR1B, TCCR1B_WGM12);
            SET_BIT(TCCR1B, TCCR1B_WGM13);
            break;
    }

    /*Set OCR1A Mode*/
    TCCR1A &= OCR1A_CLEAR_MASK;
    TCCR1A |= Copy_u8OCR1AMode;

    /*Set OCR1B Mode*/
    TCCR1A &= OCR1B_CLEAR_MASK;
    TCCR1A |= Copy_u8OCR1BMode;
    
    /*Set Timer1 Prescaler*/
    TCCR1B &= CLOCK_SELECT_MASK;
    TCCR1B |= Copy_u8Scaler;
}

void Timer1_voidSetPreloadValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

void Timer1_voidSetOCR1AValue(u16 Copy_u16OCR1AValue)
{
    OCR1A = Copy_u16OCR1AValue;
}

void Timer1_voidSetOCR1BValue(u16 Copy_u16OCR1BValue)
{
    OCR1B = Copy_u16OCR1BValue;
}

void Timer1_voidSetICR1Value(u16 Copy_u16ICR1Value)
{
    ICR1 = Copy_u16ICR1Value;
}


u16  ICU_voidGetICR1Value(void)
{
    return ICR1;
}


void ICU_voidSetTriggerEdge(u8 Copy_u8TriggerEdge)
{
    switch (Copy_u8TriggerEdge)
    {
    case ICU_TRIGGER_EDGE_FALLING_EDGE:
        CLEAR_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    
    case ICU_TRIGGER_EDGE_RISING_EDGE:
        SET_BIT(TCCR1B, TCCR1B_ICES1);
        break;
    
    default:
        break;
    }
}



void Timer1_voidOVFInterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_TOIE1);
}

void Timer1_voidOVFInterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_TOIE1);
}

void Timer1_voidOC1AInterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_OCIE1A);
}

void Timer1_voidOC1AInterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_OCIE1A);
}

void Timer1_voidOC1BInterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_OCIE1B);
}

void Timer1_voidOC1BInterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_OCIE1B);
}

void ICU_voidInterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_TICIE1);
}

void ICU_voidInterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_TICIE1);
}


/****************Set Interrupts Functions Call Back*********************/
void Timer1_voidOVFSetCallBack(void (*NotifiFunction)(void))
{
    Timer1_OVF_NotificationFunc = NotifiFunction;
}

void Timer1_voidOC1ASetCallBack(void (*NotifiFunction)(void))
{
    Timer1_OC1A_NotificationFunc = NotifiFunction;
}

void Timer1_voidOC1BSetCallBack(void (*NotifiFunction)(void))
{
    Timer1_OC1B_NotificationFunc = NotifiFunction;
}

void ICU_voidSetCallBack(void (*NotifiFunction)(void))
{
    Timer1_ICU_NotificationFunc = NotifiFunction;
}
/*************************************************************************/

ISR(TIMER1_OVF_vect)
{
    if(Timer1_OVF_NotificationFunc)
    {
        Timer1_OVF_NotificationFunc();
    }
}

ISR(TIMER1_COMPA_vect)
{
    if(Timer1_OC1A_NotificationFunc)
    {
        Timer1_OC1A_NotificationFunc();
    }
}

ISR(TIMER1_COMPB_vect)
{
    if(Timer1_OC1B_NotificationFunc)
    {
        Timer1_OC1B_NotificationFunc();
    }
}

ISR(TIMER1_CAPT_vect)
{
    if(Timer1_ICU_NotificationFunc)
    {
        Timer1_ICU_NotificationFunc();
    }
}


/*****************************************************************************/
/************************************Timer1***********************************/
void Timer2_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode)
{
    //Set Timer 2 Mode//
    switch (Copy_u8Mode)
    {
    case TIMER2_NORMAL_MODE:
        CLEAR_BIT(TCCR2, TCCR2_WGM20);
        CLEAR_BIT(TCCR2, TCCR2_WGM21);
        break;
    case TIMER2_PHASE_CORRECT_MODE:
        SET_BIT(TCCR2, TCCR2_WGM20);
        CLEAR_BIT(TCCR2, TCCR2_WGM21);
        break;
    case TIMER2_CTC_MODE:
        CLEAR_BIT(TCCR2, TCCR2_WGM20);
        SET_BIT(TCCR2, TCCR2_WGM21);
        break;
    case TIMER2_FAST_MODE:
        SET_BIT(TCCR2, TCCR2_WGM20);
        SET_BIT(TCCR2, TCCR2_WGM21);
        break;
    
    default:
        break;
    }

    /*Set OCR2 Mode*/
    TCCR2 &= OC2_CLEAR_MASK;
    TCCR2 |= Copy_u8OCRMode;
    
    /*Set TIMER2 Prescaler*/
    TCCR2 &= CLOCK_SELECT_MASK;
    TCCR2 |= Copy_u8Scaler;
}

void Timer2_voidSetPreloadValue(u8 Copy_u8Value)
{
    TCNT2 = Copy_u8Value;
}

void Timer2_voidSetCompareMatchValue(u8 Copy_u8Value)
{
    OCR2 = Copy_u8Value;
}

u8   Timer2_u8GetTimer2Value(void)
{
    return TCNT2;
}


void Timer2_voidDelay_ms(u16 Copy_u16MilliSec)
{
    u8 Local_u8Counter = ((u32)Copy_u16MilliSec * MILLI_SECOND)/ COMPARE_MATCH_VALUE;
    Timer2_voidSetCompareMatchValue(COMPARE_MATCH_VALUE);
    Timer2_voidInit(TIMER2_CTC_MODE, SCALER_8, OC2_DISCONECTED);
    
    while (Local_u8Counter--)
    {
        while (GET_BIT(TIFR, TIFR_OCF2) == 0);
        SET_BIT(TIFR, TIFR_OCF2);
    }
    

}
void Timer2_voidDelay_us(u16 Copy_u16MicroSec)
{
    u16 Local_u16Counter = Copy_u16MicroSec/ COMPARE_MATCH_VALUE;
    Timer2_voidSetCompareMatchValue(COMPARE_MATCH_VALUE);
    Timer2_voidInit(TIMER2_CTC_MODE, SCALER_8, OC2_DISCONECTED);
    
    while (Local_u16Counter--)
    {
        while (GET_BIT(TIFR, TIFR_OCF2) == 0);
        SET_BIT(TIFR, TIFR_OCF2);
    }
    
}

void Timer2_void_OVF_InterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_TOIE2);
}

void Timer2_void_OVF_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_TOIE2);
}

void Timer2_void_OCR_InterruptEnable(void)
{
    SET_BIT(TIMSK, TIMSK_OCIE2);
}

void Timer2_void_OCR_InterruptDisable(void)
{
    CLEAR_BIT(TIMSK, TIMSK_OCIE2);
}

void Timer2_voidTOVSetCallBack(void (*NotifiFunction)(void))
{
    Timer2_TOV_NotificationFunc = NotifiFunction;
}

void Timer2_voidOCRSetCallBack(void (*NotifiFunction)(void))
{
    Timer2_OCR_NotificationFunc = NotifiFunction;
}


ISR(TIMER2_OVF_vect)
{
    if(Timer2_TOV_NotificationFunc)
    {
        Timer2_TOV_NotificationFunc();
    }
}

ISR(TIMER2_COMP_vect)
{
    if(Timer2_OCR_NotificationFunc)
    {
        Timer2_OCR_NotificationFunc();
    }
}
/*****************************************************************************/
