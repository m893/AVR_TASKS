/***********
 * Author :   Mohammed Akram
 * Date  :   19 April,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              19 April, 2023               Mohammed Akram
***************************************************************************/
#ifndef  TWI_INTERFACE_H
#define  TWI_INTERFACE_H


typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartConditionError,
	SlaveAddressWithWriteRequestError,
	SlaveAddressWithReadRequestError,
	SendDataPacketError,
	MasterReadDataPacketError,
	
}ERR_t;

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
ERR_t TWI_ERRSendStartCondition(void);
ERR_t TWI_ERRSendRepeatedStartCondition(void);
ERR_t TWI_ERRSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
ERR_t TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
ERR_t TWI_ERRSendDataPacket(u8 Copy_u8DataPacket);
ERR_t TWI_ERRReceiveDataPacket(u8 *Copy_pu8DataPacket);
void TWI_voidSendStopCondition(void);

#endif
