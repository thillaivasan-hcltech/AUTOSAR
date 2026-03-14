#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Std_Types.h"

#define COMMAND_PARSER_START_SEC_CODE
#include "command_parser_MemMap.h"

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} command_state_t;

typedef struct {
    uint8 latest_command;
    boolean valid;
    command_state_t state;
} command_parser_t;

extern const uint8 allowed_positions[MAX_POSITIONS];

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_init(P2VAR(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_process_byte(P2VAR(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte);
FUNC(Std_ReturnType, COMMAND_PARSER_CODE) command_parser_get_latest(P2CONST(command_parser_t, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#define COMMAND_PARSER_STOP_SEC_CODE
#include "command_parser_MemMap.h"

#endif /* COMMAND_PARSER_H */
