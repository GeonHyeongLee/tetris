#include "game_info.h"

void show_key_usage(windows_console_t* console) {

    // debug
    // ������ ���������� ���� �׽�Ʈ �� ��ǥ ��궧���� �ʿ��ϴ�.
    // ���� ������� ������ �ȴ�. ���� �����ؼ� �ּ�ó���ߴ�.
    cell_test(console);


    display_text(console, "Stage: 1", 25, 4); // ���� ��������

    display_text(console, "Target Lines: 9", 25, 6); // ���־��� ��ǥ ���μ�
    display_text(console, "Cleard Lines: 1", 25, 7); // �ڳװ� �� ���μ�

    display_text(console, "Difficulty: Easy", 25, 9); // ���� ����

    display_text(console, "Difficulty: Easy", 25, 9); // ���� ����
    display_text(console, "Highest Cleard Line : 123 (Medium)", 25, 10);
    //��墸��
    display_text(console, "��", 26, 13); display_text(console, "��Up: Rotate", 30, 13);
    display_text(console, "��", 25, 14); display_text(console, "��Left: Left Move", 30, 14);
    display_text(console, "��", 27, 14); display_text(console, "��Right: Right Move", 30, 15);
    display_text(console, "��", 26, 15); display_text(console, "��Down: Soft Drop", 30, 16);
    display_text(console, "��Space: Hard Drop", 30, 17);
    display_text(console, "��ESC: Quit", 30, 18);
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
