#ifndef __GAME_FSM_H__
#define __GAME_FSM_H__

#include "common.h"

extern bool game_over;


typedef enum _game_state_t {
    GAME_STATE_INITIALIZATION,
    //������ ���۵Ǳ� �� �ʱ�ȭ �ܰ�.
    //�޸� �Ҵ�, ���� �ʱ�ȭ �� �غ� �۾� ����.

    //WAITING_INSERT_COIN_STATE, // DEMO_STATE
    GAME_STATE_WAITING_FOR_COIN,
    //���� �Է��� ��ٸ��� ����.
    //�÷��̾ ������ �����ϱ� ���� ������ �ִ� �ܰ�.

    GAME_STATE_RUNNING,
    //GAME_STATE_IN_GAME,
    //���� ������ ���� ���� ����.
    //��� �̵�, ���� ��� �� �ֿ� ���� ������ ����Ǵ� �ܰ�.

    GAME_STATE_GAME_OVER,
    //������ ���� ����.
    //���� ���� ǥ�� �� ����� ���θ� �����ϴ� �ܰ�.

    GAME_STATE_USER_INITIAL_INPUT,
    //�÷��̾ �ڽ��� �̴ϼ��� �Է��ϴ� �ܰ�.
    //���� ��� ���� �Ǵ� �������� ������Ʈ�� ���õ� �۾� ����.
} game_state_t;


void set_game_state(game_state_t* state);
game_state_t get_game_state(game_state_t* state);
//void update_game_state(game_state_t* state);


#endif
