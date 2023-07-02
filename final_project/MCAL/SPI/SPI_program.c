/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   17 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         17 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



void SPI_voidMasterInit(void)
{
    /*
    *setup rising sample falling
    Data order : LSB
    clk select : F/128
    SPI Enable
    */

   //LSB
   SET_BIT(SPCR, DORD);

   //Master
   SET_BIT(SPCR, MSTR);

    //CPOL
    CLEAR_BIT(SPCR, CPOL);

    //CPHA
    SET_BIT(SPCR, CPHA);

    //clk / 128
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);

    //enable 
    SET_BIT(SPCR, SPE);


}

void SPI_voidSlaveInit(void)
{
    /*
    *setup rising sample falling
    Data order : LSB
    clk select : F/128
    */

    //LSB
    SET_BIT(SPCR, DORD);

    //Slave
    CLEAR_BIT(SPCR, MSTR);

    //CPOL
    CLEAR_BIT(SPCR, CPOL);

    //CPHA
    SET_BIT(SPCR, CPHA);

    //clk / 128
    SET_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);

    //enable 
    SET_BIT(SPCR, SPE);
}


void SPI_voidTrancieveData(u8 Copy_u8TransData, u8 *pu8RecievedData)
{
    while(GET_BIT(SPSR, SPIF) == 0);

    SPDR =  Copy_u8TransData;

    while(GET_BIT(SPSR, SPIF) == 0);

    if(pu8RecievedData)
    {
    	*pu8RecievedData = SPDR;
    }
}

void SPI_voidRecieveData(u8 *pu8RecievedData)
{
    while(GET_BIT(SPSR, SPIF) == 0);

    if(pu8RecievedData)
    {
    	*pu8RecievedData = SPDR;
    }
}
