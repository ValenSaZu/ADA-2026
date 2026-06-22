#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particion(vector<int>& Array, int inicio, int final) {
    int pivote = Array[inicio];
    int i = inicio + 1;
    int j = final;
    while (true) {
        // i encuentra uno mayor al pivote
        while (i <= final && Array[i] <= pivote) {
            i++;
        }
        // j encuentra uno menor al pivote
        while (Array[j] > pivote) {
            j--;
        }
        //si el mayor al pivote ya esta despues del menor al pivote, ya esta terminado
        if (i >= j) break;
        // si no, cambia
        swap(Array[i], Array[j]);
    }
    //colocar el pivote en medio, con sus menores a la izquierda y mayores a la derecha
    swap(Array[inicio], Array[j]);
    //retorna donde dejo el pivote
    return j;
}

void quickSort(vector<int>& Array, int inicio, int final) {
    if (inicio < final) {
        int pivote = particion(Array, inicio, final);
        // ordena los lados sin qitar de su lugar al pivote
        quickSort(Array, inicio, pivote - 1);
        quickSort(Array, pivote + 1, final);
    }
}

int main()
{
    cout << "Hello World!\n";
}