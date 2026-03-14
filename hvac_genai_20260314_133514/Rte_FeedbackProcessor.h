/* AUTOSAR RTE Header for Feedback Processor */

#ifndef RTE_FEEDBACK_PROCESSOR_H
#define RTE_FEEDBACK_PROCESSOR_H

#include "Rte_Type.h"

/* RTE API Prototypes */
uint16 Rte_Read_ADC_Value(void);
void Rte_Write_Feedback_Position(uint16 position);

#endif /* RTE_FEEDBACK_PROCESSOR_H */
