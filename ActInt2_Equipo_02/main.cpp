#include "libraries.h"
#include "askInput.h"
#include "mainPrims.h"
#include "printAnswers.h"
#include "Flujo.h"

int main(int charc, char *argv[]) {
    // Iterar por cada archivo de prueba
    for (int i = 0; i < 1; i++) {
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

        /**
         * @note `To code TSP (DP)`
         * tspAlgorithm()
         */


         //maxFlowAlgorithm()
        int resMaxFlow = fordFulkerson(graphFlow, 0, graphFlow.size() - 1);

        std::string resultFlow ="El flujo maximo del grafo es: " + std::to_string(resMaxFlow);

        /**
         * @note `To code Min distance points`
         * minDistancePoints()
         */
        outputAnswers(i, resultPrims, resultFlow);
    }
}