/***********
 * Author :   Mohammed Akram
 * Date  :   10 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              10 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#define  TCNT0                  *((volatile u8 *)0x52)

#define NORMAL_MODE           0
#define CTC_MODE              1
#define FAST_PWM_MODE         2
#define PHASE_CORRECT_MODE    3

#define ICU_FALLING_EDGE       1
#define ICU_RISING_EDGE        0

#define ICU_INTERRUPT_ENABLE   1
#define ICU_INTERRUPT_DISABLE   0



#define FAST_OC0_DISCONNECTED    0
#define FAST_SET_ON_TOP          1
#define FAST_CLEAR_ON_TOP        2


#define PHASE_OC0_DISCONNECTED             0
#define PHASE_SET_OC0_ON_COMAPRE           1
#define PHASE_CLEAR_OC0_ON_COMPARE         2

typedef enum
{
	normal_mode = 0 ,
	ctc_mode = 0 ,
	fast_mode = 0 ,
	phase_mode = 0 ,
}timer0_mode;

typedef enum
{
	timer0_stop =0 ,
	timer0_scaler_1 ,
	timer0_scaler_8 ,
	timer0_scaler_64 ,
	timer0_scaler_128 ,

}timer0_scaler;

void TIMER0_VoidIntit2(timer0_mode mode , timer0_scaler scaler);


void TIMER0_voidInit(void);
void TIMER2_voidInit(void);


void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);


#endif
