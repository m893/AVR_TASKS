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

#ifndef MCAL_UART_INTERFACE_H_
#define MCAL_UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidTransmitData(u8 Copy_u8Data);
void UART_voidRecieveData(u8 *pu8RecievedData);

#endif
