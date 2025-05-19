#include "game_info.h"

void show_key_usage(windows_console_t* console) {

    // debug
    // 지워도 무방하지만 종종 테스트 및 좌표 계산때문에 필요하다.
    // 최종 릴리즈에서 지워도 된다. 보기 불편해서 주석처리했다.
    cell_test(console);


    display_text(console, "Stage: 1", 25, 4); // 현재 스테이지

    display_text(console, "Target Lines: 9", 25, 6); // 없애야할 목표 라인수
    display_text(console, "Cleard Lines: 1", 25, 7); // 자네가 깬 라인수

    display_text(console, "Difficulty: Easy", 25, 9); // 현재 레벨

    display_text(console, "Difficulty: Easy", 25, 9); // 현재 레벨
    display_text(console, "Highest Cleard Line : 123 (Medium)", 25, 10);
    //▲▼◀▶
    display_text(console, "▲", 26, 13); display_text(console, "ㆍUp: Rotate", 30, 13);
    display_text(console, "◀", 25, 14); display_text(console, "ㆍLeft: Left Move", 30, 14);
    display_text(console, "▶", 27, 14); display_text(console, "ㆍRight: Right Move", 30, 15);
    display_text(console, "▼", 26, 15); display_text(console, "ㆍDown: Soft Drop", 30, 16);
    display_text(console, "ㆍSpace: Hard Drop", 30, 17);
    display_text(console, "ㆍESC: Quit", 30, 18);
    display_text(console, "carroty.com", 30, 24);
}

void show_game_demo(windows_console_t* console) {
    //display_text(console, "TETRIS", CENTER_X, CENTER_Y);
    display_text(console, "TETRIS", 15, 15);
}

void show_game_start(windows_console_t* console) {
    display_text(console, "GAME START !!", 15, 15);
}

void show_game_over(windows_console_t* console) {
    display_text(console, "GAME END !!", 15, 15);
}

void show_high_score(windows_console_t* console) {
    display_text(console, "abc 123", 15, 15);
    display_text(console, "xyz 121", 15, 16);
}
