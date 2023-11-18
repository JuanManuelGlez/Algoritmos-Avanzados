/**
 * Programa que resuelve Situación Problema2
 * con el uso de algoritmos avanzados:
 * Algoritmo de Prim
 * Algoritmo de TSP (DP)
 * Algoritmo de Ford Fulkerson
 * Distancia euclidiana
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 11/01/23, Modificación 11/17/23
 */
#include "libraries.h"
#include "askInput.h"
#include "mainPrims.h"
#include "printAnswers.h"
#include "mainFord.h"
#include "minDistance.h"
#include "mainTsp.h"

int main(int charc, char *argv[]) {
    // Iterar por cada archivo de prueba
    // Automatización de lectura y output
    for (int i = 0; i < 3; i++) {
        std::map<int, std::vector<std::vector<int>>> graphsMap;
        std::vector<std::pair<int, int>> coords;
        std::pair<int, int> newCoord;
        readInputTxt(i, graphsMap, coords);

        int totalGraphs = graphsMap.size();
        int sizeGraphs = graphsMap[0].size();

        std::vector<std::vector<int>>
                graphColonies(sizeGraphs, std::vector<int>(sizeGraphs));
        std::vector<std::vector<int>>
                graphFlow(sizeGraphs, std::vector<int>(sizeGraphs));

        // Creación de grafos
        createGraphs(totalGraphs, graphColonies, graphFlow, graphsMap);

        newCoord = coords[coords.size() - 1];
        coords.pop_back();

        // Sección de Arbol con adyacencias más cortas (MST)
        std::map<int, std::pair<int, int>> MST = applyPrimsAlgorithm(graphColonies);
        std::string resultPrims = printPrimsAnswer(MST);

        // Algoritmo de TSP 
        std::string resultTsp = tspAlgorithm(graphColonies, graphFlow, sizeGraphs);

        // Algoritmo de Ford Fulkerson
        int resMaxFlow = fordFulkerson(graphFlow, 0, graphFlow.size() - 1);
        std::string resultFlow ="El flujo maximo del grafo es: " + std::to_string(resMaxFlow ) + "\n";
        
        // Obtener la distancia mínima entre dos puntos
        std::string minDist = minDistanceEuclidean(coords, coords.size(), newCoord);

        // Impresión de resultados
        outputAnswers(i, resultPrims, minDist, resultTsp, resultFlow);
    }
}