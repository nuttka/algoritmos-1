#include "Board.hpp"

Board::Board(int x, int y){
  this->x = x;
  this->y = y;
  this->board.resize(x);

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			this->matrix_board.at(i).resize(y);
		}
	}
}
Board::~Board();

void Board::setX(int x){
  this->x = x;
}
int Board::getX() const{
  return this->x;
}

void Board::setY(int y){
  this->y = y;
}
int Board::getY() const{
  return this->y;
}

void Board::setPositionValue(int x, int y, int value){
  this->board.at(x).at(y) = value;
}
int Board::getPositionValue(int x, int y) const{
  return this->board.at(x).at(y);
}

Matrix<int> Board::getBoard() const{
  return this->board;
}
void Board::printBoard() const{
  for(auto row=this->matrix_board.begin(); row!=this->matrix_board.end(); row++){
		for(auto col=row->begin(); col!=row->end(); col++){
			std::cout << *col << " ";
		}
		std::cout << std::endl;
	}
}