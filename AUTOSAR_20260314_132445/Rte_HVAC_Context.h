/* AUTOSAR RTE Header for HVAC Context */

#ifndef RTE_HVAC_CONTEXT_H
#define RTE_HVAC_CONTEXT_H

#include "Rte_Type.h"

// RTE API prototypes
void Rte_Call_CommandParser_Init(void);
void Rte_Call_CommandParser_ProcessByte(uint8 byte);

void Rte_Call_FlapControl_Init(void);
void Rte_Call_FlapControl_Update(void);

void Rte_Call_MotorDriver_Init(void);

void Rte_Call_FeedbackProcessor_Init(void);
void Rte_Call_FeedbackProcessor_Update(void);

void Rte_Call_LEDStatus_Init(void);
void Rte_Call_LEDStatus_Update(void);

boolean Rte_Call_UART_ByteAvailable(void);
uint8 Rte_Call_UART_Receive(void);

#endif /* RTE_HVAC_CONTEXT_H */
