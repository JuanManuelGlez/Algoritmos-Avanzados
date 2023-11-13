#include "libraries.h"
#include "askInput.h"
#include "mainPrims.h"
#include "printAnswers.h"

int main(int charc, char *argv[]) {
    int sizeGraph;
    std::cout << "Escribe el numero de colonias en la ciudad: " << std::endl;
    getSizeGraph(sizeGraph);

    std::vector<std::vector<int>> graph(sizeGraph, std::vector<int>(sizeGraph));
    std::cout << "Escribe el grafo con las distancias en kms" << std::endl;
    std::cout << "entre las colonias de la ciduad: " << std::endl;
    getGraph(sizeGraph, graph);
    
    // Sección de Arbol con adyacencias más cortas (MST)
    std::map<int, std::pair<int, int>> MST = applyPrimsAlgorith(graph);
    printPrimsAnswer(MST);

    /**
     * @note `To code TSP (DP)`
     * tspAlgorithm()
     */

    /**
     * @note `To code Max flow`
     * maxFlowAlgorithm()
     */
}