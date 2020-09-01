#include "Game.hpp"

Game::Game(std::unique_ptr<Board> board){
  this->board = std::move(board);

  this->list.resize(this->board->getX() * this->board->getY());

  int k=0;
  for(int x=0; x<this->board->getX(); x++){
    for(int y=0; y<this->board->getY(); y++){
      k = (this->board->getY())*x + (1+y) -1;
      std::pair<int, int> pos;
      pos.first = x;
      pos.second = y;
      this->list.at(k).push_back(pos);
	  }
	}
}
Game::~Game(){
}

void Game::addPlayer(std::unique_ptr<Player> player){
  this->players.push_back(std::move(player));
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
      k = (this->board->getY())*x + (1+y) -1;

      if(positionValue == 0){
        break;
      }
      if(x-positionValue>=0){
        pos.first = x-positionValue;
        this->list.at(k).push_back(pos);
        pos.first = x;
      }
      if(x+positionValue<this->board->getX()){
        pos.first = x+positionValue;
        this->list.at(k).push_back(pos);
        pos.first = x;
      }
      if(y-positionValue>=0){
        pos.second = y-positionValue;
        this->list.at(k).push_back(pos);
        pos.second = y;
      }
      if(y+positionValue<this->board->getY()){
        pos.second = y+positionValue;
        this->list.at(k).push_back(pos);
      }
	  }
	}
}

std::map<int, int> Game::bfs(){
  std::queue<std::pair<int, int>> q;
  std::pair<int, int> finalPostion;
  std::map<std::pair<int, int>, std::pair<int, bool>> visited;
  std::map<int, int> possiblesWin;

  finalPostion.first = this->board->getX()-1;
  finalPostion.second = this->board->getY()-1;

  int count;

  for(auto p = this->players.begin(); p!=this->players.end(); p++){
    q.push(std::pair<int, int>((*p)->getX(), (*p)->getY()));
    visited.clear();
    std::pair<int, int> v = q.front();
    visited.insert({v,std::pair<int, bool>(0, true)});
    while(!q.empty()){
      std::pair<int, int> v = q.front();
      int vPosition = (this->board->getY())*v.first + (1+v.second) -1;
      q.pop();
      (*p)->setSteps(this->board->getPositionValue(v.first, v.second));
      
      for(auto col=this->list.at(vPosition).begin(); col != this->list.at(vPosition).end(); col++){
        visited.insert({(*col),std::pair<int, bool>(visited.find(v)->second.first+1 , false)});
        if(!visited.find(*col)->second.second){

          if((*col) == finalPostion){
            count = visited.find((*col))->second.first;
            possiblesWin.insert({(*p)->getId(), count});
            while(!q.empty()){
              q.pop();
            }
            break;
          }
          visited.find(*col)->second.second = true;
          q.push((*col));
        }
      }
    }
  }
  return possiblesWin;
}

void Game::defineWinner(std::map<int, int> possiblesWin){
  if(!possiblesWin.empty()){
    int count = possiblesWin.begin()->second;
    int winner = possiblesWin.begin()->first;
    for(auto itr = possiblesWin.begin(); itr != possiblesWin.end(); itr++){
      if((*itr).second<count){
        count = (*itr).second;
        winner = (*itr).first;
      }else if((*itr).second==count && (*itr).first!=winner){
        int last1;
        int id1;
        int first1;
        int id2;
        int last2;
        int first2;
        for(auto p = this->players.begin(); p!=this->players.end(); p++){
          if((*p)->getId() == (*itr).first){
            last1 = (*p)->getLastStep();
            id1 = (*p)->getId();
            first1 = (*p)->getFirstMoviment();
          }else if((*p)->getId() == winner){
            last2 = (*p)->getLastStep();
            id2 = (*p)->getId();
            first2 = (*p)->getFirstMoviment();
          }
          if(last1>last2){
            winner = id2;
          }else if(last1<last2){
            winner = id1;
          }else{
            if(first1>=first2){
              winner = id2;
            }else{
              winner = id1;
            }
          }
        }
      }
    } 
    char ascii = winner + 65;
    std::cout << ascii << std::endl << count << std::endl;
  }else{
    std::cout << "SEM VENCEDORES" << std::endl;
  }
}