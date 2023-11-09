/**
 * Programa que resuelve el problema del coloreo de un grafo
 * híbrido de Fuerza Bruta con Welsh Powell para la terminación prematura.
 * Se asegura que ningún nodo en algún punto tenga color repetido si
 * existe adyacencia.
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 11/08/23, Modificación 11/08/23
 */

#include "libraries.h"
#include "graphColoring.h"
#include "ask_inputs.h"
#include "print_graph.h"

int main(int charc, char *argv[]) {
    int n;
    std::vector<std::pair<int, int>> degrees;

    // Obtener tamaño de grafo
    getSizeGraph(n);
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    
    // Obtener grafo del usuario
    getGraph(n, graph);

    // Cálculo de grado de vértices
    calculateDegreeNode(graph, degrees);
    
    // Obtención del grafo por asociación de color -> vértice/s asociado 
    std::map<int, std::vector<int>> colors = graphColoring(graph, degrees);
    resultingGraph(colors);
}