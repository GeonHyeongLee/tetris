#ifndef __CELL_H__
#define __CELL_H__

#include "common.h"

#include "console_driver.h"

#include "point.h"
#include "colors.h"

typedef enum _cell_att_t { // cell_attribute_t
	E, // 0 비었음 empty
	W, // 1 벽, 없앨수 없음
	I, // 2번부터는 있는 일반적인 셀인데, 칼라를 표기하기 위해서, 
	J, // 3
	L, // 4
	O, // 5
	S, // 6
	T, // 7
	Z, // 8
	//B, // 향후 확장용 Bomb // 폭탄 셀
	//X, // Shadow // 쉐도우(?) 셀

} cell_att_t;

//typedef enum _cell_att_t { // cell_attribute_t
//	E, // 0 비었음 empty
//	W, // 1 벽, 없앨수 없음
//	N, //  2번부터는 있는 일반적인 셀인데, 칼라를 표기하기 위해서, 
//  B
//} cell_att_t;
// 이렇게 하는게 나을듯
// 색상은 block의 shape 를 보고 칠하는게 나을듯

typedef struct _cell_t {
    point_t point; // cell의 위치
    color_t color; // cell의 색상
    cell_att_t att; // cell의 속성
	bool fixed;
} cell_t;

void init_cell(cell_t* cell, int x, int y, cell_att_t att, color_t color);
//void draw_one_cell(cell_t* cell, uint32_t x, uint32_t y);
void draw_cell(cell_t* cell, uint32_t x, uint32_t y);
void cell_test(windows_console_t* console);

#endif