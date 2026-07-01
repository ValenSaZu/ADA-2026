#include <iostream>
#include <vector>

using namespace std;

//Devuelve el nuevo fin del Array
int combinar(vector<int>& Array, int inicio, int mitad, int final) {
    int n1 = mitad - inicio + 1;
    int n2 = final - mitad;

    vector<int> L(n1), R(n2); // Inicializar vectores con su tamaño correcto

    for (int i = 0; i < n1; i++)
        L[i] = Array[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = Array[mitad + 1 + j];// Tener cuidado en la inicializacion

    vector<int> temporal;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        int candidato;
        if (L[i] < R[j]) {
            candidato = L[i++];
        }
        else if (R[j] < L[i]) {
            candidato = R[j++];
        }
        else { // Duplicados, elegir solo uno
            candidato = L[i++];
            j++;
        }

        // Solo agregamos si el temporal está vacío o si no es igual al último agregado
        if (temporal.empty() || temporal.back() != candidato) {
            temporal.push_back(candidato);
        }
    }

    while (i < n1) {
        int candidato = L[i++];
        if (temporal.empty() || temporal.back() != candidato) {
            temporal.push_back(candidato);
        }
    }

    while (j < n2) {
        int candidato = R[j++];
        if (temporal.empty() || temporal.back() != candidato) {
            temporal.push_back(candidato);
        }
    }

    // Reemplazar los datos
    for (int idx = 0; idx < temporal.size(); idx++) {
        Array[inicio + idx] = temporal[idx];
    }

    return inicio + temporal.size() - 1;
}

// Retorna el nuevo límite final del subarreglo procesado
int mergeSort(vector<int>& Array, int inicio, int final) {
    if (inicio < final) {
        // La mitad debe ser relativa a los límites actuales
        int mitad = inicio + (final - inicio) / 2;

        int nuevo_limite_izq = mergeSort(Array, inicio, mitad);
        int nuevo_limite_der = mergeSort(Array, nuevo_limite_izq + 1, final);

        return combinar(Array, inicio, nuevo_limite_izq, nuevo_limite_der);
    }
    return final;
}

int main() {
    vector<int> Array = { 8, 3, 5, 3, 1, 8, 7, 5, 2, 8 };

    // Guardamos el nuevo tamaño final que tendrá el vector tras los borrados
    int final_real = mergeSort(Array, 0, Array.size() - 1);

    // Redimensionamos el vector al tamaño real de sobrevivientes
    Array.resize(final_real + 1);

    // Imprimir resultado
    for (int i = 0; i < Array.size(); i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}