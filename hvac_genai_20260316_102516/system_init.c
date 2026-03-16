#include "Rte_SystemInit.h"
#include "SystemInit_MemMap.h"

#define SYSTEMINIT_START_SEC_CODE
#include "SystemInit_MemMap.h"

FUNC(Std_ReturnType, SYSTEMINIT_CODE) System_Init(void) {
    Std_ReturnType ret = E_OK;
    ret |= CommandParser_Init();
    ret |= FeedbackProcessor_Init();
    ret |= FlapControl_Init(0x00U);
    ret |= MotorDriver_Init();
    ret |= LedStatus_Init();
    ret |= LedStatus_PowerOk();
    return ret;
}

#define SYSTEMINIT_STOP_SEC_CODE
#include "SystemInit_MemMap.h"
