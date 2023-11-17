
#include "libraries.h"
#define V 4
 
 /**
  * @brief     
  *Función que implementa el algoritmo de Ford-Fulkerson para encontrar el flujo máximo en un grafo.
 */

/**
 *  @brief 
 * la funcion bfs encuentra el camino de aumento en el grafo residual.
*/
bool bfs(int rGraph[V][V], int s, int t, int parent[], int n)
{

    bool visited[n];
    memset(visited, 0, sizeof(visited));
 

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
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
 * @brief 
 * Función que implementa el algoritmo de Ford-Fulkerson para encontrar el flujo máximo en un grafo.
*/
int fordFulkerson(std::vector<std::vector<int>> graph, int s, int t)
{
    int u, v;
 

    int rGraph[V]
              [V]; 
    for (u = 0; u < graph.size(); u++)
        for (v = 0; v < graph.size(); v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; 
 
    int max_flow = 0; 

    while (bfs(rGraph, s, t, parent, graph.size())) {
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
 
{}
    return max_flow;
}