#include "system_init.h"

#define SYSTEM_INIT_START_SEC_CODE
#include "system_init_MemMap.h"

FUNC(Std_ReturnType, SYSTEM_INIT_CODE) system_init(P2VAR(hvac_context_t, AUTOMATIC, RTE_APPL_DATA) ctx, uint8 initial_pos) {
    if (ctx == NULL) { return E_NOT_OK; }
    if (command_parser_init(&ctx->cmd) != E_OK) { return E_NOT_OK; }
    if (feedback_processor_init(&ctx->fb) != E_OK) { return E_NOT_OK; }
    if (flap_control_init(&ctx->flap, initial_pos) != E_OK) { return E_NOT_OK; }
    if (motor_driver_init(&ctx->motor) != E_OK) { return E_NOT_OK; }
    if (led_status_init(&ctx->led) != E_OK) { return E_NOT_OK; }
    if (led_status_power_ok(&ctx->led) != E_OK) { return E_NOT_OK; }
    return E_OK;
}

#define SYSTEM_INIT_STOP_SEC_CODE
#include "system_init_MemMap.h"
