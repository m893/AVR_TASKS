#include <util/delay.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



#if(LCD_MODE == EIGHT_BIT_MODE)
void LCD_voidInit(void)
{
    //Initialize Data Port
    DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
    //Initialize Control Pins
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, OUTPUT);
#if RW != NC
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, OUTPUT);
#endif
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, OUTPUT);

    //wait for more than 30ms
    _delay_ms(50);

    //Send Function Set Command
    LCD_voidSendCommand(CMD_SET_8BIT_2LINE_7DOTS);
    //wait for 1ms
    //Send Display ON/ OFF Control Command
    LCD_voidSendCommand(CMD_ON_OFF_DISPLAY_ON);

    //Send Clear Command
    LCD_voidSendCommand(CMD_CLEAR_DISPLAY);

}

void LCD_voidSendChar(u8 Copy_u8Data)
{
    //SET RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, HIGH);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, LOW);
#endif
    //Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);

}


static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //Clear RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, LOW);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, LOW);
#endif
    //Set The Command On The Data/Command Port
    DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
}


#elif (LCD_MODE == FOUR_BIT_MODE_SAME_PORT)
void LCD_voidInit(void)
{
    //initialize Data Pins
    DIO_voidSetPinDirection(LCD_DATA_PORT, D4, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D5, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D6, OUTPUT);
    DIO_voidSetPinDirection(LCD_DATA_PORT, D7, OUTPUT);
    //Initialize Control Pins
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, OUTPUT);
#if RW != NC
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, OUTPUT);
#endif
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, EN, OUTPUT);

	//wait for more than 30ms
	_delay_ms(50);

    LCD_voidSendCommand(CMD_SET_4BIT_MODE);

	LCD_voidSendCommand(CMD_SET_4BIT_2LINE_7DOTS);

	LCD_voidSendCommand(CMD_ON_OFF_DISPLAY_ON);

	LCD_voidSendCommand(CMD_CLEAR_DISPLAY);
}

void LCD_voidSendChar(u8 Copy_u8Data)
{
    //SET RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, HIGH);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, LOW);
#endif

#ifdef HIGHER_NIBBLE
    //Set The Higher Nibble Command On The Data/Command Port
    DIO_voidSetBitsInPort(LCD_DATA_PORT, Copy_u8Data, DATA_MASK);
#elif LOWER_NIBBLE
    DIO_voidSetBitsInPort(LCD_DATA_PORT, (Copy_u8Data >> LOWER_NIBBLE), DATA_MASK);
#endif
    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);

#ifdef HIGHER_NIBBLE
    //Set The Lower Nibble Command On The Data/Command Port
    DIO_voidSetBitsInPort(LCD_DATA_PORT, (Copy_u8Data << HIGHER_NIBBLE), DATA_MASK);
#elif  LOWER_NIBBLE
    DIO_voidSetBitsInPort(LCD_DATA_PORT, Copy_u8Data, DATA_MASK);
#endif
    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);

}


static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //Clear RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, LOW);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, LOW);
#endif

#ifdef HIGHER_NIBBLE
    //Set The Higher Nibble Command On The Data/Command Port
    DIO_voidSetBitsInPort(LCD_DATA_PORT, Copy_u8Command, DATA_MASK);
#elif LOWER_NIBBLE
    //Set The Higher Nibble Command On The Data/Command Port
    DIO_voidSetBitsInPort(LCD_DATA_PORT, (Copy_u8Command >> LOWER_NIBBLE), DATA_MASK);
#endif

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);

#ifdef HIGHER_NIBBLE
    //Set The Lower Nibble Command On The Data/Command Port
    DIO_voidSetBitsInPort(LCD_DATA_PORT, (Copy_u8Command << HIGHER_NIBBLE), DATA_MASK);
#elif LOWER_NIBBLE
    DIO_voidSetBitsInPort(LCD_DATA_PORT, Copy_u8Command, DATA_MASK);
