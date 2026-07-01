#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxNumContenedores(vector<int> pesos, int M) {
	vector<int> objetos;
	sort(pesos.begin(), pesos.end());

	int pesoAcum = 0;
	int i = 0;
	while (i < pesos.size() && pesoAcum + pesos[i] <= M) {
		pesoAcum += pesos[i];
		objetos.push_back(pesos[i]);
		i++;
	}

	return objetos;
}

vector<int> maxPeso(vector<int> pesos, int M) {
	vector<int> objetos;
	sort(pesos.rbegin(), pesos.rend());

	int pesoAcum = 0;
	int i = 0;
    while (i < pesos.size()) {
		if (pesoAcum + pesos[i] <= M) {
			pesoAcum += pesos[i];
			objetos.push_back(pesos[i]);
		}
        i++;
	}

	return objetos;
}

void imprimirResultado(const string& mensaje, const vector<int>& contenedores) {
    cout << mensaje << "[ ";
    int suma = 0;
    for (int peso : contenedores) {
        cout << peso << " ";
        suma += peso;
    }
    cout << "] -> Total contenedores: " << contenedores.size()
        << " | Toneladas totales: " << suma << "t\n";
}

int main() {
    // --- Caso de Prueba 1: Probando Maximizar Cantidad ---
    int capacidadBuque1 = 30;
    vector<int> contenedores1 = { 10, 2, 5, 20, 3, 8 };

    cout << "=== CASO DE PRUEBA 1 ===" << endl;
    cout << "Capacidad del buque: " << capacidadBuque1 << " toneladas." << endl;

    vector<int> resultadoA = maxNumContenedores(contenedores1, capacidadBuque1);
    imprimirResultado("Contenedores cargados (Max Cantidad): ", resultadoA);

    cout << "\n--------------------------------------------------\n\n";

    // --- Caso de Prueba 2: Demostración de por qué el apartado B es una heurística ---
    int capacidadBuque2 = 10;
    vector<int> contenedores2 = { 9, 5, 5 };

    cout << "=== CASO DE PRUEBA 2 (Contraejemplo para el peso) ===" << endl;
    cout << "Capacidad del buque: " << capacidadBuque2 << " toneladas." << endl;
    cout << "Pesos disponibles: { 9, 5, 5 }" << endl;

    vector<int> resultadoB = maxPeso(contenedores2, capacidadBuque2);
    imprimirResultado("Resultado del Algoritmo Voraz (Max Peso): ", resultadoB);

    cout << "Nota: La solución óptima real sería cargar { 5, 5 } para sumar 10t, "
        << "pero el enfoque voraz se queda en 9t." << endl;

    return 0;
}