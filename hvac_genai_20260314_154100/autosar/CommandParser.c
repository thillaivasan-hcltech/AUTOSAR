#include "CommandParser.h"
#include "Rte_CommandParser.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define COMMANDPARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

static uint8 latestCommand = 0U;
static boolean valid = FALSE;
static command_state_t state = CMD_STATE_INIT;

FUNC(void, COMMANDPARSER_CODE) CommandParser_Init(void)
{
    latestCommand = 0U;
    valid = FALSE;
    state = CMD_STATE_INIT;
}

FUNC(void, COMMANDPARSER_CODE) CommandParser_ProcessByte(void)
{
    uint8 byte;
    if (Rte_Read_rpCommandByte(&byte) == E_OK)
    {
        state = CMD_STATE_WAIT_RX;
        if (isAllowedCommand(byte))
        {
            latestCommand = byte;
            valid = TRUE;
            state = CMD_STATE_VALID;
        }
        else
        {
            valid = FALSE;
            state = CMD_STATE_INVALID;
        }
    }
}

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    if (pos == NULL_PTR)
    {
        return E_NOT_OK;
    }
    if (valid)
    {
        *pos = latestCommand;
        return E_OK;
    }
    return E_NOT_OK;
}

static FUNC(boolean, COMMANDPARSER_CODE) isAllowedCommand(uint8 cmd)
{
    for (uint8 i = 0U; i < MAX_POSITIONS; ++i)
    {
        if (cmd == allowed_positions[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

#define COMMANDPARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
