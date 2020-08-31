#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>

class Player{
private:
	int id;
	bool isWinner = false;
	bool isStuck = false;
	std::pair<int, int> position;
	int lastMoviment = 0;

public:
	Player(int id, int x, int y);
	~Player();
	
  void setId(int id);
	int getId() const;

	void setIsWinner(bool isWinner);
	bool getIsWinner() const;

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setIsStuck(bool isStuck);
	bool getIsStuck() const;
  
	void setLastMoviment(int lastMoviment);
	int getLastMoviment() const;

	void printPlayer() const;
	void movePlayer(int x, int y);
};

#endif