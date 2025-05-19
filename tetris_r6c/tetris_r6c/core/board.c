#include "board.h"


static void draw_board_from_data(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]);


cell_t gboard[BOARD_HEIGHT][BOARD_WIDTH] = { 0, }; // ��ü ���� ���� ����

// ����� �ʱ� ������ ���� �ִ� ������
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

// ����׿�: ����� � �׾Ƴ��� ���� ������
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

            // old �̷��� �ϸ� ���� �ʴٴ� ���� �����ֱ� ���� ���� �ڵ�
            //board[i][j].point.x = j;
            //board[i][j].point.y = i;
            //board[i][j].att = E; // ��� E�� ����� ���� �׸��� �ۼ��ؾ� �� �ڵ尡 �þ��.

            gboard[i][j].point.x = BOARD_START_POS_X_ON_DISPLAY + j;
            gboard[i][j].point.y = BOARD_START_POS_Y_ON_DISPLAY + i;
            gboard[i][j].att = data[i][j]; // ������ ���� �����͸� ������ �����ϴ°� �ξ�
            // �ڵ��� ����
            // ���⵵ ���, ������ ���
            // ���带 ���� �ϱ⵵ �ſ� ����.
            gboard[i][j].color = YELLOW;
        }
    }
};


// ���� ������ ����Ѵ�.
// �׷��� �׸� �������� ������
// �ؽ�Ʈ�� ���ͼ� ���� �����ϰ�, (10,10,N)
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


// insert ��Ű���� �����ġ�� �ٸ� ����� �����Ѵٸ� �浹�̶� �Ǵ��Ѵ�.
// �ٸ� ����� �����Ѵٴ� �ǹ̴� 0�� �ƴ϶�� ���̴�.
// �ε�����? �ƴϿ� = false = �浹�� ����!

//�� �Լ��� �� �߸��Ȱ� ������
//�ؿ� ����� �ִٸ� �׻� true�� ���;� �ϴµ�, �ȳ��´�. �����غ���
// r1
//bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
//    static int dummy_cnt = 0;
//    //bool collision_result = false;
//    // NULL ���� üũ aaa
//    if (block == NULL) {
//        return true; // NULL ����� �浹�� ����
//    }
//
//    // 1. Ű �Է¿� ���� ���� ����
//    int dx = 0;
//    int dy = 0;
//
//    // (�̵���) �� ��ġ�� ������ ����
//    int new_x = 0;
//    int new_y = 0;
//
//    // ���� ��� Z ����� 5,5 ��ġ�� ���Ҵٸ�, ��ȿ�� ���� �Ʒ��� ����.
//    // (5,5) (6,5) (6,6) (7,6)
//    for (int i = 0; i < BLOCK_HEIGHT; i++) { // ����� �� ������ ���鼭
//        for (int j = 0; j < BLOCK_WIDTH; j++) {
//
//            // ���� ��踦 ������� Ȯ�� aaa 0�� �´��� �����ؾ���
//            //if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
//            //    return true; // ��踦 ����� �浹 �߻�
//            //}
//
//            if (block->data[block->rotation_dir][i][j] == E) {  // 1. ����� ���� E(=empty)��� �˻��� �ʿ䰡 ����.
//                continue; 
//            } 
//
//            else if (block->data[block->rotation_dir][i][j] > W) { // 2. ����� ���� ä�����ִ� ��� (SHAPE�� ���� 2,3,4..�ϼ� �����ϱ� "> W"�� �˻��Ѵ�.)
//                new_y = block->y + i + dy; // 3. board���� ����� ��ġ�� �˾Ƴ���.
//                new_x = block->x + j + dx;
//                //printf("[%d](%d,%d) ", dummy_cnt, new_x, new_y); // ��ȿ�� ���� �� �����ϴ��� ����غ���
//
//                // ����: �Ʒ��� ���� �ڵ��ߴµ�, �̷��� �ϸ� �ȵȴ�.
//                // collision_result�� ����� ������ ������ ���� �˻��Ѵ�.
//                // ��� �����ϴ��� �ñ��ϴٸ�, �ּ��� Ǯ�� ������ ���� �ȴ�.
//                //if (board[new_y][new_x].att == E ) { collision_result = false; }
//                //else { collision_result = true; }
//
//                // �浹�� �߻��ϸ� �Լ��� �ٷ� Ż���ؾ� �Ѵ�.
//                if (board[new_y][new_x].att != E) { 
//                    return true; 
//                }
//
//                // ���� �ڵ�: �Ʒ��� ���� ��ǥ������ ����Ҽ��� ������, 
//                // �����ϰ� ���ŷӴ�.
//                //if (new_x < 1 || new_x >= 10 || new_y < 0 || new_y >= 20) {
//                //    collision_result= true; // �浹 �߻�
//                //}
//            }
//        }
//    }
//    return false; // ��� ���� �˻�Ǿ��� �浹�� ������ false ��ȯ
//}

