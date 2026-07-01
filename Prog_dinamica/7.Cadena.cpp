#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> constructMatrix(vector<int> pesos) {
	vector<vector<pair<int, int>>> matrix(pesos.size(), vector<pair<int, int>>(pesos.size(), { INT_MAX, -1 }));
	// un eslabon
	for (int i = 0; i < pesos.size(); i++) matrix[i][i] = { 0, i };
	// dos a mas eslabones
	for (int j = 1; j < pesos.size(); j++) {
		for(int i = 0; i < pesos.size() - j; i++){
			int corte = -1;
			for (int k = i; k < j + i; k++) {
				int costo_corte = matrix[i][k].first + matrix[k + 1][j + i].first + pesos[i] + pesos[j + i] + pesos[k] + pesos[k + 1];
				if (costo_corte < matrix[i][j + i].first) { // si otro corte es menor que el costo en la casilla actual
					matrix[i][j + i] = { costo_corte, k };
				}
			}
		}
	}
	return matrix;
}

void reconstructSolution(vector<vector<pair<int, int>>>& matrix, int ini, int fin) {
	if (ini == fin) {
		cout << "e" << ini;
		return;
	}
	cout << "(";
	reconstructSolution(matrix, ini, matrix[ini][fin].second);
	cout << " - ";
	reconstructSolution(matrix, matrix[ini][fin].second + 1, fin);
	cout << ")";
}

int main() {
	// Ejemplo con 4 eslabones y sus respectivos pesos
	// e0 = 10, e1 = 1, e2 = 5, e3 = 10
	vector<int> pesos = { 10, 1, 5, 10 };

	// 1. Construimos la matriz con los costos y cortes
	vector<vector<pair<int, int>>> matrix = constructMatrix(pesos);

	// 2. Reconstruimos e imprimimos la solución óptima
	cout << "El costo minimo es: " << matrix[0][pesos.size() - 1].first << endl;
	reconstructSolution(matrix, 0, pesos.size()-1);

	return 0;
}
