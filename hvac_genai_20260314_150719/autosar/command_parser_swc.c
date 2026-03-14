#include "Rte_CommandParser.h"

void CommandParser_Init(void)
{
    Rte_Write_CommandParser_LatestCommand(0U);
    Rte_Write_CommandParser_Valid(false);
    Rte_Write_CommandParser_State(CMD_STATE_INIT);
}

void CommandParser_ProcessByte(void)
{
    uint8_t byte;
    Rte_Read_CommandParser_ReceivedByte(&byte);
    Rte_Write_CommandParser_State(CMD_STATE_WAIT_RX);
    if (isAllowedCommand(byte)) {
        Rte_Write_CommandParser_LatestCommand(byte);
        Rte_Write_CommandParser_Valid(true);
        Rte_Write_CommandParser_State(CMD_STATE_VALID);
    } else {
        Rte_Write_CommandParser_Valid(false);
        Rte_Write_CommandParser_State(CMD_STATE_INVALID);
    }
}

static bool isAllowedCommand(uint8_t cmd)
{
    const uint8_t allowed_positions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (unsigned int i = 0; i < MAX_POSITIONS; ++i) {
        if (cmd == allowed_positions[i]) {
            return true;
        }
    }
    return false;
}
