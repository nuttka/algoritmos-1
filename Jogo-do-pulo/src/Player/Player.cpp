#include "Player.hpp" 

Player::Player(int id, int x, int y){
  this->id = id;
  this->position.first = x;
  this->position.second = y;
  // this->node->position = this->position;
  // this->node->down = nullptr;
  // this->node->right = nullptr;
  // this->node->left = nullptr;
  // this->node->up = nullptr;
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

void Player::setLastMoviment(int lastMoviment){
  this->lastMoviment.push_back(lastMoviment);
}
int Player::getLastMoviment() const{
  if(this->lastMoviment.size()>=1){
    return this->lastMoviment.at(this->lastMoviment.size()-1);
  }
  return 0;
}

void Player::printPlayer() const{
  std::cout << "Player ID: " << this->id << std::endl;
	std::cout << "Position<x, y>: <" << this->position.first << ", " << this->position.second << ">" << std::endl;
}

void Player::movePlayer(int x, int y){
  this->position.first = x;
  this->position.second = y;
}

int Player::getNumberOfSteps() const{
  return this->lastMoviment.size();
}

int Player::getFirstMoviment() const{
  return this->lastMoviment.at(0);
}