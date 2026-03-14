/* CommandParser.h - AUTOSAR Compliant Header */

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define COMMANDPARSER_SW_MAJOR_VERSION 1
#define COMMANDPARSER_SW_MINOR_VERSION 0
#define COMMANDPARSER_SW_PATCH_VERSION 0

#define MAX_POSITIONS 8

typedef enum {
    CMD_STATE_INIT = 0,
    CMD_STATE_WAIT_RX,
    CMD_STATE_VALID,
    CMD_STATE_INVALID
} CommandParser_StateType;

typedef struct {
    uint8 latestCommand;
    boolean valid;
    CommandParser_StateType state;
} CommandParser_Type;

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_Init(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_ProcessByte(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte);
FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2CONST(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* COMMANDPARSER_H */
