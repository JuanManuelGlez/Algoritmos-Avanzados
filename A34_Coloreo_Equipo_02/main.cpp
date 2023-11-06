#include "libraries.h"

/**
 * @brief Función helper para comparación por segundo elemento de pares
 * @param const `std::pair<int, int> &a`
 * @param const `std::pair<int, int> &b`
 * @note `Time complexity - O(1)`
 * @return `bool`
 */
bool sortbysecdesc(const std::pair<int, int> &a,
                   const std::pair<int, int> &b){
    return a.second > b.second;
}

/**
 * @brief Hacer sort descendente por grado de vértices
 * @param degrees `std::vector<std::pair<int, int>> &degrees`
 * @note `Time complexity - O(n log n)`
 * @return `std::pair<bool, int>`
 */
void sortDegreeNodes(std::vector<std::pair<int, int>> &degrees) {
    std::sort(degrees.begin(), degrees.end(), sortbysecdesc);
}

std::map<int, std::vector<int>> adjacencyMap(std::vector<std::vector<int>> matrix) {
    std::map<int, std::vector<int>> adjacenyMap;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 1) {
                adjacenyMap[i].push_back(j);
            }
        }
    }
    return adjacenyMap;
}

/**
 * @brief Revisar en cada color del map si existe el nodo actual
 * @param colors `std::map<int, std::vector<int>>`
 * @param node `int`
 * @note `Time complexity - O(n²)`
 * @return `bool`
 */
bool findNodeInMap(std::map<int, std::vector<int>> colors, int node) {
    for (std::map<int, std::vector<int>>::iterator ptr = colors.begin(); ptr != colors.end(); ptr++){
        if (std::find(ptr->second.begin(), ptr->second.end(), node) != ptr->second.end()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Revisar si se encuentra nodo en las adyacencias a procesar
 * @param node `int`
 * @param &neighbors `std::vector<int>`
 * @note `Time complexity - O(n)`
 * @return `bool`
 */
bool isAdjacent(int node, std::vector<int> &neighbors) {
    return std::find(neighbors.begin(), neighbors.end(), node) != neighbors.end();
}

/**
 * @brief Revisar si se encuentra nodo en los vecinos en matriz
 * @param node `int`
 * @param matrix `std::vector<std::vector<int>>`
 * @note `Time complexity - O(n)`
 * @return `bool`
 */
bool isAdjacentToNeigh(int node, std::vector<int> nodes, std::vector<std::vector<int>> matrix) {
    for (int x = 0; x < nodes.size(); x++) {
        if (matrix[node][nodes[x]] == 1) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Algoritmo de graphColoring
 * @param matrix `std::vector<std::vector<int>>`
 * @param degrees `std::vector<std::pair<int, int>>`
 * @note `Time complexity - O(n³)`
 * @return `std::map<int, std::vector<int>>`
 */
std::map<int, std::vector<int>> graphColoring(std::vector<std::vector<int>> matrix,
                                                  std::vector<std::pair<int, int>> degrees) {
    std::map<int, std::vector<int>> colors;
    std::map<int, std::vector<int>> adjacencies = adjacencyMap(matrix);
    int n = 0;
    for (int i = 0; i < degrees.size() && n < matrix.size(); i++) {
        int node = degrees[i].first;
        std::vector<int> nodes;
        for (int col = 0; col < matrix.size(); col++) {
            if (matrix[node][col] != 1 &&
             !isAdjacent(col, adjacencies[node]) &&
              !findNodeInMap(colors, col) && !isAdjacentToNeigh(col, nodes, matrix)) {
               nodes.push_back(col);
               n++;
            }
        }
        colors[i] = nodes;
    }
    return colors;
}

/**
 * @brief Calcular grado de los nodos
 * @param matrix `std::vector<std::vector<int>>`
 * @param &degrees `std::vector<std::pair<int, int>>`
 * @note `Time complexity - O(n²)`
 */
void calculateDegreeNode(std::vector<std::vector<int>> matrix,
                        std::vector<std::pair<int, int>> &degrees) {
    for (int i = 0; i < matrix.size(); i++) {
        std::pair<int, int> temp;
        temp.first = i;
        for (int j = 0; j < matrix.size(); j++){
            if (matrix[i][j] == 1) {
                temp.second++;
            }
        }
        degrees.push_back(temp);
    }
    sortDegreeNodes(degrees);
}

int main(int charc, char *argv[]) {
    int n;
    std::vector<std::pair<int, int>> degrees;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> graph[i][j];
        }
    }
    calculateDegreeNode(graph, degrees);
    std::map<int, std::vector<int>> colors = graphColoring(graph, degrees);
    for (std::map<int, std::vector<int>>::iterator ptr = colors.begin(); ptr != colors.end(); ptr++) {
        for (int i = 0; i < ptr->second.size(); i++) {
            std::cout << "Vértice: " << ptr->second[i] << ","
                      << " Color asignado: "
                      << ptr->first << std::endl;
        }
    }
    // Algoritmo de Welsh-Powell de coloreo de grafos
    // 1.- Calcular grados de vértices
    // 2.- Orden Descendente de grado de vértices
    // 3.- Tomar el nodo de lista descendente ver si no está coloreado,
    // 3.1.- Si no está coloreado, buscar no adyacentes y colorearlos (con el color menos utilizado de los colores)

}