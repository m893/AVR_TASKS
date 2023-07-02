#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "GIE_interface.h"
#include "GIE_private.h"

void GIE_VoidEnabledGlobalInterrupt(void)
{
    SET_BIT(SREG , SREG_BIT7);


}
void GIE_VoidDisabledGlobalInterrupt(void)
{
    CLEAR_BIT(SREG , SREG_BIT7);


}
