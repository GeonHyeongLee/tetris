#include <string.h>

#include "blocks.h"

//I, J, L, O, S, T, Z
const char* block_shape_string[TETRIS_BLOCK_COUNT] = {
	"I", // "block I", "block i", "I", "I 모양의 블럭" 과 같이 마음대로 지으면 된다.
	"J",
	"L",
	"O",
	"S",
	"T",
	"Z"
};

const char* block_color_string[TETRIS_BLOCK_COUNT] = {
	"cyan",
	"blue",
	"orange",
	"yellow",
	"green",
	"purple",
	"red"

	//영문 한글 둘다 동시에 출력하고 싶다면 주석 해제
	//"cyan(하늘색)",
	//"blue(파란색)",
	//"orange(주황색)",
	//"yellow(노란색)",
	//"green(초록색)",
	//"purple(보라색)",
	//"red(빨간색)"

	// 한글만 출력하고 싶다면 주석 해제
	//"하늘색",
	//"파란색",
	//"주황색",
	//"노란색",
	//"초록색",
	//"보라색",
	//"빨간색"
};


// 모든 테트리스 블럭의 모양은 I, J, L, O, S, T, Z 
// Total Blocks Shapes is I(=2), J(=3), L, O, S, T, Z

/*
2. block I
cyan 하늘색
□■□□  □□□□  □□■□  □□□□
□■□□  ■■■■  □□■□  □□□□
□■□□  □□□□  □□■□  ■■■■
□■□□  □□□□  □□■□  □□□□
*/
const uint8_t data_i[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 },
		{ 0, 2, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 2 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	},
	{
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0},
		{ 0, 0, 2, 0}
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 2, 2, 2, 2 },
		{ 0, 0, 0, 0 },
	}
};

/*
3. block J
Blue 파란색

□■□□  ■□□□  □■■□  □□□□
□■□□  ■■■□  □■□□  ■■■□
■■□□  □□□□  □■□□  □□■□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_j[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 3, 3, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 3, 0, 0, 0 },
		{ 3, 3, 3, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 3, 3, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 3, 3, 3, 0 },
		{ 0, 0, 3, 0 },
		{ 0, 0, 0, 0 }
	},
};

/*
4. block L
Orange 오렌지, 주황색

□■□□  □□□□  ■■□□  □□■□
□■□□  ■■■□  □■□□  ■■■□
□■■□  ■□□□  □■□□  □□□□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_l[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 4, 0, 0 },
		{ 0, 4, 0, 0 },
		{ 0, 4, 4, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 4, 4, 4, 0 },
		{ 4, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 4, 4, 0, 0 },
		{ 0, 4, 0, 0 },
		{ 0, 4, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 4, 0 },
		{ 4, 4, 4, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
};


/*
5. block O
Yellow, 노란색
■■□□  ■■□□  ■■□□  ■■□□
■■□□  ■■□□  ■■□□  ■■□□
□□□□  □□□□  □□□□  □□□□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_o[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 5, 5, 0, 0 },
		{ 5, 5, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 5, 5, 0, 0 },
		{ 5, 5, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 5, 5, 0, 0 },
		{ 5, 5, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 5, 5, 0, 0 },
		{ 5, 5, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};

/*
6. block S
Green 녹색
□■■□  ■□□□  □■■□  □■□□
■■□□  ■■□□  ■■□□  □■■□
□□□□  □■□□  □□□□  □□■□
□□□□  □□□□  □□□□  □□□□
*/

const uint8_t data_s[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 6, 6, 0 },
		{ 6, 6, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 6, 0, 0, 0 },
		{ 6, 6, 0, 0 },
		{ 0, 6, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 6, 6, 0 },
		{ 6, 6, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 6, 0, 0 },
		{ 0, 6, 6, 0 },
		{ 0, 0, 6, 0 },
		{ 0, 0, 0, 0 }
	},
};

