#define _CRT_SECURE_NO_WARNINGS

#include "core/common.h" // 공통적으로 사용되는 C 표준 헤더 파일(stdio.h, stdint.h 등)을 불러오자. OS 독립적이다.

#include "config.h"  // 설정 파일은 최 상단에서 불러와야 한다. MCU인지 PC인지를 알아내야 하기 때문에
#include <conio.h> // Windows라면 이 헤더파일을 불러온다.
#include <windows.h>

#include "drivers/sound_driver.h"  // (H/W 및 OS 종속적인) driver 관련 헤더파일을 불러온다.
#include "drivers/console_driver.h"
#include "drivers/key_driver.h"

#include "core/point.h" // 게임 관련 헤더 파일을 불러온다
#include "core/colors.h"
//#include "core/images.h" 
#include "core/blocks.h"
#include "core/board.h"
#include "core/stage_info.h"
#include "core/game_info.h"
#include "core/game_fsm.h"

uint32_t tick_1ms = 0;

#define TASK_MOVE_INTERVAL (DEFAULT_DROP_SPEED-500)
#define TASK_TEST_INTERVAL 10

bool task_move_flag; // 블럭의 이동 플래그
bool task_lock_flag; // 디버그용 플래그
bool user_quit = false;

void timer_polling() {
    tick_1ms++;

    if (tick_1ms % TASK_MOVE_INTERVAL == 0) { task_move_flag = true; }
    if (tick_1ms % TASK_TEST_INTERVAL == 0) { task_lock_flag = true; }
    delay_ms(1); // 정확하게 1ms 가 되지는 않지만, 그렇다고 오차가 매우 심한것은 아니라서 적당히 쓸만하다.
}

void show_big_message(const char* message) {
    system("cls");
    printf("\n\n\n");
    printf("==============================\n");
    printf("                              \n");
    printf("      %s      \n", message);
    printf("                              \n");
    printf("==============================\n");
    Sleep(2000); // 2초 동안 보여줌
}

