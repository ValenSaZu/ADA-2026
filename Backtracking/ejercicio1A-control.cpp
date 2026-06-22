#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<int> soa;

void solve(int nivel, int total, int partialSol, int& bestSol, int actualSol, vector<int> arr1, vector<int>& arr2) {
	if (partialSol == total) {
		if (actualSol < bestSol) {
			bestSol = actualSol;
			soa = arr2;
		}
		return;
	}
	if (partialSol > total || nivel >= arr1.size()) {
		return;
	}
	if (partialSol + arr1[nivel] <= total) {
		arr2[nivel]++;
		solve(nivel, total, partialSol + arr1[nivel], bestSol, actualSol + 1, arr1, arr2);
		arr2[nivel]--;
	}
	solve(nivel + 1, total, partialSol, bestSol, actualSol, arr1, arr2);
}

int backtracking(int total, vector<int> arr1) {
	int voa = INT_MAX;
	vector<int> arr2(arr1.size(), 0);
	solve(0, total, 0, voa, 0, arr1, arr2);
	return voa;
}

int main() {
	vector<int> monedas = { 1, 3, 4 };
	int cantMonedas = backtracking(10, monedas);
	cout << "La cantidad de monedas dadas es " << cantMonedas << endl;
	for (int i = 0; i < monedas.size(); i++) {
		if (soa[i] > 0) {
			cout << soa[i] << " monedas de " << monedas[i] << endl;
		}
	}
	return 0;
}

//Pensar bien cual es la condicion de corte para obtener la solucion optima sin olvidar tomar en cuenta el tam del vector