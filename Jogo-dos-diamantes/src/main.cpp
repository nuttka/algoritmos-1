#include <iostream>
#include <vector>

int main(){

	// Início entrada
	int amountsOfDiamonds;
	std::vector<int> weights;

	std::cin >> amountsOfDiamonds;

	for(int i=0; i<amountsOfDiamonds; i++){
		int weight;
		std::cin >> weight;
		weights.push_back(weight);
	}

	return 0;
}