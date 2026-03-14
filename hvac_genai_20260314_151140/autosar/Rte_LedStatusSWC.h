#ifndef RTE_LEDSTATUSSWC_H
#define RTE_LEDSTATUSSWC_H

#include "Rte_Type.h"

void LedStatus_Init(void);
void LedStatus_SetPosition(uint8 pos);
void LedStatus_PowerOk(void);
void LedStatus_Error(void);

#endif /* RTE_LEDSTATUSSWC_H */
