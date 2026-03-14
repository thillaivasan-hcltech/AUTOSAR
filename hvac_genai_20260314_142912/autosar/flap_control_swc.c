#include "Rte_FlapControlSWC.h"

void FlapControl_Init(void)
{
    uint8_t initial_pos;
    Rte_Read_FlapControlSWC_InitialPosition(&initial_pos);
    Rte_Write_FlapControlSWC_CurrentPosition(initial_pos);
    Rte_Write_FlapControlSWC_TargetPosition(initial_pos);
    Rte_Write_FlapControlSWC_InMotion(false);
    Rte_Write_FlapControlSWC_State(FLAP_IDLE);
}

void FlapControl_Update(void)
{
    uint8_t cmd_pos, fb_pos;
    bool cmd_valid, fb_valid;

    Rte_Read_FlapControlSWC_CommandPosition(&cmd_pos);
    Rte_Read_FlapControlSWC_CommandValid(&cmd_valid);
    Rte_Read_FlapControlSWC_FeedbackPosition(&fb_pos);
    Rte_Read_FlapControlSWC_FeedbackValid(&fb_valid);

    if (!cmd_valid || !fb_valid) {
        Rte_Write_FlapControlSWC_InMotion(false);
        Rte_Write_FlapControlSWC_State(FLAP_FAULT);
        return;
    }

    if (cmd_pos != fb_pos) {
        Rte_Write_FlapControlSWC_TargetPosition(cmd_pos);
        Rte_Write_FlapControlSWC_InMotion(true);
        Rte_Write_FlapControlSWC_State(FLAP_MOVING);
    } else {
        Rte_Write_FlapControlSWC_InMotion(false);
        Rte_Write_FlapControlSWC_State(FLAP_TARGET_REACHED);
    }
    Rte_Write_FlapControlSWC_CurrentPosition(fb_pos);
}
