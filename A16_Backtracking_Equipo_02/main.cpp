#include "backTrack.h"
#include <iostream>

int main(int argc, char *argv[]){
    int n, m;

    // Pedir al usuario las dimensiones de la matriz
    std::cout << "Introduce el número de filas (n): ";
    std::cin >> n;
    std::cout << "Introduce el número de columnas (m): ";
    std::cin >> m;

    // Crear una matriz (vector de vectores) de tamaño n x m
    std::vector<std::vector<int>> matriz(n, std::vector<int>(m));
    std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));

    // Leer los valores de la matriz
    std::cout << "Introduce los valores de la matriz:" << std::endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cin >> matriz[i][j];
        }
    }
    bool hasAnswer = backTracking(matriz, 0, 0, ans);
    // Opcional: Mostrar la matriz leída
    std::cout << "\nMatriz BackTracking:" << std::endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cout << ans[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}
