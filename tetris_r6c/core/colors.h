#ifndef __COLORS_H__
#define __COLORS_H__

//추가적으로 밝은 색상은 해당 값에 8을 더한 값으로 표현됩니다(예: 밝은 파랑은 9).
typedef enum _color_t {
    BLACK, //0
    BLUE, // 1
    GREEN, // 2
    CYAN, // 3
    RED, // 4
    PURPLE, // 5
    YELLOW, // 6
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_PURBPLE,
    LIGHT_YELLOW,
    LIGHT_WHITE,
} color_t;

//typedef enum _block_color_t {
//    BLOCK_E_COLOR, // Empty Cell Color
//    BLOCK_W_COLOR, // Wall Color
//    BLOCK_I_COLOR,
//    BLOCK_J_COLOR, // 3
//    BLOCK_L_COLOR,
//    BLOCK_O_COLOR,
//    BLOCK_S_COLOR,
//    BLOCK_T_COLOR,
//    BLOCK_Z_COLOR,
//} block_color_t;

char* get_color_string(color_t color);

#endif


