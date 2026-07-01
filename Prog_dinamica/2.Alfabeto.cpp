#include <vector>
#include <iostream>
#include <algorithm> // tener cuidado con librerias necesarias

using namespace std;

template <typename T>
bool f(vector<T> secuencia, T x, T y) {
	for (int i = 0; i < secuencia.size() - 1; i++) {
		if (secuencia[i] == x) return secuencia[i + 1] == y;
	}
	return false;
}

template <typename T>
vector<vector<bool>> constructMatrix(vector<T> alfabeto, vector<T> secuenciaSecreta) {
	vector<vector<bool>> matrix(alfabeto.size(), vector<bool>(alfabeto.size(), false));

	for (int i = 0; i < alfabeto.size(); i++) {
		for (int j = 0; j < alfabeto.size(); j++) {
			matrix[i][j] = f(secuenciaSecreta, alfabeto[i], alfabeto[j]);
		}
	}

	return matrix;
}

template <typename T>
vector<T> matrixWithTransition(vector<vector<bool>>& matrix, vector<T> alfabeto) {
	int n = alfabeto.size();

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][k] && matrix[k][j]) {
					matrix[i][j] = true;
				}
			}
		}
	}

	vector<T> secuencia;
	vector<pair<int, T>> procedencias;

	for (int i = 0; i < n; i++) {
		int nProcedencia = 0;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j]) nProcedencia++;
		}
		procedencias.push_back({ nProcedencia, alfabeto[i] });
	}

	sort(procedencias.rbegin(), procedencias.rend());

	for (int i = 0; i < n; i++) {
		secuencia.push_back(procedencias[i].second);
	}

	return secuencia;
}

template <typename T>
int buscarIndice(vector<T> alfabeto, T elemento) {
	for (int i = 0; i < alfabeto.size(); i++) {
		if (alfabeto[i] == elemento) return i;
	}
	return -1;
}

template <typename T>
bool existConection(vector<vector<bool>> matrix, vector<T> alfabeto, T x, T y) {
	int idxX = buscarIndice(alfabeto, x);
	int idxY = buscarIndice(alfabeto, y);
	if (idxX == -1 || idxY == -1) return false;
	return matrix[idxX][idxY];
}

int main() {
	vector<char> alfabeto = { 'a', 'b', 'c', 'd' };

	vector<char> secuenciaSecreta = { 'c', 'd', 'b', 'a' };
	vector<vector<bool>> matrix = (constructMatrix(alfabeto, secuenciaSecreta));

	vector<char> secuencia = matrixWithTransition(matrix, alfabeto);

	char x = 'd';
	char y = 'a';

	if (existConection(matrix, alfabeto, x, y)) {
		cout << "Existe una conexion entre: " << x << " y " << y << endl;
	}
	else {
		cout << "No hay conexion" << endl;
	}
}