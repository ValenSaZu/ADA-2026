#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> elegirTareas(vector<int> beneficio, vector<int> plazo, int M, int& acumBenefit) {
	vector<pair<int, int>> tareas(plazo.size());
	vector<int> plazosTareas(M, -1);

	vector<pair<int, int>> sol;

	for (int i = 0; i < plazo.size(); i++) {
		tareas[i] = { beneficio[i], plazo[i] };
	}

	sort(tareas.rbegin(), tareas.rend());

	int i = 0;
	acumBenefit = 0;
	while (i < plazo.size()) {
		// Buscar lugar para las tareas con  mayor beneficio
		int intento_indice = tareas[i].second - 1;

		// Mientras el índice sea válido (>= 0)
		while (intento_indice >= 0) {
			// Si el slot está libre, lo tomamos
			if (plazosTareas[intento_indice] == -1) {
				acumBenefit += tareas[i].first;
				plazosTareas[intento_indice] = tareas[i].first;
				sol.push_back(tareas[i]);
				break; // Ya encontramos sitio para esta tarea, salimos del while interno
			}
			// Si estaba ocupado, restamos 1 para intentar en el día anterior
			intento_indice--;
		}
		i++;
	}
	return sol;
}

int main() {
	vector<int> beneficio = { 50, 10, 15, 30 };
	vector<int> plazos = { 2, 1, 2, 1 };

	int acumBenefit;

	vector<pair<int, int>> tareas_elegidas = elegirTareas(beneficio, plazos, 2, acumBenefit);

	cout << "Para el beneficio " << acumBenefit << " se eligieron las tareas: " << endl;
	for (int i = 0; i < tareas_elegidas.size(); i++) {
		cout << "Con beneficio " << tareas_elegidas[i].first << " y plazo " << tareas_elegidas[i].second << endl;
	}
}