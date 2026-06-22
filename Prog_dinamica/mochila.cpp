#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> constructMatrix(vector<int> p, vector<int>b, int m) {
	vector<vector<int>> matrix(p.size() + 1, vector<int>(m + 1, 0));

	for (int i = 1;i <= p.size();i++) {
		for (int j = 1;j <= m;j++) {
			if (j - p[i-1] >= 0) {
				matrix[i][j] = max(matrix[i - 1][j], b[i-1] + matrix[i - 1][j - p[i-1]]);
			}
			else {
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}

	return matrix;
}

vector<int> reconstructSolution(vector<vector<int>> matrix, vector<int> p, vector<int> b, int& acumBenefit) {
	vector<int> sol(matrix.size() - 1, 0);
	int j = matrix[0].size() - 1;
	for (int i = matrix.size() - 1; i > 0; i--) {
		if (!(matrix[i][j] == matrix[i - 1][j])) {
			sol[i - 1] = 1;
			acumBenefit += b[i - 1];
			j -= p[i - 1];
		}
	}
	return sol;
}

vector<int> prog_dinamica(vector<int> p, vector<int>b, int m, int& acumBenefit) {
	vector<vector<int>> matrix = constructMatrix(p, b, m);
	vector<int> solution = reconstructSolution(matrix, p, b, acumBenefit);
	return solution;
}

int main() {

}