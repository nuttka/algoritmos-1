#include "../include/Board/Board.hpp"
#include "../include/Player/Player.hpp"
#include "../include/Game/Game.hpp"

int main(){

	// Início entrada

	int xBoard;
	int yBoard;
	int amountPlayers;
	int boardValues;
	int xPlayer;
	int yPlayer;

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

	std::cout << "-----" << std::endl;
	std::cout << "Printing ListAdj" << std::endl;
	game->createListAdj();
	game->printListAdj();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing BFS" << std::endl;
	game->bfs();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Board" << std::endl;
	game->printBoard();
	std::cout << "-----" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Printing Players" << std::endl;
	for(int i=0; i<amountPlayers; i++){
		game->getPlayer(i)->printPlayer();
	}
	std::cout << "-----" << std::endl;

	return 0;
}