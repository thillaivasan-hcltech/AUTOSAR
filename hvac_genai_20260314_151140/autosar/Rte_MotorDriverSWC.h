#ifndef RTE_MOTORDRIVERSWC_H
#define RTE_MOTORDRIVERSWC_H

#include "Rte_Type.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

void MotorDriver_Init(void);
void Motor_Drive(motor_dir_t dir, boolean enable, uint8 pwm);
void Motor_Stop(void);
boolean MotorDriver_Status(void);

#endif /* RTE_MOTORDRIVERSWC_H */
