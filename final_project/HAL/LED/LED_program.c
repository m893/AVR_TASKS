/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   29 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         29 MAR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

/*******************************Includes Section *****************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"
/*****************************************************************************************/



/************************************ Implementation Section ******************************/

/************************************************************************
 * description : LED Initialize Its Pin As OUTPUT
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void LED_voidInit(const LED_t* Copy_pLed)
{
	if(Copy_pLed)
	{
		DIO_voidSetPinDirection(Copy_pLed->port, Copy_pLed->pin, OUTPUT);
	}
	else{}
}


/************************************************************************
 * description : Write The Required Volt On LED's Pin To Turn ON
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void LED_voidON(const LED_t* Copy_pLed)
{
	if(Copy_pLed)
		{
			DIO_voidWritePin(Copy_pLed->port, Copy_pLed->pin, Copy_pLed->ON_VOLT_LEVEL);
		}
		else{}
}


/************************************************************************
 * description : Write The Required Volt On LED's Pin To Turn OFF
 * INPUT Args  : Reference To The LED Structure 
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void LED_voidOFF(const LED_t* Copy_pLed)
{
	if(Copy_pLed)
	{
		DIO_voidWritePin(Copy_pLed->port, Copy_pLed->pin, !(Copy_pLed->ON_VOLT_LEVEL));
	}
	else{}
}
