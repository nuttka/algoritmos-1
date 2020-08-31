#include "Game.hpp"

Game::Game(std::unique_ptr<Board> board){
  this->board = std::move(board);

  this->list.resize(this->board->getX() * this->board->getY());

  int k=0;
  for(int x=0; x<this->board->getX(); x++){
    for(int y=0; y<this->board->getY(); y++){
      std::pair<int, int> pos;
      pos.first = x;
      pos.second = y;
      this->list.at(k).push_back(pos);
      k = k+1;
	  }
	}
}
Game::~Game(){
}

void Game::addPlayer(std::unique_ptr<Player> player){
  this->players.push_back(std::move(player));
}

void Game::printBoard() const{
  this->board->printBoard();
}
void Game::printPlayers() const{
  for(auto i=this->players.begin(); i!=this->players.end(); i++){
		(*i)->printPlayer();
	}
}

Board* Game::getBoard() const{
  return this->board.get();
}
Player* Game::getPlayer(int id) const{
  return this->players.at(id).get();
}

void Game::createListAdj(){
  int k=0;
  for(int x=0; x<this->board->getX(); x++){
    for(int y=0; y<this->board->getY(); y++){
      int positionValue = this->board->getPositionValue(x, y);
      std::pair<int, int> pos;
      pos.first = x;
      pos.second = y;

      if(positionValue == 0){
        break;
      }
      if(x-positionValue>=0){
        pos.first = x-positionValue;
        this->list.at(k).push_back(pos);
      }
      if(x+positionValue<this->board->getX()){
        pos.first = x+positionValue;
        this->list.at(k).push_back(pos);
      }
      if(y-positionValue>=0){
        pos.second = y-positionValue;
        this->list.at(k).push_back(pos);
      }
      if(y+positionValue<this->board->getY()){
        pos.second = y+positionValue;
        this->list.at(k).push_back(pos);
      }

      k = k+1;
	  }
	}
}

void Game::printListAdj(){
  for(auto row=this->list.begin(); row != this->list.end(); ++row){
		for(auto col=row->begin(); col != row->end(); ++col){
			std::cout << "<" << col->first << ", " << col->second << "> ";
		}

		std::cout << std::endl;
	}
}

void Game::bfs(){
  std::queue<std::pair<int, int>> q;
  std::pair<int, int> finalPostion;
  std::map<std::pair<int, int>, bool> visited;
  std::map<int, int> possiblesWin;

  finalPostion.first = this->board->getX()-1;
  finalPostion.second = this->board->getY()-1;

  int count;

  for(auto p = this->players.begin(); p!=this->players.end(); p++){
    q.push(std::pair<int, int>((*p)->getX(), (*p)->getY()));
    count = 0;
    visited.clear();

    std::cout << "----------------" << (*p)->getId() << std::endl;
    std::cout << "To no player: " << (*p)->getId() << std::endl;

    while(!q.empty()){
      count = count + 1;
      std::pair<int, int> v = q.front();
      int vPosition = (this->board->getY())*v.first + (1+v.second) -1;
      q.pop();
      visited.insert({v, true});
      if(v == finalPostion){
        possiblesWin.insert({(*p)->getId(), count});
        while(!q.empty()){
          q.pop();
        }
        std::cout << "Já cheguei no final, agr saio" << std::endl;
        break;
      }

      std::cout << "To visitando esse: " << v.first << ", " << v.second << "> ";

      for(auto col=this->list.at(vPosition).begin(); col != this->list.at(vPosition).end(); col++){

        std::cout << "Esse apareceu: " << col->first << col->second << std::endl;

        visited.insert({v, false});
        if(!visited.find(*col)->second){
          std::cout << "Esse foi pra fila: " << col->first << col->second << std::endl;
          q.push((*col));
        }
      }
    }
  }

  count = 0;
  int winner;
  for(auto itr = possiblesWin.begin(); itr != possiblesWin.end(); itr++){ 
    if((*itr).second>count){
      count = (*itr).second;
      winner = (*itr).first;
    }
  } 

  std::cout << std::endl << "Ganhador: " << winner << std::endl << "Rodadas: " << count;

}