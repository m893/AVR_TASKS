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

#ifndef MCAL_GIE_INTERFACE_H_
#define MCAL_GIE_INTERFACE_H_


/*interrupt functions*/
# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* MCAL_GIE_INTERFACE_H_ */
