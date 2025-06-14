#include <stdio.h>

#include "console_driver.h"

void draw_box(int x, int y, int width, int height, const char* msg) {
    int message_length = (int)strlen(msg); // 메시지 길이

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // 박스 테두리 그리기
            if (i == 0 && j == 0) {
                printf("┌"); // 왼쪽 상단 모서리
            }
            else if (i == 0 && j == width - 1) {
                printf("┐"); // 오른쪽 상단 모서리
            }
            else if (i == height - 1 && j == 0) {
                printf("└"); // 왼쪽 하단 모서리
            }
            else if (i == height - 1 && j == width - 1) {
                printf("┘"); // 오른쪽 하단 모서리
            }
            else if (i == 0 || i == height - 1) {
                printf("─"); // 상단 및 하단 테두리
            }
            else if (j == 0 || j == width - 1) {
                printf("│"); // 좌측 및 우측 테두리
            }
            // 메시지 출력 위치 설정
            else if (i == height / 2 && j >= (width - message_length) / 2 && j < (width - message_length) / 2 + message_length) {
                printf("%c", msg[j - (width - message_length) / 2]);
            }
            else {
                printf(" "); // 박스 내부 빈 공간
            }
        }
        printf("\n");
    }
}


void display_text(windows_console_t* console, char* text, uint32_t x, uint32_t y) {
    COORD pos;
    pos.X = (short)x;
    pos.Y = (short)y;
    pos.X *= 2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
    //printf("■");
    printf("%s", text);
}

void console_set_fill_color(int background_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord = { 0, 0 }; // 콘솔의 시작 위치 (좌상단)
    DWORD count;

    // 현재 콘솔 정보 가져오기
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }

    // 전체 콘솔 크기 계산 (열 * 행)
    DWORD console_size = csbi.dwSize.X * csbi.dwSize.Y;

    // 배경색 설정 (foreground: 검정, background: 파랑)
    WORD attributes = (background_color << 4) | (csbi.wAttributes & 0x0F);
    SetConsoleTextAttribute(hConsole, attributes);

    // 콘솔 화면을 지정된 색으로 채우기
    FillConsoleOutputAttribute(hConsole, attributes, console_size, coord, &count);

    // 콘솔 화면을 공백 문자로 채우기
    FillConsoleOutputCharacter(hConsole, ' ', console_size, coord, &count);

    // 커서를 다시 좌상단으로 이동
    SetConsoleCursorPosition(hConsole, coord);
}


void console_set_fore_color(windows_console_t* console, uint8_t fore_color) {
    console->fore_color = fore_color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore_color);
}

void console_set_back_color(windows_console_t* console, uint8_t back_color) {
    console->back_color = back_color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back_color);
}

void console_set_color(windows_console_t* console, uint8_t fore_color, uint8_t back_color) {
    console->fore_color = fore_color;
    console->back_color = back_color;
    //void console_set_color(unsigned short text, unsigned short back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console->fore_color | (console->back_color << 4));
}

void console_set_default_color(windows_console_t* console) {
    console_set_color(console, WHITE, BLACK);
}




void SetCurrentCursorPos(int x, int y) {
    COORD pos; // = (x, y);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

point_t GetCurrentCursorPos(void) {
    point_t curr_point; // curPoint 타입이 운영체제 종속적이라서  point_t 타입을 만들어 이식성을 좋게 하려고 했다네요.
    CONSOLE_SCREEN_BUFFER_INFO curr_info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr_info);
    curr_point.x = curr_info.dwCursorPosition.X;
    curr_point.y = curr_info.dwCursorPosition.Y;

    return curr_point;
}


//void clearPreviousPosition(int x, int y) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD pos = { x, y };
//    DWORD written;
//    FillConsoleOutputCharacter(hConsole, ' ', 1, pos, &written); // 이전 위치를 공백으로 덮음
//}


void console_clear_region(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    DWORD charsWritten;

    for (int cols = 0; cols < height; cols++) {
        // Implicit casts should not lower precision
        coord.X = (SHORT)x; // coord.X, Y는 SHORT의 범위(-32,768 ~ 32,767) 내에 있어야 한다.
        coord.Y = (SHORT)(y + cols);
        FillConsoleOutputCharacter(hConsole, ' ', width, coord, &charsWritten);
    }
}

