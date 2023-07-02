/***********
 * Author :   Mohammed Akram 
 * Date  :   29 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              29 Marc, 2023               Mohammed Akram
***************************************************************************/
#ifndef  GIE_INTERFACE_H
#define  GIE_INTERFACE_H


# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

void GIE_VoidEnabledGlobalInterrupt(void);
void GIE_VoidDisabledGlobalInterrupt(void);




#endif
