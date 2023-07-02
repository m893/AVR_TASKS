#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define FOUR_BIT_MODE_SAME_PORT             0
#define FOUR_BIT_MODE_SEPARATE_PORT_PINS    1
#define EIGHT_BIT_MODE                      2

#define NIBBLE_SHIFT                        0X04

#define BIT0                                0
#define BIT1                                1
#define BIT2                                2
#define BIT3                                3
#define BIT4                                4
#define BIT5                                5
#define BIT6                                6
#define BIT7                                7
                                                 //0b001L NF--
#define CMD_SET_8BIT_2LINE_7DOTS            0x38 //0b0011 1000
#define CMD_SET_8BIT_1LINE_10DOTS           0x34 //0b0011 0100
#define CMD_SET_4BIT_MODE                   0x02
#define CMD_SET_4BIT_2LINE_7DOTS            0x28 //0b0010 1000
#define CMD_SET_4BIT_1LINE_10DOTS           0x24 //0b0010 0100
#define CMD_ON_OFF_DISPLAY_OFF              0x08
#define CMD_ON_OFF_DISPLAY_ON               0x0C
#define CMD_ON_OFF_CURSOR_ON                0x0E
#define CMD_ON_OFF_CURSOR_OFF               0x0C
#define CMD_ON_OFF_CURSOR_BLINK             0x0F
#define CMD_CLEAR_DISPLAY                   0x01
#define ROW1_OFFSET 		                0x40
#define ROW1_CMD 			                0x80


#define POSITIVE                            0
#define NEGATIVE                            1

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif
