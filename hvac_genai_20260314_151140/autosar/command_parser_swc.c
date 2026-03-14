#include "Rte_CommandParserSWC.h"

void CommandParser_Init(void) {
    Rte_IWrite_CommandParserSWC_CommandParser_Init_latestCommand(0U);
    Rte_IWrite_CommandParserSWC_CommandParser_Init_valid(FALSE);
    Rte_IWrite_CommandParserSWC_CommandParser_Init_state(CMD_STATE_INIT);
}

void CommandParser_ProcessByte(uint8 byte) {
    command_state_t state = CMD_STATE_WAIT_RX;
    boolean valid = FALSE;
    uint8 latestCommand = 0U;

    if (IsAllowedCommand(byte)) {
        latestCommand = byte;
        valid = TRUE;
        state = CMD_STATE_VALID;
    } else {
        valid = FALSE;
        state = CMD_STATE_INVALID;
    }

    Rte_IWrite_CommandParserSWC_CommandParser_ProcessByte_latestCommand(latestCommand);
    Rte_IWrite_CommandParserSWC_CommandParser_ProcessByte_valid(valid);
    Rte_IWrite_CommandParserSWC_CommandParser_ProcessByte_state(state);
}

boolean CommandParser_GetLatest(uint8 *pos) {
    boolean valid = FALSE;
    Rte_IRead_CommandParserSWC_CommandParser_GetLatest_valid(&valid);
    if (valid) {
        Rte_IRead_CommandParserSWC_CommandParser_GetLatest_latestCommand(pos);
        return TRUE;
    }
    return FALSE;
}

static boolean IsAllowedCommand(uint8 cmd) {
    const uint8 allowed_positions[MAX_POSITIONS] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (unsigned int i = 0; i < MAX_POSITIONS; ++i) {
        if (cmd == allowed_positions[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
