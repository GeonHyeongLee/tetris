#ifndef __BOARD_H__
#define __BOARD_H__

#include "common.h"
#include "console_driver.h"
#include "key_driver.h"
#include "blocks.h"
#include "game_fsm.h"

// ��Ʈ�������� ǥ�� ���� ũ��� ���� 10��, ���� 20���̴�.
#define BOARD_WIDTH (10 + 2) // 2�� �þ���� ���� �������� �� ��(Wall Cell)�� ǥ���ϱ� �����̴�.
#define BOARD_HEIGHT (20 + 1) // 1�� �þ���� ���� ���������� �ٴ� ��(Bottom Cell)�� ǥ���ϱ� �����̴�.

// ���尡 �ܼ� â���� ���۵� (x,y) ��ġ�� �����Ѵ�.
#define BOARD_START_POS_X_ON_DISPLAY (4)
#define BOARD_START_POS_Y_ON_DISPLAY (4)

// ���峻���� ����� ������ ��ġ�� �����Ѵ�.
// �ֻ���̹Ƿ� Y�� ���� 0�� �����ϴ�.
#define BLOCK_START_POS_X_ON_BOARD  ((BOARD_WIDTH-2)/2)
#define BLOCK_START_POS_Y_ON_BOARD  (0)

// ��          �� // (0,0),(1,0),(2,0),(n,0), ...
// ��          �� // (0,1),
// ��          �� // (0,2),
// .............. 
// �������� // (0,n),

typedef enum _dir_t {
    DIR_UP = 1,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} dir_t;

extern cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH]; // aaa ���� ������ ������ �ȴ�. ���� ������ �ٲ���.
extern cell_att_t cell_att_arr[BOARD_HEIGHT][BOARD_WIDTH];


void init_board(cell_att_t data[BOARD_HEIGHT][BOARD_WIDTH]); // ���带 �ʱ�ȭ �ϴ� �Լ�
void print_board_pos_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // ������ x,y������ ȭ�鿡 text�� ����ϴ� �Լ�
void print_board_att_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
//void clear_board_data(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);

void insert_block_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int x, int y); // ������ x,y��ġ�� ����� �����ϴ� �Լ�
bool check_wall_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block); // ������ �浹�˻�
bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block); // ���忡�� ��� �浹�� �����ϴ� �Լ�
void remove_current_block_from_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block);// ������ ��� ���� (��������� �ƴ� ���� ����� �����Ѵ�.)

//void draw_board_from_data(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // ���ڷ� ���� �����ͷ� board�� �׸��� �Լ�
void update_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // �� �Լ��� ����, �̸��� ���ϴ�
void update_board_with_line_clear(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]); // �� �Լ��� board�� ä����(���� ����) ä�����ִ� row�� �����.

// --------------------------------
// Ű �Է¿� ���� ����� �����̴� �Լ�
//bool move_block_by_key_input(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint16_t key_code);
void move_block_by_key_input(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* origin_block, uint16_t key_code);
void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block); // ���� �󿡼� ����� ȸ����Ű�� �Լ�

// aaa �� �Լ��� �Ʒ��� ���� ������
// Ű �Է��� ����̽� �������̱� �����̴�.
//void move_block_on_board  (cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);
//void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);
//void move_or_rotate_block_on_board_by_key_input : blockd�� move �� rotate �ϴ� �Լ�, �̰� �̸��� �ʹ� ���ݾ�
//void handle_block_on_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, uint16_t key_code);

void clear_line_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);
void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block);

// ����׿�: ���� �����ϴ� �Լ�
void insert_cell_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y);

extern bool block_collision;
#endif