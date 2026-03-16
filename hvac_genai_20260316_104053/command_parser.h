#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Std_Types.h"

#define MAX_POSITIONS 8

typedef struct {
    uint8 latest_command;
    boolean valid;
} CommandParser_Type;

typedef struct {
    uint8 allowed_positions[MAX_POSITIONS];
} CommandParser_ConfigType;

FUNC(void, COMMAND_PARSER_CODE) CommandParser_Init(P2CONST(CommandParser_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);
FUNC(void, COMMAND_PARSER_CODE) CommandParser_ProcessByte(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte);
FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2CONST(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* COMMAND_PARSER_H */
