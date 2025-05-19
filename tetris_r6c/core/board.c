#include "board.h"


static void draw_board_from_data(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);

cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, }; // 전체 보드 전역 변수

// 블럭의 초기 정보를 갖고 있는 데이터
cell_att_t cell_att_arr[BOARD_HEIGHT][BOARD_WIDTH] = {
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(0,7),(0,8),(0,9),(0,10),(0,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (1,0),(1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(1,7),(1,8),(1,9),(1,10),(1,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (2,0),(2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(2,7),(2,8),(2,9),(2,10),(2,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (3,0),(3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(3,7),(3,8),(3,9),(3,10),(3,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (4,0),(4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(4,7),(4,8),(4,9),(4,10),(4,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (5,0),(5,1),(5,2),(5,3),(5,4),(5,5),(5,6),(5,7),(5,8),(5,9),(5,10),(5,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (6,0),(6,1),(6,2),(6,3),(6,4),(6,5),(6,6),(6,7),(6,8),(6,9),(6,10),(6,11)
    { W, E, E, E, E, E, E, E, E, E, E, W }, // (7,0),(7,1),(7,2),(7,3),(7,4),(7,5),(7,6),(7,7),(7,8),(7,9),(7,10),(7,11)
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, I, J, L, O, S, T, Z, E, I, J, W }, // (18,0),(18,1),(18,2),(18,3),(18,4),(18,5),(18,6),(18,7),(18,8),(18,9),(18,10),(18,11)
    { W, I, J, L, O, S, T, Z, E, I, J, W }, // (19,0),(19,1),(19,2),(19,3),(19,4),(19,5),(19,6),(19,7),(19,8),(19,9),(19,10),(19,11)
    { W, W, W, W, W, W, W, W, W, W, W, W }, // (20,0),(20,1),(20,2),(20,3),(20,4),(20,5),(20,6),(20,7),(20,8),(20,9),(20,10),(20,11)
};

// 디버그용: 블럭을 몇개 쌓아놓은 샘플 데이터
//old: board_init_cell_data
//new: cell_att_board
/*
cell_att_t cell_att_arr[BOARD_HEIGHT][BOARD_WIDTH] = {
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, E, E, E, E, E, E, E, E, E, E, W },
    { W, Z, Z, Z, Z, Z, Z, Z, Z, Z, E, W },
    { W, Z, Z, Z, Z, Z, Z, Z, Z, Z, E, W },
    { W, Z, Z, Z, Z, Z, Z, Z, Z, Z, Z, W },
    { W, Z, Z, Z, Z, Z, Z, Z, Z, E, E, W },
    { W, Z, Z, Z, Z, Z, Z, Z, Z, Z, Z, W },
    { W, W, W, W, W, W, W, W, W, W, W, W },
};
*/

void init_board(cell_att_t data[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            //cell_init(&gboard[i][j], 0, 0, YELLOW);

            // old 이렇게 하면 좋지 않다는 예를 보여주기 위한 나쁜 코드
            //board[i][j].point.x = j;
            //board[i][j].point.y = i;
            //board[i][j].att = E; // 모두 E로 만들면 벽을 그릴때 작성해야 할 코드가 늘어난다.

            gboard[i][j].point.x = BOARD_START_POS_X_ON_DISPLAY + j;
            gboard[i][j].point.y = BOARD_START_POS_Y_ON_DISPLAY + i;
            gboard[i][j].att = data[i][j]; // 별도의 보드 데이터를 만든후 삽입하는게 훨씬
            // 코딩이 간편
            // 보기도 깔끔, 가독성 우수
            // 보드를 수정 하기도 매우 쉽다.
            gboard[i][j].color = YELLOW;
        }
    }
};


// 보드 정보를 출력한다.
// 그런데 그리 유용하지 않은데
// 텍스트로 나와서 보기 불편하고, (10,10,N)
void print_board_pos_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("(%d,%d)", board[i][j].point.x, board[i][j].point.y);
        }
        printf("\r\n");
    }
}

void print_board_att_info(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%d ", board[i][j].att);
        }
        printf("\r\n");
    }
}


// insert 시키려는 블럭위치에 다른 블럭이 존재한다면 충돌이라 판단한다.
// 다른 블럭이 존재한다는 의미는 0이 아니라는 뜻이다.
// 부딪혔니? 아니오 = false = 충돌이 없다!

//이 함수가 좀 잘못된거 같은데
//밑에 블럭이 있다면 항상 true가 나와야 하는데, 안나온다. 수정해보자
// r1
//bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
//    static int dummy_cnt = 0;
//    //bool collision_result = false;
//    // NULL 참조 체크 aaa
//    if (block == NULL) {
//        return true; // NULL 블록은 충돌로 간주
//    }
//
//    // 1. 키 입력에 따른 방향 설정
//    int dx = 0;
//    int dy = 0;
//
//    // (이동할) 새 위치를 저장할 변수
//    int new_x = 0;
//    int new_y = 0;
//
//    // 예를 들어 Z 블럭을 5,5 위치에 놓았다면, 유효한 셀은 아래와 같다.
//    // (5,5) (6,5) (6,6) (7,6)
//    for (int i = 0; i < BLOCK_HEIGHT; i++) { // 블럭의 셀 루프를 돌면서
//        for (int j = 0; j < BLOCK_WIDTH; j++) {
//
//            // 보드 경계를 벗어나는지 확인 aaa 0이 맞는지 수정해야함
//            //if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
//            //    return true; // 경계를 벗어나면 충돌 발생
//            //}
//
//            if (block->data[block->rotation_dir][i][j] == E) {  // 1. 블럭의 셀이 E(=empty)라면 검사할 필요가 없다.
//                continue; 
//            } 
//
//            else if (block->data[block->rotation_dir][i][j] > W) { // 2. 블럭의 셀이 채워져있는 경우 (SHAPE에 따라 2,3,4..일수 있으니까 "> W"로 검사한다.)
//                new_y = block->y + i + dy; // 3. board에서 블럭의 위치를 알아낸다.
//                new_x = block->x + j + dx;
//                //printf("[%d](%d,%d) ", dummy_cnt, new_x, new_y); // 유효한 셀만 잘 추출하는지 출력해보기
//
//                // 주의: 아래와 같이 코딩했는데, 이렇게 하면 안된다.
//                // collision_result를 덮어쓰기 때문에 마지막 셀만 검사한다.
//                // 어떻게 동작하는지 궁금하다면, 주석을 풀고 실행해 보면 된다.
//                //if (board[new_y][new_x].att == E ) { collision_result = false; }
//                //else { collision_result = true; }
//
//                // 충돌이 발생하면 함수를 바로 탈출해야 한다.
//                if (board[new_y][new_x].att != E) { 
//                    return true; 
//                }
//
//                // 참고 코드: 아래와 같이 좌표값으로 계산할수도 있지만, 
//                // 불편하고 번거롭다.
//                //if (new_x < 1 || new_x >= 10 || new_y < 0 || new_y >= 20) {
//                //    collision_result= true; // 충돌 발생
//                //}
//            }
//        }
//    }
//    return false; // 모든 셀이 검사되었고 충돌이 없으면 false 반환
//}

// 벽과의 충돌 검사
//벽 충돌 : 블록이 좌 / 우 / 상단 벽에 닿으면 이동이 차단되지만, 고정되지 않습니다.
bool check_wall_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
    if (block == NULL) {
        printf("유효하지 않은 block 참조 입니다.\r\n");
        return true; // NULL 블록은 충돌로 간주
    }

    int dx = 0; // 키 입력에 따른 방향 설정
    int dy = 0;

    int new_x = 0; // 이동할 새 위치를 저장할 변수
    int new_y = 0;

    for (int col = 0; col < BLOCK_HEIGHT; col++) {
        for (int row = 0; row < BLOCK_WIDTH; row++) {

            if (block->data[block->rotation_dir][col][row] == E) {  // 블럭의 셀이 E(=empty)라면 검사할 필요가 없다.
                continue;
            }
            else if (block->data[block->rotation_dir][col][row] > W) { // 2. 블럭의 셀이 채워져있는 경우 (SHAPE에 따라 2,3,4..일수 있으니까 "> W"로 검사한다.)
                new_y = block->y + col + dy; // 3. board에서 블럭의 위치를 알아낸다.
                new_x = block->x + row + dx;
                
                if ((new_x < 1) || (new_x > BOARD_WIDTH - 2)) {
                    return true;
                }
                if (new_y < 0) {
                    return true;
                }

            }
        }
    }
    return false;
}

// 블록 충돌: 블록이 바닥이나 다른 블록에 닿으면 고정됩니다.
bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {

    // NULL 참조 체크 aaa
    if (block == NULL) { 
        printf("유효하지 않은 block 참조 입니다.\r\n");
        return true; // NULL 블록은 충돌로 간주
    }

    // 1. 키 입력에 따른 방향 설정
    int dx = 0;
    int dy = 0;

    // 이동할 새 위치를 저장할 변수
    int new_x = 0;
    int new_y = 0;

    // 예를 들어 Z 블럭을 5,5 위치에 놓았다면, 유효한 셀은 아래와 같다.
    // (5,5) (6,5) (6,6) (7,6)
    for (int col = 0; col < BLOCK_HEIGHT; col++) { 
        for (int row = 0; row < BLOCK_WIDTH; row++) {

            // 보드 경계를 벗어나는지 확인 aaa 0이 맞는지 수정해야함
            //if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
            //    return true; // 경계를 벗어나면 충돌 발생
            //}

            if (block->data[block->rotation_dir][col][row] == E) {  // 1. 블럭의 셀이 E(=empty)라면 검사할 필요가 없다.
                continue;
            }
            else if (block->data[block->rotation_dir][col][row] > W) { // 2. 블럭의 셀이 채워져있는 경우 (SHAPE에 따라 2,3,4..일수 있으니까 "> W"로 검사한다.)
                new_y = block->y + col + dy; // 3. board에서 블럭의 위치를 알아낸다.
                new_x = block->x + row + dx;
                //printf("[%d](%d,%d) ", dummy_cnt, new_x, new_y); // 유효한 셀만 잘 추출하는지 출력해보기

                // 주의: 아래와 같이 코딩했는데, 이렇게 하면 안된다.
                // collision_result를 덮어쓰기 때문에 마지막 셀만 검사한다.
                // 어떻게 동작하는지 궁금하다면, 주석을 풀고 실행해 보면 된다.
                //if (board[new_y][new_x].att == E ) { collision_result = false; }
                //else { collision_result = true; }
                
                if (board[new_y][new_x].att != E) { // 충돌이 발생하면 함수를 바로 탈출해야 한다.
                    return true;
                }

                // 참고 코드: 아래와 같이 좌표값으로 계산할수도 있지만, 
                // 불편하고 번거롭다.
                //if (new_x < 1 || new_x >= 10 || new_y < 0 || new_y >= 20) {
                //    collision_result= true; // 충돌 발생
                //}
            }
        }
    }
    return false; // 모든 셀이 검사되었고 충돌이 없으므로 false 반환
}

void remove_current_block_from_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
    if (block == NULL) {
        printf("block 참조가 NULL입니다.\r\n");
        return;
    }

    // 1. 키 입력에 따른 방향 설정
    int dx = 0;
    int dy = 0;

    // (이동할) 새 위치를 저장할 변수
    int new_x = 0;
    int new_y = 0;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            //if (block->att[block->rotation_index][i][j] == N) {
            if (block->data[block->rotation_dir][i][j] == E) { continue; } // 1. block의 E(=empty)면 검사할 필요가 없다.
            else {
                new_x = block->x + j + dx; // 2. board에서 블럭의 위치를 알아낸다.
                new_y = block->y + i + dy;
                board[new_y][new_x].att = E;
            }

        }
    }
}

