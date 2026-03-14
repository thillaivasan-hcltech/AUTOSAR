#ifndef LED_STATUS_H
#define LED_STATUS_H

#include "Std_Types.h"

#define LED_STATUS_START_SEC_CODE
#include "led_status_MemMap.h"

#define LED_POS_SIZE 8

typedef struct {
    uint8 state_bits;
} led_status_t;

FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_init(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_set_position(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos);
FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_power_ok(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_error(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst);

#define LED_STATUS_STOP_SEC_CODE
#include "led_status_MemMap.h"

#endif /* LED_STATUS_H */
