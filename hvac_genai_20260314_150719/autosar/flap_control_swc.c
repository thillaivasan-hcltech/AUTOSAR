#include "Rte_FlapControl.h"

void FlapControl_Init(void)
{
    uint8_t cur_pos;
    Rte_Read_FlapControl_CurrentPosition(&cur_pos);
    Rte_Write_FlapControl_CurrentPosition(cur_pos);
    Rte_Write_FlapControl_TargetPosition(cur_pos);
    Rte_Write_FlapControl_InMotion(false);
    Rte_Write_FlapControl_State(FLAP_IDLE);
}

void FlapControl_Update(void)
{
    uint8_t cmd_pos, fb_pos;
    bool cmd_valid, fb_valid;
    Rte_Read_FlapControl_CommandPosition(&cmd_pos);
    Rte_Read_FlapControl_CommandValid(&cmd_valid);
    Rte_Read_FlapControl_FeedbackPosition(&fb_pos);
    Rte_Read_FlapControl_FeedbackValid(&fb_valid);
    bool start_move = false;

    if (!cmd_valid || !fb_valid) {
        Rte_Write_FlapControl_InMotion(false);
        Rte_Write_FlapControl_State(FLAP_FAULT);
        return;
    }

    if (cmd_pos != fb_pos) {
        Rte_Write_FlapControl_TargetPosition(cmd_pos);
        Rte_Write_FlapControl_InMotion(true);
        Rte_Write_FlapControl_State(FLAP_MOVING);
        start_move = true;
    } else {
        Rte_Write_FlapControl_InMotion(false);
        Rte_Write_FlapControl_State(FLAP_TARGET_REACHED);
    }
    Rte_Write_FlapControl_CurrentPosition(fb_pos);
}