// 충돌검사 추가: 회전할수 있는지 여부를 체크해야 한다. 예 I가 깊게 박혀있을때 회전시킬수가 없다.
// 좌표 보정 누락: 회전으로 인해 경계를 벗어나면 안된다.
// 이는 모두 충돌 검사 함수가 담당한다.
// rotate_block_on_board 은 그냥 회전만 한다.
void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* old_block) {

    // 1. 블럭을 복사해놓는다. 기존 블럭이 어떤 모양인지 모르니까
    block_t copied_block;
    memcpy(&copied_block, old_block, sizeof(block_t));

    // 2. 기존 블럭을 보드에서 제거한다.
    remove_current_block_from_board(board, old_block);

    // 3. 블럭을 회전
    copied_block.rotation_dir += 1;
    copied_block.rotation_dir %= 4;

    // 4. 충돌이 없다면, 회전된 블럭 삽입
    //    충돌이 있다면, 기존의 블럭 삽입 (=즉 회전이 안된다.)
    bool is_collision = false;
    is_collision = check_block_collision_on_board(board, &copied_block); // on rotate
    is_collision ? printf("r충돌") : printf("r안충돌");
       

    if (!is_collision) { // 복사한 블럭(=copied_block)을 board에 넣을때 충돌이 없다면 
        remove_current_block_from_board(board, old_block); // old_block을 보드에서 지우고
        insert_block_to_board(board, &copied_block, copied_block.x, copied_block.y); // new_blockd을 보드에 삽입한다.
        memcpy(old_block, &copied_block, sizeof(block_t)); // old 블럭을 이동된 새로운 블럭으로 갱신한다.
        //update_board(console, board); // 보드를 업데이트한다.
    }
    else {
        remove_current_block_from_board(board, old_block); // old_block을 보드에서 지우고
        insert_block_to_board(board, old_block, old_block->x, old_block->y); // old 블럭을 삽입한다.
        //memcpy(old_block, &copied_block, sizeof(block_t)); // 이 코드를 넣으면 안된다.
        //충돌이 발생한 경우(else 블록), memcpy를 통해 old_block을 copied_block으로 덮어씁니다.
        //copied_block은 충돌이 발생한 유효하지 않은 좌표를 가지고 있으므로, old_block의 좌표가 유효하지 않은 상태로 변경됩니다.
        //결과적으로 다음 이동 시 유효하지 않은 좌표를 기준으로 이동을 시도하여 블럭이 보드에서 사라집니다.
        //update_board(console, board);
    }
}



