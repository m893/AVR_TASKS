/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   6 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         6 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define     RIGHT_ADJUST            0
#define     LEFT_ADJUST             1
#define     FULL_ADC_REG            2

// #define     AREF                    0
// #define     AVCC                    1
// #define     INTERNAL_2v56           2

#define REF_CLR_MASK        0x3F

#define AREF                0x00
#define AVCC                0x40
#define INTERNAL_2v56       0xC0

#define     DISABLE         0
#define     ENABLE          1

#define ADC_SCALER_2        0b00000001
#define ADC_SCALER_4        0b00000010
#define ADC_SCALER_8        0b00000011
#define ADC_SCALER_16       0b00000100
#define ADC_SCALER_32       0b00000101
#define ADC_SCALER_64       0b00000110
#define ADC_SCALER_128      0b00000111

#define ADC_CLR_SCALER_MASK 0b11111000
#define CHANNEL_CLR_MASK    0b11100000



/****************************Register Description***********************************/
#define     ADMUX           *((volatile u8 *)0x27)  // ADC Multiplixer Selection Register
#define     ADMUX_MUX0      0                       // ADC Muliplixer Bit 0
#define     ADMUX_MUX1      1                       // ADC Muliplixer Bit 1
#define     ADMUX_MUX2      2                       // ADC Muliplixer Bit 2
#define     ADMUX_MUX3      3                       // ADC Muliplixer Bit 3
#define     ADMUX_MUX4      4                       // ADC Muliplixer Bit 4
#define     ADMUX_ADLAR     5                       // ADC Left Adjust Result
#define     ADMUX_REFS0     6                       // ADC Reference Selection Bit 0
#define     ADMUX_REFS1     7                       // ADC Reference Selection Bit 1

#define     ADCSRA           *((volatile u8 *)0x26)  // ADC Control and Status Register
#define     ADCSRA_ADPS0     0                       // ADC Prescaler Selection bit 0 
#define     ADCSRA_ADPS1     1                       // ADC Prescaler Selection bit 1
#define     ADCSRA_ADPS2     2                       // ADC Prescaler Selection bit 2
#define     ADCSRA_ADIE      3                       // ADC Interrupt Enable Bit
#define     ADCSRA_ADIF      4                       // ADC Interrupt Flag Bit
#define     ADCSRA_ADATE     5                       // ADC Auto Trigger Enable bit
#define     ADCSRA_ADSC      6                       // ADC Start Conversion bit
#define     ADCSRA_ADEN      7                       // ADC Enable Bit


#define     ADC             *((volatile u16 *)0x24) //ADC High_Low Registers (16-Bit)
#define     ADCL            *((volatile u8 *)0x24)  //ADC Low Register (8-Bit)
#define     ADCH            *((volatile u8 *)0x25)  //ADC High Register (8-Bit)


#define     ADC_vect    __vector_16


#endif