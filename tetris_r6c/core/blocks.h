#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#include <time.h>
#include "common.h"
#include "cell.h"
//#include "board.h" // qqq 이게 문제가 된다.

#define BLOCK_WIDTH  (4)
#define BLOCK_HEIGHT (4)
#define BLOCK_ROTATION_DIR (4)
#define TETRIS_BLOCK_COUNT 7

//"#define 블럭이화면오른쪽으로갈수있는최대값 100" 이 정의에서 블럭이화면오른쪽으로갈수있는최대값을 뭐라고 작명하면 좋을까?
// 블럭이 오른쪽으로 이동할수 있는 최대값은 단순히 120/2-1이 아니다!
// 블럭 좌상단이 기준점이 되기때문에 -3을 추가로 해줘야 한다.
#define MAX_BLOCK_X_POS ((DEFAULT_CONSOLE_ROWS/2-1)-(BLOCK_WIDTH-1))

// (이전에도 말했지만) y축으로는 /2 해줄 필요없다.
// A는 가로0.5, 세로 1의 비율이지만, ■는 1:1 비율이기 때문이다.
#define MAX_BLOCK_Y_POS ((DEFAULT_CONSOLE_COLS-1)-(BLOCK_HEIGHT-1))

// E = 0 = Empty
// W = 1 = Wall
// 그래서 2부터 시작된다.
typedef enum _block_shapes_t { // 블럭 모양
	//SHAPE_I= 2, // 헷갈리니까 빼는게 좋을거 같은데.. aaa
	SHAPE_I= 2, // 헷갈리니까 빼는게 좋을거 같은데..
	SHAPE_J,
	SHAPE_L,
	SHAPE_O,
	SHAPE_S,
	SHAPE_T,
	SHAPE_Z,
} block_shapes_t;

typedef enum _block_color_t {
	SHAPE_I_COLOR= 3,	// 하늘색 COLOR_CYAN
	SHAPE_J_COLOR= 1,	// 파란색 COLOR_BLUE
	SHAPE_L_COLOR= 12,	// 주황색이 없어서.. COLOR_ORANGE
	SHAPE_O_COLOR= 14,	// 노란색 COLOR_YELLOW
	SHAPE_S_COLOR= 2,	// 초록색 COLOR_GREEN
	SHAPE_T_COLOR= 5,	// 보라색 COLOR_PURPLE
	SHAPE_Z_COLOR= 4	// 빨간색 COLOR_RED
} block_color_t;


// block 데이터 탑입
typedef struct _block_t {
	block_shapes_t shape;	// I,J,L,O,S,T,Z 어느 모양인가?
	int rotation_dir;		// 현재 회전 방향을 저장할 변수 0,1,2,3=0,90,180,270 // rotation_index
	uint8_t data[BLOCK_ROTATION_DIR][BLOCK_HEIGHT][BLOCK_WIDTH]; // 블럭의 데이터
	int x;					// 보드내에서 블럭의 위치 x
	int y;					// 보드내에서 블럭의 위치 y
	block_color_t color;	// 블럭의 색상
	bool fixed;				// fixed=true가 되면 블럭을 움직일수 없다. 	// aaa is_active라고 변수명을 바꾸는것이 나을까요?
	uint32_t lock_delay;	// 충돌후 고정까지 남은 시간 (ms단위)
} block_t;

// aaa 이렇게 만들면 더 좋을듯
//typedef struct _block_t {
//	shapes_t shape;				// I,J,L,O,S,T,Z 어느 모양인가?
//	dirt_t rotation_dir;		// 현재 회전 방향을 저장할 변수 0,1,2,3=0,90,180,270 // rotation_index
//	cell_t data[BLOCK_ROTATION_DIR][BLOCK_HEIGHT][BLOCK_WIDTH]; // 블럭의 데이터
//	pos_t pos;				// 보드내에서 블럭의 위치 x
//	color_t color;	// 블럭의 색상
//	bool fixed;				// fixed=true가 되면 블럭을 움직일수 없다. 	// aaa is_active라고 변수명을 바꾸는것이 나을까요?
//	uint32_t lock_delay;	// 충돌후 고정까지 남은 시간 (ms단위)
//} block_t;


void init_block(block_t* block, block_shapes_t shape, int x, int y);
void print_block_info(const block_t* block, bool option); // 블럭 정보를 화면에 출력한다. optin을 true로하면 블럭의 그래픽 정보도 같이 보여준다.
char* get_block_shape_string(const block_t* block);
// 블럭 shape 정보를 0,1,2,3,..과 같이 갖고 오면, 개발자건 사용자건 1이 뭔지 헷갈리기 때문에 "I","J","L".. 과 같이 돌려준다.
// 보기가 매우 불편하기 때문에 와 같이 갖고 온다. "block I", "block J"와 같이 만들어된다.
char* get_block_color_string(const block_t* block);

//void move_block(block_t* block, dir_t dir); // 주의! dir_t 방향 (Up, Down, Left, Right)으로 이동시킨다.
void rotate_block(block_t* block); // 주의! 회전만 시키고 그리지는 않는다.
//void draw_block(block_t* block); // 블럭의 화면에 출력한다. 이 함수는 console에 그리는데, 나중에 board와 결합하게 되면 쓸모가 없어진다.

void set_block_position(block_t* block, uint32_t x, uint32_t y); // 역시, x,y값만 바뀌고 그리지는 않는다.
void fix_block(block_t* block); // 블럭을 현재 위치에서 고정시킨다.
void unfix_block(block_t* block); // 블럭 고정을 해제한다.
void create_random_block(block_t* block); // 7 개중에서 1개의 랜덤 블럭을 만든다.
// shape만 랜덤으로 뽑고, 나머지는 init_block로 초기화 시키면 된다.


#endif