/* AUTOSAR SWC for Flap Control */
#include "Rte_SwcFlapControl.h"

void SwcFlapControl_Init(void)
{
    uint8_t initialPos;
    Rte_Read_InitialPosition(&initialPos);
    Rte_Write_CurrentPosition(initialPos);
    Rte_Write_TargetPosition(initialPos);
    Rte_Write_InMotion(FALSE);
    Rte_Write_FlapState(FLAP_IDLE);
}

void SwcFlapControl_Update(void)
{
    uint8_t cmdPos, fbPos;
    boolean cmdValid, fbValid;
    Rte_Read_CommandPosition(&cmdPos);
    Rte_Read_CommandValid(&cmdValid);
    Rte_Read_FeedbackPosition(&fbPos);
    Rte_Read_FeedbackValid(&fbValid);

    if (!cmdValid || !fbValid) {
        Rte_Write_InMotion(FALSE);
        Rte_Write_FlapState(FLAP_FAULT);
        return;
    }

    if (cmdPos != fbPos) {
        Rte_Write_TargetPosition(cmdPos);
        Rte_Write_InMotion(TRUE);
        Rte_Write_FlapState(FLAP_MOVING);
    } else {
        Rte_Write_InMotion(FALSE);
        Rte_Write_FlapState(FLAP_TARGET_REACHED);
    }
    Rte_Write_CurrentPosition(fbPos);
}