// 아래 함수와 동일하다.
void update_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    draw_board_from_data(console, board);
}

void update_board_with_line_clear(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    clear_line_on_board(board); // 모두 채워져있는 line을 지운다.
    update_board(console, board); 
}



// 현재 상태의 데이터로 보드를 그린다. 데이터를 삭제하지 않는다.
static void draw_board_from_data(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            switch (board[i][j].att) {
            case E: // 0
                console_set_fore_color(console, WHITE);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case W: // 1
                console_set_fore_color(console, GRAY);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case I:
                console_set_fore_color(console, SHAPE_I_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case J:
                console_set_fore_color(console, SHAPE_J_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case L:
                console_set_fore_color(console, SHAPE_L_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case O:
                console_set_fore_color(console, SHAPE_O_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case S:
                console_set_fore_color(console, SHAPE_S_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case T:
                console_set_fore_color(console, SHAPE_T_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;

            case Z:
                console_set_fore_color(console, SHAPE_Z_COLOR);
                draw_cell(&board[i][j], board[i][j].point.x, board[i][j].point.y);
                console_set_default_color(console);
                break;
            }
        }
    }
}

void insert_cell_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], cell_t* cell, int cell_x, int cell_y) {
    cell->point.x = cell_x;
    cell->point.y = cell_y;
    //printf("cell pos(x,y)=(%d,%d)\r\n", cell->point.x, cell->point.y);
    board[cell->point.y][cell->point.x].att = cell->att;
}

// 블럭을 삽입하는 코드, 충돌체크를 하지 않고 삽입한다. = 잘못된 위치(벽에 걸치기)도 삽입된다.
void insert_block_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int x, int y) {
    if (check_block_collision_on_board(board, block) == true) {  // 블럭을 삽입할수 없다면 게임 오버!
        game_over = true;
        return;
    } 

    block->x = x;
    block->y = y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            // 블록 내부의 cell이 N인지 확인
            //if (block->att[block->rotation_index][i][j] == N) {
            if (block->data[block->rotation_dir][i][j] > W) { // 벽 Wall=2 보다 큰 모든 블럭들은
                int bx = block->x + j; // 보드상의 x 좌표
                int by = block->y + i; // 보드상의 y 좌표

                //printf("(bx,by)=(%d,%d)\r\n", bx, by); // 디버그용
                board[by][bx].att = block->data[block->rotation_dir][i][j];
                //board[by][bx].att = block->shape;
                //board[by][bx].att = block->data;//  block->shape;
                //board[by][bx].att = block->data;//  block->shape;
                // aaa 이게 더 표현이 좋은데? 나중에 이렇게 바꾸자
                //board[by][bx].cell.data = block->cell[block->rotation_dir][i][j].data;
            }
        }
    }
}

