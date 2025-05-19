#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdint.h>
#include <stdbool.h>
#include "color.h"
#include "cursor.h"


typedef struct _windows_console_t {
    uint32_t cols;
    uint32_t rows;

    color_t fore_color;
    color_t back_color;

    cursor_info_t cursor_info;
} windows_console_t;

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);


#endif