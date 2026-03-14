/* AUTOSAR SWC for Command Parser */
#include "Rte_SwcCommandParser.h"

void SwcCommandParser_Init(void)
{
    Rte_Write_CommandParserState(CMD_STATE_INIT);
    Rte_Write_LatestCommand(0U);
    Rte_Write_CommandValid(FALSE);
}

void SwcCommandParser_ProcessByte(void)
{
    uint8_t byte;
    boolean isValid = FALSE;
    uint8_t allowedPositions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    Rte_Read_ReceivedByte(&byte);
    for (unsigned int i = 0; i < MAX_POSITIONS; ++i) {
        if (byte == allowedPositions[i]) {
            isValid = TRUE;
            break;
        }
    }
    if (isValid) {
        Rte_Write_LatestCommand(byte);
        Rte_Write_CommandValid(TRUE);
        Rte_Write_CommandParserState(CMD_STATE_VALID);
    } else {
        Rte_Write_CommandValid(FALSE);
        Rte_Write_CommandParserState(CMD_STATE_INVALID);
    }
}

void SwcCommandParser_GetLatestCommand(void)
{
    uint8_t latestCommand;
    boolean isValid;
    Rte_Read_CommandValid(&isValid);
    if (isValid) {
        Rte_Read_LatestCommand(&latestCommand);
        Rte_Write_OutputCommand(latestCommand);
    }
}