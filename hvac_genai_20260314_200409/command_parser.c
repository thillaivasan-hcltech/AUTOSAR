#include "command_parser.h"
#include "Rte_CommandParser.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define COMMAND_PARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

static FUNC(boolean, COMMAND_PARSER_CODE) CommandParser_IsAllowedCommand(uint8 cmd);

static VAR(uint8, COMMAND_PARSER_VAR) CommandParser_LatestCommand = 0U;
static VAR(boolean, COMMAND_PARSER_VAR) CommandParser_Valid = FALSE;

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_Init(void)
{
    CommandParser_LatestCommand = 0U;
    CommandParser_Valid = FALSE;
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_ProcessByte(uint8 byte)
{
    if (CommandParser_IsAllowedCommand(byte))
    {
        CommandParser_LatestCommand = byte;
        CommandParser_Valid = TRUE;
        return E_OK;
    }
    else
    {
        CommandParser_Valid = FALSE;
        return E_NOT_OK;
    }
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    if (pos == NULL_PTR)
    {
        return E_NOT_OK;
    }
    if (CommandParser_Valid)
    {
        *pos = CommandParser_LatestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

static FUNC(boolean, COMMAND_PARSER_CODE) CommandParser_IsAllowedCommand(uint8 cmd)
{
    static const uint8 allowed_positions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (uint8 i = 0; i < MAX_POSITIONS; ++i)
    {
        if (cmd == allowed_positions[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

#define COMMAND_PARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