// ������ �浹 �˻�
//�� �浹 : ����� �� / �� / ��� ���� ������ �̵��� ���ܵ�����, �������� �ʽ��ϴ�.
bool check_wall_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
    if (block == NULL) {
        printf("��ȿ���� ���� block ���� �Դϴ�.\r\n");
        return true; // NULL ����� �浹�� ����
    }

    int dx = 0; // Ű �Է¿� ���� ���� ����
    int dy = 0;

    int new_x = 0; // �̵��� �� ��ġ�� ������ ����
    int new_y = 0;

    for (int col = 0; col < BLOCK_HEIGHT; col++) {
        for (int row = 0; row < BLOCK_WIDTH; row++) {

            if (block->data[block->rotation_dir][col][row] == E) {  // ����� ���� E(=empty)��� �˻��� �ʿ䰡 ����.
                continue;
            }
            else if (block->data[block->rotation_dir][col][row] > W) { // 2. ����� ���� ä�����ִ� ��� (SHAPE�� ���� 2,3,4..�ϼ� �����ϱ� "> W"�� �˻��Ѵ�.)
                new_y = block->y + col + dy; // 3. board���� ����� ��ġ�� �˾Ƴ���.
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

// ��� �浹: ����� �ٴ��̳� �ٸ� ��Ͽ� ������ �����˴ϴ�.
bool check_block_collision_on_board(const cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {

    // NULL ���� üũ aaa
    if (block == NULL) { 
        printf("��ȿ���� ���� block ���� �Դϴ�.\r\n");
        return true; // NULL ����� �浹�� ����
    }

    // 1. Ű �Է¿� ���� ���� ����
    int dx = 0;
    int dy = 0;

    // �̵��� �� ��ġ�� ������ ����
    int new_x = 0;
    int new_y = 0;

    // ���� ��� Z ����� 5,5 ��ġ�� ���Ҵٸ�, ��ȿ�� ���� �Ʒ��� ����.
    // (5,5) (6,5) (6,6) (7,6)
    for (int col = 0; col < BLOCK_HEIGHT; col++) { 
        for (int row = 0; row < BLOCK_WIDTH; row++) {

            // ���� ��踦 ������� Ȯ�� aaa 0�� �´��� �����ؾ���
            //if (new_x < 0 || new_x >= BOARD_WIDTH || new_y < 0 || new_y >= BOARD_HEIGHT) {
            //    return true; // ��踦 ����� �浹 �߻�
            //}

            if (block->data[block->rotation_dir][col][row] == E) {  // 1. ����� ���� E(=empty)��� �˻��� �ʿ䰡 ����.
                continue;
            }
            else if (block->data[block->rotation_dir][col][row] > W) { // 2. ����� ���� ä�����ִ� ��� (SHAPE�� ���� 2,3,4..�ϼ� �����ϱ� "> W"�� �˻��Ѵ�.)
                new_y = block->y + col + dy; // 3. board���� ����� ��ġ�� �˾Ƴ���.
                new_x = block->x + row + dx;
                //printf("[%d](%d,%d) ", dummy_cnt, new_x, new_y); // ��ȿ�� ���� �� �����ϴ��� ����غ���

                // ����: �Ʒ��� ���� �ڵ��ߴµ�, �̷��� �ϸ� �ȵȴ�.
                // collision_result�� ����� ������ ������ ���� �˻��Ѵ�.
                // ��� �����ϴ��� �ñ��ϴٸ�, �ּ��� Ǯ�� ������ ���� �ȴ�.
                //if (board[new_y][new_x].att == E ) { collision_result = false; }
                //else { collision_result = true; }
                
                if (board[new_y][new_x].att != E) { // �浹�� �߻��ϸ� �Լ��� �ٷ� Ż���ؾ� �Ѵ�.
                    return true;
                }

                // ���� �ڵ�: �Ʒ��� ���� ��ǥ������ ����Ҽ��� ������, 
                // �����ϰ� ���ŷӴ�.
                //if (new_x < 1 || new_x >= 10 || new_y < 0 || new_y >= 20) {
                //    collision_result= true; // �浹 �߻�
                //}
            }
        }
    }
    return false; // ��� ���� �˻�Ǿ��� �浹�� �����Ƿ� false ��ȯ
}

void remove_current_block_from_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) {
    if (block == NULL) {
        printf("block ������ NULL�Դϴ�.\r\n");
        return;
    }

    // 1. Ű �Է¿� ���� ���� ����
    int dx = 0;
    int dy = 0;

    // (�̵���) �� ��ġ�� ������ ����
    int new_x = 0;
    int new_y = 0;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            //if (block->att[block->rotation_index][i][j] == N) {
            if (block->data[block->rotation_dir][i][j] == E) { continue; } // 1. block�� E(=empty)�� �˻��� �ʿ䰡 ����.
            else {
                new_x = block->x + j + dx; // 2. board���� ����� ��ġ�� �˾Ƴ���.
                new_y = block->y + i + dy;
                board[new_y][new_x].att = E;
            }

        }
    }
}

// �浹�˻� �߰�: ȸ���Ҽ� �ִ��� ���θ� üũ�ؾ� �Ѵ�. �� I�� ��� ���������� ȸ����ų���� ����.
// ��ǥ ���� ����: ȸ������ ���� ��踦 ����� �ȵȴ�.
// �̴� ��� �浹 �˻� �Լ��� ����Ѵ�.
// rotate_block_on_board �� �׳� ȸ���� �Ѵ�.
void rotate_block_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* old_block) {

    // 1. ����� �����س��´�. ���� ����� � ������� �𸣴ϱ�
    block_t copied_block;
    memcpy(&copied_block, old_block, sizeof(block_t));

    // 2. ���� ����� ���忡�� �����Ѵ�.
    remove_current_block_from_board(board, old_block);

    // 3. ����� ȸ��
    copied_block.rotation_dir += 1;
    copied_block.rotation_dir %= 4;

    // 4. �浹�� ���ٸ�, ȸ���� ��� ����
    //    �浹�� �ִٸ�, ������ ��� ���� (=�� ȸ���� �ȵȴ�.)
    bool is_collision = false;
    is_collision = check_block_collision_on_board(board, &copied_block); // on rotate
    is_collision ? printf("r�浹") : printf("r���浹");
       

    if (!is_collision) { // ������ ���(=copied_block)�� board�� ������ �浹�� ���ٸ� 
        remove_current_block_from_board(board, old_block); // old_block�� ���忡�� �����
        insert_block_to_board(board, &copied_block, copied_block.x, copied_block.y); // new_blockd�� ���忡 �����Ѵ�.
        memcpy(old_block, &copied_block, sizeof(block_t)); // old ����� �̵��� ���ο� ������� �����Ѵ�.
        //update_board(console, board); // ���带 ������Ʈ�Ѵ�.
    }
    else {
        remove_current_block_from_board(board, old_block); // old_block�� ���忡�� �����
        insert_block_to_board(board, old_block, old_block->x, old_block->y); // old ����� �����Ѵ�.
        //memcpy(old_block, &copied_block, sizeof(block_t)); // �� �ڵ带 ������ �ȵȴ�.
        //�浹�� �߻��� ���(else ���), memcpy�� ���� old_block�� copied_block���� ����ϴ�.
        //copied_block�� �浹�� �߻��� ��ȿ���� ���� ��ǥ�� ������ �����Ƿ�, old_block�� ��ǥ�� ��ȿ���� ���� ���·� ����˴ϴ�.
        //��������� ���� �̵� �� ��ȿ���� ���� ��ǥ�� �������� �̵��� �õ��Ͽ� ����� ���忡�� ������ϴ�.
        //update_board(console, board);
    }
}



