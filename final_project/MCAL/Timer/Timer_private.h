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
#ifndef MCAL_TIMER_PRIVATE_H_
#define MCAL_TIMER_PRIVATE_H_

#define MILLI_SECOND            1000UL
#define COMPARE_MATCH_VALUE     250UL

/****************************************** Timer 0 ******************************************/
#define CLOCK_SELECT_MASK           0b11111000
#define OC0_CLEAR_MASK              0b11001111

static void (*Timer0_TOV_NotificationFunc)(void) = NULL;
static void (*Timer0_OCR_NotificationFunc)(void) = NULL;
//------------------------------------- Registers -------------------------------------------//
#define TCNT0   (*(volatile u8*)0x52)
#define OCR0    (*(volatile u8*)0x5C)

#define TCCR0   (*(volatile u8*)0x53)
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6
#define TCCR0_COM01   5
#define TCCR0_COM00   4
#define TCCR0_WGM01   3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0
/*********************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////
/****************************************** Timer 1 ******************************************/
#define     OCR1A_CLEAR_MASK            0x3F
#define     OCR1B_CLEAR_MASK            0xCF
#define     PRESCALER_CLEAR_MASK        0XF8

static void (*Timer1_OVF_NotificationFunc)(void)  =  NULL;
static void (*Timer1_OC1A_NotificationFunc)(void) =  NULL;
static void (*Timer1_OC1B_NotificationFunc)(void) =  NULL;
static void (*Timer1_ICU_NotificationFunc)(void)  =  NULL;

//------------------------------------- Registers -------------------------------------------//
#define TCCR1A          (*(volatile u8*)0x4F)
#define TCCR1A_COM1A1          7
#define TCCR1A_COM1A0          6
#define TCCR1A_COM1B1          5
#define TCCR1A_COM1B0          4
#define TCCR1A_FOC1A           3
#define TCCR1A_FOC1B           2
#define TCCR1A_WGM11           1
#define TCCR1A_WGM10           0

#define TCCR1B          (*(volatile u8*)0x4E)
#define TCCR1B_ICNC1           7
#define TCCR1B_ICES1           6
/* bit 5 reserved */
#define TCCR1B_WGM13           4
#define TCCR1B_WGM12           3
#define TCCR1B_CS12            2
#define TCCR1B_CS11            1
#define TCCR1B_CS10            0


#define TCNT1           (*(volatile u16*)0x4C)
#define TCNT1L          (*(volatile u8*)0x4C)
#define TCNT1H          (*(volatile u8*)0x4D)

#define OCR1A           (*(volatile u16*)0x4A)
#define OCR1AL          (*(volatile u8*)0x4A)
#define OCR1AH          (*(volatile u8*)0x4B)

#define OCR1B           (*(volatile u16*)0x48)
#define OCR1BL          (*(volatile u8*)0x48)
#define OCR1BH          (*(volatile u8*)0x49)

#define ICR1            (*(volatile u16*)0x46)
#define ICR1L           (*(volatile u8*)0x46)
#define ICR1H           (*(volatile u8*)0x47)

/*********************************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////
/****************************************** Timer 2 ******************************************/
#define OC2_CLEAR_MASK         0b11001111 
static void (*Timer2_TOV_NotificationFunc)(void) = NULL;
static void (*Timer2_OCR_NotificationFunc)(void) = NULL;

#define TCCR2    (*(volatile unsigned char*)0x45)
#define TCCR2_FOC2    7
#define TCCR2_WGM20   6
#define TCCR2_COM21   5
#define TCCR2_COM20   4
#define TCCR2_WGM21   3
#define TCCR2_CS22    2
#define TCCR2_CS21    1
#define TCCR2_CS20    0

#define TCNT2    (*(volatile unsigned char*)0x44)
#define OCR2     (*(volatile unsigned char*)0x43)

#define ASSR     (*(volatile unsigned char*)0x42)
/* bits 7-4 reserved */
#define ASSR_AS2     3
#define ASSR_TCN2UB  2
#define ASSR_OCR2UB  1
#define ASSR_TCR2UB  0
/***************************************************************************************/

//-------------------------------------------------------------------------------------//
//----------------------------- Timers Interrupts & Flags -----------------------------//
//-------------------------------------------------------------------------------------//
#define TIMSK   (*(volatile u8*)0x59)
#define TIMSK_OCIE2   7
#define TIMSK_TOIE2   6
#define TIMSK_TICIE1  5
#define TIMSK_OCIE1A  4
#define TIMSK_OCIE1B  3
#define TIMSK_TOIE1   2
#define TIMSK_OCIE0   1
#define TIMSK_TOIE0   0

#define TIFR    (*(volatile u8*)0x58)
#define TIFR_OCF2    7
#define TIFR_TOV2    6
#define TIFR_ICF1    5
#define TIFR_OCF1A   4
#define TIFR_OCF1B   3
#define TIFR_TOV1    2
#define TIFR_OCF0    1
#define TIFR_TOV0    0

//-----------------------------------------------------------------------------------//
//---------------------------------------ISR Vectors---------------------------------//
//-----------------------------------------------------------------------------------//

#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11


#endif 
