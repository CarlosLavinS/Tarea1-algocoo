#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>    

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    ifstream archivo(argv[1]);  // brimos el archivo de entrada.
    vector<int> areglo;
    int numero;

    //Leer los nums del archivo
    while (archivo >> numero) {
        areglo.push_back(numero);  //Agregamos las entradas al vector
    }
    archivo.close();  //Cerrar el archivo

    //Iniciar la medición de tiempo
    auto inicio = high_resolution_clock::now();

    //Usar la función de ordenamiento estándar de C++
    sort(areglo.begin(), areglo.end());

    //Detener la medición de tiempo
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    //Imprimir el arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (size_t i = 0; i < areglo.size(); i++) {
        cout << areglo[i] << " ";
    }
    cout << endl;

    //Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos" << endl;

    return 0;
}
