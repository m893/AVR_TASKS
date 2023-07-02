/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   17 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         17 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#ifndef MCAL_UART_INTERFACE_H_
#define MCAL_UART_INTERFACE_H_

void SPI_voidSlaveInit(void);
void SPI_voidMasterInit(void);
void SPI_voidTrancieveData(u8 Copy_u8TransData, u8 *pu8RecievedData);
void SPI_voidRecieveData(u8 *pu8RecievedData);

#endif
