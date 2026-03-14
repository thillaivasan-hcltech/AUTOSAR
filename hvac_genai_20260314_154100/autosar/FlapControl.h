#ifndef FLAPCONTROL_H
#define FLAPCONTROL_H

#include "Std_Types.h"

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef enum {
    FLAP_IDLE = 0,
    FLAP_MOVING,
    FLAP_TARGET_REACHED,
    FLAP_FAULT
} flap_state_t;

FUNC(void, FLAPCONTROL_CODE) FlapControl_Init(void);
FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(void);

#endif /* FLAPCONTROL_H */
