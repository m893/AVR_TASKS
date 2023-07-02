#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

void EXTI_VoidEnable(u8 Copy_U8Intnum)
{
    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0  :
            SET_BIT(GICR,INT0);
        break;
        case  EXTI_INT1:
            SET_BIT(GICR,INT1);
        break;
        case  EXTI_INT2 :
            SET_BIT(GICR,INT2);
        break;
    
    default:
        break;
    }
}
void EXTI_VoidDisable(u8 Copy_U8Intnum)
{
    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0:
            CLEAR_BIT(GICR,INT0);
        break;
        case  EXTI_INT1:
            CLEAR_BIT(GICR,INT1);
        break;
        case  EXTI_INT2:
            CLEAR_BIT(GICR,INT2);
        break;
    
    default:
        break;
    }

}
void EXTI_VoidTriggerEdge(u8 Copy_U8Intnum , u8 Copy_U8Edge)
{

    switch (Copy_U8Intnum)
    {
    case  EXTI_INT0:
                switch (Copy_U8Edge)
                {
                     case  LOW_LEVEL:
                        CLEAR_BIT(MCUCR,ISC00);
                        CLEAR_BIT(MCUCR,ISC01);
                         break;
                    case  ANY_LOGICAL_CHANGE :
                        SET_BIT(MCUCR,ISC00);
                        CLEAR_BIT(MCUCR,ISC01);
                         break;
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCR,ISC00);
                        SET_BIT(MCUCR,ISC01);
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCR,ISC00);
                        SET_BIT(MCUCR,ISC01);
                         break;
                
                     default:
                         break;
                }
        break;
        case  EXTI_INT1:
                switch (Copy_U8Edge)
                {
                     case  LOW_LEVEL:
                        CLEAR_BIT(MCUCR,ISC10);
                        CLEAR_BIT(MCUCR,ISC11);
                         break;
                    case  ANY_LOGICAL_CHANGE :
                        SET_BIT(MCUCR,ISC10);
                        CLEAR_BIT(MCUCR,ISC11);
                         break;
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCR,ISC10);
                        SET_BIT(MCUCR,ISC11);
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCR,ISC10);
                        SET_BIT(MCUCR,ISC11);
                         break;
                
                     default:
                         break;
                }
        break;
        case  EXTI_INT2:
                switch (Copy_U8Edge)
                {
            
                     case  FALLING_EDGE :
                        CLEAR_BIT(MCUCSR,ISC2);
                        
                         break;
                    case  RISING_EDGE :
                        SET_BIT(MCUCSR,ISC2);
                         break;
                
                     default:
                         break;
                }
            break;
    
        default:
        break;
    }
}
