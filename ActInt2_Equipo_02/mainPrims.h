#pragma once
#include "libraries.h"

/**
 * Estructura para comparación de pares en una cola de priorización
*/
struct CompareFirstElement {
    /**
     * @brief Helper para regresar una cola de priorización con menor cantidad
     * @note `Time Complexity - O(1)`
     * @param a `const std::pair<int, std::pair<int, int>>`
     * @param b `const std::pair<int, std::pair<int, int>>`
     * @returns Bool, sin embargo se acomoda la cola de priorización
     */
    bool operator()(const std::pair<int, std::pair<int, int>> &a,
                    const std::pair<int, std::pair<int, int>> &b) const {
        return a.first > b.first;
    }
};

/**
 * @brief Función que recupera la conexión con menor valor
 * @note `Time Complexity - O(n²)`
 * @param graph `std::vector<std::vector<int>>`
 * @param &edges `std::map<int, std::pair<int, int>>`
 * @returns void `Solo la modificación de mapa con resultados`
 */
void getSmallestEdge(std::vector<std::vector<int>> graph,
                     std::map<int, std::pair<int, int>> &edges) {
    // Valor mayor para encontrar el mínimo de los valores
    int minimumEdge = INT_MAX;
    // Guardar par con posiciones de grafo
    std::pair<int, int> indexes;
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[0].size(); j++) {
            if(graph[i][j] != 0 && minimumEdge > graph[i][j]) {
                indexes.first = i;
                indexes.second = j;
                minimumEdge = graph[i][j];
            }
        }
    }
    // Guardar en mapa con pesos los índices
    edges[graph[indexes.first][indexes.second]] = indexes;
}

/**
 * @brief Función que aplica algoritmo de Prims
 * @note `Time Complexity - O(elog(e))`
 * @param graph `std::vector<std::vector<int>>`
 * @returns `std::map<int, std::pair<int, int>>`
 */
std::map<int, std::pair<int, int>> applyPrimsAlgorith(std::vector<std::vector<int>> graph) {
    // Vector para marcar los nodos visitados
    std::vector<bool> visited(graph.size(), false);

    // Cola de priorización que contiene par con un entero y par de enteros
    // Realiza la comparación y regresa los elementos con menor peso
    std::priority_queue<std::pair<int, std::pair<int, int>>,
    std::vector<std::pair<int, std::pair<int, int>>>, CompareFirstElement> minEdges;

    // Mapa que tiene las conexiones con las respuestas
    std::map<int, std::pair<int, int>> edges;

    // Procesamiento de la primer conexión y la mínima en todo el grafo
    getSmallestEdge(graph, edges);

    // Obtener el primer elemento y marcarlo como visitado
    int startVertex = edges.begin()->second.first;
    visited[startVertex] = true;

    // Revisar adyacencias de ese primer nodo
    for (int col = 0; col < graph.size(); col++) {
        if (graph[startVertex][col] != 0) {
            minEdges.push({graph[startVertex][col], {startVertex, col}});
        }
    }

    while(!minEdges.empty()) {
        // Temporal para hacer búsqueda en BFS
        std::pair<int, std::pair<int, int>> minEdge = minEdges.top();
        minEdges.pop();

        // Obtener el siguiente vértice
        int nextVertex = minEdge.second.second;

        // Si no ha sido visitado
        if(!visited[nextVertex]) {
            // Marcar como visitado
            visited[nextVertex] = true;
            // Asignar un nuevo valor al mapa con nuevo mínimo
            edges[minEdge.first] = {minEdge.second.first, minEdge.second.second};
            // Revisar adyacencias de ese nodo
            for (int col = 0; col < graph.size(); col++) {
                if(graph[nextVertex][col] != 0 && !visited[col]) {
                    minEdges.push({graph[nextVertex][col], {nextVertex, col}});
                }
            }
        }
    }
    return edges;
}
