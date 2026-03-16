#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

#include "Std_Types.h"
#include "command_parser.h"
#include "flap_control.h"
#include "motor_driver.h"
#include "feedback_processor.h"
#include "led_status.h"

typedef struct {
    CommandParser_ConfigType cmdConfig;
    FlapControl_ConfigType flapConfig;
    MotorDriver_ConfigType motorConfig;
    FeedbackProcessor_ConfigType fbConfig;
    LedStatus_ConfigType ledConfig;
} SystemInit_ConfigType;

FUNC(void, SYSTEM_INIT_CODE) System_Init(P2CONST(SystemInit_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);

#endif /* SYSTEM_INIT_H */
