#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> constructMatrix(vector<pair<int,int>> cadena1, vector<pair<int, int>> cadena2, int ini1, int ini2, int x1, int x2, int& finalcost1, int& finalcost2) {
	vector<vector<pair<int, int>>> matrix(2, vector<pair<int, int>>(cadena1.size(), {0, -1}));

	matrix[0][0].first = cadena1[0].first + ini1;
	matrix[1][0].first = cadena2[0].first + ini2;

	for (int j = 1; j < cadena1.size(); j++) {
		int actualChain1 = matrix[0][j - 1].first + cadena1[j].first;
		int otherChain1 = matrix[1][j - 1].first + cadena2[j - 1].second + cadena1[j].first;

		int actualChain2 = matrix[1][j - 1].first + cadena2[j].first;
		int otherChain2 = matrix[0][j - 1].first + cadena1[j - 1].second + cadena2[j].first;
		
		if (otherChain1 < actualChain1) {
			matrix[0][j].first = otherChain1;
			matrix[0][j].second = 1;
		}
		else if (actualChain1 <= otherChain1) {
			matrix[0][j].first = actualChain1;
			matrix[0][j].second = 0;
		}

		if (otherChain2 < actualChain2) {
			matrix[1][j].first = otherChain2;
			matrix[1][j].second = 0;
		}
		else if (actualChain2 <= otherChain2) {
			matrix[1][j].first = actualChain2;
			matrix[1][j].second = 1;
		}
	}

	finalcost1 = matrix[0][cadena1.size() - 1].first + x1;
	finalcost2 = matrix[1][cadena1.size() - 1].first + x2;

	return matrix;
}

vector<int> reconstructSolution(vector<vector<pair<int, int>>> matrix, int& finalCost1, int& finalCost2) {
	int n = matrix[0].size();
	vector<int> solution(n);
	int carril;

	if (finalCost1 < finalCost2) {
		carril = 0;
	}
	else {
		carril = 1;
	}

	solution[n - 1] = carril;

	for (int i = n - 1; i > 0; i--) {
		solution[i - 1] = matrix[carril][i].second;
		carril = matrix[carril][i].second;
	}

	return solution;
}

int main() {
	int entrada1 = 2;
	int entrada2 = 4;

	int salida1 = 3;
	int salida2 = 2;

	// .first = tiempo de estación, .second = tiempo de cruce a la otra línea
	vector<pair<int, int>> cadena1 = {
		{7, 2}, {9, 3}, {3, 1}, {4, 3}, {8, 4}, {4, 0}
	};

	vector<pair<int, int>> cadena2 = {
		{8, 2}, {5, 1}, {6, 2}, {4, 2}, {5, 1}, {7, 0}
	};

	int costoFinal1 = 0;
	int costoFinal2 = 0;

	// 1. Calcular la matriz de programación dinámica
	vector<vector<pair<int, int>>> matrix = constructMatrix(cadena1, cadena2, entrada1, entrada2, salida1, salida2, costoFinal1, costoFinal2);

	// 2. Obtener el costo óptimo absoluto
	int costoMinimo = min(costoFinal1, costoFinal2);
	cout << "El tiempo minimo total de fabricacion es: " << costoMinimo << " minutos.\n" << endl;

	// 3. Reconstruir el camino óptimo tomado
	vector<int> ruta = reconstructSolution(matrix, costoFinal1, costoFinal2);

	// 4. Mostrar el resultado amigable en la consola (sumamos 1 para que las líneas se vean como 1 y 2 en vez de 0 y 1)
	cout << "Ruta optima de estaciones a seguir:" << endl;
	for (int i = 0; i < ruta.size(); i++) {
		cout << "Estacion " << (i + 1) << " -> Linea de montaje " << (ruta[i] + 1) << endl;
	}

	return 0;
}