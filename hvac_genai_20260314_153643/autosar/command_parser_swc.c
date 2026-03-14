#include "Rte_CommandParserSWC.h"

#define COMMAND_PARSER_SWC_START_SEC_CODE
#include "CommandParserSWC_MemMap.h"

FUNC(Std_ReturnType, COMMAND_PARSER_SWC_CODE) CommandParserSWC_Init(void)
{
    /* Local static instance for state management */
    static command_parser_t commandParserInstance;
    command_parser_init(&commandParserInstance);
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_SWC_CODE) CommandParserSWC_ProcessByte(void)
{
    Std_ReturnType ret;
    uint8 byte;
    boolean byteAvailable;
    static command_parser_t commandParserInstance;

    ret = Rte_Read_CommandParserSWC_ByteAvailable(&byteAvailable);
    if (ret != E_OK || byteAvailable == FALSE) {
        return E_NOT_OK;
    }

    ret = Rte_Read_CommandParserSWC_ReceivedByte(&byte);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    command_parser_process_byte(&commandParserInstance, byte);
    return E_OK;
}

FUNC(Std_ReturnType, COMMAND_PARSER_SWC_CODE) CommandParserSWC_GetLatestCommand(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    static command_parser_t commandParserInstance;
    if (command_parser_get_latest(&commandParserInstance, pos)) {
        return E_OK;
    }
    return E_NOT_OK;
}

#define COMMAND_PARSER_SWC_STOP_SEC_CODE
#include "CommandParserSWC_MemMap.h"
