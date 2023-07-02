/*
 *Author: Mohammed Akram 
 *  Creation Data : 26 , March 2023
 *   Version: V1.0
 * Compiler :   GNU GCc   
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>



#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_voidInit()
{
    #if LCD_INIT_MODE==EIGHT_BIT_MODE
    /* Initialize  Data Port*/
     DIO_VoidSetPortSpecificDirection(LCD_DATA_PORT,OUTPUT);

     // set RS and R/W and ENABLE as output
     DIO_voidSetPinDirection(LCD_CRTL_PORT,LCD_RS_PIN,OUTPUT);
     DIO_voidSetPinDirection(LCD_CRTL_PORT,LCD_RW_PIN,OUTPUT);
     DIO_voidSetPinDirection(LCD_CRTL_PORT,LCD_EN_PIN,OUTPUT);

     //wait for 30 ms
     _delay_ms(50);
     
     LCD_VoidSendCommand(FUNCTION_SET_CMD);
     LCD_VoidSendCommand(DISPLAY_ON_OFF_CMD);
     LCD_VoidSendCommand(DISPLAY_CLEAR_CMD);






    #elif  LCD_INIT_MODE==FOUR_BIT_MODE

    #else

        error("LCD CONFIGRATION ERROR ")

    #endif
}

 static void LCD_VoidSendCommand(u8 Copy_Command)
{
    //clear the RS pin To sent Command 
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_RS_PIN,LOW);
    //clear the R/W pin to write 
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_RW_PIN,LOW);
    //set the command to data the data port
    DIO_VoidSetSpacificvalue(LCD_DATA_PORT,Copy_Command);
    /* send enable pulse*/
    //low 
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,LOW);
    //high
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,HIGH);
    _delay_ms(2);
    //low
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,LOW);




}
void LCD_VoidSendData(u8 Copy_Data)
{
    //clear the RS pin To sent data
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_RS_PIN,HIGH);
    //clear the R/W pin to write 
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_RW_PIN,LOW);
    //set the command to data the data port
    DIO_VoidSetSpacificvalue(LCD_DATA_PORT,Copy_Data);
    /* send enable pulse*/
    //low 
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,LOW);
    //high
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,HIGH);
    _delay_ms(2);
    //low
    DIO_VoidSetPinValue(LCD_CRTL_PORT,LCD_EN_PIN,LOW);


}

void LCD_voidClearLcd(void)
{
    LCD_VoidSendCommand(DISPLAY_CLEAR_CMD);
}

void LCD_VoidGoToXY(u8 Copy_U8Xpostion  , u8 Copy_U8Ypostion)
{
    u8 Local_U8CharacterAdress = 0;
    //calculate the address 

    if(Copy_U8Xpostion==0)
    {
            //if x=0 so adrees = y 
            Local_U8CharacterAdress =Copy_U8Ypostion ;

    }
    else if (Copy_U8Xpostion==1)
    {
        //if x =1 so adress = y+40
        Local_U8CharacterAdress=Copy_U8Ypostion + 0x40 ;

    }
    else 
    {
        //raise error 
    }
    // set bit8 to to 1 because address command has 1 in bit8

    SET_BIT(Local_U8CharacterAdress,7);
    LCD_VoidSendCommand(Local_U8CharacterAdress);

}
void LCD_VoidSendString ( u8 * Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter =0 ;
    while (Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        LCD_VoidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter ++;
    }

}
void LCD_VoidSendNumber(u32  Copy_U8number)
{
    u8 local_u8ArrayyNumber[10];
    u8 local_u8LoopCounter =0 ;
    while(Copy_U8number != 0)
    {
        local_u8ArrayyNumber[local_u8LoopCounter]=Copy_U8number % 10;
        Copy_U8number /= 10 ;
        local_u8LoopCounter ++ ;
    }
    local_u8LoopCounter -- ; // while increament and check condition
    while(local_u8LoopCounter != 255) // beacuse loopcounter is unsigned so when we delver to - value == 255
    {
        //we want to send Asci code so add '0' 48 plus the number  if number is 5 so ascii code of 5 = 5+48('0') =53 
        LCD_VoidSendData(local_u8ArrayyNumber[local_u8LoopCounter]+ '0');
        local_u8LoopCounter -- ;
    }
}
void LCD_VoidSendCustomCharacter( u8 * Copy_pU8CharacterArray ,u8 Copy_U8PatternNumber , u8 Copy_U8Xpostion ,  u8 Copy_U8Ypostion  )
{
    u8 Local_u8LoopCounter ;
    u8 Local_u8CGRAMAdress = 0;
    //calcute the adress of CGRAM = pattern number *8  
    Local_u8CGRAMAdress = Copy_U8PatternNumber * 8 ;
    //set bit 6 to 1 according to command in datasheet 
    SET_BIT(Local_u8CGRAMAdress , 6);
    //send the command that tell i call the CGRAM 
    LCD_VoidSendCommand(Local_u8CGRAMAdress);
    for(Local_u8LoopCounter =0 ; Local_u8LoopCounter < 8 ; Local_u8LoopCounter ++)
    {
        LCD_VoidSendData(Copy_pU8CharacterArray[Local_u8LoopCounter]);
    }
    // postion of start display and  sent data to DDRAM to display in lcd 
    LCD_VoidGoToXY(Copy_U8Xpostion , Copy_U8Ypostion);
    LCD_VoidSendData(Copy_U8PatternNumber);
    
}
