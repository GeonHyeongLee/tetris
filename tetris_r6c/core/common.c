#include "common.h"

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 55 * 10000; i++);
    //for (uint32_t i = 0; i < ms * 10; i++);
}