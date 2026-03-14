#ifndef FLAP_CONTROL_H
#define FLAP_CONTROL_H

#include "Std_Types.h"

#define FLAP_CONTROL_START_SEC_CODE
#include "flap_control_MemMap.h"

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef enum {
    FLAP_IDLE = 0,
    FLAP_MOVING,
    FLAP_TARGET_REACHED,
    FLAP_FAULT
} flap_state_t;

typedef struct {
    uint8 current_position;
    uint8 target_position;
    boolean in_motion;
    flap_state_t state;
} flap_control_t;

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) flap_control_init(P2VAR(flap_control_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cur_pos);
FUNC(Std_ReturnType, FLAP_CONTROL_CODE) flap_control_update(P2VAR(flap_control_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid);

#define FLAP_CONTROL_STOP_SEC_CODE
#include "flap_control_MemMap.h"

#endif /* FLAP_CONTROL_H */
