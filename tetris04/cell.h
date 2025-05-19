#ifndef CELL_H
#define CELL_H

#include <stdint.h>
#include <stdbool.h>
#include "point.h"
#include "color.h"
#include "blocks.h"



typedef struct _cell_t {
    point_t point; // cell�� ��ġ
    color_t color; // cell�� ����
    cell_attributes_t att; // cell�� �Ӽ�
} cell_t;

#endif