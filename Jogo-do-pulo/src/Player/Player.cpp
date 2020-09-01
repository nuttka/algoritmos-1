#include "Player.hpp" 

Player::Player(int id, int x, int y){
  this->id = id;
  this->position.first = x;
  this->position.second = y;
}
Player::~Player(){
}

void Player::setId(char id){
  this->id = id;
}
char Player::getId() const{
  return this->id;
}

void Player::setX(int x){
  this->position.first = x;
}
int Player::getX() const{
  return this->position.first;
}

void Player::setY(int y){
  this->position.second = y;
}
int Player::getY() const{
  return this->position.second;
}

void Player::setSteps(int steps){
  this->steps.push_back(steps);
}
int Player::getLastStep() const{
  if(this->steps.size()>=1){
    return this->steps.at(this->steps.size()-1);
  }
  return 0;
}

int Player::getFirstMoviment() const{
  return this->steps.at(0);
}