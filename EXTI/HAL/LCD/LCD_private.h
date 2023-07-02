/*
 *Author: Mohammed Akram 
 *  Creation Data : 26 , March 2023
 *   Version: V1.0
 * Compiler :   GNU GCc   
 */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_



#define  LCD_ALL_OUTOUT    0xff


#define FUNCTION_SET_CMD           0x38  //0b00111000
#define DISPLAY_ON_OFF_CMD         0X0c
#define DISPLAY_CLEAR_CMD          0X01


#define EIGHT_BIT_MODE      1
#define FOUR_BIT_MODE       0

static void LCD_VoidSendCommand(u8 Copy_Command) ;


#endif
