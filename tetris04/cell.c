#ifndef __CELL_H__
#define __CELL_H__

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "color.h"
#include "cursor.h"
#include "console.h"
#include "cell.h"

#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_COLS 120
#define DEFAULT_ROWS 30

#define RESIZE_COLS (DEFAULT_COLS-30) //=90
#define RESIZE_ROWS 30



void cell_init(cell_t* cell, int x, int y, cell_attributes_t att, color_t color) {
    cell->point.x = x;
    cell->point.y = y;
    cell->att = att;
    cell->color = color;
}

void cell_draw_test(windows_console_t* console) {
    cell_t my_cell;
    cell_init(&my_cell, 0, 0, N, YELLOW); // 좌표계 점검용 테스트 코드
    console_set_fore_color(console, my_cell.color);
    //console->fore_color(my_cell.color);
    cell_draw(&my_cell, 0, 0); // 좌상단
    cell_draw(&my_cell, RESIZE_COLS / 2 - 1, 0); // 우상단
    cell_draw(&my_cell, RESIZE_COLS / 2 - 1, RESIZE_ROWS - 1); // 우하단
    cell_draw(&my_cell, 0, RESIZE_ROWS - 1); // 좌하단
    cell_draw(&my_cell, (RESIZE_COLS / 2 - 1) / 2, (RESIZE_ROWS - 1) / 2); // 정중앙
}

#endif
