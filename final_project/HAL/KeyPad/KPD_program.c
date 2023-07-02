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

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"



void KPD_voidInit(void)
{
	//Set Rows Pins as Input pull up
	DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW0_PIN, IN_PULL_UP);
	DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW1_PIN, IN_PULL_UP);
	DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW2_PIN, IN_PULL_UP);
	DIO_voidSetPinDirection(KPD_ROWS_PORT, KPD_ROW3_PIN, IN_PULL_UP);

	//Set Colomns Pins as Output High
	DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, OUTPUT);
	DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, OUTPUT);
	DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, OUTPUT);
	DIO_voidSetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, OUTPUT);
}

u8 KPD_u8GetPressedKey(void)
{
	static u8 KPD_u8CharsArray[KPD_ROWS_NUM][KPD_COLUMNS_NUM] = KPD_KEYS_ARRAY;
	static u8 KPD_u8RowsArray[KPD_ROWS_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	static u8 KPD_u8ColumnsArray[KPD_COLUMNS_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	

	u8 Local_u8RowsCounter;
	u8 Local_u8ColmsCounter;
	u8 Local_u8RowValue;
	u8 Local_u8PressedKey = KPD_NO_KEY_PRESSED;

	for(Local_u8ColmsCounter=0; Local_u8ColmsCounter<KPD_COLUMNS_NUM; Local_u8ColmsCounter++)
	{
		DIO_voidWritePin(KPD_COLUMNS_PORT, KPD_u8ColumnsArray[Local_u8ColmsCounter], LOW);

		for(Local_u8RowsCounter=0; Local_u8RowsCounter<KPD_ROWS_NUM; Local_u8RowsCounter++)
		{
			Local_u8RowValue = DIO_voidReadPin(KPD_ROWS_PORT, KPD_u8RowsArray[Local_u8RowsCounter]);

			if(Local_u8RowValue == LOW)
			{
				Local_u8PressedKey = KPD_u8CharsArray[Local_u8RowsCounter][Local_u8ColmsCounter];

				while(Local_u8RowValue == LOW)
				{
					Local_u8RowValue = DIO_voidReadPin(KPD_ROWS_PORT, KPD_u8RowsArray[Local_u8RowsCounter]);
				}
				
				return Local_u8PressedKey;
			}
		}

		DIO_voidWritePin(KPD_COLUMNS_PORT, KPD_u8ColumnsArray[Local_u8ColmsCounter], HIGH);
	}

	return Local_u8PressedKey;
}



