#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Vector para guardar nodos visitados
// Vector en orden con las posiciones de las distancias
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
            if(distancias[i] < minNode.second &&
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

int main(int argc, char *argv[]){
    vector<int> nodosVisitados;
    vector<int> distancias;
    vector<vector<int>> matrizDistancias;
    int n = 4;
    std::cout << "Inserta el número de nodos: ";
    //cin >> n;
    vector<vector<int>> matriz(n, vector<int>(n));
    // Leer los valores de la matriz
    std::cout << "Introduce los valores de la matriz:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matriz[i][j];
        }
    }
    for (int i = 0; i < n; i ++) {
        dijkstraAlgorithm(matriz, i, distancias, nodosVisitados);
        matrizDistancias.push_back(distancias);
        distancias.clear();
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                cout << "node " << i + 1 << " to node " << j + 1 << ": "<< matrizDistancias[i][j] << " ";
                cout << endl;
            }
        }
        cout << endl;
    }
}