#include "Rte_CommandParser.h"
#include "CommandParser_MemMap.h"

#define COMMANDPARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

static uint8 latestCommand = 0U;
static boolean valid = FALSE;
static command_state_t state = CMD_STATE_INIT;

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_Init(void) {
    latestCommand = 0U;
    valid = FALSE;
    state = CMD_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_ProcessByte(uint8 byte) {
    state = CMD_STATE_WAIT_RX;
    if (IsAllowedCommand(byte)) {
        latestCommand = byte;
        valid = TRUE;
        state = CMD_STATE_VALID;
    } else {
        valid = FALSE;
        state = CMD_STATE_INVALID;
    }
    return E_OK;
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (valid) {
        *pos = latestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

static FUNC(boolean, COMMANDPARSER_CODE) IsAllowedCommand(uint8 cmd) {
    uint8 i;
    for (i = 0U; i < MAX_POSITIONS; ++i) {
        if (cmd == allowed_positions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

#define COMMANDPARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
