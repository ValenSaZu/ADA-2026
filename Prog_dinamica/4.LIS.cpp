#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> constructMatrix(vector<int> elements, int& LIS, int& idx) {
	//Inicializar
	vector<vector<int>> matrix(2, vector<int>(elements.size()));

	for (int i = 0; i < elements.size();i++) {
		matrix[0][i] = 1; // longitud maxima de cadena
		matrix[1][i] = -1; // predecesor
	}

	LIS = 1; //minimo es 1
	idx = 0;
	for (int elem = 0; elem < elements.size(); elem++) {
		for (int prev = 0; prev < elem; prev++) {
			if (elements[prev] < elements[elem]) {
				if (matrix[0][prev] + 1 > matrix[0][elem]) {
					matrix[0][elem] = matrix[0][prev] + 1;
					matrix[1][elem] = prev;
				}
				if (matrix[0][elem] > LIS) {
					LIS = matrix[0][elem];
					idx = elem;
				}
			}
		}
	}

	return matrix;
}

vector<int> reconstructSolution(vector<vector<int>> matrix, vector<int> elements, int idx) {
	vector<int> solution;
	int index = idx;
	while (index != -1) {
		solution.insert(solution.begin(), elements[index]);
		index = matrix[1][index];
	}
	return solution;
}

int main() {
	vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };
	int LIS;
	int index;
	vector<vector<int>> matrix = constructMatrix(V, LIS, index);
	vector<int> solution = reconstructSolution(matrix, V, index);

	cout << "La longitud de la cadena mas larga es: " << LIS << endl;
	cout << "Los elementos son: ";
	for (int i = 0; i < solution.size();i++) {
		cout << solution[i] << " ";
	}
	return 0;
}