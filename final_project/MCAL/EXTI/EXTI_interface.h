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

#ifndef MCAL_EXTI_INTERFACE_H_
#define MCAL_EXTI_INTERFACE_H_



#define EX_INT0             0    
#define EX_INT1             1
#define EX_INT2             2

#define LOW_LEVEL           0
#define ANY_LOGICAL_CHANGE  1
#define FALLING_EDGE        2
#define RISING_EDGE         3


/*interrupt functions*/
# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)




void EXTI_voidEXTIEnable(u8 Copy_u8Interrupt_Name);
void EXTI_voidEXTIDisable(u8 Copy_u8Interrupt_Name);
void EXTI_voidEXTITriggerEdge(u8 Copy_u8Interrupt_Name, u8 Copy_u8Edge);
void EXTI_voidSetCallBack(u8 Copy_u8Interrupt_Name, void (*EXT_INT_voidpFunction)(void));


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
