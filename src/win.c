#include "drop.h"

void ansi_on() {
    HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dw_mode = 0;
    GetConsoleMode(h_out, &dw_mode);
    dw_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(h_out, dw_mode);
}
void ansi_off() {
    HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dw_mode = 0;
    GetConsoleMode(h_out, &dw_mode);
    dw_mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(h_out, dw_mode);
}