void console_clear(const windows_console_t* console) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD console_size = 0;
    DWORD chars_written = 0;
    COORD top_left = { 0, 0 }; // 화면 좌상단 좌표

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) { // 현재 콘솔 정보 가져오기
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }
    console_size = csbi.dwSize.X * csbi.dwSize.Y; // 콘솔의 전체 크기 계산 (열 * 행)
    FillConsoleOutputCharacter(hConsole, ' ', console_size, top_left, &chars_written); // 콘솔 화면을 공백 문자로 채우기
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, console_size, top_left, &chars_written); // 콘솔 화면의 모든 속성을 기본값으로 채우기
    SetConsoleCursorPosition(hConsole, top_left); // 커서를 화면의 좌상단으로 이동
}

void setcolor(unsigned short text, unsigned short back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

// 커서의 숨김,표시 정보를 가져오는 함수
bool get_cursor_visibility(void) {
    bool result = true; // tre가 default
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO cursorInfo;

    // 현재 커서 정보 가져오기
    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        //cursorInfo.bVisible = visible; // TRUE: 표시, FALSE: 숨김
        //SetConsoleCursorInfo(hConsole, &cursorInfo);
        result = cursorInfo.bVisible;
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
    return result;
}

//void console_clear(windows_console_t* console);

void set_cursor_visible(windows_console_t* console, bool hide) {
    console->cursor_info.is_hide = hide;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = console->cursor_info.is_hide; // TRUE: 표시, FALSE: 숨김
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
}

void console_set_cursor(windows_console_t* console, uint32_t x, uint32_t y, bool value) {
    console->cursor_info.x = x;
    console->cursor_info.y = y;
    console->cursor_info.is_hide = value;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = console->cursor_info.is_hide; // TRUE: 표시, FALSE: 숨김
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
}


void init_window_console(windows_console_t* console) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    console_clear(console);

    // STD_OUTPUT_HANDLE을 통해 콘솔 핸들 가져오기
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 콘솔 화면 버퍼 정보 가져오기
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // 현재 콘솔 창의 크기 정보 얻어오기
        console->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        console->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // 현재 콘솔 창의 fore, back 색상 정보 알아오기
        WORD attributes = csbi.wAttributes;
        console->fore_color = attributes & 0x0F;
        console->back_color = (attributes >> 4) & 0x0F;

        // 커서 정보 알아내기
        console->cursor_info.x = csbi.dwCursorPosition.X; // 커서의 X 좌표
        console->cursor_info.y = csbi.dwCursorPosition.Y; // 커서의 Y 좌표

        console->cursor_info.is_hide = get_cursor_visibility();
        //set_cursor_visibility(console->cursor_info.is_hide);

        //console_resize(const windows_console_t * console, uint32_t cols, uint32_t rows) {
        console_resize(console, RESIZE_COLS, RESIZE_ROWS);
    }
    else {
        printf("Unable to get console window information.\n");

        printf("Error: Unable to get console cursor position.\n");
        console->cursor_info.x = -1;
        console->cursor_info.y = -1;
    }
    //printf("cosole (cols,rows)= %d,%d", console->cols, console->rows);

    set_cursor_visible(console, false);
    console_set_fore_color(console, GRAY); // back_color 신경쓰기 귀찮을때, 
    console_set_cursor(console, 0, 0, false);
    console_set_fill_color(BLACK);
}

void console_set_size(windows_console_t* console, uint32_t cols, uint32_t rows) {
    console->cols = cols;
    console->rows = rows;

    uint8_t dummy_str[128] = { 0, };
    sprintf(dummy_str, "mode con: cols=%d lines=%d", console->cols, console->rows);

    system(dummy_str);
    //system("mode con: cols=100 lines=30");//가로크기 100, 세로크기50
    //printf("%s\r\n", dummy_str);

}

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows) {
    console_set_size(console, cols, rows);
}

void console_display_info(const windows_console_t* console) {
    static uint8_t dummy_count = 0;
    printf("This Console information.\r\n");
    printf("[%d] Size (cols,rows) = (%d,%d)\r\n", ++dummy_count, console->cols, console->rows);

    //printf("[%d] Colors (fore,back) = (%d,%d)\r\n", ++dummy_count, console->fore_color, console->back_color);
    printf("[%d] Colors (fore,back) = (%s,%s)\r\n", ++dummy_count, get_color_string(console->fore_color), get_color_string(console->back_color));
    printf("[%d] Cursor (x,y,hide) = %d,%d,%d)\r\n", ++dummy_count, console->cursor_info.x, console->cursor_info.y, console->cursor_info.is_hide);
}