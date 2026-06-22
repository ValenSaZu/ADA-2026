#include <vector>
#include <climits>
#include <iostream>

using namespace std;

vector<int> soa;

void solve(int nivel, int& bestSol, int actualSol, vector<vector<int>> arr1, vector<int> arr2) {
	if (nivel >= arr1.size()) {
		if (actualSol < bestSol) {
			bestSol = actualSol;
			soa = arr2;
		}
		return;
	}
	for (int tarea = 0; tarea < arr1[0].size(); tarea++) {
		if (arr2[tarea] == -1) {
			arr2[tarea] = nivel;
			solve(nivel + 1, bestSol, actualSol + arr1[nivel][tarea], arr1, arr2);
			arr2[tarea] = -1;
		}
	}
}

int backtracking(vector<vector<int>> arr) {
	int voa = INT_MAX;
	vector<int> arr2(arr[0].size(), -1);
	solve(0, voa, 0, arr, arr2);
	return voa;
}

int main() {
	vector<int> w1 = { 9,2,7 };
	vector<int> w2 = { 6,4,3 };
	vector<int> w3 = { 5,8,1 };

	vector<vector<int>> matrix = { w1,w2,w3 };

	int voa = backtracking(matrix);

	cout << "El costo minimo es " << voa << endl;
	
	cout << "Se eligio en cada tarea: " << endl;

	for (int i = 0; i < soa.size(); i++) {
		cout << "Tarea " << i << " : Trabajador " << soa[i] << " con costo " << matrix[soa[i]][i] << endl;
	}
}

//Pensar bien cuando se necesita bucle