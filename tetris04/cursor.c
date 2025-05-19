#ifndef __CURSOR_H__
#define __CURSOR_H__

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "color.h"
#include "cursor.h"
#include "console.h"
#include "point.h"



// 커서 숨김 여부 확인
bool get_cursor_visibility(void) {
    bool result = true;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        result = cursorInfo.bVisible;
    }
    else {
        printf("Error: Unable to get console cursor visibility.\n");
    }
    return result;
}

// 커서 위치 설정
void SetCurrentCursorPos(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 숨김/표시 설정
void set_cursor_visible(void* console_ptr, bool hide) {
    windows_console_t* console = (windows_console_t*)console_ptr;
    console->cursor_info.is_hide = hide;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = !console->cursor_info.is_hide; // false면 숨김
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
}

point_t GetCurrentCursorPos(void) {
    point_t curr_point; // curPoint 타입이 운영체제 종속적이라서  point_t 타입을 만들어 이식성을 좋게 하려고 했다네요.
    CONSOLE_SCREEN_BUFFER_INFO curr_info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr_info);
    curr_point.x = curr_info.dwCursorPosition.X;
    curr_point.y = curr_info.dwCursorPosition.Y;

    return curr_point;
}

#endif // __CURSOR_H__