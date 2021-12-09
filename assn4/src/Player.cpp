#include "Player.h"

Player::Player(){
  player_pos_x = 200;
  player_pos_y = 370;
  player_start_vel = 4;
  player_vel = player_start_vel;
}

Player::~Player(){}

int Player::player_get_pos_x(){
    return player_pos_x;
}

int Player::player_get_pos_y(){
    return player_pos_y;
}

int Player::player_get_vel(){
    return player_vel;
}

void Player::player_add_vel(int v){
    player_vel += v;
}

void Player::player_set_pos_x(int x){
    player_pos_x = x;
}

void Player::player_set_pos_y(int y){
    player_pos_y = y;
}

void Player::player_set_vel(int v){
    player_vel = v;
}
