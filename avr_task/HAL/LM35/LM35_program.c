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
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"


void LM35_voidInit(LM35_t * LM35)
{
    static u8 Local_u8InitFlag = 0;
    
    DIO_voidSetPinDirection(LM35->Port, LM35->Pin, INPUT);

    if(Local_u8InitFlag == 0)
    {
        ADC_voidInit();
        Local_u8InitFlag = 1;
    }
    else{}

}

u8  LM35_u8GetTemp(LM35_t * LM35)
{
    u16 Local_u16DigitalValue;
    f32 Local_f32MilliVolt;
    f32 Local_f32AcurateDegree;
    u8 Local_u8Degree;

    Local_u16DigitalValue = ADC_u16StartConversionSynchronous(LM35->Pin);
    Local_f32MilliVolt = ((f32)Local_u16DigitalValue * MAX_MILLI_VOLT) / (f32)RESOLUTION;

    Local_f32AcurateDegree = Local_f32MilliVolt / MILLI_VOLT_DEGREE;

    if((Local_f32AcurateDegree - (s32)Local_f32AcurateDegree) >= 0.5)
    {
    	Local_f32AcurateDegree += 1.0;
    }

    Local_u8Degree = (u8)Local_f32AcurateDegree;

    return Local_u8Degree;

}
