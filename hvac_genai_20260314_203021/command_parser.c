/* AUTOSAR compliant command_parser.c */
#include "command_parser.h"
#include "Rte_CommandParser.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define COMMAND_PARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

static FUNC(boolean, COMMAND_PARSER_CODE) CommandParser_IsAllowedCommand(uint8 cmd);

static VAR(uint8, COMMAND_PARSER_VAR) latestCommand = 0U;
static VAR(boolean, COMMAND_PARSER_VAR) valid = FALSE;
static VAR(command_state_t, COMMAND_PARSER_VAR) state = CMD_STATE_INIT;

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_Init(void) {
    latestCommand = 0U;
    valid = FALSE;
    state = CMD_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_ProcessByte(uint8 byte) {
    state = CMD_STATE_WAIT_RX;
    if (CommandParser_IsAllowedCommand(byte)) {
        latestCommand = byte;
        valid = TRUE;
        state = CMD_STATE_VALID;
    } else {
        valid = FALSE;
        state = CMD_STATE_INVALID;
    }
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (valid) {
        *pos = latestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

static FUNC(boolean, COMMAND_PARSER_CODE) CommandParser_IsAllowedCommand(uint8 cmd) {
    static const uint8 allowedPositions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (uint8 i = 0; i < MAX_POSITIONS; ++i) {
        if (cmd == allowedPositions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

#define COMMAND_PARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
