#ifndef __BOARD_H__
#define __BOARD_H__

#include "common.h"
#include "console_driver.h"
#include "key_driver.h"
#include "blocks.h"
#include "game_fsm.h"

// 테트리스에서 표준 셀의 크기는 가로 10셀, 세로 20셀이다.
#define BOARD_WIDTH (10 + 2) // 2가 늘어난것은 왼쪽 오른쪽의 벽 셀(Wall Cell)을 표현하기 위함이다.
#define BOARD_HEIGHT (20 + 1) // 1이 늘어난것은 위와 마찬가지로 바닥 셀(Bottom Cell)을 표현하기 위함이다.

// 보드가 콘솔 창에서 시작될 (x,y) 위치를 결정한다.
#define BOARD_START_POS_X_ON_DISPLAY (4)
#define BOARD_START_POS_Y_ON_DISPLAY (4)

// 보드내에서 블럭이 시작할 위치를 결정한다.
// 최상단이므로 Y는 보통 0이 적당하다.
#define BLOCK_START_POS_X_ON_BOARD  ((BOARD_WIDTH-2)/2)
#define BLOCK_START_POS_Y_ON_BOARD  (0)

// ■          ■ // (0,0),(1,0),(2,0),(n,0), ...
// ■          ■ // (0,1),
// ■          ■ // (0,2),
// .............. 
// ■■■■■■■ // (0,n),

typedef enum _dir_t {
    DIR_UP = 1,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} dir_t;

extern cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH]; // aaa 전역 변수가 문제가 된다. 지역 변수로 바꾸자.
extern cell_att_t cell_att_arr[BOARD_HEIGHT][BOARD_WIDTH];


void init_board(cell_att_t data[BOARD_HEIGHT][BOARD_WIDTH]); // 보드를 초기화 하는 함수
void print_board_pos_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // 보드의 x,y정보를 화면에 text로 출력하는 함수
void print_board_att_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
//void clear_board_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);

void insert_block_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int x, int y); // 보드의 x,y위치에 블럭을 삽입하는 함수
bool check_wall_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block); // 벽과의 충돌검사
bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block); // 보드에서 블럭 충돌을 감지하는 함수
void remove_current_block_from_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block);// 보드의 블럭 제거 (기존블럭이 아닌 현재 블럭만 제거한다.)

//void draw_board_from_data(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // 인자로 받은 데이터로 board를 그리는 함수
void update_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // 위 함수와 동일, 이름이 편하다
void update_board_with_line_clear(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // 이 함수는 board를 채워되(위와 동일) 채워져있는 row를 지운다.

// --------------------------------
// 키 입력에 따라 블럭을 움직이는 함수
//bool move_block_by_key_input(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint16_t key_code);
void move_block_by_key_input(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* origin_block, uint16_t key_code);
void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block); // 보드 상에서 블럭을 회전시키는 함수

// aaa 위 함수는 아래와 같이 나누자
// 키 입력은 디바이스 종속적이기 때문이다.
//void move_block_on_board  (cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);
//void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);
//void move_or_rotate_block_on_board_by_key_input : blockd을 move 및 rotate 하는 함수, 이거 이름이 너무 길잖아
//void handle_block_on_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint16_t key_code);

void clear_line_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);

// 디버그용: 셀을 삽입하는 함수
void insert_cell_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);

extern bool block_collision;
#endif