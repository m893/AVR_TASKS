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

#ifndef MCAL_TIMER_INTERFACE_H_
#define MCAL_TIMER_INTERFACE_H_

#define NULL    ((void*)0)

#define TIMER0_NORMAL_MODE          0
#define TIMER0_FAST_MODE            1
#define TIMER0_CTC_MODE             2
#define TIMER0_PHASE_CORRECT_MODE   3

#define SCALER_TIMER_STOP           0
#define SCALER_1                    1
#define SCALER_8                    2
#define SCALER_64                   3
#define SCALER_256                  4
#define SCALER_1024                 5
#define EXTERNAL_FALLING_EDGE       6
#define EXTERNAL_RISING_EDGE        7


#define OC0_DISCONECTED            0x00
#define OC0_TOGGLE                 0x10
#define OC0_NON_INVERTING          0x20
#define OC0_INVERTING              0x30


void Timer0_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode);
void Timer0_voidSetPreloadValue(u8 Copy_u8Value);
void Timer0_voidSetCompareMatchValue(u8 Copy_u8Value);
u8   Timer0_u8GetTimer0Value(void);

void Timer0_voidTOVSetCallBack(void (*NotifiFunction)(void));
void Timer0_voidOCRSetCallBack(void (*NotifiFunction)(void));

void Timer0_void_OVF_InterruptEnable(void);
void Timer0_void_OVF_InterruptDisable(void);
void Timer0_void_OCR_InterruptEnable(void);
void Timer0_void_OCR_InterruptDisable(void);

void Timer0_voidDelay_Sec(u8 Copy_u8Second);
void Timer0_voidDelay_ms(u32 Copy_u32MilliSec);
void Timer0_voidDelay_us(u32 Copy_u16MicroSec);


/******************************* Timer 1 **************************************/
#define 	TIMER1_NORMAL_MODE                              0 
#define 	TIMER1_CTC_TOP_OCR1A_MODE                       1
#define 	TIMER1_CTC_TOP_ICR1_MODE                        2
#define     TIMER1_PHASECORRECT_TOP_ICR1_MODE               3       
#define     TIMER1_PHASECORRECT_TOP_OCR1A_MODE              4        
#define 	TIMER1_PHASE_FREQ_CORRECT_TOP_ICR1_MODE         5            
#define     TIMER1_PHASE_FREQ_CORRECT_TOP_OCR1A_MODE        6                
#define 	TIMER1_FASTPWM_TOP_ICR1_MODE                    7    
#define     TIMER1_FASTPWM_TOP_OCR1A_MODE                   8


#define OC1A_DISCONECTED                    0x00
#define OC1A_TOGGLE                         0x40
#define OC1A_NON_INVERTING                  0x80
#define OC1A_INVERTING                      0xC0

#define OC1B_DISCONECTED                    0x00
#define OC1B_TOGGLE                         0x10
#define OC1B_NON_INVERTING                  0x20
#define OC1B_INVERTING                      0x30


#define     TIMER1_OC1A_DISCONNECTED                        0x00
#define     Timer1_OC1A_TOGGLE                              0x40
#define     Timer1_OC1A_NON_INVERTING                       0x80
#define     Timer1_OC1A_INVERTING                           0xC0

#define     TIMER1_OC1B_DISCONNECTED                        0x00
#define     Timer1_OC1B_TOGGLE                              0x10
#define     Timer1_OC1B_NON_INVERTING                       0x20
#define     Timer1_OC1B_INVERTING                           0x30

#define     ICU_TRIGGER_EDGE_FALLING_EDGE                   0
#define     ICU_TRIGGER_EDGE_RISING_EDGE                    1

#define     ICU_INTERRUPT_DISABLE                           0
#define     ICU_INTERRUPT_ENABLE                            1

void Timer1_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCR1AMode, u8 Copy_u8OCR1BMode);
void Timer1_voidSetPreloadValue(u16 Copy_u16Value);
void Timer1_voidSetOCR1AValue(u16 Copy_u16OCR1AValue);
void Timer1_voidSetOCR1BValue(u16 Copy_u16OCR1BValue);
void Timer1_voidSetICR1Value(u16 Copy_u16ICR1Value);
void Timer1_voidOVFSetCallBack(void (*NotifiFunction)(void));
void Timer1_voidOC1ASetCallBack(void (*NotifiFunction)(void));
void Timer1_voidOC1BSetCallBack(void (*NotifiFunction)(void));
void Timer1_voidOVFInterruptEnable(void);
void Timer1_voidOVFInterruptDisable(void);
void Timer1_voidOC1AInterruptEnable(void);
void Timer1_voidOC1AInterruptDisable(void);
void Timer1_voidOC1BInterruptEnable(void);
void Timer1_voidOC1BInterruptDisable(void);

u16  ICU_voidGetICR1Value(void);
void ICU_voidSetCallBack(void (*NotifiFunction)(void));
void ICU_voidSetTriggerEdge(u8 Copy_u8TriggerEdge);
void ICU_voidInterruptEnable(void);
void ICU_voidInterruptDisable(void);

/******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
/******************************* Timer 2 **************************************/
#define TIMER2_NORMAL_MODE                  0
#define TIMER2_PHASE_CORRECT_MODE           1
#define TIMER2_CTC_MODE                     2
#define TIMER2_FAST_MODE                    3

#define OC2_DISCONECTED                    0x00
#define OC2_TOGGLE                         0x10
#define OC2_NON_INVERTING                  0x20
#define OC2_INVERTING                      0x30

#define TIMER2_SCLAER_STOP                  0
#define TIMER2_SCLAER_1                     1
#define TIMER2_SCLAER_8                     2
#define TIMER2_SCLAER_32                    3
#define TIMER2_SCLAER_64                    4
#define TIMER2_SCLAER_128                   5
#define TIMER2_SCLAER_256                   6
#define TIMER2_SCLAER_1024                  7


void Timer2_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OCRMode);
void Timer2_voidSetPreloadValue(u8 Copy_u8Value);
void Timer2_voidSetCompareMatchValue(u8 Copy_u8Value);
u8   Timer2_u8GetTimer2Value(void);

void Timer2_voidTOVSetCallBack(void (*NotifiFunction)(void));
void Timer2_voidOCRSetCallBack(void (*NotifiFunction)(void));

void Timer2_void_OVF_InterruptEnable(void);
void Timer2_void_OVF_InterruptDisable(void);
void Timer2_void_OCR_InterruptEnable(void);
void Timer2_void_OCR_InterruptDisable(void);

void Timer2_voidDelay_ms(u16 Copy_u16MilliSec);
void Timer2_voidDelay_us(u16 Copy_u16MicroSec);
/******************************************************************************/


#endif 
