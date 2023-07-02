#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_voidInit(void);
void LCD_voidSendChar(u8 Copy_u8Data);
void LCD_voidClearDisplay(void);
void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void LCD_voidSendString(u8 * Copy_pu8StringArray);
void LCD_voidSendNumber(s32 Copy_s8Number);
void LCD_voidSendCustomCharachter(u8 * Copy_pu8CharArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);
void LCD_voidCursorOn(void);
void LCD_voidCursorBlink(void);
void LCD_voidCursorOff(void);
void LCD_voidDisplayOn(void);
void LCD_voidDisplayOff(void);

#endif
