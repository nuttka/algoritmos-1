#include <iostream>
#include <vector>

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int sumOfVectorElements(std::vector<int> &arr){
	int sum = 0;
	for(auto it=arr.begin(); it!=arr.end(); ++it)
		sum += *it;
	return sum;
}

int solution(std::vector<int> &weights){
	int sumOfWeights = sumOfVectorElements(weights);
	const int row = weights.size() + 1;
	const int col = sumOfWeights/2 + 1;
	std::vector<std::vector<int>> matrix(row, std::vector<int>(col, 0));
	
	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			if(weights.at(i-1)<=j){
				int param = weights.at(i-1) + matrix[i-1][j-weights.at(i-1)];
				matrix[i][j] = max(matrix[i-1][j], param);
			}else
				matrix[i][j] = matrix[i-1][j];
		}
	}

	return sumOfWeights-(2*matrix[row-1][col-1]);
}

int main(){
	int amountsOfDiamonds;
	std::vector<int> weights;

	std::cin >> amountsOfDiamonds;

	for(int i=0; i<amountsOfDiamonds; i++){
		int weight;
		std::cin >> weight;
		weights.push_back(weight);
	}

	std::cout << solution(weights) << std::endl;
	return 0;
}