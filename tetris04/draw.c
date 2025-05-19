#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "color.h"
#include "cursor.h"
#include "console.h"
#include "cell.h"


//void draw_one_cell(cell_t* cell, uint32_t x, uint32_t y) {
void cell_draw(cell_t* cell, uint32_t x, uint32_t y) {
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


void block_draw(block_t* block) {
    //blk->x = x;
    //blk->y = y;

    // 초기 좌표 설정
    uint32_t initial_x = block->x * 2; // X 좌표는 두 배로 확대
    uint32_t initial_y = block->y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            // 블록 데이터가 있는 경우만 출력
            if (block->att[block->rotation_index][i][j] == 1) {
                setcolor(block->color, BLACK); // 블록 색상 설정
                SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // 커서 위치 설정
                printf("■");
                setcolor(WHITE, BLACK);
            }
            else {
                SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // 빈 셀 위치 설정
                printf("□");
                //printf("  ");
            }
        }
    }

    // 기본 색상으로 복원
    setcolor(WHITE, BLACK);
}

/*old 지우지 말것
void block_draw(const block_t* blk, uint32_t x, uint32_t y) {
    static int tmp_row = 0;
    SetCurrentCursorPos(x*2, y); // 초기 좌표를 잡고
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            if (blk->data[blk->rotation_index][i][j] == 1) {
                setcolor(blk->color, BLACK);
                printf("■");
                setcolor(WHITE, BLACK);
            }
            else {
                printf("□");
            }

        }
        //printf("\r\n");
        SetCurrentCursorPos(x * 2, y + ++tmp_row);
    }
}
*/