// �Ʒ� �Լ��� �����ϴ�.
void update_board(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    draw_board_from_data(console, board);
}

void update_board_with_line_clear(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {
    clear_line_on_board(board); // ��� ä�����ִ� line�� �����.
    update_board(console, board);
    

}



// ���� ������ �����ͷ� ���带 �׸���. �����͸� �������� �ʴ´�.
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

// ����� �����ϴ� �ڵ�, �浹üũ�� ���� �ʰ� �����Ѵ�. = �߸��� ��ġ(���� ��ġ��)�� ���Եȴ�.
void insert_block_to_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block, int x, int y) {
    if (check_block_collision_on_board(board, block) == true) {  // ����� �����Ҽ� ���ٸ� ���� ����!
        game_over = true;
        return;
    } 

    block->x = x;
    block->y = y;

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            // ��� ������ cell�� N���� Ȯ��
            //if (block->att[block->rotation_index][i][j] == N) {
            if (block->data[block->rotation_dir][i][j] > W) { // �� Wall=2 ���� ū ��� �������
                int bx = block->x + j; // ������� x ��ǥ
                int by = block->y + i; // ������� y ��ǥ

                //printf("(bx,by)=(%d,%d)\r\n", bx, by); // ����׿�
                board[by][bx].att = block->data[block->rotation_dir][i][j];
                //board[by][bx].att = block->shape;
                //board[by][bx].att = block->data;//  block->shape;
                //board[by][bx].att = block->data;//  block->shape;
                // aaa �̰� �� ǥ���� ������? ���߿� �̷��� �ٲ���
                //board[by][bx].cell.data = block->cell[block->rotation_dir][i][j].data;
            }
        }
    }
}