/*
7. block T
Violet 보라색
□■□□  □■□□  ■■■□  □■□□
■■■□  ■■□□  □■□□  □■■□
□□□□  □■□□  □□□□  □■□□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_t[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 0, 7, 0, 0 },
		{ 7, 7, 7, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 7, 0, 0 },
		{ 7, 7, 0, 0 },
		{ 0, 7, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 7, 7, 7, 0 },
		{ 0, 7, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 7, 0, 0 },
		{ 0, 7, 7, 0 },
		{ 0, 7, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};
/*
8. block Z
Red 빨간색

■■□□  □■□□  ■■□□  □□■□
□■■□  ■■□□  □■■□  □■■□
□□□□  ■□□□  □□□□  □■□□
□□□□  □□□□  □□□□  □□□□
*/
const uint8_t data_z[BLOCK_ROTATION_DIR][BLOCK_WIDTH][BLOCK_HEIGHT] = {
	{
		{ 8, 8, 0, 0 },
		{ 0, 8, 8, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 8, 0, 0 },
		{ 8, 8, 0, 0 },
		{ 8, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 8, 8, 0, 0 },
		{ 0, 8, 8, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 8, 0 },
		{ 0, 8, 8, 0 },
		{ 0, 8, 0, 0 },
		{ 0, 0, 0, 0 }
	},
};

// 블록 초기화 함수
void init_block(block_t* block, block_shapes_t shape, int x, int y) {
    block->shape = shape;

    switch (shape) {
		case SHAPE_I:
			memcpy(block->data, data_i, sizeof(data_i));
			block->color = SHAPE_I_COLOR;
			break;

		case SHAPE_J:
			memcpy(block->data, data_j, sizeof(data_j));
			block->color = SHAPE_J_COLOR;
			break;

		case SHAPE_L:
			memcpy(block->data, data_l, sizeof(data_l));
			block->color = SHAPE_L_COLOR;
			break;

		case SHAPE_O:
			memcpy(block->data, data_o, sizeof(data_o));
			block->color = SHAPE_O_COLOR;
			break;

		case SHAPE_S:
			memcpy(block->data, data_s, sizeof(data_s));
			block->color = SHAPE_S_COLOR;
			break;

		case SHAPE_T:
			memcpy(block->data, data_t, sizeof(data_t));
			block->color = SHAPE_T_COLOR;
			break;

		case SHAPE_Z:
			memcpy(block->data, data_z, sizeof(data_z));
			block->color = SHAPE_Z_COLOR;
			break;
		default:
			break;
    }

	block->x = x;
    block->y = y;
    block->rotation_dir = 0;
	block->fixed = false; // 고정 시켜놓지 않는다.
}


//char* get_block_shape_string(block_shapes_t shape) {
char* get_block_shape_string(const block_t* block) {
	if (block->shape >= 0 && block->shape < TETRIS_BLOCK_COUNT) { // 유효한 범위인지 확인
		return block_shape_string[block->shape];       // 해당 블록 이름 반환
	}
	return "Unknown"; // 유효하지 않은 값이면 기본값 반환
}

//printf("Block Shape: %d\n", get_block_shape_string(block_1.shape));
//printf("Block Color: %d\n", get_block_color(block_1.color));

char* get_block_color_string(const block_t* block) { 
	if (block->shape >= 0 && block->shape < TETRIS_BLOCK_COUNT) { // 유효한 범위인지 확인
		return block_color_string[block->color];       // 해당 블록 이름 반환
	}
	return "Unknown"; // 유효하지 않은 값이면 기본값 반환
}

void print_block_info(const block_t* block, bool option) {
	//printf("Block Shape: %s\n", get_block_string(block->shape));
	////printf("Block Color: %s\n", get_color_string(block->color));
	//printf("Block Color: %d\n", block->color);
	//printf("Block Rotation (%d):\n", block->rotation_index);

	static uint32_t dummy_cnt = 0;
	//printf("[%d] Block (shape,rotation_dir,x,y,color)=(%s,%d,%d,%d,%d)\r\n", \
	//	++dummy_cnt, get_block_shape_string(block), block->rotation_dir, block->x, block->y, block->color \
	//);

	printf("[%d] Block (shape,rotation_dir,x,y,color)=(%s,%d,%d,%d,%s)\r\n", \
		++dummy_cnt, get_block_shape_string(block), block->rotation_dir, block->x, block->y, get_block_color_string(block) \
	);


	if(option==true) {
		for (int i = 0; i < BLOCK_HEIGHT; i++) {
			for (int j = 0; j < BLOCK_WIDTH; j++) {
				printf("%d ", block->data[block->rotation_dir][i][j]);
			}
			printf("\r\n");
		}
	}
	printf("\r\n");
}


