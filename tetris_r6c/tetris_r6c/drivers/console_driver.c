#include <stdio.h>

#include "console_driver.h"

void draw_box(int x, int y, int width, int height, const char* msg) {
    int message_length = (int)strlen(msg); // �޽��� ����

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // �ڽ� �׵θ� �׸���
            if (i == 0 && j == 0) {
                printf("��"); // ���� ��� �𼭸�
            }
            else if (i == 0 && j == width - 1) {
                printf("��"); // ������ ��� �𼭸�
            }
            else if (i == height - 1 && j == 0) {
                printf("��"); // ���� �ϴ� �𼭸�
            }
            else if (i == height - 1 && j == width - 1) {
                printf("��"); // ������ �ϴ� �𼭸�
            }
            else if (i == 0 || i == height - 1) {
                printf("��"); // ��� �� �ϴ� �׵θ�
            }
            else if (j == 0 || j == width - 1) {
                printf("��"); // ���� �� ���� �׵θ�
            }
            // �޽��� ��� ��ġ ����
            else if (i == height / 2 && j >= (width - message_length) / 2 && j < (width - message_length) / 2 + message_length) {
                printf("%c", msg[j - (width - message_length) / 2]);
            }
            else {
                printf(" "); // �ڽ� ���� �� ����
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
    //printf("��");
    printf("%s", text);
}

void console_set_fill_color(int background_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord = { 0, 0 }; // �ܼ��� ���� ��ġ (�»��)
    DWORD count;

    // ���� �ܼ� ���� ��������
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }

    // ��ü �ܼ� ũ�� ��� (�� * ��)
    DWORD console_size = csbi.dwSize.X * csbi.dwSize.Y;

    // ���� ���� (foreground: ����, background: �Ķ�)
    WORD attributes = (background_color << 4) | (csbi.wAttributes & 0x0F);
    SetConsoleTextAttribute(hConsole, attributes);

    // �ܼ� ȭ���� ������ ������ ä���
    FillConsoleOutputAttribute(hConsole, attributes, console_size, coord, &count);

    // �ܼ� ȭ���� ���� ���ڷ� ä���
    FillConsoleOutputCharacter(hConsole, ' ', console_size, coord, &count);

    // Ŀ���� �ٽ� �»������ �̵�
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
    point_t curr_point; // curPoint Ÿ���� �ü�� �������̶�  point_t Ÿ���� ����� �̽ļ��� ���� �Ϸ��� �ߴٳ׿�.
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
//    FillConsoleOutputCharacter(hConsole, ' ', 1, pos, &written); // ���� ��ġ�� �������� ����
//}


void console_clear_region(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    DWORD charsWritten;

    for (int cols = 0; cols < height; cols++) {
        // Implicit casts should not lower precision
        coord.X = (SHORT)x; // coord.X, Y�� SHORT�� ����(-32,768 ~ 32,767) ���� �־�� �Ѵ�.
        coord.Y = (SHORT)(y + cols);
        FillConsoleOutputCharacter(hConsole, ' ', width, coord, &charsWritten);
    }
}

void console_clear(const windows_console_t* console) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD console_size = 0;
    DWORD chars_written = 0;
    COORD top_left = { 0, 0 }; // ȭ�� �»�� ��ǥ

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) { // ���� �ܼ� ���� ��������
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }
    console_size = csbi.dwSize.X * csbi.dwSize.Y; // �ܼ��� ��ü ũ�� ��� (�� * ��)
    FillConsoleOutputCharacter(hConsole, ' ', console_size, top_left, &chars_written); // �ܼ� ȭ���� ���� ���ڷ� ä���
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, console_size, top_left, &chars_written); // �ܼ� ȭ���� ��� �Ӽ��� �⺻������ ä���
    SetConsoleCursorPosition(hConsole, top_left); // Ŀ���� ȭ���� �»������ �̵�
}

void setcolor(unsigned short text, unsigned short back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

// Ŀ���� ����,ǥ�� ������ �������� �Լ�
bool get_cursor_visibility(void) {
    bool result = true; // tre�� default
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO cursorInfo;

    // ���� Ŀ�� ���� ��������
    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        //cursorInfo.bVisible = visible; // TRUE: ǥ��, FALSE: ����
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

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = console->cursor_info.is_hide; // TRUE: ǥ��, FALSE: ����
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

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = console->cursor_info.is_hide; // TRUE: ǥ��, FALSE: ����
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
}


void init_window_console(windows_console_t* console) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    console_clear(console);

    // STD_OUTPUT_HANDLE�� ���� �ܼ� �ڵ� ��������
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // �ܼ� ȭ�� ���� ���� ��������
    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        // ���� �ܼ� â�� ũ�� ���� ������
        console->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        console->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // ���� �ܼ� â�� fore, back ���� ���� �˾ƿ���
        WORD attributes = csbi.wAttributes;
        console->fore_color = attributes & 0x0F;
        console->back_color = (attributes >> 4) & 0x0F;

        // Ŀ�� ���� �˾Ƴ���
        console->cursor_info.x = csbi.dwCursorPosition.X; // Ŀ���� X ��ǥ
        console->cursor_info.y = csbi.dwCursorPosition.Y; // Ŀ���� Y ��ǥ

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
    console_set_fore_color(console, GRAY); // back_color �Ű澲�� ��������, 
    console_set_cursor(console, 0, 0, false);
    console_set_fill_color(BLACK);
}

void console_set_size(windows_console_t* console, uint32_t cols, uint32_t rows) {
    console->cols = cols;
    console->rows = rows;

    uint8_t dummy_str[128] = { 0, };
    sprintf(dummy_str, "mode con: cols=%d lines=%d", console->cols, console->rows);

    system(dummy_str);
    //system("mode con: cols=100 lines=30");//����ũ�� 100, ����ũ��50
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