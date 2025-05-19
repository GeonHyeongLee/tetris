#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "color.h"
#include "cursor.h"
#include "console.h"

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows);

void console_clear(windows_console_t* console);

void console_set_cursor(windows_console_t* console, uint32_t x, uint32_t y, bool value) {
    console->cursor_info.x = x;
    console->cursor_info.y = y;
    console->cursor_info.is_hide = value;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = !console->cursor_info.is_hide;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }
    else {
        printf("Error: Unable to set console cursor visibility.\n");
    }
}

void console_init(windows_console_t* console) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    console_clear(console);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        console->cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        console->rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        WORD attributes = csbi.wAttributes;
        console->fore_color = attributes & 0x0F;
        console->back_color = (attributes >> 4) & 0x0F;

        console->cursor_info.x = csbi.dwCursorPosition.X;
        console->cursor_info.y = csbi.dwCursorPosition.Y;
        console->cursor_info.is_hide = get_cursor_visibility();

        console_resize(console, console->cols, console->rows);
    }
    else {
        printf("Unable to get console window information.\n");
        console->cursor_info.x = -1;
        console->cursor_info.y = -1;
    }
}

void console_set_size(windows_console_t* console, uint32_t cols, uint32_t rows) {
    console->cols = cols;
    console->rows = rows;

    char dummy_str[128];
    sprintf(dummy_str, "mode con: cols=%d lines=%d", cols, rows);
    system(dummy_str);
}

void console_resize(const windows_console_t* console, uint32_t cols, uint32_t rows) {
    console_set_size((windows_console_t*)console, cols, rows);
}

void console_display_info(const windows_console_t* console) {
    static uint8_t dummy_count = 0;
    printf("This Console information.\r\n");
    printf("[%d] Size (cols,rows) = (%d,%d)\r\n", ++dummy_count, console->cols, console->rows);
    printf("[%d] Colors (fore,back) = (%s,%s)\r\n", ++dummy_count, get_color_string(console->fore_color), get_color_string(console->back_color));
    printf("[%d] Cursor (x,y,hide) = %d,%d,%d)\r\n", ++dummy_count, console->cursor_info.x, console->cursor_info.y, console->cursor_info.is_hide);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore_color | (back_color << 4));
}

void console_set_default_color(windows_console_t* console) {
    console_set_color(console, WHITE, BLACK);
}

void console_set_fill_color(int background_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord = { 0, 0 };
    DWORD count;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }

    DWORD console_size = csbi.dwSize.X * csbi.dwSize.Y;
    WORD attributes = (background_color << 4) | (csbi.wAttributes & 0x0F);
    SetConsoleTextAttribute(hConsole, attributes);

    FillConsoleOutputAttribute(hConsole, attributes, console_size, coord, &count);
    FillConsoleOutputCharacter(hConsole, ' ', console_size, coord, &count);
    SetConsoleCursorPosition(hConsole, coord);
}

void console_clear_region(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    DWORD charsWritten;

    for (uint32_t row = 0; row < height; row++) {
        coord.X = (SHORT)x;
        coord.Y = (SHORT)(y + row);
        FillConsoleOutputCharacter(hConsole, ' ', width, coord, &charsWritten);
    }
}

void console_clear(const windows_console_t* console) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD console_size = 0;
    DWORD chars_written = 0;
    COORD top_left = { 0, 0 };

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        printf("Error: Unable to get console screen buffer info.\n");
        return;
    }

    console_size = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, ' ', console_size, top_left, &chars_written);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, console_size, top_left, &chars_written);
    SetConsoleCursorPosition(hConsole, top_left);
}



#endif
