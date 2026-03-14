/* MotorDriver.h - AUTOSAR Compliant Header */

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define MOTORDRIVER_SW_MAJOR_VERSION 1
#define MOTORDRIVER_SW_MINOR_VERSION 0
#define MOTORDRIVER_SW_PATCH_VERSION 0

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} MotorDriver_DirType;

typedef struct {
    boolean enabled;
    MotorDriver_DirType dir;
    uint8 pwmDuty;
} MotorDriver_Type;

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Init(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Drive(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst, MotorDriver_DirType dir, boolean enable, uint8 pwm);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Stop(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Status(P2CONST(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst);

#endif /* MOTORDRIVER_H */
