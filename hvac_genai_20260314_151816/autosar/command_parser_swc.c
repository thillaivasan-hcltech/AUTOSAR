#include "Rte_CommandParserSWC.h"

void CommandParserSWC_Init(void)
{
    Rte_IWrite_CommandParserSWC_CommandState_CMD_STATE_INIT();
    Rte_IWrite_CommandParserSWC_LatestCommand(0U);
    Rte_IWrite_CommandParserSWC_Valid(false);
}

void CommandParserSWC_ProcessByte(uint8 byte)
{
    boolean isValid = FALSE;
    uint8 allowedPositions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (uint8 i = 0; i < MAX_POSITIONS; ++i) {
        if (byte == allowedPositions[i]) {
            isValid = TRUE;
            break;
        }
    }
    if (isValid) {
        Rte_IWrite_CommandParserSWC_LatestCommand(byte);
        Rte_IWrite_CommandParserSWC_Valid(TRUE);
        Rte_IWrite_CommandParserSWC_CommandState_CMD_STATE_VALID();
    } else {
        Rte_IWrite_CommandParserSWC_Valid(FALSE);
        Rte_IWrite_CommandParserSWC_CommandState_CMD_STATE_INVALID();
    }
}

boolean CommandParserSWC_GetLatest(uint8 *pos)
{
    boolean valid;
    Rte_IRead_CommandParserSWC_Valid(&valid);
    if (valid) {
        Rte_IRead_CommandParserSWC_LatestCommand(pos);
        return TRUE;
    }
    return FALSE;
}
