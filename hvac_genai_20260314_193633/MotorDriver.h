#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Std_Types.h"

#define MOTORDRIVER_SW_MAJOR_VERSION 1U
#define MOTORDRIVER_SW_MINOR_VERSION 0U
#define MOTORDRIVER_SW_PATCH_VERSION 0U

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Init(void);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Drive(motor_dir_t dir, boolean enable, uint8 pwm);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Stop(void);
FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status);

#endif /* MOTORDRIVER_H */
