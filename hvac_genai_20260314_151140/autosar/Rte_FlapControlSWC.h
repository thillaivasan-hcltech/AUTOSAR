#ifndef RTE_FLAPCONTROLSWC_H
#define RTE_FLAPCONTROLSWC_H

#include "Rte_Type.h"

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef enum {
    FLAP_IDLE = 0,
    FLAP_MOVING,
    FLAP_TARGET_REACHED,
    FLAP_FAULT
} flap_state_t;

void FlapControl_Init(uint8 cur_pos);
boolean FlapControl_Update(uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid);

#endif /* RTE_FLAPCONTROLSWC_H */
