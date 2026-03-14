#ifndef RTE_SYSTEMINITSWC_H
#define RTE_SYSTEMINITSWC_H

#include "Rte_Type.h"
#include "Rte_CommandParserSWC.h"
#include "Rte_FeedbackProcessorSWC.h"
#include "Rte_FlapControlSWC.h"
#include "Rte_MotorDriverSWC.h"
#include "Rte_LedStatusSWC.h"

void System_Init(uint8 initial_pos);

#endif /* RTE_SYSTEMINITSWC_H */
