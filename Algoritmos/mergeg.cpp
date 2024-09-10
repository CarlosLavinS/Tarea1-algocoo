#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Función que mezcla dos subarreglos de arr[].
//El primer subarreglo es arr[left..mid]
//El segundo subarreglo es arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //Crear vectores temporales
    vector<int> L(n1), R(n2);

    //Copiar datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    //Mezclar los vectores temporales de nuevo en arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Copiar los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Funcion que implementa Merge Sort.
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//Funcion para imprimir un vector
void printVector(const vector<int>& arr) {
   for (size_t i = 0; i < arr.size(); i++) // Usar size_t en lugar de int
       cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    //Abrir el archivo pasado como argumento
    ifstream archivo(argv[1]);
    vector<int> arr;
    int numero;

    // Leer los números del archivo
    while (archivo >> numero) {
        arr.push_back(numero);
    }

    archivo.close();


    // Imprimir el vector original
    cout << "Vector original: \n";
    printVector(arr);

    //Iniciar la medicion de tiempo
    auto inicio = high_resolution_clock::now();

    //Llama a mergeSort
    mergeSort(arr, 0, arr.size() - 1);

    //Detiene la medicion de tiempo
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    //Imprimir el vector ordenado
    cout << "\nVector ordenado: \n";
    printVector(arr);

    //Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos" << endl;

    return 0;
}
