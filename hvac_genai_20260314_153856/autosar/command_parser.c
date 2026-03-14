#include "command_parser.h"
#include "Rte_CommandParser.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define COMMAND_PARSER_START_SEC_CODE
#include "CommandParser_MemMap.h"

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_Init(void)
{
    Std_ReturnType ret = E_OK;
    /* Initialize internal state */
    static uint8 latestCommand = 0U;
    static boolean valid = FALSE;
    static command_state_t state = CMD_STATE_INIT;
    return ret;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_ProcessByte(uint8 byte)
{
    Std_ReturnType ret = E_OK;
    boolean isValid = FALSE;
    /* Check if the command is allowed */
    for (uint8 i = 0U; i < MAX_POSITIONS; ++i) {
        if (byte == allowed_positions[i]) {
            isValid = TRUE;
            break;
        }
    }
    if (isValid) {
        latestCommand = byte;
        valid = TRUE;
        state = CMD_STATE_VALID;
    } else {
        valid = FALSE;
        state = CMD_STATE_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    Std_ReturnType ret = E_NOT_OK;
    if (valid) {
        *pos = latestCommand;
        ret = E_OK;
    }
    return ret;
}

#define COMMAND_PARSER_STOP_SEC_CODE
#include "CommandParser_MemMap.h"
