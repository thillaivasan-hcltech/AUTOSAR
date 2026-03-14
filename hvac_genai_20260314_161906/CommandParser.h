#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Std_Types.h"

#define COMMANDPARSER_SW_MAJOR_VERSION 1
#define COMMANDPARSER_SW_MINOR_VERSION 0
#define COMMANDPARSER_SW_PATCH_VERSION 0

#define MAX_POSITIONS 8

FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_Init(void);
FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_ProcessByte(uint8 byte);
FUNC(Std_ReturnType, COMMANDPARSER_CODE) CommandParser_GetLatest(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* COMMANDPARSER_H */
