#include "Rte_FlapControlSWC.h"

void FlapControlSWC_Init(uint8 cur_pos)
{
    Rte_IWrite_FlapControlSWC_CurrentPosition(cur_pos);
    Rte_IWrite_FlapControlSWC_TargetPosition(cur_pos);
    Rte_IWrite_FlapControlSWC_InMotion(FALSE);
    Rte_IWrite_FlapControlSWC_State_FLAP_IDLE();
}

boolean FlapControlSWC_Update(uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid)
{
    boolean startMove = FALSE;
    if (!cmd_valid || !fb_valid) {
        Rte_IWrite_FlapControlSWC_InMotion(FALSE);
        Rte_IWrite_FlapControlSWC_State_FLAP_FAULT();
        return FALSE;
    }
    if (cmd_pos != fb_pos) {
        Rte_IWrite_FlapControlSWC_TargetPosition(cmd_pos);
        Rte_IWrite_FlapControlSWC_InMotion(TRUE);
        Rte_IWrite_FlapControlSWC_State_FLAP_MOVING();
        startMove = TRUE;
    } else {
        Rte_IWrite_FlapControlSWC_InMotion(FALSE);
        Rte_IWrite_FlapControlSWC_State_FLAP_TARGET_REACHED();
    }
    Rte_IWrite_FlapControlSWC_CurrentPosition(fb_pos);
    return startMove;
}