// Ű �Է��� �޾� ����� �̵���Ű�� �Լ�
// Ű �Է��� �޴´�.
// �̵��Ѵ�.
// �浹�� �߻��߳�?
// �ƴϿ� �̵��� ��ǥ �״�� insert
// ��: ���� ��ǥ�� �缳��

bool block_collision = false;

void move_block_by_key_input(windows_console_t* console, cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* origin_block, uint16_t key_code) {
    if (origin_block->fixed == true) return;     // ��� �Ӽ��� fixed ��� �̵��̳� ȸ���� ��ų �ʿ䰡 ����.

    // 1. ���� ����� �����س���
    block_t copied_block;
    memcpy(&copied_block, origin_block, sizeof(block_t));
    //block_t tmp_block = *block; // �̷��͵� �ȴٴµ�? C���� �̰� �ȴٰ�?? aaa

    //print_board_att_info(board); // ������
    // 2. ���� ����� ���忡�� ����
    // ���忡�� ����� ���� �ִ� ������(�� 2,2,0,2,.. )�� �����ϴ°���, ��� ��ü�� �����ϴ°� �ƴϴ�
    remove_current_block_from_board(board, origin_block);
    //update_board(console, board); // ���带 ������Ʈ�Ѵ�.
    //print_board_att_info(board);

    switch (key_code) {
        // ������ ���������� ����� ȸ��(rotate)�ϰ�����, ����뿡���� ����� ���� �̵���Ű��. 
        case KEY_DOWN: // ������ ����� �Ʒ��� ��ĭ�� �̵�
            //if (copied_block.y < BOARD_HEIGHT) { copied_block.y += 1; }
            // ����: ���� ���� ���� ������, ��� �浹�Լ��� �ٴ��� �����ϱ� ������, ���� ���� ���� ������ �ʾƵ� �ȴ�.
            // ���� ���� ��ǥ ��� ����� ����Ҽ��� x,y ��ǥ�� ����ؾ� �ϱ� ������ �� �Ӹ��� ��������.
            copied_block.y += 1;
            //printf("down(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_LEFT: // ������ ����� ����(LEFT)�� �̵�
            //if (copied_block.x > 1) { copied_block.x -= 1; }
            copied_block.x -= 1;
            //printf("left(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_RIGHT: // ������ ����� ���������� �̵�
            //if (copied_block.x < BOARD_WIDTH) { copied_block.x += 1; }
            copied_block.x += 1;
            //printf("right(x,y)=(%d,%d)", copied_block.x, copied_block.y);
            break;

        case KEY_SPACE: // ����� ����߸��� block hard drop
            // �̱���
            break;
    }

    bool is_wall_collision = false;
    bool is_block_collision = false;

    is_wall_collision= check_wall_collision_on_board(board, &copied_block);    
    is_block_collision = check_block_collision_on_board(board, &copied_block); // on move
    //is_collision ? printf("m�浹")  : printf("m���浹");

    if (is_wall_collision) {
        printf("�� �浹!\n");
        insert_block_to_board(board, origin_block, origin_block->x, origin_block->y); // ���� ���(=origin_block)�� �����Ѵ�.
        return;
    }

    if (!is_block_collision) { // ������ ���(=copied_block)�� board�� ������ �浹�� ���ٸ� 
        printf("m���浹");
        //printf("collision %d: ", is_collision);
        //remove_current_block_from_board(board, origin_block); // old_block�� ���忡�� �����
        insert_block_to_board(board, &copied_block, copied_block.x, copied_block.y); // ���忡 ����
        memcpy(origin_block, &copied_block, sizeof(block_t)); // ���� ���(origin_block)�� ī���� ���(copied_block)���� ��������.
    }
    else { // ������ ����� board�� ������ �浹�� �ִٸ�
        printf("m�浹");
        block_collision = true;
        //printf("collision %d: ", is_collision);
        //remove_current_block_from_board(board, origin_block); // old_block�� ���忡�� �����
        insert_block_to_board(board, origin_block, origin_block->x, origin_block->y); // ���� ���(=origin_block)�� �����Ѵ�.
        //memcpy(old_block, &copied_block, sizeof(block_t)); // �� �ڵ带 ������ �ȵȴ�.
        //�浹�� �߻��� ���(else ���), memcpy�� ���� old_block�� copied_block���� ����ϴ�.
        //copied_block�� �浹�� �߻��� ��ȿ���� ���� ��ǥ�� ������ �����Ƿ�, old_block�� ��ǥ�� ��ȿ���� ���� ���·� ����˴ϴ�.
        //��������� ���� �̵� �� ��ȿ���� ���� ��ǥ�� �������� �̵��� �õ��Ͽ� ����� ���忡�� ������ϴ�.
    }
}