// 키 입력을 받아 블럭을 이동시키는 함수
// 키 입력을 받는다.
// 이동한다.
// 충돌이 발생했나?
// 아니오 이동한 좌표 그대로 insert
// 예: 이전 좌표로 재설정

bool block_collision = false;

void move_block_by_key_input(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* origin_block, uint16_t key_code) {
    if (origin_block->fixed == true) return;     // 블럭 속성이 fixed 라면 이동이나 회전을 시킬 필요가 없다.

    // 1. 원래 블럭을 복사해놓고
    block_t copied_block;
    memcpy(&copied_block, origin_block, sizeof(block_t));
    //block_t tmp_block = *block; // 이런것도 된다는데? C에서 이게 된다고?? aaa

    //print_board_att_info(board); // 디버깅용
    // 2. 원본 블럭을 보드에서 제거
    // 보드에서 블럭이 갖고 있는 데이터(예 2,2,0,2,.. )를 제거하는거지, 블럭 자체를 제거하는게 아니다
    remove_current_block_from_board(board, origin_block);
    //update_board(console, board); // 보드를 업데이트한다.
    //print_board_att_info(board);

    switch (key_code) {
        // 릴리즈 버전에서는 블럭을 회전(rotate)하겠지만, 디버깅에서는 블럭을 위로 이동시키자.
        case KEY_UP: // 복사한 블럭을 위(UP)로 이동
            //copied_block.y -= 1; // 키를 위로 이동할때는 이렇게 단순하게 적으면 안되고, 상단을 체크해 줘야 한다.
            // 왜냐면 맨위 라인은 블럭의 충돌을 감지할 어떤 블럭 (예를 들면 W)가 없기 때문이다.
            // 따라서 0 이하로 움직이지 못하게 제한해야 한다.
            if (copied_block.y > 0) { copied_block.y -= 1; }
            //printf("up  (x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_DOWN: // 복사한 블럭을 아래로 한칸씩 이동
            //if (copied_block.y < BOARD_HEIGHT) { copied_block.y += 1; }
            // 설명: 위와 같이 만들어도 되지만, 블럭 충돌함수가 바닥을 감지하기 때문에, 굳이 위와 같이 만들지 않아도 된다.
            // 위와 같이 좌표 계산 방법을 사용할수록 x,y 좌표를 계산해야 하기 때문에 더 머리가 아파진다.
            copied_block.y += 1;
            //printf("down(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_LEFT: // 복사한 블럭을 왼쪽(LEFT)로 이동
            //if (copied_block.x > 1) { copied_block.x -= 1; }
            copied_block.x -= 1;
            //printf("left(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_RIGHT: // 복사한 블럭을 오른쪽으로 이동
            //if (copied_block.x < BOARD_WIDTH) { copied_block.x += 1; }
            copied_block.x += 1;
            //printf("right(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_SPACE: // 블럭을 떨어뜨리기 block hard drop
            // 미구현
            break;
    }

    bool is_wall_collision = false;
    bool is_block_collision = false;

    is_wall_collision= check_wall_collision_on_board(board, &copied_block);    
    is_block_collision = check_block_collision_on_board(board, &copied_block); // on move
    //is_collision ? printf("m충돌")  : printf("m안충돌");

    if (is_wall_collision) {
        printf("벽 충돌!\n");
        insert_block_to_board(board, origin_block, origin_block->x, origin_block->y); // 원래 블럭(=origin_block)을 삽입한다.
        return;
    }

    if (!is_block_collision) { // 복사한 블럭(=copied_block)을 board에 넣을때 충돌이 없다면 
        printf("m안충돌");
        //printf("collision %d: ", is_collision);
        //remove_current_block_from_board(board, origin_block); // old_block을 보드에서 지우고
        insert_block_to_board(board, &copied_block, copied_block.x, copied_block.y); // 보드에 삽입
        memcpy(origin_block, &copied_block, sizeof(block_t)); // 원래 블럭(origin_block)을 카피한 블럭(copied_block)으로 갱신힌다.
    }
    else { // 복사한 블럭을 board에 넣을때 충돌이 있다면
        printf("m충돌");
        block_collision = true;
        //printf("collision %d: ", is_collision);
        //remove_current_block_from_board(board, origin_block); // old_block을 보드에서 지우고
        insert_block_to_board(board, origin_block, origin_block->x, origin_block->y); // 원래 블럭(=origin_block)을 삽입한다.
        //memcpy(old_block, &copied_block, sizeof(block_t)); // 이 코드를 넣으면 안된다.
        //충돌이 발생한 경우(else 블록), memcpy를 통해 old_block을 copied_block으로 덮어씁니다.
        //copied_block은 충돌이 발생한 유효하지 않은 좌표를 가지고 있으므로, old_block의 좌표가 유효하지 않은 상태로 변경됩니다.
        //결과적으로 다음 이동 시 유효하지 않은 좌표를 기준으로 이동을 시도하여 블럭이 보드에서 사라집니다.
    }
}


