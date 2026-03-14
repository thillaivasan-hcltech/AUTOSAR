#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "Std_Types.h"
#include "Platform_Types.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Init(void);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDrive(motor_dir_t dir, boolean enable, uint8 pwm);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorStop(void);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status);

#endif /* MOTOR_DRIVER_H */
