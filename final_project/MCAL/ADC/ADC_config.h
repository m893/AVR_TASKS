/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   6 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         6 APR, 2023    Hossam M. Elzhar         Initial Creation
*********************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/*Options:
        ENABLE
        DISBALE
*/
#define     ADC_ENABLE                  ENABLE

/*Option
        ADC_SCALER_2
        ADC_SCALER_4
        ADC_SCALER_8
        ADC_SCALER_16
        ADC_SCALER_32
        ADC_SCALER_64
        ADC_SCALER_128
*/
#define     ADC_SCALER_SELECTION        ADC_SCALER_64

/*Options: 
        LEFT_ADJUST
        RIGHT_ADJUST
        FULL_ADC_REG
*/
#define     ADC_RESULT           FULL_ADC_REG

/*
    Options:
        AREF
        AVCC
        INTERNAL_2v56
*/
#define     ADC_REFERENCE_SELECTION     AVCC

/*Options:
        ENABLE
        DISBALE
*/
#define     ADC_INTERRUPT_STATUS        DISBALE




#endif