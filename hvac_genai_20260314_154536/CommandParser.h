#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Std_Types.h"

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} command_state_t;

extern const uint8 allowed_positions[MAX_POSITIONS];

FUNC(void, COMMANDPARSER_CODE) CommandParser_Init(void);
FUNC(void, COMMANDPARSER_CODE) CommandParser_ProcessByte(void);
FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* COMMANDPARSER_H */
