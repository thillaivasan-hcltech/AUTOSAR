#include "CommandParser.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define COMMANDPARSER_START_SEC_CONST_8
#include "CommandParser_MemMap.h"

static const uint8 AllowedPositions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

#define COMMANDPARSER_STOP_SEC_CONST_8
#include "CommandParser_MemMap.h"

#define COMMANDPARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

static uint8 CommandParser_LatestCommand = 0U;
static boolean CommandParser_Valid = FALSE;
static command_state_t CommandParser_State = CMD_STATE_INIT;

static FUNC(boolean, COMMANDPARSER_CODE) IsAllowedCommand(uint8 cmd);

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_Init(void)
{
    CommandParser_LatestCommand = 0U;
    CommandParser_Valid = FALSE;
    CommandParser_State = CMD_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_ProcessByte(uint8 byte)
{
    CommandParser_State = CMD_STATE_WAIT_RX;
    if (IsAllowedCommand(byte)) {
        CommandParser_LatestCommand = byte;
        CommandParser_Valid = TRUE;
        CommandParser_State = CMD_STATE_VALID;
        return E_OK;
    } else {
        CommandParser_Valid = FALSE;
        CommandParser_State = CMD_STATE_INVALID;
        return E_NOT_OK;
    }
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (CommandParser_Valid) {
        *pos = CommandParser_LatestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

static FUNC(boolean, COMMANDPARSER_CODE) IsAllowedCommand(uint8 cmd)
{
    for (uint8 i = 0; i < MAX_POSITIONS; ++i) {
        if (cmd == AllowedPositions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

#define COMMANDPARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
