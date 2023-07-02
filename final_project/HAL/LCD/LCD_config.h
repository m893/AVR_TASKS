#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H



/*
 * Options:
 * 		FOUR_BIT_MODE_SAME_PORT
 * 		FOUR_BIT_MODE_SEPARATE_PORT_PINS
 *      EIGHT_BIT_MODE
 */
#define LCD_MODE		  FOUR_BIT_MODE_SEPARATE_PORT_PINS




#if (LCD_MODE == EIGHT_BIT_MODE)
    /*
    * Options:
    * 		DIO_PORTA
    * 		DIO_PORTB
    * 		DIO_PORTC
    * 		DIO_PORTD
    */
    #define LCD_DATA_PORT     DIO_PORTC
    #define LCD_CONTROL_PORT  DIO_PORTD

    /*
    * Options:
    * 		PIN0
    * 		PIN1
    * 		PIN2
    * 		PIN3
    * 		PIN4
    * 		PIN5
    * 		PIN6
    * 		PIN7
    *      NC
    */
    #define RS                PIN0
    #define RW                NC
    #define EN                PIN2

    #define D0                PIN0
    #define D1                PIN1
    #define D2                PIN2
    #define D3                PIN3
    #define D4                PIN4
    #define D5                PIN5
    #define D6                PIN6
    #define D7                PIN7

#elif (LCD_MODE == FOUR_BIT_MODE)

    /*
    * Options:
    * 		DIO_PORTA
    * 		DIO_PORTB
    * 		DIO_PORTC
    * 		DIO_PORTD
    */
    #define LCD_DATA_PORT     DIO_PORTA
    #define LCD_CONTROL_PORT  DIO_PORTA

    /*
    * Options:
    * 		PIN0
    * 		PIN1
    * 		PIN2
    * 		PIN3
    * 		PIN4
    * 		PIN5
    * 		PIN6
    * 		PIN7
    *      NC
    */
    #define RS                PIN2
    #define RW                NC
    #define EN                PIN3

    #define D4                PIN4
    #define D5                PIN5
    #define D6                PIN6
    #define D7                PIN7

    #define DATA_MASK         ((1<<D4)|(1<<D5)|(1<<D6)|(1<<D7))

    #if (D4 == PIN0) && (D5 == PIN1) && (D6 == PIN2)  && (D7 == PIN3) 
        #define LOWER_NIBBLE    NIBBLE_SHIFT
    #elif (D4 == PIN4) && (D5 == PIN5) && (D6 == PIN6)  && (D7 == PIN7)
        #define HIGHER_NIBBLE   NIBBLE_SHIFT
    #else
        #error "YOU Must Select DATA PINS From PIN0 To PIN3 OR From PIN4 To PIN7"
    #endif

#elif (LCD_MODE == FOUR_BIT_MODE_SEPARATE_PORT_PINS)

    /*
    * Options:
    * 		DIO_PORTA
    * 		DIO_PORTB
    * 		DIO_PORTC
    * 		DIO_PORTD
    *       NC
    */
    #define LCD_D4_PORT     DIO_PORTA
    #define LCD_D5_PORT     DIO_PORTB
    #define LCD_D6_PORT     DIO_PORTC
    #define LCD_D7_PORT     DIO_PORTD
    #define LCD_RS_PORT     DIO_PORTA
    #define LCD_RW_PORT     NC
    #define LCD_EN_PORT     DIO_PORTB

    /*
    * Options:
    * 		PIN0
    * 		PIN1
    * 		PIN2
    * 		PIN3
    * 		PIN4
    * 		PIN5
    * 		PIN6
    * 		PIN7
    *       NC
    */
    #define RS                PIN1
    #define RW                NC
    #define EN                PIN1

    #define D4                PIN0
    #define D5                PIN0
    #define D6                PIN0
    #define D7                PIN0

#else

    #error ("LCD_MODE, Error Configurations")

#endif






#endif