int main(void) {
    //static uint32_t dummy_move_cnt = 0; // 디버그용: 스케줄링 시간을 출력하기 위한 용도
    //static uint32_t dummy_test_cnt = 0;
    //printf("Game Started...\r\n");

    // 사운드 초기화 및 플레이
    const char* file_path = "rsc/sounds/sample1.wav";
    play_sound(file_path);
    //stop_sound(); // 개발할때는 정신없으니 음악을 꺼놓자.

    // 미구현
    // show_game_demo(&console); // 데모를 보여주면서 동전 입력을 기다리자.

    // 디스플레이(=윈도우 콘솔창) 초기화
    windows_console_t console;
    init_window_console(&console);
    show_key_usage(&console); // 키 입력 정보를 보여준다.    

    // 보드 초기화   
    init_board(cell_att_arr); // 보드 데이터(=벽 정보, 셀 정보 등)를 인자로받아서 보드를 초기화 한다.

    // 디버그용: 함수가 잘 동작하나 테스트 용
    //clear_line_on_board(gboard);
    // 미구현 혹은 덜 구현된 함수 모음
    // draw_next_block(next_block); // 다음 블럭을 보여주기
    //draw_box(25, 20, 20, 6, "Hello, World !!");

    // 디버깅용 테스트용 블럭 설정
    // 개발시 테스트 하기 위한 용도
    // 내가 원하는 특정 블럭(예를 들면 I) 및 좌표 설정을 하기 위한 용도
    // 
    //block_t test_block;
    //#define TEST_BLOCK_SHAPE SHAPE_I
    //#define BLOCK_TEST_POS_X 5
    //#define BLOCK_TEST_POS_Y 0
    //
    //init_block(&test_block, TEST_BLOCK_SHAPE, BLOCK_TEST_POS_X, BLOCK_TEST_POS_Y);
    //rotate_block(&test_block);
    //print_block_info(&test_block, true);
    //insert_block_to_board(gboard, &random_block, BLOCK_TEST_POS_X, BLOCK_TEST_POS_Y); // aaa insert 함수안에 update가 있다. 제거하자. bbb 제거했다.

    block_t first_block;
    create_random_block(&first_block);
    init_block(&first_block, first_block.shape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
    insert_block_to_board(gboard, &first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);

    key_init();
    uint16_t key_code = 0;

    while (!game_over) {
        timer_polling();

        // 키 입력이 있는 경우에만 블럭을 이동시켜야 한다.
        // 이전 코드는 이렇게 짰었는데, key_code값을 계속 읽기때문에 아래 코드가 오동작할수 있다.
        //key_code = get_key_code();
        //move_block_by_key_input(gboard, &test_block, key_code);
        //update_board(&console, gboard);

        if (_kbhit()) { // 키 입력이 있는 경우에만 블럭을 이동시켜야 한다.
            key_code = get_key_code();

            if (key_code == KEY_ESC) {
                show_big_message("게임을 종료합니다!!");
                user_quit = true;
                break;
            }
            move_block_by_key_input(&console, gboard, &first_block, key_code);
            update_board(&console, gboard);

            // 디버그용
            // 키입력은 원래 board에서 받는데, 아래 f(=fixed), c(=create), r(=rotate)는 디버깅 용도이므로 여기에서 코딩했다.
            switch (key_code) {
            //case KEY_F:
            //case KEY_f:// 디버그 용도: 블럭을 현재 위치에서 고정시킨다.
            //    if (first_block.fixed == false) { // 고정되었나? false == 아니오
            //        first_block.fixed = true; // 플래그를 "고정됨"으로 바꾼다.
            //        fix_block(&first_block);  // 블럭을 고정시킨다.

            //    }
            //    else { // 고정되었나? 예
            //        first_block.fixed = false; // 플래그를 "고정되지 않음"으로 바꾼다.
            //        unfix_block(&first_block); // 블럭 고정을 해제한다.
            //    }
            //    break;

            //case KEY_C:
            //case KEY_c: // 디버그 용도: 랜덤으로 블럭을 하나 만든다!
            //    update_board_with_line_clear(&console, gboard);
            //    create_random_block(&first_block); // 7 개중에서 1개의 랜덤 블럭을 만든다.
            //    insert_block_to_board(gboard, &first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD); // aaa insert 함수안에 update가 있다. 제거하자. bbb 제거했다.
            //    break;

            case KEY_R:
            case KEY_r: // 블럭 회전
                rotate_block_on_board(gboard, &first_block); // 반시계방향으로 이동하므로, 왼쪽오른쪽과 같은 인자를 더 줄 필요는 없다.
                update_board(&console, gboard); // aaa rotate 함수안에 update가 있다. 제거하자. bbb 오케이 제거했다.
                break;
            }
        }

        // 참고: 이렇게 코딩할경우 블럭이 GAME_SPEED 만큼 내려오는건 맞지만, 키 입력이 GAME_SPEED 만큼 늦게 입력 받아진다.
        // Sleep(GAME_SPEED); 
        // move_block_by_key_input(&console, gboard, &test_block, KEY_DOWN);
        // 즉 이렇게 하면 안된다는 거지
        // 블럭은 1초간격으로 내려오지만, 키입력을 누를때마다 빠르게 받을수 있어야 한다.        

        if (task_move_flag) {
            task_move_flag = false;
            //printf("[%d] Move !!\r\n", ++dummy_move_cnt);
            move_block_by_key_input(&console, gboard, &first_block, KEY_DOWN);
            update_board(&console, gboard);
        }

        //if (task_lock_flag) {
        //    task_lock_flag = false;
        //    printf("[%d] Test !!\r\n", ++dummy_test_cnt);
        //    void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t * block) {
        //    lock_block_after_delay(gboard, &test_block);
        //}

        if (block_collision) { // 블럭이 충돌되었다면
            block_collision = false;
            lock_block_after_delay(gboard, &first_block);
            update_board_with_line_clear(&console, gboard);
            create_random_block(&first_block); // 7 개중에서 1개의 랜덤 블럭을 만든다.
            insert_block_to_board(gboard, &first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
        }
    }

    if (!user_quit) {
        printf("게임 오버!!!");
    }
 
    return 0;
}