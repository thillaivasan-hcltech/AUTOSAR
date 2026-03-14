#include "system_init.h"
#include "Rte_SystemInit.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define SYSTEM_INIT_START_SEC_CODE
#include "SystemInit_MemMap.h"

FUNC(Std_ReturnType, SYSTEM_INIT_CODE) SystemInit(uint8 initialPos)
{
    Std_ReturnType ret = E_OK;
    /* Initialize all components */
    CommandParser_Init();
    FeedbackProcessor_Init();
    FlapControl_Init(initialPos);
    MotorDriver_Init();
    LedStatus_Init();
    LedStatus_PowerOk();
    return ret;
}

#define SYSTEM_INIT_STOP_SEC_CODE
#include "SystemInit_MemMap.h"
