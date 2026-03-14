#include "led_status.h"

#define LED_STATUS_START_SEC_CODE
#include "led_status_MemMap.h"

FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_init(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->state_bits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_set_position(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->state_bits = 1U << (pos >> 5);
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_power_ok(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->state_bits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) led_status_error(P2VAR(led_status_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->state_bits = 0xFFU;
    return E_OK;
}

#define LED_STATUS_STOP_SEC_CODE
#include "led_status_MemMap.h"
