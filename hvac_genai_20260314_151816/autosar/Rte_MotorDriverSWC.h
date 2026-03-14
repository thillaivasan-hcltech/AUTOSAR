#ifndef RTE_MOTORDRIVERSWC_H
#define RTE_MOTORDRIVERSWC_H

#include "Rte_Type.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} MotorDirType;

void MotorDriverSWC_Init(void);
void MotorDriverSWC_Drive(MotorDirType dir, boolean enable, uint8 pwm);
void MotorDriverSWC_Stop(void);
boolean MotorDriverSWC_Status(void);

#endif /* RTE_MOTORDRIVERSWC_H */
