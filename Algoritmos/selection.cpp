#include <iostream>
#include <fstream>  
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    ifstream archivo(argv[1]);  //Abrimos el archivo de entrada.

    vector<int> areglo;  //Creamos un vector que almacenará los datos de entrada (un array)
    int numero;

    // Leemos las entradas del archivo y las almacenamos en el vector
    while (archivo >> numero) {
        areglo.push_back(numero);  //Agregamos las entradas al vector
    }
    archivo.close();

    int n = areglo.size();  //Tamaño del arreglo-vector

    //Iniciar la medición de tiempo
    auto inicio = high_resolution_clock::now();

    //Algoritmo Selection Sort
    for (int i = 0; i < n-1; i++) {
        int minimo_indice = i;  //Sirve para encontrar el elemento mínimo del arreglo
        for (int j = i+1; j < n; j++) {
            if (areglo[j] < areglo[minimo_indice]) {
                minimo_indice = j;  //Actualizamos el índice mínimo
            }
        }
        //Hacemos un intercambio entre el elemento mínimo y el primer elemento que se encuentra en desorden
        int temp = areglo[minimo_indice];
        areglo[minimo_indice] = areglo[i];
        areglo[i] = temp;
    }

    //Detener la medición de tiempo
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    //Procedemos a imprimir el arreglo ya ordenado
    cout << "Areglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << areglo[i] << " ";
    }
    cout << endl;

    //Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos" << endl;

    return 0;
}
