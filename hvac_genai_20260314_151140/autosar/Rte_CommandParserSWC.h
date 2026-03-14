#ifndef RTE_COMMANDPARSERSWC_H
#define RTE_COMMANDPARSERSWC_H

#include "Rte_Type.h"

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} command_state_t;

void CommandParser_Init(void);
void CommandParser_ProcessByte(uint8 byte);
boolean CommandParser_GetLatest(uint8 *pos);

#endif /* RTE_COMMANDPARSERSWC_H */
