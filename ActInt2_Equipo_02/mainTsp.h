// mainTsp.h
#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int minDistance;
vector<int> bestPath;
int bestTraffic;

void tsp(const vector<vector<int>>& dist, const vector<vector<int>>& traffic, vector<bool>& visited, int currPos, int n, int count, int cost, int trafficCost, vector<int>& path) {
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

string tspAlgorithm(const vector<vector<int>>& graphColonies, const vector<vector<int>>& graphFlow, int sizeGraphs) {
    minDistance = INT_MAX;
    bestTraffic = 0;
    vector<bool> visited(sizeGraphs, false);
    vector<int> path;
    path.push_back(0); // Empezando desde la colonia A
    visited[0] = true;

    tsp(graphColonies, graphFlow, visited, 0, sizeGraphs, 1, 0, 0, path);

    string result = "Ruta más corta: ";
    for (int i : bestPath) {
        result += char('A' + i);
        result += " ";
    }
    result += "\nCosto de la ruta: " + to_string(minDistance);
    result += "\nCapacidad máxima de tráfico en esta ruta: " + to_string(bestTraffic) + "\n";

    return result;
}
