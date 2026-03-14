#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H

#include "Std_Types.h"
#include "command_parser.h"
#include "flap_control.h"
#include "motor_driver.h"
#include "feedback_processor.h"
#include "led_status.h"

#define SYSTEM_INIT_START_SEC_CODE
#include "system_init_MemMap.h"

typedef struct {
    command_parser_t cmd;
    flap_control_t flap;
    motor_driver_t motor;
    feedback_processor_t fb;
    led_status_t led;
} hvac_context_t;

FUNC(Std_ReturnType, SYSTEM_INIT_CODE) system_init(P2VAR(hvac_context_t, AUTOMATIC, RTE_APPL_DATA) ctx, uint8 initial_pos);

#define SYSTEM_INIT_STOP_SEC_CODE
#include "system_init_MemMap.h"

#endif /* SYSTEM_INIT_H */
