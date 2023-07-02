#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8Stat)
{
	//switch on port type
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			//switch on State type
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_REG(DDRA); break;
				case OUTPUT:  SET_REG(DDRA); break;
				case IN_PULL_UP: CLEAR_REG(DDRA); SET_REG(PORTA); break;
				default:
					break;
			}
			break;
		case DIO_PORTB:
			//switch on State type
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_REG(DDRB); break;
				case OUTPUT:  SET_REG(DDRB); break;
				case IN_PULL_UP: CLEAR_REG(DDRB); SET_REG(PORTB); break;
				default:
					break;
			}
			break;
		case DIO_PORTC:
			//switch on State type
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_REG(DDRC); break;
				case OUTPUT:  SET_REG(DDRC); break;
				case IN_PULL_UP: CLEAR_REG(DDRC); SET_REG(PORTC); break;
				default:
					break;
			}
			break;
		case DIO_PORTD:
			//switch on State type
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_REG(DDRD); break;
				case OUTPUT:  SET_REG(DDRD); break;
				case IN_PULL_UP: CLEAR_REG(DDRD); SET_REG(PORTD); break;
				default:
					break;
			}
			break;
	}
}

void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8SpecificDirection)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			ASSIGN_REG(DDRA, Copy_u8SpecificDirection);
			break;
		case DIO_PORTB:
			ASSIGN_REG(DDRB, Copy_u8SpecificDirection);
			break;
		case DIO_PORTC:
			ASSIGN_REG(DDRC, Copy_u8SpecificDirection);
			break;
		case DIO_PORTD:
			ASSIGN_REG(DDRD, Copy_u8SpecificDirection);
			break;
		default:
			break;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 Copy_u8Stat)
{
	//switch on port type
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
            //switch on State type
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_BIT(DDRA, Copy_u8Pin); break;
				case OUTPUT:  SET_BIT(DDRA, Copy_u8Pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRA, Copy_u8Pin); SET_BIT(PORTA, Copy_u8Pin); break;
				default:
					break;
			}
			break;
		case DIO_PORTB:
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_BIT(DDRB, Copy_u8Pin); break;
				case OUTPUT:  SET_BIT(DDRB, Copy_u8Pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRB, Copy_u8Pin); SET_BIT(PORTB, Copy_u8Pin); break;
				default:
					break;
			}
			break;
		case DIO_PORTC:
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_BIT(DDRC, Copy_u8Pin); break;
				case OUTPUT:  SET_BIT(DDRC, Copy_u8Pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRC, Copy_u8Pin); SET_BIT(PORTC, Copy_u8Pin); break;
				default:
					break;
			}
			break;
		case DIO_PORTD:
			switch(Copy_u8Stat)
			{
				case INPUT: CLEAR_BIT(DDRD, Copy_u8Pin); break;
				case OUTPUT:  SET_BIT(DDRD, Copy_u8Pin); break;
                case IN_PULL_UP: CLEAR_BIT(DDRD, Copy_u8Pin); SET_BIT(PORTD, Copy_u8Pin); break;
				default:
					break;
			}
			break;

		default:
			break;
	}

}


/************************************************************************
 * description : Write A value On A Port
 * INPUT Args  : PORT Type, Value
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8SpecificValue)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORTA: ASSIGN_REG(PORTA, Copy_u8SpecificValue); break;
		case DIO_PORTB: ASSIGN_REG(PORTB, Copy_u8SpecificValue); break;
		case DIO_PORTC: ASSIGN_REG(PORTC, Copy_u8SpecificValue); break;
		case DIO_PORTD: ASSIGN_REG(PORTD, Copy_u8SpecificValue); break;
		default: break;
	}

}

void DIO_voidSetBitsInPort(u8 Copy_u8PortName, u8 Copy_u8SpecificValue, u8 Copy_u8Mask)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORTA: 
			CLEAR_BITS_REG(PORTA, Copy_u8Mask);
			SET_BITS_REG(PORTA, (Copy_u8SpecificValue & Copy_u8Mask));
			break;
		case DIO_PORTB: 
			CLEAR_BITS_REG(PORTB, Copy_u8Mask);
			SET_BITS_REG(PORTB, (Copy_u8SpecificValue & Copy_u8Mask));
			break;
		case DIO_PORTC:
			CLEAR_BITS_REG(PORTC, Copy_u8Mask);
			SET_BITS_REG(PORTC, (Copy_u8SpecificValue & Copy_u8Mask));
			break;
		case DIO_PORTD:
			CLEAR_BITS_REG(PORTD, Copy_u8Mask);
			SET_BITS_REG(PORTD, (Copy_u8SpecificValue & Copy_u8Mask));
			break;
		default: 
			break;
	}
}

/************************************************************************
 * description : Read value OF A Port
 * INPUT Args  : PORT Type
 * RETURN      : Value Of Port
 * **********************************************************************
 * */
u8 DIO_u8ReadPort(u8 Copy_u8PortName)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORTA:
			return PINA;
			break;
		case DIO_PORTB:
			return PINB;
			break;
		case DIO_PORTC:
			return PINC;
			break;
		case DIO_PORTD:
			return PIND;
			break;
		default:
			return 0x00;
			break;
	}
}


/************************************************************************
 * description : Write A value On A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port, Value
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void DIO_voidWritePin(u8 Copy_u8PortName, u8 Copy_u8Pin, u8 Copy_u8Stat)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA:
			switch(Copy_u8Stat)
			{
				case LOW: CLEAR_BIT(PORTA, Copy_u8Pin); break;
				case HIGH:  SET_BIT(PORTA, Copy_u8Pin); break;
				default: break;
			}
			break;
		case DIO_PORTB:
			switch(Copy_u8Stat)
			{
				case LOW: CLEAR_BIT(PORTB, Copy_u8Pin); break;
				case HIGH:  SET_BIT(PORTB, Copy_u8Pin); break;
				default: break;
			}
			break;
		case DIO_PORTC:
			switch(Copy_u8Stat)
			{
				case LOW: CLEAR_BIT(PORTC, Copy_u8Pin); break;
				case HIGH:  SET_BIT(PORTC, Copy_u8Pin); break;
				default: break;
			}
			break;
		case DIO_PORTD:
			switch(Copy_u8Stat)
			{
				case LOW: CLEAR_BIT(PORTD, Copy_u8Pin); break;
				case HIGH:  SET_BIT(PORTD, Copy_u8Pin); break;
				default: break;
			}
			break;
	}
}



/************************************************************************
 * description : Read A value OF A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port
 * RETURN      : HIGH OR LOW
 * **********************************************************************
 * */
u8 DIO_voidReadPin(u8 Copy_u8PortName, u8 Copy_u8Pin)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORTA:
			return GET_BIT(PINA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			return GET_BIT(PINB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			return GET_BIT(PINC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			return GET_BIT(PIND,Copy_u8Pin);
			break;
		default:
			return 0x00;
			break;
	}
}



/************************************************************************
 * description : Toggle A value OF A Pin In Port
 * INPUT Args  : PORT Type, Pin Number In Port
 * RETURN      : Execution Status (OK OR NOT_OK)
 * **********************************************************************
 * */
void DIO_voidTogglePin(u8 Copy_u8PortName, u8 Copy_u8Pin)
{
	switch (Copy_u8PortName)
	{
		case DIO_PORTA:
			TOGGLE_BIT(PORTA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			TOGGLE_BIT(PORTB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			TOGGLE_BIT(PORTC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			TOGGLE_BIT(PORTD,Copy_u8Pin);
			break;
		default: break;
	}

}