//void handle_collision(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) { // r1
//    static int lock_delay = 0; // 바닥에 닿은 후 경과 시간
//    const int LOCK_TIME = 80000; // 500ms (0.5초) aaa 시간계산 다시 해야함, 급한대로 대충 50이라 적은것임
//    bool is_collision = false;
//    
//    //static dummy_cnt = 0;
//    //printf("[%d] handle !!", ++dummy_cnt);
//
//    // 부딪혔니? 아니오 = false = 충돌이 없다!
//    // 예쓰 = true = 충돌이 있다!
//    is_collision = check_block_collision_on_board(board, block); // on handle
//    if (is_collision) {  // 충돌이 있다
//        //printf("[%d/%d] lock_delay/LOCK_TIME", lock_delay, LOCK_TIME);
//        lock_delay += 1; // 1ms 단위로 호출된다고 가정
//        if (lock_delay >= LOCK_TIME) {
//            //printf("locked !!");
//            //printf("[%d/%d]", lock_delay, LOCK_TIME);
//            fix_block(block);
//            lock_delay = 0; // 타이머 초기화
//            create_random_block(block);// 새로운 블록 생성
//        }
//    }
//    else {
//        //printf("[%d] unlock", lock_delay);
//        lock_delay = 0; // 충돌하지 않으면 타이머 초기화
//    }
//}

