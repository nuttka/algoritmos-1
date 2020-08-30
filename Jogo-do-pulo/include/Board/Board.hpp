#ifndef BOARD_H
#define BOARD_H


#include "Player.hpp"

#include <iostream>
#include <vector>
#include <memory>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

class Board{
private:
	int x;
	int y;
	Matrix<int> board;

public:
	Board(int x, int y);
	~Board();

  void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setPositionValue(int x, int y, int value);
	int getPositionValue(int x, int y) const;

  Matrix<int> getBoard() const;
	void printBoard() const;
};

#endif