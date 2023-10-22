/**
 * Programa que implementa algoritmo de Dijkstra
    * @author Daniel Gutiérrez Gómez A01068056
    * @author Juan Manuel González Ascencio A00572003
    * @author Julio César Pérez Rodríguez A01705763
 * Creación 19/19/23, Modificación 20/19/23
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "libraries.h"
using namespace std;

/**
 * @brief Se hace iteración de todos los nodos
 * hasta visitar todos y encontrar el camino mínimo
 * en base a las distancias procesadas desde el nodo
 * principal hasta recorrer todos los nodos
 * @param vector<vector<int>> matriz simboliza el grafo dirigido
 * @param int nodo principal
 * @param vector<int> &distancias
 * @param vector<int> visitados
 * Time complexity O(n²)
 */
void dijkstraAlgorithm(vector<vector<int>> matriz, int nodo,
                        vector<int> &distancias,
                        vector<int> visitados) {
    // Procesamiento del primer nodo
    for (int i = 0; i < matriz.size(); i++) {
        distancias.push_back(matriz[nodo][i]);
    }
    visitados.push_back(nodo);
    while (visitados.size() < matriz.size()) {
        // Primer número es índice y segundo la distancia
        pair<int, int> minNode(INT_MAX, INT_MAX);
        // Encontrar el nuevo mínimo de distancia del nodo actual
        for (int i = 0; i < distancias.size(); i++) {
            // Si el nodo no es diferente a la iteración en la que estamos
            // si además es adyacente y si no ha sido visitado
            if (distancias[i] < minNode.second &&
                distancias[i] > 0 && visitados[i] != i && nodo != i) {
                minNode.first = i;
                minNode.second = distancias[i];
            }
        }
        // Marcar como visitado el nodo con menor distancia
        visitados.push_back(minNode.first);

        // Procesamiento de nodos adyacentes
        for (int col = 0; col < matriz.size(); col++) {
            // Si el el nodo no tiene adyacencia y la matriz en el nodo de menor distancia
            // no es -1 entonces se actualiza con el costo actual más la distancia
            // al nodo mínimo
            // Actualizar vector de distancias la suma de las distancias
            if (distancias[col] == -1 && matriz[minNode.first][col] != -1) {
                distancias[col] = matriz[minNode.first][col] + distancias[minNode.first];
            }
            // Si el nodo es mayor a 0 y la matriz en la posición del mínimo es mayor a 0
            // (existen adyacencias), calcular el mínimo entre la suma de la distancia actual
            // con la suma de la distancia del nodo mínimo y de la distancia en esa posición
            // Actualizar vector de distancias con el mínimo
            else if (distancias[col] > 0 && matriz[minNode.first][col] > 0) {
                int min = std::min(matriz[minNode.first][col] + distancias[minNode.first], distancias[col]);
                distancias[col] = min;
            }
        }
    }
}

/**
 * @brief Aplicar algoritmo de Dijkstra
 * para cada nodo de la matriz dada
 * @param vector<vector<int>> matriz
 * @param vector<int> &distancias
 * @param vector<int> visitados
 * @param vector<vector<int>> &matrizDistancias
 * Time complexity O(n³)
 */
void applyDijkstra(vector<vector<int>> matriz,
                   vector<int> &distancias,
                   vector<int> visitados,
                   vector<vector<int>> &matrizDistancias) {
    for (int i = 0; i < matriz.size(); i++) {
        dijkstraAlgorithm(matriz, i, distancias, visitados);
        matrizDistancias.push_back(distancias);
        distancias.clear();
    }
}

/**
 * @brief Impresión de matriz de distancias generadas
 * por recorrer todos los nodos
 * @param vector<vector<int>> matrizDistancias
 * Time complexity O(n²)
 */
void printDijkstra(vector<vector<int>> matrizDistancias) {

    cout << "---------------------" << endl;
    cout << "Dijkstra" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < matrizDistancias.size(); i++) {
        for (int j = 0; j < matrizDistancias.size(); j++) {
            if (i != j) {
                cout << "node " << i + 1 << " to node " << j + 1 << ": " << matrizDistancias[i][j] << " ";
                cout << endl;
            }
        }
        cout << endl;
    }
}
#endif // DIJKSTRA_H