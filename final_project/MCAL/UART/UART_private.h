/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   16 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         16 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/
#ifndef MCAL_UART_PRIVATE_H_
#define MCAL_UART_PRIVATE_H_


/* USART I/O Data Register */
#define UDR       (*(volatile unsigned char*)0x2C)

/* USART Control and Status Register A */
#define UCSRA    (*(volatile unsigned char*)0x2B)
#define    UCSRA_RXC          7
#define    UCSRA_TXC          6
#define    UCSRA_UDRE         5
#define    UCSRA_FE           4
#define    UCSRA_DOR          3
#define    UCSRA_UPE          2
#define    UCSRA_U2X          1
#define    UCSRA_MPCM         0

/* USART Control and Status Register B */
#define UCSRB   (*(volatile unsigned char*)0x2A)
#define    UCSRB_RXCIE        7
#define    UCSRB_TXCIE        6
#define    UCSRB_UDRIE        5
#define    UCSRB_RXEN         4
#define    UCSRB_TXEN         3
#define    UCSRB_UCSZ         2
#define    UCSRB_UCSZ2        2
#define    UCSRB_RXB8         1
#define    UCSRB_TXB8         0

/* USART Control and Status Register C */
#define     UCSRC     (*(volatile unsigned char*)0x40)
#define     UCSRC_URSEL        7
#define     UCSRC_UMSEL        6
#define     UCSRC_UPM1         5
#define     UCSRC_UPM0         4
#define     UCSRC_USBS         3
#define     UCSRC_UCSZ1        2
#define     UCSRC_UCSZ0        1
#define     UCSRC_UCPOL        0

/* USART Baud Rate Register High */
#define     UBRRH    (*(volatile unsigned char*)0x40)
#define     UBRRH_URSEL        7

/* USART Baud Rate Register Low */
#define UBRRL    (*(volatile unsigned char*)0x29)

#endif 
