/* AUTOSAR HVAC Controller Component Implementation */
#include "Rte_HVAC_Controller.h"

void HVAC_Controller_MainFunction(void)
{
    /* Initialize system and run main loop */
    while (1)
    {
        /* Execute HVAC logic tasks */
        if (Rte_Call_UART_Receive())
        {
            /* Process UART data and parse commands */
            Rte_Call_CommandParser_Parse();
        }
        /* Control flap based on parsed commands and feedback */
        Rte_Call_FlapControl_Update();
    }
}
