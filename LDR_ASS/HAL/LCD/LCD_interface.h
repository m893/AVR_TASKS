/***********
 * Author :   Mohammed Akram 
 * Date  :   26 March,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              26 Marc, 2023               Mohammed Akram
***************************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define PIN0    0       
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define LOW     0
#define HIGH    1

#define OUTPUT  1
#define INPUT   0

#define PULLUP          0
#define NO_PULLUP       1
void LCD_VoidGoToXY(u8 Copy_U8Xpostion  , u8 Copy_U8Ypostion) ;
void LCD_VoidSendData(u8 Copy_Data);
void LCD_voidInit(void);
void LCD_voidClearLcd(void);
void LCD_VoidSendString ( u8 * Copy_pu8StringArray);
void LCD_VoidSendNumber(u32  Copy_U8number);
void LCD_VoidSendCustomCharacter ( u8 * Copy_pU8CharacterArray ,u8 Copy_U8PatternNumber , u8 Copy_U8Xpostion, u8 Copy_U8Ypostion  );



#endif