#define LOCK_TIME 50000
// 충돌 다루기 함수
// 블럭이 고정되었는가? 일정 시간이 지난후 블럭을 고정시키기 여부를 돌려주는 함수
void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block) {
    if (block->fixed) return;

    bool is_collision = check_block_collision_on_board(board, block);

    if (is_collision) {
        block->lock_delay += 1; // 10ms 단위로 증가 (게임 루프 주기와 일치)
        if (block->lock_delay >= LOCK_TIME) {
            block->fixed = true;
            block->lock_delay = 0;
            //printf("yy블록 고정!\n");
            printf("yyyyyyyy\n");
        }
        else {
            block->fixed = false;
            block->lock_delay = 0;
        }
    }
}

// 요청한 row의 줄에 0이 있느냐 없느냐
// 있다  clear할 라인이 아니다
// 없다 clear할 라인이다.
// 참고: 아래와 같이 짜서는 안된다.
// Loops with at most one iteration should be refactored
//bool is_row_empty(const cell_t row[]) {
//    for (int col = 1; col < 11; col++) {
//        if (row[col].att == E) { return true; }// 0이 있다면? 이 row는 무조건 full 된것이 루프 종료
//        else { // row에 뭔가 셀이 있다!
//            //printf("%d ", row[col].att); 
//            return true;
//        }
//    }
//}

