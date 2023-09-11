#include "backTrackLab.h"
#include "branchAndBound.h"
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
    std::vector<std::vector<int>> ansBackTrack(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> ansBranchAndBound(n, std::vector<int>(m, 0));

    // Leer los valores de la matriz
    std::cout << "Introduce los valores de la matriz:" << std::endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            std::cin >> matriz[i][j];
        }
    }

    bool hasAnswerBack = backTracking(matriz, 0, 0, ansBackTrack);
    bool hasAnswerBranch = branchAndBound(matriz, 0, 0, ansBranchAndBound);
    // Opcional: Mostrar la matriz leída
    if(hasAnswerBack) {
        std::cout << "\nMatriz BackTracking:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
            {
                std::cout << ansBackTrack[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    if(hasAnswerBranch) {
        std::cout << "\nMatriz BranchAndBound:" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cout << ansBranchAndBound[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "\n No hay respuesta" << std::endl;
    }
    return 0;
}
