#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Arista {
	int inicio;
	int fin;
	int peso;

	bool operator <(Arista otra) {
		return peso < otra.peso;
	}
};

vector<Arista> kruskal(int numVertices, vector<Arista> grafo, int& acumulado) {
	sort(grafo.begin(), grafo.end());
	vector<int> vertices(numVertices);
	vector<Arista> MST;
	for (int i = 0; i < numVertices; i++) {
		vertices[i] = i;
	}
	for (auto g : grafo) {
		auto a = g.inicio;
		auto b = g.fin;

		if (vertices[a] != vertices[b]) {
			MST.push_back(g);

			int colorAnterior = vertices[b];
			int colorNuevo = vertices[a];

			acumulado += g.peso;

			for (int i = 0; i < numVertices; i++) {
				if (vertices[i] == colorAnterior) {
					vertices[i] = colorNuevo;
				}
			}
		}
	}
	return MST;
}

int main() {
	Arista e1(0, 1, 1);
	Arista e2(0, 2, 3);
	Arista e3(1, 2, 3);
	Arista e4(1, 3, 6);
	Arista e5(2, 3, 4);
	Arista e6(2, 4, 2);
	Arista e7(3, 4, 5);

	vector<Arista> grafo = { e1,e2,e3,e4,e5,e6,e7 };

	int acumulado = 0;

	vector<Arista> sol = kruskal(5, grafo, acumulado);

	cout << "El acumulado de pesos es " << acumulado << endl;
	cout << "Se uso las aristas:" << endl;
	for (int i = 0; i < sol.size();i++) {
		cout << "ini: " << sol[i].inicio << " ; fin: " << sol[i].fin << " ; peso: " << sol[i].peso << endl;
	}

	return 0;
}
//Agrupacion por "color" para saber si estan dentro del grupo o no, esto evita los ciclos y mapea los vertices usados
//Tener cuidado con == y =