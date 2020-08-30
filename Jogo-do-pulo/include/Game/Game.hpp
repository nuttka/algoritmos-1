#ifndef GAME_H
#define GAME_H


#include "Board.hpp"
#include "Player.hpp"

class Game{
private:
	std::unique_ptr<Board> board;
	std::vector<std::unique_ptr<Player>> players;

public:
	Game(std::unique_ptr<Board> board);
	~Game();

	void addPlayer(std::unique_ptr<Player> player);

	void printBoard() const;
	void printPlayers() const;

	Board* getBoard() const;
	Player* getPlayer(int id) const;
};

#endif