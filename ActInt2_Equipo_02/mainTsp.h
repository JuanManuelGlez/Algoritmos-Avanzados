/**
 * Programa que resuelve segundo problema
 * Algoritmo de TSP (DP)
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 11/01/23, Modificación 11/17/23
 */
#include "libraries.h"

int minDistance;
std::vector<int> bestPath;
int bestTraffic;

/**
 * @brief Función que calcula algoritmo del TSP con DP
 * @note`Time Complexity - O(n!)`
 * @param &dist `const std::vector<std::vector<int>> grafo distancias`
 * @param &traffic `const std::vector<std::vector<int>> grafo tráfico`
 * @param &visited `const std::vector<bool> vector visitados`
 * @param currPos `int posicion actual`
 * @param n `int tamaño de grafo`
 * @param count `int contador`
 * @param cost `int costo`
 * @param trafficCost `int costo del tráfico`
 * @param &path `const std::vector<int> camino más corto`
 * @return void `Modifica vector de camino`
 */
void tsp(const std::vector<std::vector<int>>& dist, const std::vector<std::vector<int>>& traffic,
 std::vector<bool>& visited, int currPos, int n, int count, int cost, int trafficCost, std::vector<int>& path) {
    if (count == n && dist[currPos][0]) {
        if (cost < minDistance || (cost == minDistance && trafficCost > bestTraffic)) {
            minDistance = cost + dist[currPos][0];
            bestTraffic = trafficCost + traffic[currPos][0];
            bestPath = path;
            bestPath.push_back(0);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[currPos][i]) {
            visited[i] = true;
            path.push_back(i);
            tsp(dist, traffic, visited, i, n, count + 1, cost + dist[currPos][i], trafficCost + traffic[currPos][i], path);
            path.pop_back();
            visited[i] = false;
        }
    }
}

/**
 * @brief Función que llama al algoritmo del TSP con DP
 * @note`Time Complexity - O(n)`
 * @param &graphColonies `const std::vector<std::vector<int>> grafo de colonias`
 * @param &graphFlow `const std::vector<std::vector<int>> grafo de flujo`
 * @param sizeGraph `int tamaño grafo`
 * @return std::string `Resultado camino más corto`
 */
std::string tspAlgorithm(const std::vector<std::vector<int>>& graphColonies, const std::vector<std::vector<int>>& graphFlow, int sizeGraphs) {
    minDistance = INT_MAX;
    bestTraffic = 0;
    std::vector<bool> visited(sizeGraphs, false);
    std::vector<int> path;
    path.push_back(0); // Empezando desde la colonia A
    visited[0] = true;

    tsp(graphColonies, graphFlow, visited, 0, sizeGraphs, 1, 0, 0, path);

    std::string result = "Ruta más corta: ";
    for (int i : bestPath) {
        result += char('A' + i);
        result += " ";
    }
    result += "\nCosto de la ruta: " + to_string(minDistance);
    result += "\nCapacidad máxima de tráfico en esta ruta: " + to_string(bestTraffic) + "\n";

    return result;
}
