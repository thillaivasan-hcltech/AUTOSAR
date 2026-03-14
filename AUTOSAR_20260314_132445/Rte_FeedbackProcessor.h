/* AUTOSAR RTE Header for Feedback Processor */

#ifndef RTE_FEEDBACK_PROCESSOR_H
#define RTE_FEEDBACK_PROCESSOR_H

#include "Rte_Type.h"

// RTE API prototypes
void FeedbackProcessor_Init(void);
void FeedbackProcessor_Update(void);
uint16 FeedbackProcessor_GetPosition(void);

uint16 Rte_Call_ADC_Read(void);

#endif /* RTE_FEEDBACK_PROCESSOR_H */
