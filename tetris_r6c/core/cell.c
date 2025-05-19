#include "cell.h"

void init_cell(cell_t* cell, int x, int y, cell_att_t att, color_t color) {
    cell->point.x = x;
    cell->point.y = y;
    cell->att = att;
    cell->color = color;
    cell->fixed = false;
}

//void draw_one_cell(cell_t* cell, uint32_t x, uint32_t y) {
void draw_cell(cell_t* cell, uint32_t x, uint32_t y) {
    cell->point.x = x;
    cell->point.y = y;

    COORD pos;
    pos.X = (short)cell->point.x;
    pos.Y = (short)cell->point.y;
    pos.X *= 2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
    printf("■");
}

void cell_test(windows_console_t* console) {
    cell_t my_cell;
    init_cell(&my_cell, 0, 0, I, YELLOW); // 좌표계 점검용 테스트 코드
    
    console_set_fore_color(console, my_cell.color);
    //console->fore_color(my_cell.color);
    draw_cell(&my_cell, 0, 0); // 좌상단
    draw_cell(&my_cell, RESIZE_COLS / 2 - 1, 0); // 우상단
    draw_cell(&my_cell, RESIZE_COLS / 2 - 1, RESIZE_ROWS - 1); // 우하단
    draw_cell(&my_cell, 0, RESIZE_ROWS - 1); // 좌하단
    draw_cell(&my_cell, (RESIZE_COLS / 2 - 1) / 2, (RESIZE_ROWS - 1) / 2); // 정중앙

    console_set_default_color(console);
}

