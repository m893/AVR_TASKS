/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   4 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         4 APR, 2023      Hossam M. Elzhar          Initial Creation
*********************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "../../MCAL/Timer/Timer_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

#include "POV_interface.h"
#include "POV_private.h"
#include "POV_config.h"

void CalculateTime(void);
volatile u16 POV_u16LastRotTime;

//Hours Var is not the real Hours, its Incrementd every 12 minutes, not every 60 minutes.
volatile u8 POV_u8Hours;
volatile u8 POV_u8Minutes;
volatile u8 POV_u8Seconds;

volatile u8 POV_u8Position;

//Every Team Member should write his initailizations in This Function

void POV_voidInit(void)
{
	Timer0_voidInit(TIMER0_CTC_MODE,SCALER_64,OC0_DISCONECTED);
	Timer0_voidSetCompareMatchValue(200);
	Timer0_void_OCR_InterruptEnable();
	Timer0_voidOCRSetCallBack(&CalculateTime);
}

void POV_voidStartDisplay(void)
{

}
void CalculateTime(void)
{
	static counter ;
	counter ++ ;
	if(counter == 625)
	{
		POV_u8Seconds ++;
		counter=0;
	}
	else
	{}
	if(POV_u8Seconds == 60)
	{
		POV_u8Minutes ++ ;
		POV_u8Seconds = 0 ;
	}
	else{}
	if(POV_u8Minutes == 60)
	{
		POV_u8Hours ++ ;
		POV_u8Minutes = 0 ;
	}
	else
	{}
	if(POV_u8Hours == 12 )
	{
		POV_u8Hours = 0 ;
	}
	else {

	}

}
