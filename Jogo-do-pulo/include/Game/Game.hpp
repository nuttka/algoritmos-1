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

	Player* getPlayer(int id) const;

	void createListAdj();
	std::map<int, int> bfs();
	void defineWinner(std::map<int, int> possiblesWin);

};

#endif