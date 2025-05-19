#include "stage_info.h"

typedef struct _stage_info_t {
	uint32_t curr_stage_no; // ���� ���� 1,2,3,4,
	uint32_t curr_goal_count; //12 // 12������ ���־� ���� ���������� �Ѿ
	uint32_t next_block_shape; // ���� ��� shape
	//uint32_t score_board[MAX_SCORE];
} stage_info_t;

void init_stage_info(stage_info_t* info) {
	info->curr_stage_no = INIT_STAGE_NO;
	info->curr_goal_count = INIT_GOAL_COUNT;

}

void set_stage_info(stage_info_t* info, uint32_t stage_no, uint32_t goal_count) {
	info->curr_stage_no = stage_no;
	info->curr_goal_count = goal_count;
}

uint32_t get_stage_no(stage_info_t* info) {

}

uint32_t get_stage_goal_count(stage_info_t* info) {

}

uint32_t get_next_block_shape(stage_info_t* info) {

}