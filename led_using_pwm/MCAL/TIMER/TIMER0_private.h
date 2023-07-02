/***********
 * Author :   Mohammed Akram
 * Date  :   9 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              9 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H



#define PRESCALER_TIMER_STOP   0
#define PRESCALER_1            1
/*REGISTER TO SELECT MODE FOR TIMER OR COUNTER AND THE PRESCALER AND SELECT MODE O TIMER*/
#define  TCCR0           *((volatile u8 *)0x53)

#define TCCR0_CS00        0       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_CS01        1       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_CS02        2       //SELECT TIMER OR COUNTER AND PRESCAELR FOR TIMER MODE
#define TCCR0_WGM01       3       //SELECT NORMAL MODE OR CTC MODE
#define TCCR0_COM00       4       //MODE OF OC0 IN CTC MODE
#define TCCR0_COM01       5       //MODE OF OC0 IN CTC MODE
#define TCCR0_WGM00       6       //SELECT NORMAL MODE OR CTC MODE
#define TCCR0_FOC0        7       


//REGISTER TO STORE TIMER VALUE
#define  TCNT0                  *((volatile u8 *)0x52)


// REISTER TO SET THE COMPARE VALUE 
#define OCR0                        *((volatile u8 *)0x5c)


//REGISTER TO SET INTERRUPT ENABLE FOR NORMAL MODE AND CTC MODE
#define TIMSK                       *((volatile u8 *)0x59)

#define TIMSK_TOIE0       0       //TIMER OVERFLOW INTERRUPT ENABLE 
#define TIMSK_OCIE0       1       //TIMER OUTPUT COMPARE MATCH ENABLE


//REGISTER FOR TIMER FLAGS
#define  TIFR                           *((volatile u8 *)0x58)

#define TIFR_TOV0       0    //flag for overflow mode
#define TIFR_OCF0       1    //flag for output compare (CTC)






#endif