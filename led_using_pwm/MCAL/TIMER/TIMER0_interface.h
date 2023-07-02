/***********
 * Author :   Mohammed Akram
 * Date  :   9 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              9 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#define NORMAL_MODE  0
#define CTC_MODE     1


void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8Value);
void TIMER0_voidSetOCMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetOVFCallBack(void(*pvNotificationFunction)(void));
void TIMER0_voidSetOCCallBack(void(*pvNotificationFunction)(void));

void TIMER0_voidEnableInterrupt(u8 Copy_u8Mode);
void TIMER0_voidDisableInterrupt(u8 Copy_u8Mode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32Time);
void TIMER0_voidSetBusyWait_OCMode(u32 Copy_u32Time);


#endif