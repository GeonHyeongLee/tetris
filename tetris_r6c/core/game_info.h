#ifndef __GAME_INFO_H__
#define __GAME_INFO_H__
#include "common.h"

#include "console_driver.h"

#define GAME_TITLE "TETRIS"// 게임 타이틀
#define GAME_VER	1// 게임 버전
#define GAME_USAGE "aaabbbccc"// 게임 설명

void show_key_usage(windows_console_t* console);
void show_game_demo(windows_console_t* console);

void show_game_start(windows_console_t* console);
void show_game_over(windows_console_t* console);
void show_high_score(windows_console_t* console);

#endif
