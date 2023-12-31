/**
 * Programa que resuelve tercer problema
 * Algoritmo de Ford Fulkerson
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 11/01/23, Modificación 11/17/23
 */
#include "libraries.h"

/**
 * @brief la funcion bfs encuentra el camino de aumento en el grafo residual.
 * @param rGraph es el grafo residual.
 * @param s es el nodo fuente.
 * @param t es el nodo sumidero.
 * @param parent es un arreglo de padres.
 * @param n es el numero de nodos.
 * @note `Time Complexity - O(N^2)`
 * @returns bool si existe un camino de aumento.
*/
bool bfs(std::vector<std::vector<int>> &rGraph, int s, int t, std::vector<int> &parent, int n) {

    std::vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {

                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 

    return false;
}
 
/**
 * @brief Función que implementa el algoritmo de Ford-Fulkerson para encontrar el flujo máximo en un grafo.
 * @param graph es el grafo.
 * @param s es el nodo fuente.
 * @param t es el nodo sumidero.
 * @note `Time Complexity - O(N^2)`
 * @returns int el flujo máximo.
*/
int fordFulkerson(std::vector<std::vector<int>> &graph, int s, int t) {
    int u, v;
    
 
    const int V = graph.size();
    std::vector<std::vector<int>> rGraph(graph.size(), std::vector<int>(graph.size()));

    for (u = 0; u < graph.size(); u++)
        for (v = 0; v < graph.size(); v++)
            rGraph[u][v] = graph[u][v];

    std::vector<int> parent(graph.size());

    int max_flow = 0; 

    while (bfs(rGraph, s, t, parent, V)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        
        max_flow += path_flow;
    }
    return max_flow;
}