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

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void UART_voidInit(void)
{
    u8 Local_u8UCSRC = 0;

    CLEAR_BIT(Local_u8UCSRC, UCSRC_UMSEL);

    SET_BIT(UCSRB, UCSRB_RXEN);
    SET_BIT(UCSRB, UCSRB_TXEN);

    SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
    CLEAR_BIT(UCSRB, UCSRB_UCSZ2);

    CLEAR_BIT(Local_u8UCSRC, UCSRC_UPM0);
    CLEAR_BIT(Local_u8UCSRC, UCSRC_UPM1);

    CLEAR_BIT(Local_u8UCSRC, UCSRC_USBS);

    SET_BIT(Local_u8UCSRC, UCSRC_URSEL);

    UCSRC = Local_u8UCSRC;

    CLEAR_BIT(UBRRH, UBRRH_URSEL);
    UBRRH = 0;
    UBRRL = 51;
}

void UART_voidTransmitData(u8 Copy_u8Data)
{
    while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);

    UDR = Copy_u8Data;

    while(GET_BIT(UCSRA, UCSRA_TXC) == 0);
    SET_BIT(UCSRA, UCSRA_TXC);
}

void UART_voidRecieveData(u8 *pu8RecievedData)
{
    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);

    if(pu8RecievedData)
    {
        *pu8RecievedData = UDR;
    }
}
