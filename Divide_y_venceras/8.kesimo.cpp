#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particion(vector<int>& Array, int ini, int fin) {
	int pivote = Array[ini];
	int x = ini + 1;
	int y = fin;
	while (true) {
		while (x <= fin && Array[x] <= pivote) {// se debe poner exacto donde termina
			x++;
		}
		while (Array[y] > pivote) {e
			y--;
		}
		if (x >= y) break;
		swap(Array[x], Array[y]);
	}
	swap(Array[ini], Array[y]);
	return y;
}

int quick(vector<int>& Array, int ini, int fin, int kesimo) {
	int pivote = particion(Array, ini, fin);
	if (pivote == kesimo) return Array[kesimo];
	else if (pivote > kesimo) return quick(Array, ini, pivote - 1, kesimo);
	else if (pivote < kesimo) return quick(Array, pivote + 1, fin, kesimo);
}

int main() {
	return 0;
}