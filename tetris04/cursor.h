#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include <stdbool.h>


typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;


#endif