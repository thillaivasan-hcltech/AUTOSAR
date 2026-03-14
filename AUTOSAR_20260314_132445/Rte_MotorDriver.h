/* AUTOSAR RTE Header for Motor Driver */

#ifndef RTE_MOTOR_DRIVER_H
#define RTE_MOTOR_DRIVER_H

#include "Rte_Type.h"

// RTE API prototypes
void MotorDriver_Init(void);
void MotorDriver_Drive(uint8 direction, uint8 dutyCycle);
void MotorDriver_Stop(void);
uint8 MotorDriver_Status(void);

#endif /* RTE_MOTOR_DRIVER_H */
