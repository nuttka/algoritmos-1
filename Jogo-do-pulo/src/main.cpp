#include "../include/Board/Board.hpp"
#include "../include/Player/Player.hpp"
#include "../include/Game/Game.hpp"

#include <chrono>

int main(){

	// Início entrada

	int xBoard;
	int yBoard;
	int amountPlayers;
	int boardValues;
	int xPlayer;
	int yPlayer;

	auto start = std::chrono::steady_clock::now();

	std::cin >> xBoard;
	std::cin >> yBoard;
	std::cin >> amountPlayers;

	std::unique_ptr<Board> board(new Board(xBoard, yBoard));

	for(int i=0; i<xBoard; i++){
		for(int j=0; j<yBoard; j++){
			std::cin >> boardValues;
			board->setPositionValue(i, j, boardValues);
		}
	}

	std::unique_ptr<Game> game(new Game(std::move(board)));

	for(int i=0; i<amountPlayers; i++){
		std::cin >> xPlayer;
		std::cin >> yPlayer; 

		std::unique_ptr<Player> newPlayer = std::make_unique<Player>(i, xPlayer, yPlayer);
		game->addPlayer(std::move(newPlayer));
	}

	// Fim entrada.

	game->createListAdj();
	game->defineWinner(game->bfs());


	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << std::chrono::duration <double, std::milli>(diff).count() << std::endl;

	return 0;
}