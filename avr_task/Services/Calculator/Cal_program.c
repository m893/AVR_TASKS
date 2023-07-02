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
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "util/delay.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "Cal_interface.h"
#include "Cal_private.h"
#include "Cal_config.h"



void Convert_ArrayToIntger(u8 * Copy_pu8Array, u8 Copy_u8ArraySize, s32 * Copy_ps32Number)
{
	s8 Local_s8LoopCounter = Copy_u8ArraySize - 1;
	u8 Local_u8Power = 0;
	*Copy_ps32Number = 0;

	while(Local_s8LoopCounter>=0)
	{
		*Copy_ps32Number += (Copy_pu8Array[Local_s8LoopCounter] - '0') * MyPower(10, Local_u8Power);
		Local_u8Power++;
		Local_s8LoopCounter--;
	}

}



s32 Calculator_s32Calculate(s32 Copy_s32Operand1, s32 Copy_s32Operand2, u8 Copy_u8Operator)
{
	s32 Local_s32Result = 0;

	switch (Copy_u8Operator)
	{
		case '+':
			Local_s32Result = Copy_s32Operand1 + Copy_s32Operand2;
			break;
		case '-':
			Local_s32Result = Copy_s32Operand1 - Copy_s32Operand2;
			break;
		case '*':
			Local_s32Result = Copy_s32Operand1 * Copy_s32Operand2;
			break;
		case '/':
			Local_s32Result = Copy_s32Operand1 / Copy_s32Operand2;
			break;
		default:
			break;
	}

	return Local_s32Result;
}



static u32 MyPower(u8 Copy_u8Base, u8 Copy_u8Power)
{
	u32 Local_u32Result = 1;
	u8 Local_u8LoopCounter = 0;

	if(Copy_u8Power == 0)
	{
		Local_u32Result = 1;
	}
	else
	{
		for(Local_u8LoopCounter=0; Local_u8LoopCounter<Copy_u8Power; Local_u8LoopCounter++)
		{
			Local_u32Result *= Copy_u8Base;
		}
	}

	return Local_u32Result;
}
