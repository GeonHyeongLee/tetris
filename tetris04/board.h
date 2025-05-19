#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "cell.h"
#include "console.h"
#include "blocks.h"

#define BOARD_WIDTH     (10 + 2) // 좌우 벽 포함
#define BOARD_HEIGHT    (20 + 1) // 아래 바닥 포함
#define BOARD_START_X   4
#define BOARD_START_Y   4

// 방향 정의
#define DIR_UP      1
#define DIR_DOWN    2
#define DIR_LEFT    3
#define DIR_RIGHT   4

// 외부 전역 보드 및 초기 상태 정의
extern cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH];
extern cell_attributes_t board_data_attributes[BOARD_HEIGHT][BOARD_WIDTH];

// 함수 선언
void board_init(cell_attributes_t data[BOARD_HEIGHT][BOARD_WIDTH]);
void board_display_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_draw(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_clear_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void board_insert_cell(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);
void board_insert_block(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int block_x, int block_y);
void board_move_block(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint8_t dir);
void board_roate_block(block_t* block);

#endif // __BOARD_H__
