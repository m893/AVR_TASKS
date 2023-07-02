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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../GIE/GIE_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


volatile u16 ADC_u16_DigitalValue;
volatile u8 Local_u8ReadFlag;


void ADC_voidInit(void)
{
    /*Check For The ADC Enable*/
    #if ADC_ENABLE  == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADEN);
    #elif ADC_ENABLE == DISABLE
        CLEAR_BIT(ADCSRA, ADCSRA_ADEN);
    #else
        #error "Error, ADC_ENABLE Configuration Error"
    #endif

    /*Check For The ADC Interrupt*/ 
    #if ADC_INTERRUPT_STATUS == ENABLE
        SET_BIT(ADCSRA, ADCSRA_ADIE);
    #elif ADC_INTERRUPT_STATUS == DISABLE
        CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
    #else
        #error("Error, ADC_INTERRUPT_ENABLE Configuration Error")
    #endif

    /*Check for the Reference Voltage Option*/
    // #if ADC_REFERENCE_SELECTION == AREF
    //     CLEAR_BIT(ADMUX, ADMUX_REFS0);
    //     CLEAR_BIT(ADMUX, ADMUX_REFS1);
    // #elif   ADC_REFERENCE_SELECTION == AVCC
    //     SET_BIT(ADMUX, ADMUX_REFS0);
    //     CLEAR_BIT(ADMUX, ADMUX_REFS1);       
    // #elif   ADC_REFERENCE_SELECTION == INTERNAL_2v56
    //     SET_BIT(ADMUX, ADMUX_REFS0);
    //     SET_BIT(ADMUX, ADMUX_REFS1);
    // #else
    //     #error ("Error, ADC_REFERENCE_SELECTION Configuration Error")
    // #endif


    /*Set the reference selection options using BitMasking*/
    ADMUX &= REF_CLR_MASK;
    ADMUX |= ADC_REFERENCE_SELECTION;

    /*Check For The ADC Adjust Result*/
    #if ADC_RESULT == RIGHT_ADJUST
        CLEAR_BIT(ADMUX, ADMUX_ADLAR);
    #elif ADC_RESULT == LEFT_ADJUST
        SET_BIT(ADMUX, ADMUX_ADLAR);
    #elif ADC_RESULT == FULL_ADC_REG
        /*Do Nothing*/
    #else
        #error("Error, ADC_RESULT Confiuration Error")
    #endif


    /* Check For The Prescaler Values*/
    ADCSRA &= ADC_CLR_SCALER_MASK;
    ADCSRA |= ADC_SCALER_SELECTION;

}


void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus)
{
    switch(Copy_u8InterruptStatus)
    {
        case DISABLE:
            CLEAR_BIT(ADCSRA, ADCSRA_ADIE);
        break;

        case ENABLE:
            SET_BIT(ADCSRA, ADCSRA_ADIE);
        break;

        default:
            /*Do Noting*/
        break;
    }
}

u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber) //Polling
{
    u8 Local_u8DigitalValue;

    ADMUX &= CHANNEL_CLR_MASK;
    ADMUX |= Copy_u8ChannelNumber;

    SET_BIT(ADCSRA, ADCSRA_ADSC);

    while( (GET_BIT(ADCSRA, ADCSRA_ADIF)) == DISABLE );

    CLEAR_BIT(ADCSRA, ADCSRA_ADSC);
    CLEAR_BIT(ADCSRA, ADCSRA_ADIF);

#if ADC_RESULT == RIGHT_ADJUST
    Local_u8DigitalValue = (u8)ADC;
#elif ADC_RESULT == LEFT_ADJUST
    Local_u8DigitalValue = ADCH;
#elif ADC_RESULT == FULL_ADC_REG
    Local_u8DigitalValue = (u8)ADC;
#else
    #error("Error, ADC_RESULT Confiuration Error")
#endif

    return Local_u8DigitalValue;
}

u16 ADC_u16StartConversionSynchronous(u8 Copy_u8ChannelNumber) //Polling
{
    
    ADMUX &= CHANNEL_CLR_MASK;
    ADMUX |= Copy_u8ChannelNumber;

    SET_BIT(ADCSRA, ADCSRA_ADSC);

    while( (GET_BIT(ADCSRA, ADCSRA_ADIF)) == DISABLE );

    CLEAR_BIT(ADCSRA, ADCSRA_ADSC);
    CLEAR_BIT(ADCSRA, ADCSRA_ADIF);


    return ADC;
}

u8 ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber) //Based On Interrupt
{
    u8 Local_u8DigitalValue = ADC_RESULT_NOT_READY;

    if(Local_u8ReadFlag == 0)   
    {
        /*Set ADC Channel*/
        ADMUX &= CHANNEL_CLR_MASK;
        ADMUX |= Copy_u8ChannelNumber;

        /*ADC Start Conversion*/
        SET_BIT(ADCSRA, ADCSRA_ADSC);
        Local_u8ReadFlag = 1;
    } 
    else if(Local_u8ReadFlag == 2)
    {
        #if ADC_RESULT == RIGHT_ADJUST

            Local_u8DigitalValue = (u8)ADC_u16_DigitalValue;

        #elif ADC_RESULT == LEFT_ADJUST

            Local_u8DigitalValue = (u8)(ADC_u16_DigitalValue);

        #elif ADC_RESULT == FULL_ADC_REG

            Local_u8DigitalValue = (u8)ADC_u16_DigitalValue;

        #endif
        
        Local_u8ReadFlag = 0;
    }
    
    return Local_u8DigitalValue;
}

u16 ADC_u16StartConversionAsynchronous(u8 Copy_u8ChannelNumber) //Based On Interrupt
{
    u16 Local_u16DigitalValue = ADC_RESULT_NOT_READY;

    if(Local_u8ReadFlag == 0)   
    {
        /*Set ADC Channel*/
        ADMUX &= CHANNEL_CLR_MASK;
        ADMUX |= Copy_u8ChannelNumber;

        /*ADC Start Conversion*/
        SET_BIT(ADCSRA, ADCSRA_ADSC);
        Local_u8ReadFlag = 1;
    } 
    else if(Local_u8ReadFlag == 2)
    {
        Local_u16DigitalValue = ADC_u16_DigitalValue;
        Local_u8ReadFlag = 0;
    }
    
    return Local_u16DigitalValue;
}


ISR(ADC_vect)
{

    Local_u8ReadFlag = 2;

#if ADC_RESULT == RIGHT_ADJUST

    ADC_u16_DigitalValue = ADC;

#elif ADC_RESULT == LEFT_ADJUST

    ADC_u16_DigitalValue = (u16)ADCH;

#elif ADC_RESULT == FULL_ADC_REG

    ADC_u16_DigitalValue = ADC;

#endif
    
}