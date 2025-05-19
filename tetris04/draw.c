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
    printf("��");
}


void block_draw(block_t* block) {
    //blk->x = x;
    //blk->y = y;

    // �ʱ� ��ǥ ����
    uint32_t initial_x = block->x * 2; // X ��ǥ�� �� ��� Ȯ��
    uint32_t initial_y = block->y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            // ��� �����Ͱ� �ִ� ��츸 ���
            if (block->att[block->rotation_index][i][j] == 1) {
                setcolor(block->color, BLACK); // ��� ���� ����
                SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // Ŀ�� ��ġ ����
                printf("��");
                setcolor(WHITE, BLACK);
            }
            else {
                SetCurrentCursorPos(initial_x + j * 2, initial_y + i); // �� �� ��ġ ����
                printf("��");
                //printf("  ");
            }
        }
    }

    // �⺻ �������� ����
    setcolor(WHITE, BLACK);
}

/*old ������ ����
void block_draw(const block_t* blk, uint32_t x, uint32_t y) {
    static int tmp_row = 0;
    SetCurrentCursorPos(x*2, y); // �ʱ� ��ǥ�� ���
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            if (blk->data[blk->rotation_index][i][j] == 1) {
                setcolor(blk->color, BLACK);
                printf("��");
                setcolor(WHITE, BLACK);
            }
            else {
                printf("��");
            }

        }
        //printf("\r\n");
        SetCurrentCursorPos(x * 2, y + ++tmp_row);
    }
}
*/