/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   28 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         28 MAR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H




/*
 * Options:
 * 		DIO_PORTA
 * 		DIO_PORTB
 * 		DIO_PORTC
 * 		DIO_PORTD
 */
#define KPD_ROWS_PORT        DIO_PORTC
#define KPD_COLUMNS_PORT     DIO_PORTC

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
 */
#define KPD_ROW0_PIN         PIN0
#define KPD_ROW1_PIN         PIN1
#define KPD_ROW2_PIN         PIN2
#define KPD_ROW3_PIN         PIN2

#define KPD_COLUMN0_PIN      PIN0
#define KPD_COLUMN1_PIN      PIN1
#define KPD_COLUMN2_PIN      PIN2
#define KPD_COLUMN3_PIN      PIN2


#define KPD_ROWS_NUM           4
#define KPD_COLUMNS_NUM        4

#define KPD_KEYS_ARRAY { {'7', '8', '9', '+'},\
                         {'4', '5', '6', '-'},\
                         {'1', '2', '3', '*'},\
                         {'#', '0', '=', '/'} }


#define KPD_NO_KEY_PRESSED     255




#endif
