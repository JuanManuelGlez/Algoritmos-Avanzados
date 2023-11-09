#include "libraries.h"
#include "askInput.h"

int main(int charc, char *argv[]) {
    int sizeGraph;
    std::vector<std::vector<int>> graph;
    std::cout << "Escribe el numero de colonias en la ciudad: " << std::endl;
    getSizeGraph(sizeGraph);

    std::cout << "Escribe el grafo con las distancias en kms" << std::endl;
    std::cout << "entre las colonias de la ciduad: " << std::endl;
    getGraph(sizeGraph, graph);

    /**
     * @note `To code Prims`
     * primsAlgotithm()
     */

    /**
     * @note `To code TSP (DP)`
     * tspAlgorithm()
     */

    /**
     * @note `To code Max flow`
     * maxFlowAlgorithm()
     */
}