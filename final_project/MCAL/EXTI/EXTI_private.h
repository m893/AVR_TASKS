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
#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_



/*External Interrupt */
#define MCUCSR  (*(volatile unsigned char*)0x54)
#define ISC2    6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

#define GICR    (*(volatile unsigned char*)0x5B)
#define INT1    7
#define INT0    6
#define INT2    5

#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1   7
#define INTF0   6
#define INTF2   5



/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3



static void (*INT0_fptr)(void);
static void (*INT1_fptr)(void);
static void (*INT2_fptr)(void);


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
