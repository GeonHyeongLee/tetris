#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <time.h>
#include "common.h"
#include "cell.h"
//#include "board.h" // qqq �̰� ������ �ȴ�.

#define BLOCK_WIDTH  (4)
#define BLOCK_HEIGHT (4)
#define BLOCK_ROTATION_DIR (4)
#define TETRIS_BLOCK_COUNT 7

//"#define �����ȭ����������ΰ����ִ��ִ밪 100" �� ���ǿ��� �����ȭ����������ΰ����ִ��ִ밪�� ����� �۸��ϸ� ������?
// ����� ���������� �̵��Ҽ� �ִ� �ִ밪�� �ܼ��� 120/2-1�� �ƴϴ�!
// ��� �»���� �������� �Ǳ⶧���� -3�� �߰��� ����� �Ѵ�.
#define MAX_BLOCK_X_POS ((DEFAULT_CONSOLE_ROWS/2-1)-(BLOCK_WIDTH-1))

// (�������� ��������) y�����δ� /2 ���� �ʿ����.
// A�� ����0.5, ���� 1�� ����������, ��� 1:1 �����̱� �����̴�.
#define MAX_BLOCK_Y_POS ((DEFAULT_CONSOLE_COLS-1)-(BLOCK_HEIGHT-1))

// E = 0 = Empty
// W = 1 = Wall
// �׷��� 2���� ���۵ȴ�.
typedef enum _block_shapes_t { // ��� ���
	//SHAPE_I= 2, // �򰥸��ϱ� ���°� ������ ������.. aaa
	SHAPE_I= 2, // �򰥸��ϱ� ���°� ������ ������..
	SHAPE_J,
	SHAPE_L,
	SHAPE_O,
	SHAPE_S,
	SHAPE_T,
	SHAPE_Z,
} block_shapes_t;

typedef enum _block_color_t {
	SHAPE_I_COLOR= 3,	// �ϴû� COLOR_CYAN
	SHAPE_J_COLOR= 1,	// �Ķ��� COLOR_BLUE
	SHAPE_L_COLOR= 12,	// ��Ȳ���� ���.. COLOR_ORANGE
	SHAPE_O_COLOR= 14,	// ����� COLOR_YELLOW
	SHAPE_S_COLOR= 2,	// �ʷϻ� COLOR_GREEN
	SHAPE_T_COLOR= 5,	// ����� COLOR_PURPLE
	SHAPE_Z_COLOR= 4	// ������ COLOR_RED
} block_color_t;


// block ������ ž��
typedef struct _block_t {
	block_shapes_t shape;	// I,J,L,O,S,T,Z ��� ����ΰ�?
	int rotation_dir;		// ���� ȸ�� ������ ������ ���� 0,1,2,3=0,90,180,270 // rotation_index
	uint8_t data[BLOCK_ROTATION_DIR][BLOCK_HEIGHT][BLOCK_WIDTH]; // ����� ������
	int x;					// ���峻���� ����� ��ġ x
	int y;					// ���峻���� ����� ��ġ y
	block_color_t color;	// ����� ����
	bool fixed;				// fixed=true�� �Ǹ� ����� �����ϼ� ����. 	// aaa is_active��� �������� �ٲٴ°��� �������?
	uint32_t lock_delay;	// �浹�� �������� ���� �ð� (ms����)
} block_t;

// aaa �̷��� ����� �� ������
//typedef struct _block_t {
//	shapes_t shape;				// I,J,L,O,S,T,Z ��� ����ΰ�?
//	dirt_t rotation_dir;		// ���� ȸ�� ������ ������ ���� 0,1,2,3=0,90,180,270 // rotation_index
//	cell_t data[BLOCK_ROTATION_DIR][BLOCK_HEIGHT][BLOCK_WIDTH]; // ����� ������
//	pos_t pos;				// ���峻���� ����� ��ġ x
//	color_t color;	// ����� ����
//	bool fixed;				// fixed=true�� �Ǹ� ����� �����ϼ� ����. 	// aaa is_active��� �������� �ٲٴ°��� �������?
//	uint32_t lock_delay;	// �浹�� �������� ���� �ð� (ms����)
//} block_t;


void init_block(block_t* block, block_shapes_t shape, int x, int y);
void print_block_info(const block_t* block, bool option); // ��� ������ ȭ�鿡 ����Ѵ�. optin�� true���ϸ� ����� �׷��� ������ ���� �����ش�.
char* get_block_shape_string(const block_t* block);
// ��� shape ������ 0,1,2,3,..�� ���� ���� ����, �����ڰ� ����ڰ� 1�� ���� �򰥸��� ������ "I","J","L".. �� ���� �����ش�.
// ���Ⱑ �ſ� �����ϱ� ������ �� ���� ���� �´�. "block I", "block J"�� ���� �����ȴ�.
char* get_block_color_string(const block_t* block);

//void move_block(block_t* block, dir_t dir); // ����! dir_t ���� (Up, Down, Left, Right)���� �̵���Ų��.
void rotate_block(block_t* block); // ����! ȸ���� ��Ű�� �׸����� �ʴ´�.
//void draw_block(block_t* block); // ����� ȭ�鿡 ����Ѵ�. �� �Լ��� console�� �׸��µ�, ���߿� board�� �����ϰ� �Ǹ� ���� ��������.

void set_block_position(block_t* block, uint32_t x, uint32_t y); // ����, x,y���� �ٲ�� �׸����� �ʴ´�.
void fix_block(block_t* block); // ����� ���� ��ġ���� ������Ų��.
void unfix_block(block_t* block); // ��� ������ �����Ѵ�.
void create_random_block(block_t* block); // 7 ���߿��� 1���� ���� ����� �����.
void hard_drop(block_t* block); // ���ϴ� ����
// shape�� �������� �̰�, �������� init_block�� �ʱ�ȭ ��Ű�� �ȴ�.


#endif