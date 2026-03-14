#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Std_Types.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

FUNC(void, MOTORDRIVER_CODE) MotorDriver_Init(void);
FUNC(void, MOTORDRIVER_CODE) MotorDriver_Drive(motor_dir_t direction, boolean enable, uint8 pwm);
FUNC(void, MOTORDRIVER_CODE) MotorDriver_Stop(void);
FUNC(boolean, MOTORDRIVER_CODE) MotorDriver_Status(void);

#endif /* MOTORDRIVER_H */
