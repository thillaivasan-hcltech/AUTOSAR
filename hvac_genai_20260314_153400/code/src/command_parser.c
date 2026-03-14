#include "command_parser.h"

#define COMMAND_PARSER_START_SEC_CODE
#include "command_parser_MemMap.h"

const uint8 allowed_positions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_init(P2VAR(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->latest_command = 0U;
    inst->valid = FALSE;
    inst->state = CMD_STATE_INIT;
    return E_OK;
}

static FUNC(boolean, COMMAND_PARSER_CODE) is_allowed_command(uint8 cmd) {
    for (uint8 i = 0; i < MAX_POSITIONS; ++i) {
        if (cmd == allowed_positions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_process_byte(P2VAR(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->state = CMD_STATE_WAIT_RX;
    if (is_allowed_command(byte)) {
        inst->latest_command = byte;
        inst->valid = TRUE;
        inst->state = CMD_STATE_VALID;
    } else {
        inst->valid = FALSE;
        inst->state = CMD_STATE_INVALID;
    }
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_get_latest(P2CONST(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL || pos == NULL) { return E_NOT_OK; }
    if (inst->valid) {
        *pos = inst->latest_command;
        return E_OK;
    }
    return E_NOT_OK;
}

#define COMMAND_PARSER_STOP_SEC_CODE
#include "command_parser_MemMap.h"
