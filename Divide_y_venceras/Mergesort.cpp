#include <iostream>
#include <vector>

using namespace std;

void combinar(vector<int>& Array, int inicio, int mitad, int final) {
    int n1 = mitad - inicio + 1;
    int n2 = final - mitad;
    vector<int> L, R;
    //Copiar los datos de ambas partes del array
    for (int i = 0; i < n1; i++)
        L[i] = Array[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = Array[mitad + 1 + j];
    int i = 0, j = 0, k = inicio;
    //Coloca el menor de las listas reemplazando en el Array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            Array[k++] = L[i++];
        else
            Array[k++] = R[j++];
    }
    //Agrega lo que pudiera haber faltado
    while (i < n1)
        Array[k++] = L[i++];
    while (j < n2)
        Array[k++] = R[j++];
}

void mergeSort(vector<int>& Array, int inicio, int final) {
    if (inicio < final) {
        int mitad = (inicio + final) / 2;
        mergeSort(Array, inicio, mitad);
        mergeSort(Array, mitad+1,final);
        combinar(Array, inicio, mitad, final);
    }
}

int main()
{
    cout << "Hello World!\n";
}