//void handle_collision(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], const block_t* block) { // r1
//    static int lock_delay = 0; // �ٴڿ� ���� �� ��� �ð�
//    const int LOCK_TIME = 80000; // 500ms (0.5��) aaa �ð���� �ٽ� �ؾ���, ���Ѵ�� ���� 50�̶� ��������
//    bool is_collision = false;
//    
//    //static dummy_cnt = 0;
//    //printf("[%d] handle !!", ++dummy_cnt);
//
//    // �ε�����? �ƴϿ� = false = �浹�� ����!
//    // ���� = true = �浹�� �ִ�!
//    is_collision = check_block_collision_on_board(board, block); // on handle
//    if (is_collision) {  // �浹�� �ִ�
//        //printf("[%d/%d] lock_delay/LOCK_TIME", lock_delay, LOCK_TIME);
//        lock_delay += 1; // 1ms ������ ȣ��ȴٰ� ����
//        if (lock_delay >= LOCK_TIME) {
//            //printf("locked !!");
//            //printf("[%d/%d]", lock_delay, LOCK_TIME);
//            fix_block(block);
//            lock_delay = 0; // Ÿ�̸� �ʱ�ȭ
//            create_random_block(block);// ���ο� ��� ����
//        }
//    }
//    else {
//        //printf("[%d] unlock", lock_delay);
//        lock_delay = 0; // �浹���� ������ Ÿ�̸� �ʱ�ȭ
//    }
//}

#define LOCK_TIME 50000
// �浹 �ٷ�� �Լ�
// ����� �����Ǿ��°�? ���� �ð��� ������ ����� ������Ű�� ���θ� �����ִ� �Լ�
void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t* block) {
    if (block->fixed) return;

    bool is_collision = check_block_collision_on_board(board, block);

    if (is_collision) {
        block->lock_delay += 1; // 10ms ������ ���� (���� ���� �ֱ�� ��ġ)
        if (block->lock_delay >= LOCK_TIME) {
            block->fixed = true;
            block->lock_delay = 0;
            //printf("yy��� ����!\n");
            printf("yyyyyyyy\n");
        }
        else {
            block->fixed = false;
            block->lock_delay = 0;
        }
    }
}

