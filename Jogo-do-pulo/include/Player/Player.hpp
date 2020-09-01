#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>

class Player{
private:
	char id;
	std::pair<int, int> position;
	std::vector<int> steps;

public:
	Player(int id, int x, int y);
	~Player();
	
  void setId(char id);
	char getId() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;
  
	void setSteps(int steps);
	int getLastStep() const;

	int getFirstMoviment() const;
};

#endif