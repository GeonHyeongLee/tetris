#define _CRT_SECURE_NO_WARNINGS

#include "core/common.h"
#include "config.h"
#include <conio.h>
#include <windows.h>
#include <math.h>  // 로그 함수 사용

#include "drivers/sound_driver.h"
#include "drivers/console_driver.h"
#include "drivers/key_driver.h"

#include "core/point.h"
#include "core/colors.h"
#include "core/blocks.h"
#include "core/board.h"
#include "core/stage_info.h"
#include "core/game_info.h"
#include "core/game_fsm.h"

uint32_t tick_1ms = 0;

#define TASK_TEST_INTERVAL 10
#define DEFAULT_DROP_SPEED 650   // 초기 낙하 간격 (ms)
#define MIN_DROP_INTERVAL 200    // 최소 간격 (ms)


int get_task_move_interval(int level) {
    double k = 150.0; 
    double interval = DEFAULT_DROP_SPEED - k * log2(level + 1);
    if (interval < MIN_DROP_INTERVAL) interval = MIN_DROP_INTERVAL;
    return (int)interval;
}

bool task_move_flag; // 블럭 이동 플래그
bool task_lock_flag; // 디버깅용 플래그

void timer_polling(int level) {
    tick_1ms++;

    int move_interval = get_task_move_interval(level);

    if (tick_1ms % move_interval == 0) task_move_flag = true;
    if (tick_1ms % TASK_TEST_INTERVAL == 0) task_lock_flag = true;

    delay_ms(1); // 1ms 근사 지연
}

int main(void) {
    const char* file_path = "rsc/sounds/sample1.wav";
    play_sound(file_path);

    windows_console_t console;
    init_window_console(&console);
    show_key_usage(&console);

    init_board(cell_att_arr);

    block_t first_block;
    create_random_block(&first_block);
    init_block(&first_block, first_block.shape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
    insert_block_to_board(gboard, &first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);

    key_init();
    uint16_t key_code = 0;
    int level = 0;

    while (!game_over) {
        level++;
        timer_polling(level);

        if (_kbhit()) {
            key_code = get_key_code();
            move_block_by_key_input(&console, gboard, &first_block, key_code);
            update_board(&console, gboard);

            switch (key_code) {
            case KEY_R:
            case KEY_r:
                rotate_block_on_board(gboard, &first_block);
                update_board(&console, gboard);
                break;
            }
        }

        if (task_move_flag) {
            task_move_flag = false;
            move_block_by_key_input(&console, gboard, &first_block, KEY_DOWN);
            update_board(&console, gboard);
        }

        if (block_collision) {
            block_collision = false;
            lock_block_after_delay(gboard, &first_block);
            update_board_with_line_clear(&console, gboard);
            create_random_block(&first_block);
            insert_block_to_board(gboard, &first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
        }
    }

    printf("게임 오버!!!");
    return 0;
}