//block_Z.rotation_index += 1;
//block_Z.rotation_index %= 4;
//block_rotate(&block_Z); // 함수를 만들자. 시계방향으로 도나? 반시계로 도나?
void rotate_block(block_t* block) { // 회전만 시키고 그리지는 않는다.
	block->rotation_dir += 1;
	block->rotation_dir %= 4;
}
//회전후 그릴 경우 block_draw() 함수를 호출해야 한다.
//block_draw(&block_Z, block_Z.x, block_Z.y);


//block_Z.x -= 1;            
//block_draw(&block_Z, block_Z.x, block_Z.y);
//block_set_pos(&block, block_Z.x - 1, block_Z.y);

// 블럭을 x,y 좌표로 이동시킨다.
// block 내부의 멤버변수 x,y만 수정될뿐이지 새로 그리지는 않는다.
// 새로 그리고 싶다면 block_draw() 함수를 호출해야 한다.



void set_block_position(block_t* block, uint32_t x, uint32_t y) {
	block->x = x;
	block->y = y;

	//블럭이 바깥으로 빠져나갈경우(즉, 콘솔 좌표 120, 30을 넘어갈경우),
	//블럭이 희한하게 그려지기 때문에 이동을 제한하자.
	//블럭이 희한하게 그려지는 이유는 블럭값이 -1 이면 FFFFFF 와 같이 바뀌기 때문이다.
	if (block->x <= 0) { block->x = 0; }
	if (block->x >= MAX_BLOCK_X_POS) { block->x = MAX_BLOCK_X_POS; }
	if (block->y <= 0) { block->y = 0; }
	if (block->y >= MAX_BLOCK_Y_POS) { block->y = MAX_BLOCK_Y_POS; }

	// GPT는 역시 효율적이군
	// x 좌표를 0에서 59 사이로 제한
	//block->x = (x < 0) ? 0 : (x > 59 ? 59 : x);
	// y 좌표를 0에서 29 사이로 제한
	//block->y = (y < 0) ? 0 : (y > 29 ? 29 : y);
}

// 추가 사항: 콘솔 정보를 넘겨주지 않는 이유는? 
// 콘솔창의 사이즈가 반드시 120, 30은 아니기 때문에, 아래와 같이 콘솔 정보를 넘겨서
// 최대 최소 사이즈를 알아내는것이 더 좋기는 하지만
// void block_set_xy(console_t* console, block_t* block, uint32_t x, uint32_t y);
// block에 console인자를 넣으면
// 1. 코드만 복잡해지고
// 2. 최종 코드는 콘솔에 그릴것이 아니라 board에 그리기 때문에
// 굳이 콘솔 정보를 넣을 필요는 없다.
//void blox_set_xy(board_t* board, block_t* block, uint32_t x, uint32_t y);


void block_draw(block_t* block) {
	//blk->x = x;
	//blk->y = y;

	// 초기 좌표 설정
	uint32_t initial_x = block->x * 2; // X 좌표는 두 배로 확대
	uint32_t initial_y = block->y;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			// 블록 데이터가 있는 경우만 출력
			if (block->data[block->rotation_dir][i][j] == 1) {
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

void fix_block(block_t* block) { // 블럭을 현재 위치에서 고정시킨다.
	block->fixed = true;
}

void unfix_block(block_t* block) { // 블럭 고정을 해제한다.
	block->fixed = false;
}

void create_random_block(block_t* block) { // 7 개중에서 1개의 랜덤 블럭을 만든다.
	int random_block_shpape= 0;
	srand((unsigned int)time(NULL));

	random_block_shpape = (rand() % TETRIS_BLOCK_COUNT); // 0~6까지 발생
	random_block_shpape += 2;
	//printf("%d", random_block_shpape); // qqq

	//init_block(block, random_block_shpape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
	// aaa 위 코드를 수행하려면 include "board.h"를 해야 하는데 이때 순환 참조 때문에 에러가 발생한다.
	// 바쁘니까 일단 아래처럼 해놓고 나중에 수정하자.
	init_block(block, random_block_shpape, 5, 0);
	//void init_block(block_t * block, block_shapes_t shape) {
	//init_block(&block); // 블럭을 초기화 하고
	//set_block_shape(&block, random_no);
}