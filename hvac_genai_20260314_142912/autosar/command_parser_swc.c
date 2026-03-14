#include "Rte_CommandParserSWC.h"

void CommandParser_Init(void)
{
    Rte_Write_CommandParserSWC_LatestCommand(0U);
    Rte_Write_CommandParserSWC_Valid(false);
    Rte_Write_CommandParserSWC_State(CMD_STATE_INIT);
}

void CommandParser_ProcessByte(void)
{
    uint8_t byte;
    Rte_Read_CommandParserSWC_ReceivedByte(&byte);
    Rte_Write_CommandParserSWC_State(CMD_STATE_WAIT_RX);

    const uint8_t allowed_positions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    bool is_allowed = false;
    for (unsigned int i = 0; i < MAX_POSITIONS; ++i) {
        if (byte == allowed_positions[i]) {
            is_allowed = true;
            break;
        }
    }

    if (is_allowed) {
        Rte_Write_CommandParserSWC_LatestCommand(byte);
        Rte_Write_CommandParserSWC_Valid(true);
        Rte_Write_CommandParserSWC_State(CMD_STATE_VALID);
    } else {
        Rte_Write_CommandParserSWC_Valid(false);
        Rte_Write_CommandParserSWC_State(CMD_STATE_INVALID);
    }
}

void CommandParser_GetLatest(uint8_t *pos)
{
    bool valid;
    Rte_Read_CommandParserSWC_Valid(&valid);
    if (valid) {
        Rte_Read_CommandParserSWC_LatestCommand(pos);
    }
}
