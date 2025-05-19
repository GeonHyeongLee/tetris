#ifndef __GAME_FSM_H__
#define __GAME_FSM_H__

#include "common.h"

extern bool game_over;


typedef enum _game_state_t {
    GAME_STATE_INITIALIZATION,
    //게임이 시작되기 전 초기화 단계.
    //메모리 할당, 변수 초기화 등 준비 작업 수행.

    //WAITING_INSERT_COIN_STATE, // DEMO_STATE
    GAME_STATE_WAITING_FOR_COIN,
    //동전 입력을 기다리는 상태.
    //플레이어가 게임을 시작하기 위해 동전을 넣는 단계.

    GAME_STATE_RUNNING,
    //GAME_STATE_IN_GAME,
    //실제 게임이 진행 중인 상태.
    //블록 이동, 점수 계산 등 주요 게임 로직이 실행되는 단계.

    GAME_STATE_GAME_OVER,
    //게임이 끝난 상태.
    //최종 점수 표시 및 재시작 여부를 결정하는 단계.

    GAME_STATE_USER_INITIAL_INPUT,
    //플레이어가 자신의 이니셜을 입력하는 단계.
    //게임 기록 저장 또는 리더보드 업데이트와 관련된 작업 수행.
} game_state_t;


void set_game_state(game_state_t* state);
game_state_t get_game_state(game_state_t* state);
//void update_game_state(game_state_t* state);


#endif
