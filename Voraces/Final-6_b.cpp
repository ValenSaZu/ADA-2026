#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Arista {
	int inicio;
	int fin;
	int peso;
};

vector<Arista> prim(int numVertices, vector<Arista> grafo, int& acumulado) {
	vector<bool> verticesUsados(numVertices, false);
	int verticesConectados = 1;
	verticesUsados[0] = true; //Aqui es donde se deberia elegir por donde se inicia

	vector<Arista> MST;

	while (verticesConectados < numVertices) {
		int min = INT_MAX;
		int ind = -1;
		for (int i = 0; i < grafo.size(); i++) {
			int ini = grafo[i].inicio;
			int fin = grafo[i].fin;
			if ((verticesUsados[ini] && !verticesUsados[fin]) || (verticesUsados[fin] && !verticesUsados[ini])) {
				if (grafo[i].peso < min) {
					min = grafo[i].peso;
					ind = i;
				}
			}
		}

		MST.push_back(grafo[ind]);
		verticesUsados[grafo[ind].inicio] = true;
		verticesUsados[grafo[ind].fin] = true;

		acumulado += min;
		verticesConectados++;
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

	vector<Arista> sol = prim(5, grafo, acumulado);

	cout << "El acumulado de pesos es " << acumulado << endl;
	cout << "Se uso las aristas:" << endl;
	for (int i = 0; i < sol.size();i++) {
		cout << "ini: " << sol[i].inicio << " ; fin: " << sol[i].fin << " ; peso: " << sol[i].peso << endl;
	}

	return 0;
}
//Tener cuidado con las variables que van dentro del bucle