#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

//funcion que lee matriz desde archivo
void leerMatriz(ifstream& archivo, vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo >> matriz[i][j];
        }
    }
}

//uncion que transpone una matriz
void transponerMatriz(const vector<vector<int>>& matrizB, vector<vector<int>>& matrizB_T, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizB_T[j][i] = matrizB[i][j];
        }
    }
}

//Funcion que multiplica matrices usando la transpuesta de B
void multiplicarMatrices(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB_T, vector<vector<int>>& matrizC, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB_T[j][k];
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

    ifstream archivo(argv[1]);

    int n;
    archivo >> n; //Leer tamaño de las matrices

    //Inicializamos matrices
    vector<vector<int>> matrizA(n, vector<int>(n));
    vector<vector<int>> matrizB(n, vector<int>(n));
    vector<vector<int>> matrizB_T(n, vector<int>(n)); // Matriz transpuesta B
    vector<vector<int>> matrizC(n, vector<int>(n, 0)); //Matriz resulstandte

    //Leemos matrices A y B
    leerMatriz(archivo, matrizA, n);
    leerMatriz(archivo, matrizB, n);
    archivo.close(); // Cerrar el archivo

    // Transponer la matriz B
    transponerMatriz(matrizB, matrizB_T, n);

    // Medir el tiempo de ejecución
    auto inicio = high_resolution_clock::now();

    // Multiplicación de matrices usando la transpuesta de B
    multiplicarMatrices(matrizA, matrizB_T, matrizC, n);

    auto fin = high_resolution_clock::now();
    auto tiempo_ejecucion = duration_cast<milliseconds>(fin - inicio).count(); // Convertir a milisegundos

    // Mostrar el tiempo de ejecución como número entero
    

    //Mostrar la matriz resultante
    cout << "La matriz resultante es:" << endl;
    mostrarMatriz(matrizC, n);
    cout << "Tiempo de ejecucion: " << tiempo_ejecucion << " ms" << endl;
    return 0;
}
