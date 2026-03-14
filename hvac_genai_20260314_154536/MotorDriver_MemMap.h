#ifdef MOTORDRIVER_START_SEC_CODE
#undef MOTORDRIVER_START_SEC_CODE
#define START_SEC_CODE
#include "MemMap.h"
#endif

#ifdef MOTORDRIVER_STOP_SEC_CODE
#undef MOTORDRIVER_STOP_SEC_CODE
#define STOP_SEC_CODE
#include "MemMap.h"
#endif
