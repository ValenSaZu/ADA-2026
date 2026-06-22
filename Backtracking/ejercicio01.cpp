#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> soa;
void solve(int nivel, int& bestSol, int actualSol, vector<int>arr1, vector<int>arr2, vector<int>& arr3) {
	if (nivel >= arr1.size()) {
		if (actualSol < bestSol) {
			bestSol = actualSol;
			soa = arr3;
		}
		return;
	}

	for (int esqui = 0; esqui < arr2.size(); esqui++) {
		if (arr3[esqui] == -1) {
			arr3[esqui] = nivel;
			int diff = abs(arr1[nivel] - arr2[esqui]);
			solve(nivel+1, bestSol, actualSol + diff, arr1, arr2, arr3);
			arr3[esqui] = -1;
		}
	}
}

int backtracking(vector<int>arr1, vector<int>arr2) {
	int voa = INT_MAX;
    vector<int>arr3(arr2.size(), -1);
	solve(0, voa, 0, arr1, arr2, arr3);
	return voa;
}

int main() {
	vector<int>Altura = { 178, 168, 190, 170 };
	vector<int>Longitud = { 183, 188, 168, 175 };
	int voa = backtracking(Altura, Longitud);
	cout << "El minimo absoluto de las diferencias es: " << voa << endl;
	for (int i = 0; i < soa.size(); i++) {
		cout << "El esqui de " << Longitud[i] << " le pertenece al alumno que mide " << Altura[soa[i]] << endl;
	}
	return 0;
}

//no modificar directamente los parametros