#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>
#include <map>

#include "../Board/Board.hpp"
#include "../Player/Player.hpp"

class Game{
private:
	std::unique_ptr<Board> board;
	std::vector<std::unique_ptr<Player>> players;
	std::vector<std::vector<std::pair<int, int>>> list;

public:
	Game(std::unique_ptr<Board> board);
	~Game();

	void addPlayer(std::unique_ptr<Player> player);

	void printBoard() const;
	void printPlayers() const;

	Board* getBoard() const;
	Player* getPlayer(int id) const;

	void createListAdj();
	void bfs();

	void printListAdj();

};

#endif