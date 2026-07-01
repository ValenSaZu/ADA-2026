#include <vector>
#include <algorithm>

using namespace std;

int particion(vector<int>& Array, int inicio, int final) {
	int pivote = Array[inicio];
	int i = inicio + 1;
	int j = final - 1;
	while (true) {
		while (i < final && Array[i] <= pivote) {
			i++;
		}
		while (Array[j] > pivote) {
			j--;
		}
		if (i >= j) break;
		swap(Array[i], Array[j]);
	}
	swap(Array[inicio], Array[j]);
	return j;
}

int quickMediana(vector<int>& Array, int inicio, int final, int posMediana) {
	int pos = particion(Array, inicio, final);
	if (pos == posMediana) {
		return Array[j];
	}
	else if (pos < posMediana) {
		quickMediana(Array, pos + 1, final, posMediana);
	}
	else {
		quickMediana(Array, inicio, pos - 1, posMediana);
	}
}

int Mediana(vector<int>& Array) {
	int posMediana = Array.size() / 2;
	int median = quickMediana(Array, 0, Array.size(), posMediana);
	if (Array.size() % 2 == 0) {
		median = (quickMediana(Array, posMediana + 1, Array.size(), 0) + median) / 2;
	}
	return median;
}

int main() {
	return 0;
}