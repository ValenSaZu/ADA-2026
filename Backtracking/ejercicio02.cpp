#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<int> soa; // Solucion Optima Activa

void solve(int nivel, int capacity, int actualWeight, int& bestSol, int actualSol, vector<int>arr1, vector<int>arr2, vector<int>&arr3) {
	if (nivel >= arr1.size()) {
		if (actualSol > bestSol) {
			bestSol = actualSol;
			soa = arr3;
		}
		return;
	}
	//para cuando lo elige
	if (actualWeight + arr1[nivel] <= capacity) {
		arr3[nivel] = 1;
		solve(nivel + 1, capacity, actualWeight + arr1[nivel], bestSol, actualSol + arr2[nivel], arr1, arr2, arr3);
		arr3[nivel] = 0;
	}
	//para cuando no
	if (actualWeight <= capacity) solve(nivel + 1, capacity, actualWeight, bestSol, actualSol, arr1, arr2, arr3);
}

int backtracking(int capacity, vector<int>arr1, vector<int>arr2) {
	int voa = INT_MIN;
	vector<int> arr3(arr1.size(), 0);
	solve(0, capacity, 0, voa, 0, arr1, arr2, arr3);
	return voa;
}

int main() {
	vector<int> Weights = { 1, 11, 21, 23, 33 };
	vector<int> Benefits = { 11, 21, 31, 33, 43 };
	int voa = backtracking(61, Weights, Benefits);
	cout << "El mayor beneficio es " << voa << endl;
	cout << "Los objetos elegidos son aquellos con los pesos:" << endl;
	for (int i = 0; i < soa.size(); i++) {
		if (soa[i] == 1) cout << Weights[i]<<endl;
	}
	return 0;
}

// Tomar en cuenta la opcion de no elegir