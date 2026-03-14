/* AUTOSAR RTE Header for HVAC Controller */

#ifndef RTE_HVAC_CONTROLLER_H
#define RTE_HVAC_CONTROLLER_H

#include "Rte_Type.h"

/* RTE API Prototypes */
Std_ReturnType Rte_Call_UART_Receive(void);
Std_ReturnType Rte_Call_CommandParser_Parse(void);
Std_ReturnType Rte_Call_FlapControl_Update(void);

#endif /* RTE_HVAC_CONTROLLER_H */
