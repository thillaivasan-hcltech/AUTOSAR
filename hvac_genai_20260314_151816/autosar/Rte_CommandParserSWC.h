#ifndef RTE_COMMANDPARSERSWC_H
#define RTE_COMMANDPARSERSWC_H

#include "Rte_Type.h"

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} CommandStateType;

void CommandParserSWC_Init(void);
void CommandParserSWC_ProcessByte(uint8 byte);
boolean CommandParserSWC_GetLatest(uint8 *pos);

#endif /* RTE_COMMANDPARSERSWC_H */
