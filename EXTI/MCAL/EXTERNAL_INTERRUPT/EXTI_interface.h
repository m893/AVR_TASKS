#ifndef  EXTI_interface_h
#define  EXTI_interface_h

#define LOW_LEVEL                0
#define ANY_LOGICAL_CHANGE       1
#define FALLING_EDGE             2
#define RISING_EDGE              3



#define EXTI_INT0        0
#define EXTI_INT1        1
#define EXTI_INT2        2



void EXTI_VoidEnable(u8 Copy_U8Intnum);
void EXTI_VoidDisable(u8 Copy_U8Intnum);
void EXTI_VoidTriggerEdge(u8 Copy_U8Intnum , u8 Copy_U8Edge);


#endif
