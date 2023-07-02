/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   9 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         9 APR, 2023    Hossam M. Elzhar          Initial Creation
*********************************************/

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidEnable(void)
{
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidSetTime(u8 Copy_u8Scaler)
{
    WDTCR &= SCALER_CLEAR_MASK;
    WDTCR |= Copy_u8Scaler;
}

void WDT_voidDisable(void)
{
    WDTCR = DISABLE_MASK;
    WDTCR = ZERO;
}
