#ifndef BOARD_H
#define BOARD_H


#include "../Player/Player.hpp"

#include <iostream>
#include <vector>
#include <memory>

class Board{
private:
	int x;
	int y;
	std::vector<std::vector<int>> board;

public:
	Board(int x, int y);
	~Board();

  void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setPositionValue(int x, int y, int value);
	int getPositionValue(int x, int y) const;
};

#endif