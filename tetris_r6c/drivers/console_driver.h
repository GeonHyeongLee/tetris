#define _CRT_SECURE_NO_WARNINGS

#ifndef __CONSOLE_DRIVER_H__
#define __CONSOLE_DRIVER_H__

#include <Windows.h>
//#include "common.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "colors.h"
#include "point.h"


#define DEFAULT_CONSOLE_ROWS 120
#define DEFAULT_CONSOLE_COLS 30

// 120이 너무 길어 보기 안좋으니 보기좋게 사이즈를 좀 줄이자.
#define RESIZE_COLS (DEFAULT_CONSOLE_ROWS-30) //=90 
#define RESIZE_ROWS 30


    // 콘솔 초기화
    // 콘솔 정보를 console 구조체에 담은후 초기화
#define CONSOLE_BACK_COLOR BLACK
#define CONSOLE_FORE_COLOR WHITE
#define CONSOLE_CURSOR_VISIBLE false
#define CONSOLE_START_POS_X_ON_WINDOW 100
#define CONSOLE_START_POS_Y_ON_WINDOW 100

typedef struct _cursor_info_t {
    uint32_t x;
    uint32_t y;
    bool is_hide;
} cursor_info_t;

typedef struct _windows_console_t {
    uint32_t cols;
    uint32_t rows;

    color_t fore_color;
    color_t back_color;

    cursor_info_t cursor_info;
} windows_console_t;

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);
void console_set_fill_color(int background_color);
void console_set_fore_color(windows_console_t* console, uint8_t fore_color);
void console_set_back_color(windows_console_t* console, uint8_t back_color);
void console_set_color(windows_console_t* console, uint8_t fore_color, uint8_t back_color);
void console_set_default_color(windows_console_t* console);
void SetCurrentCursorPos(int x, int y);
point_t GetCurrentCursorPos(void);

void console_clear_region(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
void setcolor(unsigned short text, unsigned short back);
bool get_cursor_visibility(void); // 커서의 숨김,표시 정보를 가져오는 함수
void console_clear(windows_console_t* console);
void set_cursor_visible(windows_console_t* console, bool hide);
void console_set_cursor(windows_console_t* console, uint32_t x, uint32_t y, bool value);
void init_window_console(windows_console_t* console);
void console_set_size(windows_console_t* console, uint32_t cols, uint32_t rows);
void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);
void console_display_info(const windows_console_t* console);
void draw_box(int x, int y, int width, int height, const char* msg);
//void clearPreviousPosition(int x, int y) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD pos = { x, y };
//    DWORD written;
//    FillConsoleOutputCharacter(hConsole, ' ', 1, pos, &written); // 이전 위치를 공백으로 덮음
//}

void display_text(windows_console_t* console, char* text, uint32_t x, uint32_t y);



#endif