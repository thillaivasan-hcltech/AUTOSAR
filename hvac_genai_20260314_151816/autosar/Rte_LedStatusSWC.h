#ifndef RTE_LEDSTATUSSWC_H
#define RTE_LEDSTATUSSWC_H

#include "Rte_Type.h"

void LedStatusSWC_Init(void);
void LedStatusSWC_SetPosition(uint8 pos);
void LedStatusSWC_PowerOk(void);
void LedStatusSWC_Error(void);

#endif /* RTE_LEDSTATUSSWC_H */