// ��û�� row�� �ٿ� 0�� �ִ��� ������
// �ִ�  clear�� ������ �ƴϴ�
// ���� clear�� �����̴�.
// ����: �Ʒ��� ���� ¥���� �ȵȴ�.
// Loops with at most one iteration should be refactored
//bool is_row_empty(const cell_t row[]) {
//    for (int col = 1; col < 11; col++) {
//        if (row[col].att == E) { return true; }// 0�� �ִٸ�? �� row�� ������ full �Ȱ��� ���� ����
//        else { // row�� ���� ���� �ִ�!
//            //printf("%d ", row[col].att); 
//            return true;
//        }
//    }
//}

bool is_row_full(const cell_t row[]) {
    for (int col = 1; col < 11; col++) {
        if (row[col].att == E) { return false; }// 0�� �ִٸ�? �� row�� ������ full�� �ƴϹǷ� ����
    }
    return true; // ������ ��� �����ٴ°� 0�� ���ٴ� �Ŵ�. ��� full�̶� ������
}

// �����: Empty ����, Filled�̵��� row�� ��� ����ϴ� �Լ�
void print_row(const cell_t row[]) {
}

// �����: E�� ���� row�� ��� ����ϴ� �Լ�
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

�Լ� �̸� �ĺ�: check_line_and_delete

// ���� ������ �ش� row�� ����� ��� ä�����ִٸ�, �ش� ������ �����.
����������� 
�����������
����������� // ��� ä���� �ִ�. !�����.

������ ����� ��� ������ �Ѵ�.
����������� 
�����������
����������� // ����� ������.


�׸��� ���� ��� ����� �Ʒ��� ������.
x  ��ǥ (1,0)~(10,0)
y ��ǥ (1,0)~(1,19)
(1,19)~10,19
*/
void clear_line_on_board(cell_t board[BOARD_HEIGHT][BOARD_WIDTH]) {

    //for (int row_index = 0; row_index < 20; row_index++) { // ������ ���� �˻�
    for (int row_index = BOARD_HEIGHT - 2; row_index >= 1; row_index--) { // �Ʒ������� �˻� qqq ���̰� �ֳ�?
        //print_non_empty_row(board[row_index]); // �����
        if (!is_row_full(board[row_index])) { // ����á��? (false= �ƴϿ�) �ǳʶڴ�.
            continue;
        }
        // �ش� ������ full�̶��, �ش� ������ ������.
        // 1. ���� �� ���� ����� = �÷� 1~10�� E�� ä���. ����! 0�� 11�� ��(=Wall)�̱� ������ �������� �ȵȴ�.
        else { 
            //printf("d(%d) ", row_index); // ������
            for (int col = 1; col < 11; col++) {
                board[row_index][col].att = E;
            }

            // 2. ���� �ִ� ��� ����� �� ĭ �Ʒ��� �̵�
            // ��ü ������ ���鼭 ����� �ϴ��� ����ִٸ� ����� ������.
            //�� : 5�� ������ ����� 4�� ���� �� 5�� ����, 3�� ���� �� 4�� �������� �����Ѵ�.
            for (int r = row_index; r > 0; r--) {
                for (int col = 1; col < 11; col++) {
                    board[r][col].att = board[r - 1][col].att; // ������ ���� �ٷ� ����
                }
            }
            // 3. �ֻ�� ���� �� ���·� �ʱ�ȭ
            // ���� ���� ����(0��)�� �� ���·� �ʱ�ȭ�մϴ�.
            for (int col = 1; col < 11; col++) {
                board[0][col].att = E;
            }

            // 4. �̵� �� ������ row_index�� �ٽ� �˻��ϱ� ���� �ε��� ����
            // (���� ������ ����� �� ���� á�� �� ����)
            //�ε��� ���� :
            //������ ����� ����� ���� ��, ������ row_index�� �ٽ� �˻��մϴ�.
            //�� : 5�� ������ ����� ����� ������, ���ο� ����� 5�� ���ο� ��ġ�� �� �����Ƿ� ��˻簡 �ʿ��մϴ�.
            row_index++; // �߿�: ������ ����� ���� �� ���� ���� ��˻�
        }
    }
    
}