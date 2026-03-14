/* AUTOSAR SWC for Command Parser */
#include "Rte_CommandParser.h"

void Rte_Runnable_CommandParser_Init(void) {
    command_parser_init();
}

void Rte_Runnable_CommandParser_ProcessByte(void) {
    command_parser_process_byte();
}

void Rte_Runnable_CommandParser_GetLatest(void) {
    command_parser_get_latest();
}
