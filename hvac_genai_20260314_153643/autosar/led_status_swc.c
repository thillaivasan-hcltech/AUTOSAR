#include "Rte_LedStatusSWC.h"

#define LED_STATUS_SWC_START_SEC_CODE
#include "LedStatusSWC_MemMap.h"

FUNC(Std_ReturnType, LED_STATUS_SWC_CODE) LedStatusSWC_Init(void)
{
    /* Local static instance for state management */
    static led_status_t ledStatusInstance;
    led_status_init(&ledStatusInstance);
    led_status_power_ok(&ledStatusInstance);
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_SWC_CODE) LedStatusSWC_SetPosition(void)
{
    Std_ReturnType ret;
    uint8 position;
    static led_status_t ledStatusInstance;

    ret = Rte_Read_LedStatusSWC_CurrentPosition(&position);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    led_status_set_position(&ledStatusInstance, position);
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_SWC_CODE) LedStatusSWC_Error(void)
{
    static led_status_t ledStatusInstance;
    led_status_error(&ledStatusInstance);
    return E_OK;
}

#define LED_STATUS_SWC_STOP_SEC_CODE
#include "LedStatusSWC_MemMap.h"
