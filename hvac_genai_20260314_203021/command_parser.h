/* AUTOSAR compliant command_parser.h */
#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Std_Types.h"

#define COMMAND_PARSER_SW_MAJOR_VERSION 1
#define COMMAND_PARSER_SW_MINOR_VERSION 0
#define COMMAND_PARSER_SW_PATCH_VERSION 0

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} command_state_t;

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_Init(void);
FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_ProcessByte(uint8 byte);
FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* COMMAND_PARSER_H */