bool is_row_full(const cell_t row[]) {
    for (int col = 1; col < 11; col++) {
        if (row[col].att == E) { return false; }// 0이 있다면? 이 row는 무조건 full이 아니므로 종료
    }
    return true; // 루프가 모두 끝났다는건 0이 없다는 거다. 고로 full이란 뜻이지
}

// 디버깅: Empty 든지, Filled이든지 row를 모두 출력하는 함수
void print_row(const cell_t row[]) {
}

// 디버깅: E가 없는 row를 모두 출력하는 함수
void print_non_empty_row(const cell_t row[]) {
    for (int col = 1; col < 11; col++) {
        if (row[col].att == E) { continue; }
        else {
            printf("%d ", row[col].att);
        }
    }
    printf("\r\n");
}


/*

함수 이름 후보: check_line_and_delete

// 보드 내에서 해당 row의 블럭이 모두 채워져있다면, 해당 라인을 지운다.
□□□□□□□□□□ 
■■■■■■■■■□
■■■■■■■■■■ // 모두 채워져 있다. !지운다.

지운후 블럭을 모두 내려야 한다.
□□□□□□□□□□ 
□□□□□□□□□□
■■■■■■■■■□ // 블럭을 내린다.


그리고 위의 모든 블럭을 아래로 내린다.
x  좌표 (1,0)~(10,0)
y 좌표 (1,0)~(1,19)
(1,19)~10,19
*/
void clear_line_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {

    //for (int row_index = 0; row_index < 20; row_index++) { // 위에서 부터 검사
    for (int row_index = BOARD_HEIGHT - 2; row_index >= 1; row_index--) { // 아래서부터 검사 qqq 차이가 있나?
        //print_non_empty_row(board[row_index]); // 디버깅
        if (!is_row_full(board[row_index])) { // 가득찼니? (false= 아니오) 건너뛴다.
            continue;
        }
        // 해당 라인이 full이라면, 해당 라인을 지우자.
        // 1. 가득 찬 라인 지우기 = 컬럼 1~10을 E로 채운다. 주의! 0과 11은 벽(=Wall)이기 때문에 지워서는 안된다.
        else { 
            //printf("d(%d) ", row_index); // 디버깅용
            for (int col = 1; col < 11; col++) {
                board[row_index][col].att = E;
            }

            // 2. 위에 있는 모든 블록을 한 칸 아래로 이동
            // 전체 루프를 돌면서 블럭의 하단이 비어있다면 블럭을 내린다.
            //예 : 5번 라인을 지우면 4번 라인 → 5번 라인, 3번 라인 → 4번 라인으로 복사한다.
            for (int r = row_index; r > 0; r--) {
                for (int col = 1; col < 11; col++) {
                    board[r][col].att = board[r - 1][col].att; // 윗줄을 현재 줄로 복사
                }
            }
            // 3. 최상단 줄을 빈 상태로 초기화
            // 가장 위쪽 라인(0번)을 빈 상태로 초기화합니다.
            for (int col = 1; col < 11; col++) {
                board[0][col].att = E;
            }

            // 4. 이동 후 동일한 row_index를 다시 검사하기 위해 인덱스 조정
            // (새로 내려온 블록이 또 가득 찼을 수 있음)
            //인덱스 조정 :
            //라인을 지우고 블록을 내린 후, 동일한 row_index를 다시 검사합니다.
            //예 : 5번 라인을 지우고 블록을 내리면, 새로운 블록이 5번 라인에 위치할 수 있으므로 재검사가 필요합니다.
            row_index++; // 중요: 라인을 지우고 내린 후 현재 라인 재검사
        }
    }
}