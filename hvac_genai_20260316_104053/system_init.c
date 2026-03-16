#include "system_init.h"
#include "Rte_SystemInit.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define SYSTEM_INIT_MODULE_ID 105
#define SYSTEM_INIT_VENDOR_ID 1
#define SYSTEM_INIT_SW_MAJOR_VERSION 1
#define SYSTEM_INIT_SW_MINOR_VERSION 0
#define SYSTEM_INIT_SW_PATCH_VERSION 0

#define SYSTEM_INIT_INSTANCE_ID 0
#define SYSTEM_INIT_API_ID 0x01

#define SYSTEM_INIT_DEV_ERROR_DETECT STD_ON

static boolean SystemInit_Initialized = FALSE;

FUNC(void, SYSTEM_INIT_CODE) System_Init(P2CONST(SystemInit_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (SYSTEM_INIT_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(SYSTEM_INIT_MODULE_ID, SYSTEM_INIT_INSTANCE_ID, SYSTEM_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    SystemInit_Initialized = TRUE;
}