#endif

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_CONTROL_PORT, EN, LOW);

}

#elif (LCD_MODE == FOUR_BIT_MODE_SEPARATE_PORT_PINS)
void LCD_voidInit(void)
{
    //initialize Data Pins
    DIO_voidSetPinDirection(LCD_D4_PORT, D4, OUTPUT);
    DIO_voidSetPinDirection(LCD_D5_PORT, D5, OUTPUT);
    DIO_voidSetPinDirection(LCD_D6_PORT, D6, OUTPUT);
    DIO_voidSetPinDirection(LCD_D7_PORT, D7, OUTPUT);
    //Initialize Control Pins
	DIO_voidSetPinDirection(LCD_RS_PORT, RS, OUTPUT);
#if RW != NC
	DIO_voidSetPinDirection(LCD_RW_PORT, RW, OUTPUT);
#endif
	DIO_voidSetPinDirection(LCD_EN_PORT, EN, OUTPUT);

	//wait for more than 30ms
	_delay_ms(50);

    LCD_voidSendCommand(CMD_SET_4BIT_MODE);

	LCD_voidSendCommand(CMD_SET_4BIT_2LINE_7DOTS);

	LCD_voidSendCommand(CMD_ON_OFF_DISPLAY_ON);

	LCD_voidSendCommand(CMD_CLEAR_DISPLAY);
}

void LCD_voidSendChar(u8 Copy_u8Data)
{
    //SET RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_RS_PORT, RS, HIGH);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_RW_PORT, RW, LOW);
#endif

    DIO_voidWritePin(LCD_D4_PORT, D4, GET_BIT(Copy_u8Data, BIT4));
    DIO_voidWritePin(LCD_D5_PORT, D5, GET_BIT(Copy_u8Data, BIT5));
    DIO_voidWritePin(LCD_D6_PORT, D6, GET_BIT(Copy_u8Data, BIT6));
    DIO_voidWritePin(LCD_D7_PORT, D7, GET_BIT(Copy_u8Data, BIT7));

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_EN_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);

    DIO_voidWritePin(LCD_D4_PORT, D4, GET_BIT(Copy_u8Data, BIT0));
    DIO_voidWritePin(LCD_D5_PORT, D5, GET_BIT(Copy_u8Data, BIT1));
    DIO_voidWritePin(LCD_D6_PORT, D6, GET_BIT(Copy_u8Data, BIT2));
    DIO_voidWritePin(LCD_D7_PORT, D7, GET_BIT(Copy_u8Data, BIT3));

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_EN_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);

}


static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //Clear RS Pin To Send Command (RS -> 0: Command, 1: Data)
    DIO_voidWritePin(LCD_RS_PORT, RS, LOW);
#if RW != NC
    //Clear RW Pin To Write The Command (RW -> 0: Write, 1: Read)
    DIO_voidWritePin(LCD_RW_PORT, RW, LOW);
#endif

    DIO_voidWritePin(LCD_D4_PORT, D4, GET_BIT(Copy_u8Command, BIT4));
    DIO_voidWritePin(LCD_D5_PORT, D5, GET_BIT(Copy_u8Command, BIT5));
    DIO_voidWritePin(LCD_D6_PORT, D6, GET_BIT(Copy_u8Command, BIT6));
    DIO_voidWritePin(LCD_D7_PORT, D7, GET_BIT(Copy_u8Command, BIT7));

    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_EN_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);

    DIO_voidWritePin(LCD_D4_PORT, D4, GET_BIT(Copy_u8Command, BIT0));
    DIO_voidWritePin(LCD_D5_PORT, D5, GET_BIT(Copy_u8Command, BIT1));
    DIO_voidWritePin(LCD_D6_PORT, D6, GET_BIT(Copy_u8Command, BIT2));
    DIO_voidWritePin(LCD_D7_PORT, D7, GET_BIT(Copy_u8Command, BIT3));
    //Send Enable Pulse
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);
    //HIGH
    DIO_voidWritePin(LCD_EN_PORT, EN, HIGH);
    //wait for 2ms
    _delay_ms(2);
    //LOW
    DIO_voidWritePin(LCD_EN_PORT, EN, LOW);
}

