#include "system_init.h"
#include "Std_Types.h"

#define MAIN_START_SEC_CODE
#include "main_MemMap.h"

static FUNC(uint8, MAIN_CODE) UART_receive(void) { return 0x20U; }
static FUNC(uint16, MAIN_CODE) ADC_read(void) { return 1000U; }
static FUNC(boolean, MAIN_CODE) UART_byte_available(void) { return TRUE; }

FUNC(int, MAIN_CODE) main(void) {
    hvac_context_t ctx;
    uint8 last_cmd = 0U;
    uint8 curr_pos = 0U;
    uint16 adc_val = 0U;
    boolean valid_cmd = FALSE, valid_fb = FALSE, move = FALSE;

    if (system_init(&ctx, 0x00U) != E_OK) {
        return -1;
    }

    while (1) {
        if (UART_byte_available()) {
            uint8 rx = UART_receive();
            if (command_parser_process_byte(&ctx.cmd, rx) != E_OK) {
                continue;
            }
        }
        if (command_parser_get_latest(&ctx.cmd, &last_cmd) != E_OK) {
            continue;
        }
        adc_val = ADC_read();
        if (feedback_processor_update(&ctx.fb, adc_val) != E_OK) {
            continue;
        }
        if (flap_control_update(&ctx.flap, last_cmd, valid_cmd, ctx.fb.position, valid_fb) != E_OK) {
            continue;
        }
        if (ctx.flap.state == FLAP_MOVING && move) {
            if (ctx.flap.target_position > ctx.flap.current_position) {
                motor_drive(&ctx.motor, MOTOR_DIR_FWD, TRUE, 0x80U);
            } else {
                motor_drive(&ctx.motor, MOTOR_DIR_REV, TRUE, 0x80U);
            }
        } else if (ctx.flap.state == FLAP_TARGET_REACHED) {
            motor_stop(&ctx.motor);
        } else if (ctx.flap.state == FLAP_FAULT) {
            motor_stop(&ctx.motor);
            led_status_error(&ctx.led);
        }
        led_status_set_position(&ctx.led, ctx.flap.current_position);
    }
    return 0;
}

#define MAIN_STOP_SEC_CODE
#include "main_MemMap.h"
