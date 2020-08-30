#include "Game.hpp"

Game::Game(std::unique_ptr<Board> board){
  this->board = std::move(board);
}
Game::~Game();

void Game::addPlayer(std::unique_ptr<Player> player){
  this->players.push_back(std::move(player));
}

void Game::printBoard() const{
  this->board->printBoard();
}
void Game::printPlayers() const{
  for(int i=this->players.begin(); i!=this->players.end(); i++){
		(*i)->printPlayer();
	}
}

Board* Game::getBoard() const{
  return this->board.get();
}
Player* Game::getPlayer(int id) const{
  return this->players.at(id).get();
}