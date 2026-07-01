#include <iostream>
#include <vector>

using namespace std;

bool quick(vector<int>& Array, int ini, int fin) {
	if (ini > fin) { //Caso base siempre primero
		return false;
	}
	int pivote = ini + (fin - ini) / 2; //cuidado con la mitad
	if (Array[pivote] == pivote) {
		return true;
	}
	else if (Array[pivote] > pivote) {
		return quick(Array, ini, pivote - 1);
	}
	else {
		return quick(Array, pivote + 1, fin);
	}
}

int main() {
	vector<int> Array = { -3, 0, 1, 2, 4, 5, 8, 9 };
	if (quick(Array, 0, Array.size() - 1)) {
		cout << "Hay alguno que coincide";
	}
	else {
		cout << "No coincide ninguna";
	}
	return 0;
}