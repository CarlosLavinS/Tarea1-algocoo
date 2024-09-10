#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Funcion para hacer la partición del arreglo
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  //Elegimos el ultimo elemento como pivote
    int i = low - 1;        //Indice del menor elemento

    for (int j = low; j <= high - 1; j++) {
        //Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  //Intercambiamos los elementos
        }
    }

    swap(arr[i + 1], arr[high]);  //Colocar el pivote en su lugar
    return i + 1;  //Retornamos el índice del pivote
}

//Implementación de QuickSort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        //Particionar el arreglo
        int pi = partition(arr, low, high);

        //Ordenar las dos mitades
        quickSort(arr, low, pi - 1);  //ado izquierdo del pivote
        quickSort(arr, pi + 1, high); //Lado derecho del pivote
    }
}

int main(int argc, char* argv[]) {
   

    //Abrir el archivo pasado como argumento
    ifstream archivo(argv[1]);
    vector<int> arr;
    int numero;

    //Leer los números del archivo
    while (archivo >> numero) {
        arr.push_back(numero);
    }

    archivo.close();


    //Iniciar la medición de tiempo
    auto inicio = high_resolution_clock::now();

    //Llamar a QuickSort
    quickSort(arr, 0, arr.size() - 1);

    //Detener la medición de tiempo
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    //Imprimir el arreglo ordenado
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos" << endl;

    return 0;
}
