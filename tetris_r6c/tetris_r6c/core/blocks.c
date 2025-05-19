#include <string.h>

#include "blocks.h"

//I, J, L, O, S, T, Z
const char* block_shape_string[TETRIS_BLOCK_COUNT] = {
	"I", // "block I", "block i", "I", "I ����� ���" �� ���� ������� ������ �ȴ�.
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

	//���� �ѱ� �Ѵ� ���ÿ� ����ϰ� �ʹٸ� �ּ� ����
	//"cyan(�ϴû�)",
	//"blue(�Ķ���)",
	//"orange(��Ȳ��)",
	//"yellow(�����)",
	//"green(�ʷϻ�)",
	//"purple(�����)",
	//"red(������)"

	// �ѱ۸� ����ϰ� �ʹٸ� �ּ� ����
	//"�ϴû�",
	//"�Ķ���",
	//"��Ȳ��",
	//"�����",
	//"�ʷϻ�",
	//"�����",
	//"������"
};


// ��� ��Ʈ���� ����� ����� I, J, L, O, S, T, Z 
// Total Blocks Shapes is I(=2), J(=3), L, O, S, T, Z

/*
2. block I
cyan �ϴû�
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Blue �Ķ���

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Orange ������, ��Ȳ��

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Yellow, �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Green ���
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Violet �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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
Red ������

�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
�����  �����  �����  �����
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

// ��� �ʱ�ȭ �Լ�
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
	block->fixed = false; // ���� ���ѳ��� �ʴ´�.
}


//char* get_block_shape_string(block_shapes_t shape) {
char* get_block_shape_string(const block_t* block) {
	if (block->shape >= 0 && block->shape < TETRIS_BLOCK_COUNT) { // ��ȿ�� �������� Ȯ��
		return block_shape_string[block->shape];       // �ش� ��� �̸� ��ȯ
	}
	return "Unknown"; // ��ȿ���� ���� ���̸� �⺻�� ��ȯ
}

//printf("Block Shape: %d\n", get_block_shape_string(block_1.shape));
//printf("Block Color: %d\n", get_block_color(block_1.color));

char* get_block_color_string(const block_t* block) { 
	if (block->shape >= 0 && block->shape < TETRIS_BLOCK_COUNT) { // ��ȿ�� �������� Ȯ��
		return block_color_string[block->color];       // �ش� ��� �̸� ��ȯ
	}
	return "Unknown"; // ��ȿ���� ���� ���̸� �⺻�� ��ȯ
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
//block_rotate(&block_Z); // �Լ��� ������. �ð�������� ����? �ݽð�� ����?
void rotate_block(block_t* block) { // ȸ���� ��Ű�� �׸����� �ʴ´�.
	block->rotation_dir += 1;
	block->rotation_dir %= 4;
}
//ȸ���� �׸� ��� block_draw() �Լ��� ȣ���ؾ� �Ѵ�.
//block_draw(&block_Z, block_Z.x, block_Z.y);


//block_Z.x -= 1;            
//block_draw(&block_Z, block_Z.x, block_Z.y);
//block_set_pos(&block, block_Z.x - 1, block_Z.y);

// ����� x,y ��ǥ�� �̵���Ų��.
// block ������ ������� x,y�� �����ɻ����� ���� �׸����� �ʴ´�.
// ���� �׸��� �ʹٸ� block_draw() �Լ��� ȣ���ؾ� �Ѵ�.



void set_block_position(block_t* block, uint32_t x, uint32_t y) {
	block->x = x;
	block->y = y;

	//����� �ٱ����� �����������(��, �ܼ� ��ǥ 120, 30�� �Ѿ���),
	//����� �����ϰ� �׷����� ������ �̵��� ��������.
	//����� �����ϰ� �׷����� ������ ������� -1 �̸� FFFFFF �� ���� �ٲ�� �����̴�.
	if (block->x <= 0) { block->x = 0; }
	if (block->x >= MAX_BLOCK_X_POS) { block->x = MAX_BLOCK_X_POS; }
	if (block->y <= 0) { block->y = 0; }
	if (block->y >= MAX_BLOCK_Y_POS) { block->y = MAX_BLOCK_Y_POS; }

	// GPT�� ���� ȿ�����̱�
	// x ��ǥ�� 0���� 59 ���̷� ����
	//block->x = (x < 0) ? 0 : (x > 59 ? 59 : x);
	// y ��ǥ�� 0���� 29 ���̷� ����
	//block->y = (y < 0) ? 0 : (y > 29 ? 29 : y);
}

// �߰� ����: �ܼ� ������ �Ѱ����� �ʴ� ������? 
// �ܼ�â�� ����� �ݵ�� 120, 30�� �ƴϱ� ������, �Ʒ��� ���� �ܼ� ������ �Ѱܼ�
// �ִ� �ּ� ����� �˾Ƴ��°��� �� ����� ������
// void block_set_xy(console_t* console, block_t* block, uint32_t x, uint32_t y);
// block�� console���ڸ� ������
// 1. �ڵ常 ����������
// 2. ���� �ڵ�� �ֿܼ� �׸����� �ƴ϶� board�� �׸��� ������
// ���� �ܼ� ������ ���� �ʿ�� ����.
//void blox_set_xy(board_t* board, block_t* block, uint32_t x, uint32_t y);


void block_draw(block_t* block) {
	//blk->x = x;
	//blk->y = y;

	// �ʱ� ��ǥ ����
	uint32_t initial_x = block->x * 2; // X ��ǥ�� �� ��� Ȯ��
	uint32_t initial_y = block->y;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			// ��� �����Ͱ� �ִ� ��츸 ���
			if (block->data[block->rotation_dir][i][j] == 1) {
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

void fix_block(block_t* block) { // ����� ���� ��ġ���� ������Ų��.
	block->fixed = true;
}

void unfix_block(block_t* block) { // ��� ������ �����Ѵ�.
	block->fixed = false;
}

void create_random_block(block_t* block) { // 7 ���߿��� 1���� ���� ����� �����.
	int random_block_shpape= 0;
	srand((unsigned int)time(NULL));

	random_block_shpape = (rand() % TETRIS_BLOCK_COUNT); // 0~6���� �߻�
	random_block_shpape += 2;
	//printf("%d", random_block_shpape); // qqq

	//init_block(block, random_block_shpape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
	// aaa �� �ڵ带 �����Ϸ��� include "board.h"�� �ؾ� �ϴµ� �̶� ��ȯ ���� ������ ������ �߻��Ѵ�.
	// �ٻڴϱ� �ϴ� �Ʒ�ó�� �س��� ���߿� ��������.
	init_block(block, random_block_shpape, 5, 0);
	//void init_block(block_t * block, block_shapes_t shape) {
	//init_block(&block); // ����� �ʱ�ȭ �ϰ�
	//set_block_shape(&block, random_no);
}

