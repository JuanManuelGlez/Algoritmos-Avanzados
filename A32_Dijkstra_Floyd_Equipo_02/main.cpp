/** 
 * Programa que implementa algoritmo de Dijkstra
 * y algoritmo de Floyd Warshall
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 19/19/23, Modificación 19/19/23
 */

#include "dijkstra.h"
#include "floyd.h"
#include "libraries.h"
using namespace std;

int main(int argc, char *argv[]){
    vector<int> nodosVisitados;
    vector<int> distancias;
    vector<vector<int>> matrizDistancias;
    int n;
    std::cout << "Inserta el número de nodos: ";
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));
    // Leer los valores de la matriz
    std::cout << "Introduce los valores de la matriz:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matriz[i][j];
        }
    }
    applyDijkstra(matriz, distancias, nodosVisitados, matrizDistancias);
    printDijkstra(matrizDistancias);
    Floyd(matriz, n);
    
}