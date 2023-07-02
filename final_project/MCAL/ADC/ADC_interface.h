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
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_INTERRUPT_ENABLE      1
#define ADC_INTERRUPT_DISABLE     0
#define ADC_RESULT_NOT_READY     -1


#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7

void ADC_voidInit(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);
u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber);
u16 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNumber);
u16 ADC_u16StartConversionAsynchronous(u8 Copy_u8ChannelNumber);

#endif