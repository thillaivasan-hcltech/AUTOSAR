/* AUTOSAR compliant motor_driver.h */
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "Std_Types.h"

#define MOTOR_DRIVER_SW_MAJOR_VERSION 1
#define MOTOR_DRIVER_SW_MINOR_VERSION 0
#define MOTOR_DRIVER_SW_PATCH_VERSION 0

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Init(void);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Drive(motor_dir_t direction, boolean enable, uint8 pwm);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Stop(void);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status);

#endif /* MOTOR_DRIVER_H */
