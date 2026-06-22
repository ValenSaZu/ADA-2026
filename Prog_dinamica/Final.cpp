#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Construye la matriz de costos mínimos para los segmentos de palo
vector<vector<int>> constructMatrix(const vector<int>& C) {
    int m = C.size();
    // matrix[i][j] guardará el costo mínimo del segmento desde el corte C[i] hasta C[j]
    vector<vector<int>> matrix(m, vector<int>(m, 0));

    // d es la distancia en número de cortes entre el extremo izquierdo i y el derecho j
    for (int d = 2; d < m; d++) {
        for (int i = 0; i < m - d; i++) {
            int j = i + d;
            matrix[i][j] = INT_MAX; // Buscamos el mínimo, inicializamos en infinito

            // Probamos todos los cortes intermedios posibles 'k' para romper el segmento
            for (int k = i + 1; k < j; k++) {
                int costoActual = (C[j] - C[i]) + matrix[i][k] + matrix[k][j];
                matrix[i][j] = min(matrix[i][j], costoActual); // MINIMIZAMOS costos
            }
        }
    }
    return matrix;
}

// Reconstruye el orden óptimo de las posiciones de corte
// k_elegidos guardará la secuencia de posiciones exactas donde se debe cortar consecutivamente
void reconstructSolution(const vector<vector<int>>& matrix, const vector<int>& C, int i, int j, vector<int>& k_elegidos) {
    if (i + 1 >= j) return; // No hay cortes intermedios posibles

    // Buscamos cuál fue el 'k' que produjo el valor óptimo guardado en matrix[i][j]
    for (int k = i + 1; k < j; k++) {
        if (matrix[i][j] == (C[j] - C[i]) + matrix[i][k] + matrix[k][j]) {
            k_elegidos.push_back(C[k]); // Guardamos el punto de corte en metros
            
            // Resolvemos recursivamente para los dos nuevos sub-palos generados
            reconstructSolution(matrix, C, i, k, k_elegidos);
            reconstructSolution(matrix, C, k, j, k_elegidos);
            break; 
        }
    }
}

// Función principal que unifica la programación dinámica
vector<int> prog_dinamica_cortes(int longitudPalo, vector<int> cortes, int& costoMinimo) {
    // Creamos el vector completo de puntos de referencia incluyendo los extremos 0 y longitudPalo
    vector<int> C;
    C.push_back(0);
    for (int x : cortes) C.push_back(x);
    C.push_back(longitudPalo);
    
    // Nos aseguramos de que los cortes intermedios estén ordenados de menor a mayor
    sort(C.begin() + 1, C.end() - 1);

    // 1. Construir matriz
    vector<vector<int>> matrix = constructMatrix(C);
    
    // El costo total mínimo estará en el segmento que cubre desde el inicio (0) hasta el final (m-1)
    costoMinimo = matrix[0][C.size() - 1];

    // 2. Reconstruir solución
    vector<int> ordenCortes;
    reconstructSolution(matrix, C, 0, C.size() - 1, ordenCortes);
    
    return ordenCortes;
}

int main() {
    // --- CASO A de tu imagen ---
    int longitudA = 100;
    vector<int> cortesA = {25, 50, 75};
    int costoA = 0;

    vector<int> ordenA = prog_dinamica_cortes(longitudA, cortesA, costoA);

    cout << "=== CASO A ===" << endl;
    cout << "Costo minimo: " << costoA << endl;
    cout << "Orden optimo de cortes (metros): ";
    for (int x : ordenA) cout << x << " ";
    cout << "\n\n";

    // --- CASO B de tu imagen ---
    int longitudB = 10;
    vector<int> cortesB = {4, 5, 7, 8};
    int costoB = 0;

    vector<int> ordenB = prog_dinamica_cortes(longitudB, cortesB, costoB);

    cout << "=== CASO B ===" << endl;
    cout << "Costo minimo: " << costoB << endl;
    cout << "Orden optimo de cortes (metros): ";
    for (int x : ordenB) cout << x << " ";
    cout << endl;

    return 0;
}