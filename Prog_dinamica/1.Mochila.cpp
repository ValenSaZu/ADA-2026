#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> constructMatrix(vector<int> p, vector<int>b, int m) {
	vector<vector<int>> matrix(p.size() + 1, vector<int>(m + 1, 0));

	for (int i = 1;i <= p.size();i++) {
		for (int j = 1;j <= m;j++) {
			if (j - p[i - 1] >= 0) {
				matrix[i][j] = max(matrix[i - 1][j], b[i - 1] + matrix[i - 1][j - p[i - 1]]);
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
	// ---------- EJERCICIO 1 -----------------------------------------------
	vector<int> peso1 = { 3,7,4,2,1,6 };
	vector<int> beneficio1 = { 12,3,7,4,3,8 };
	int M1 = 15;
	int acumBenefit1 = 0;

	vector<int> sol1 = prog_dinamica(peso1, beneficio1, M1, acumBenefit1);

	cout << "El beneficio total del primer ejercicio es: " << acumBenefit1 << endl;
	cout << "Los objetos que se seleccionaron son: " << endl;
	for (int i = 0;i < sol1.size(); i++) {
		if (sol1[i] == 1)cout << i + 1 << " ";
	}
	cout << "\n" << endl;

	// ---------- EJERCICIO 2 -----------------------------------------------

	vector<int> peso2 = { 51,119,68,34,17,102 };
	vector<int> beneficio2 = { 204,51,119,68,51,136 };
	int M2 = 255;
	int acumBenefit2 = 0;

	vector<int> sol2 = prog_dinamica(peso2, beneficio2, M2, acumBenefit2);

	cout << "El beneficio total del segundo ejercicio es: " << acumBenefit2 << endl;
	cout << "Los objetos que se seleccionaron son: " << endl;
	for (int i = 0;i < sol2.size(); i++) {
		if (sol2[i] == 1)cout << i + 1 << " ";
	}
	cout << "\n" << endl;

	// ---------- EJERCICIO 3 -----------------------------------------------

	vector<int> peso3 = { 130,570,140,200,360,400 };
	vector<int> beneficio3 = { 120,300,570,423,300,800 };
	int M3 = 1000;
	int acumBenefit3 = 0;

	vector<int> sol3 = prog_dinamica(peso3, beneficio3, M3, acumBenefit3);

	cout << "El beneficio total del tercer ejercicio es: " << acumBenefit3 << endl;
	cout << "Los objetos que se seleccionaron son: " << endl;
	for (int i = 0;i < sol3.size(); i++) {
		if (sol3[i] == 1)cout << i + 1 << " ";
	}
	cout << endl;
}