#endif


void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CharAddress = 0;
	if(Copy_u8XPos == 0)
	{
		if(Copy_u8YPos < 16)
		{
			//Address = Y-Position
			Local_u8CharAddress = Copy_u8YPos;
		}else{}
	}
	else if(Copy_u8XPos == 1)
	{
		if(Copy_u8YPos < 16)
		{
			Local_u8CharAddress = Copy_u8YPos + ROW1_OFFSET;
		}else{}
	}
	else
	{
		//Raise Error
	}

	Local_u8CharAddress += ROW1_CMD;

	LCD_voidSendCommand(Local_u8CharAddress);

}

void LCD_voidSendString(u8 * Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter = 0;

	while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
	{
		LCD_voidSendChar(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}


void LCD_voidSendNumber(s32 Copy_s32Number)
{
	u8 Local_u8DigitsDataArray[10] = {0};
	s8 Local_s8LoopCounter = 0;
	u8 Local_u8NumberSign  = 0; //0 -> Positive Number, 1 for Negative Number

	if(Copy_s32Number >= 0)
	{
		Local_u8NumberSign = POSITIVE;
	}
	else
	{	//Convert The Number To Positive, and take the sign
		Local_u8NumberSign = NEGATIVE;
        //Get The First Complement
		Copy_s32Number--;
        //Get The Positive Value
		Copy_s32Number = ~Copy_s32Number;
	}

    if(Copy_s32Number == 0)
    {
        Local_u8DigitsDataArray[Local_s8LoopCounter] = '0';
        Local_s8LoopCounter++;
    }else{}

	while(Copy_s32Number != 0)
	{	//Split the Number to digits, Get there ASCII, and store them in array.
		Local_u8DigitsDataArray[Local_s8LoopCounter] = (Copy_s32Number % 10) + '0';
		Copy_s32Number /= 10;
		Local_s8LoopCounter++;
	}

	Local_s8LoopCounter--;

	if(Local_u8NumberSign == NEGATIVE)
	{
		LCD_voidSendChar('-');
	}else{}

	while(Local_s8LoopCounter >= 0)
	{
		LCD_voidSendChar(Local_u8DigitsDataArray[Local_s8LoopCounter]);
		Local_s8LoopCounter--;
	}
}



void LCD_voidSendCustomCharachter(u8 * Copy_pu8CharArray,
								  u8 Copy_u8PatternNumber,
								  u8 Copy_u8XPos,
								  u8 Copy_u8YPos)
{
	u8 Local_u8LoopCounter = 0;
	u8 Local_u8CGRAMAddress = 0;
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	SET_BIT(Local_u8CGRAMAddress, 6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8LoopCounter=0; Local_u8LoopCounter<8; Local_u8LoopCounter++)
	{
		LCD_voidSendChar(Copy_pu8CharArray[Local_u8LoopCounter]);
	}

	LCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	LCD_voidSendChar(Copy_u8PatternNumber);

}


void LCD_voidDisplayOn(void)
{
    LCD_voidSendCommand(CMD_ON_OFF_DISPLAY_ON);
}

void LCD_voidDisplayOff(void)
{
    LCD_voidSendCommand(CMD_ON_OFF_DISPLAY_OFF);
}

void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(CMD_CLEAR_DISPLAY);
}

void LCD_voidCursorOn(void)
{
    LCD_voidSendCommand(CMD_ON_OFF_CURSOR_ON);
}

void LCD_voidCursorBlink(void)
{
    LCD_voidSendCommand(CMD_ON_OFF_CURSOR_BLINK);
}

void LCD_voidCursorOff(void)
{
    LCD_voidSendCommand(CMD_ON_OFF_CURSOR_OFF);
}
