/* CommandParser.c - AUTOSAR Compliant Source */

#include "CommandParser.h"

#define COMMANDPARSER_START_SEC_CONST_8
#include "CommandParser_MemMap.h"

CONST(uint8, COMMANDPARSER_CONST) AllowedPositions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

#define COMMANDPARSER_STOP_SEC_CONST_8
#include "CommandParser_MemMap.h"

#define COMMANDPARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_Init(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->latestCommand = 0U;
    inst->valid = FALSE;
    inst->state = CMD_STATE_INIT;
    return E_OK;
}

static FUNC(boolean, COMMANDPARSER_CODE) IsAllowedCommand(uint8 cmd) {
    for (uint8 i = 0U; i < MAX_POSITIONS; ++i) {
        if (cmd == AllowedPositions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_ProcessByte(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->state = CMD_STATE_WAIT_RX;
    if (IsAllowedCommand(byte)) {
        inst->latestCommand = byte;
        inst->valid = TRUE;
        inst->state = CMD_STATE_VALID;
    } else {
        inst->valid = FALSE;
        inst->state = CMD_STATE_INVALID;
    }
    return E_OK;
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2CONST(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL_PTR || pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (inst->valid) {
        *pos = inst->latestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

#define COMMANDPARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
