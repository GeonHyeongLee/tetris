#include "board.h"
#include "cell.h"
#include "console.h"
#include "color.h"
#include "blocks.h"

cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0 };

cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH] = {
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, W, W, W, W, W, W, W, W, W, W, W },
};

void board_init(int data[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            gboard[i][j].point.x = BOARD_START_X + j;
            gboard[i][j].point.y = BOARD_START_Y + i;
            gboard[i][j].att = data[i][j];
            gboard[i][j].color = YELLOW;
        }
    }
}

void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("(%d,%d)", board[i][j].point.x, board[i][j].point.y);
        }
        printf("\r\n");
    }
}

void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir) {
    board_clear_data(board);

    switch (dir) {
    case DIR_UP:    block->y -= 1; break;
    case DIR_DOWN:  block->y += 1; break;
    case DIR_LEFT:  block->x -= 1; break;
    case DIR_RIGHT: block->x += 1; break;
    }

    board_insert_block(board, block, block->x, block->y);
    board_draw(console, gboard);
}

void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            switch (board[i][j].att) {
            case W:
                console_set_fore_color(console, GREEN);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                break;
            case N:
                console_set_fore_color(console, RED);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                break;
            case E:
                console_set_fore_color(console, WHITE);
                cell_draw(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                break;
            }
            console_set_default_color(console);
        }
    }
}

void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y) {
    cell->point.x = cell_x;
    cell->point.y = cell_y;
    board[cell->point.y][cell->point.x].att = cell->att;
}

void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j].att == N) {
                board[i][j].att = E;
            }
        }
    }
}

void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y) {
    block->x = block_x;
    block->y = block_y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            board[block->y + i][block->x + j].att = block->att[block->rotation_index][i][j];
        }
    }
}
