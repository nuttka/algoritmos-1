#include "Player.hpp" 

Player::Player(int id, int x, int y){
  this->id = id;
  this->x = x;
  this->y = y;
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
  this->x = x;
}
int Player::getX() const{
  return this->x;
}

void Player::setY(int y){
  this->y = y;
}
int Player::getY() const{
  return this->y;
}

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
	std::cout << "Position<x, y>: <" << this->x << ", " << this->y << ">" << std::endl;
	std::cout << "Is winner: " << this->isWinner << std::endl;
}