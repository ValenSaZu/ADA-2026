#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particion(vector<int>& Array, int ini, int fin) {
	//usare la mitad como pivote ya que dice que est[a semiordenado
	swap(Array[ini], Array[(fin - ini) / 2]);
	int pivote = ini;
	int i = ini+1;
	int j = fin-1;
	while (true) {
		while (i < fin && Array[i] <= pivote) {
			i++;
		}
		while (Array[j] > pivote) {
			j--;
		}
		if (i >= j) break;
		swap(Array[i], Array[j]);
	}
	swap(Array[ini], Array[j]);
	return j;
}

int particionPair(vector<vector<int>>& matriz, vector<pair<int,int>>& Array, int ini, int fin) {
	//usare la mitad como pivote ya que dice que esta semiordenado
	swap(Array[ini], Array[(fin - ini) / 2]);
	swap(matriz[Array[ini].first], matriz[Array[(fin - ini) / 2].first]);
	int pivote = ini;
	int i = ini + 1;
	int j = fin-1;
	while (true) {
		while (i < fin && Array[i].second <= pivote) {
			i++;
		}
		while (Array[j].second > pivote) {
			j--;
		}
		if (i >= j) break;
		swap(Array[i], Array[j]);
		swap(matriz[Array[i].first], matriz[Array[j].first]);
	}
	swap(Array[ini], Array[j]);
	swap(matriz[Array[ini].first], matriz[Array[j].first]);
	return j;
}

void quickSort(vector<int>&Array, int ini, int fin) {
	if (ini < fin) {
		int part = particion(Array, ini, fin);
		quickSort(Array, ini, part - 1);
		quickSort(Array, part + 1, fin);
	}
}

void quickSortPair(vector<vector<int>>& matriz, vector<pair<int,int>>& Array, int ini, int fin) {
	if (ini < fin) {
		int part = particionPair(matriz, Array, ini, fin);
		quickSortPair(matriz, Array, ini, part - 1);
		quickSortPair(matriz, Array, part + 1, fin);
	}
}

void solucion(vector<vector<int>>& matriz) {
	vector<pair<int, int>> iniVectors;
	//ordenar cada vector de la matriz
	for (int i = 0; i < matriz.size();i++) {
		quickSort(matriz[i], 0, matriz.size());
		iniVectors.push_back(make_pair(i,matriz[i][0]));
	}
	//ordenar orden de vectores
	quickSortPair(matriz, iniVectors, 0, iniVectors.size());
}

int main() {
	return 0;
}