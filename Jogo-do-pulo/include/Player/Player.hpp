#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>

class Player{
private:
	char id;
	std::pair<int, int> position;
	std::vector<int> lastMoviment;

public:
	Player(int id, int x, int y);
	~Player();
	
  void setId(char id);
	char getId() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;
  
	void setLastMoviment(int lastMoviment);
	int getLastMoviment() const;

	int getFirstMoviment() const;
	void printPlayer() const;
	void movePlayer(int x, int y);
	int getNumberOfSteps() const;
};

#endif