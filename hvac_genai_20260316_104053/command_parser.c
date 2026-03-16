#include "command_parser.h"
#include "Rte_CommandParser.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define COMMAND_PARSER_MODULE_ID 100
#define COMMAND_PARSER_VENDOR_ID 1
#define COMMAND_PARSER_SW_MAJOR_VERSION 1
#define COMMAND_PARSER_SW_MINOR_VERSION 0
#define COMMAND_PARSER_SW_PATCH_VERSION 0

#define COMMAND_PARSER_INSTANCE_ID 0
#define COMMAND_PARSER_INIT_API_ID 0x01
#define COMMAND_PARSER_PROCESS_BYTE_API_ID 0x02
#define COMMAND_PARSER_GET_LATEST_API_ID 0x03

#define COMMAND_PARSER_DEV_ERROR_DETECT STD_ON

static boolean CommandParser_Initialized = FALSE;

FUNC(void, COMMAND_PARSER_CODE) CommandParser_Init(P2CONST(CommandParser_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (COMMAND_PARSER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(COMMAND_PARSER_MODULE_ID, COMMAND_PARSER_INSTANCE_ID, COMMAND_PARSER_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    CommandParser_Initialized = TRUE;
}

FUNC(void, COMMAND_PARSER_CODE) CommandParser_ProcessByte(P2VAR(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 byte) {
    if (inst == NULL_PTR) {
        #if (COMMAND_PARSER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(COMMAND_PARSER_MODULE_ID, COMMAND_PARSER_INSTANCE_ID, COMMAND_PARSER_PROCESS_BYTE_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!CommandParser_Initialized) {
        #if (COMMAND_PARSER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(COMMAND_PARSER_MODULE_ID, COMMAND_PARSER_INSTANCE_ID, COMMAND_PARSER_PROCESS_BYTE_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Process byte logic
}

FUNC(Std_ReturnType, COMMAND_PARSER_CODE) CommandParser_GetLatest(P2CONST(CommandParser_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL_PTR || pos == NULL_PTR) {
        #if (COMMAND_PARSER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(COMMAND_PARSER_MODULE_ID, COMMAND_PARSER_INSTANCE_ID, COMMAND_PARSER_GET_LATEST_API_ID, DET_E_PARAM_POINTER);
        #endif
        return E_NOT_OK;
    }
    if (!CommandParser_Initialized) {
        #if (COMMAND_PARSER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(COMMAND_PARSER_MODULE_ID, COMMAND_PARSER_INSTANCE_ID, COMMAND_PARSER_GET_LATEST_API_ID, DET_E_UNINIT);
        #endif
        return E_NOT_OK;
    }
    // Get latest command logic
    return E_OK;
}
