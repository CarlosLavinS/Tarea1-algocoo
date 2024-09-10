#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

//funcion que lee una matriz desde un archivo
void leerMatriz(ifstream& archivo, vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo >> matriz[i][j];
        }
    }
}

//Funcion para multiplicar matrices
void multiplicarMatrices(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB, vector<vector<int>>& matrizC, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

//Funcion para mostrar una matriz
void mostrarMatriz(const vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    ifstream archivo(argv[1]);//Abrimos el archivo

    int n;
    archivo >> n; //Leemos el tamaño de las matrices

    //Inicializamos matrices
    vector<vector<int>> matrizA(n, vector<int>(n));
    vector<vector<int>> matrizB(n, vector<int>(n));
    vector<vector<int>> matrizC(n, vector<int>(n, 0)); //Matriz resultante

    //Leer matrices desde el archivo
    leerMatriz(archivo, matrizA, n);
    leerMatriz(archivo, matrizB, n);

    archivo.close(); // Cerrar el archivo

    //Medir el tiempo
    auto inicio = high_resolution_clock::now();

    //Realizar multiplicacion de matriz + resultado
    multiplicarMatrices(matrizA, matrizB, matrizC, n);

    auto fin = high_resolution_clock::now();
    auto tiempo_ejecucion = duration_cast<milliseconds>(fin - inicio);

    


    cout << "La matriz resultante es:" << endl;
    mostrarMatriz(matrizC, n);//muestra matriz resultante
    cout << "Tiempo de ejecucion: " << tiempo_ejecucion.count() << " ms" << endl;
    return 0;
}
