/** 
 * Programa que implementa algoritmo de Dijkstra
 * y algoritmo de Floyd Warshall
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 19/19/23, Modificación 22/19/23
 */

#include "dijkstra.h"
#include "floyd.h"
#include "libraries.h"
using namespace std;

int main(int argc, char *argv[]){
    // Nodos visitados para Dijkstra
    vector<int> nodosVisitados;
    // Distancias utilizadas para Dijkstra
    vector<int> distancias;
    // Matriz de resultados para Dijkstra
    vector<vector<int>> matrizDistancias;
    int n;
    std::cout << "Inserta el numero de nodos: ";
    cin >> n;

    // Grafo
    vector<vector<int>> grafo(n, vector<int>(n));
    // Leer los valores de la n
    std::cout << "Introduce los valores del grafo:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grafo[i][j];
        }
    }
    // Aplicar dijkstra para cada nodo de la matriz
    applyDijkstra(grafo, distancias, nodosVisitados, matrizDistancias);
    // Imprimir resultados de Dijkstra
    printDijkstra(matrizDistancias);
    // Aplicación de algoritmo de Floyd
    applyFloyd(grafo, n);
}