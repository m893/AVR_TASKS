/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   28 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         28 MAR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"



void EXTI_voidEXTIEnable(u8 Copy_u8Interrupt_Name)
{
	switch(Copy_u8Interrupt_Name)
    {
        case EX_INT0:
            SET_BIT(GICR, INT0);
            break;
        
        case EX_INT1:
            SET_BIT(GICR, INT1);
            break;
            
        case EX_INT2:
            SET_BIT(GICR, INT2);
            break;
    }
}

void EXTI_voidEXTIDisable(u8 Copy_u8Interrupt_Name)
{
    switch(Copy_u8Interrupt_Name)
    {
        case EX_INT0:
            CLEAR_BIT(GICR, INT0);
            break;
        
        case EX_INT1:
            CLEAR_BIT(GICR, INT1);
            break;
            
        case EX_INT2:
            CLEAR_BIT(GICR, INT2);
            break;
    }
}

void EXTI_voidEXTITriggerEdge(u8 Copy_u8Interrupt_Name, u8 Copy_u8Edge)
{
    switch(Copy_u8Interrupt_Name)
    {
        case EX_INT0:
            switch(Copy_u8Edge)
            {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, ISC00);
                    CLEAR_BIT(MCUCR, ISC01);
                    break;
                    
                case ANY_LOGICAL_CHANGE:
                    SET_BIT(MCUCR, ISC00);
                    CLEAR_BIT(MCUCR, ISC01);
                    break;
                    
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC00);
                    SET_BIT(MCUCR, ISC01);
                    break;
            }
            break;
        
        case EX_INT1:
            switch(Copy_u8Edge)
            {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR, ISC10);
                    CLEAR_BIT(MCUCR, ISC11);
                    break;
                    
                case ANY_LOGICAL_CHANGE:
                    SET_BIT(MCUCR, ISC10);
                    CLEAR_BIT(MCUCR, ISC11);
                    break;
                    
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC10);
                    SET_BIT(MCUCR, ISC11);
                    break;
            }
            break;
            
        case EX_INT2:
            switch(Copy_u8Edge)
            {
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR, ISC2);
                    break;
                    
                case RISING_EDGE:
                    SET_BIT(MCUCR, ISC2);
                    break;
            }
            break;
    }
}

void EXTI_voidSetCallBack(u8 Copy_u8Interrupt_Name, void (*EXT_INT_voidpFunction)(void))
{
    switch(Copy_u8Interrupt_Name)
    {
        case EX_INT0:
            INT0_fptr = EXT_INT_voidpFunction;
            break;
        case EX_INT1:
            INT1_fptr = EXT_INT_voidpFunction;
            break;
        case EX_INT2:
            INT2_fptr = EXT_INT_voidpFunction;
            break;
    }
}



ISR(INT0_vect)
{
    INT0_fptr();
}

ISR(INT1_vect)
{
    INT1_fptr();
}

ISR(INT2_vect)
{
    INT2_fptr();
}
