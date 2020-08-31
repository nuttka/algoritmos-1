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

void Player::setId(int id){
  this->id = id;
}
int Player::getId() const{
  return this->id;
}

void Player::setIsWinner(bool isWinner){
  this->isWinner = isWinner;
}
bool Player::getIsWinner() const{
  return this->isWinner;
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

// void Player::setNodeX(int x){
//   this->node->position.first = x;
// }
// int Player::getNodeX() const{
//   return this->node->position.first;
// }

// void Player::setNodeY(int y){
//   this->node->position.second = y;
// }
// int Player::getNodeY() const{
//   return this->node->position.second;
// }

// void Player::setNodeValue(int value){
//   this->node->value = value;
// }
// int Player::getNodeValue() const{
//   return this->node->value;
// }

void Player::setIsStuck(bool isStuck){
  this->isStuck = isStuck;
}
bool Player::getIsStuck() const{
  return this->isStuck;
}

void Player::setLastMoviment(int lastMoviment){
  this->lastMoviment = lastMoviment;
}
int Player::getLastMoviment() const{
  return this->isStuck;
}

void Player::printPlayer() const{
  std::cout << "Player ID: " << this->id << std::endl;
	std::cout << "Position<x, y>: <" << this->position.first << ", " << this->position.second << ">" << std::endl;
	std::cout << "Is winner: " << this->isWinner << std::endl;
}

void Player::movePlayer(int x, int y){
  this->position.first = x;
  this->position.second = y;
}