/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "signalgeneration.h"
#include "mcc_generated_files/pin_manager.h"

#define FCY (32000000)
#include <libpic30.h>
/*
 Main application
*/


int main(void)
{
    // initialize the device
    srand(time(NULL));
    SYSTEM_Initialize();
    
    TMR2_SetInterruptHandler(HSYNC);
    TMR1_SetInterruptHandler(VSYNC);
    
    while (1)
    {
        // Add your application code
    }
    return 1;
}
/**
 End of File
*/

