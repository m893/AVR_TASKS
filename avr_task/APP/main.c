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

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"

#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/Timer/Timer_interface.h"


void CalculateTime(void);
volatile u16 POV_u16LastRotTime;
volatile u8 seconds = 30  ;
volatile u8 minutes = 58 ;
volatile u8 hours = 11  ;
s32 main(void)
{
		sei();
    	LCD_voidInit();
    	Timer0_voidInit(TIMER0_CTC_MODE,SCALER_64,OC0_DISCONECTED);
    	Timer0_voidSetCompareMatchValue(200);
    	Timer0_void_OCR_InterruptEnable();
    	Timer0_voidOCRSetCallBack(&CalculateTime);

    while (1)
    {		LCD_voidGoToXY(0,0);
    		LCD_voidSendString("s: ");
			LCD_voidGoToXY(0,4);
    		LCD_voidSendNumber(seconds);
    		//LCD_voidClearDisplay();
    		LCD_voidGoToXY(0,8);
    		LCD_voidSendString("m: ");
    		LCD_voidGoToXY(0,13);
    		LCD_voidSendNumber(minutes);
    		//LCD_voidClearDisplay();
    		LCD_voidGoToXY(1,0);
    		LCD_voidSendString("h: ");
    		LCD_voidGoToXY(1,3);
    		LCD_voidSendNumber(hours);
    		//LCD_voidClearDisplay();


    }
    
    return 0;
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
	if(POV_u8Minutes == 12 ||POV_u8Minutes == 24 ||POV_u8Minutes == 36 ||POV_u8Minutes == 48 )
	{
		POV_u8Hours ++ ;
	
	}else if (POV_u8Minutes == 60)
	{
		POV_u8Minutes =0 ;
		POV_u8Hours ++ ;
	}
	else
	{}
	if(POV_u8Hours == 60 )
	{
		POV_u8Hours = 0 ;
	}
	else {

	}

}
