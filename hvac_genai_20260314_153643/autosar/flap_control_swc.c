#include "Rte_FlapControlSWC.h"

#define FLAP_CONTROL_SWC_START_SEC_CODE
#include "FlapControlSWC_MemMap.h"

FUNC(Std_ReturnType, FLAP_CONTROL_SWC_CODE) FlapControlSWC_Init(void)
{
    /* Local static instance for state management */
    static flap_control_t flapControlInstance;
    flap_control_init(&flapControlInstance, FLAP_POS_MIN);
    return E_OK;
}

FUNC(Std_ReturnType, FLAP_CONTROL_SWC_CODE) FlapControlSWC_Update(void)
{
    Std_ReturnType ret;
    uint8 cmdPos, fbPos;
    boolean cmdValid, fbValid;
    static flap_control_t flapControlInstance;

    ret = Rte_Read_FlapControlSWC_CommandPosition(&cmdPos);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    ret = Rte_Read_FlapControlSWC_CommandValid(&cmdValid);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    ret = Rte_Read_FlapControlSWC_FeedbackPosition(&fbPos);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    ret = Rte_Read_FlapControlSWC_FeedbackValid(&fbValid);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    if (flap_control_update(&flapControlInstance, cmdPos, cmdValid, fbPos, fbValid)) {
        return E_OK;
    }
    return E_NOT_OK;
}

#define FLAP_CONTROL_SWC_STOP_SEC_CODE
#include "FlapControlSWC_MemMap.h"
