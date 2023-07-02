/*********************************************
 * Author:          Hossam M. Elzhar
 * Creation Data:   4 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         4 APR, 2023      Hossam M. Elzhar          Initial Creation
*********************************************/

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../Services/POV_Display/POV_interface.h"


s32 main(void)
{

    POV_voidInit();
    LCD_voidInit();

    while (1)
    {

        POV_voidStartDisplay();

    }
    
    return 0;
}
