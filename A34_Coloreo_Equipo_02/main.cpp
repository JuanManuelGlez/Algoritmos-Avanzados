#include "libraries.h"

// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortbysecdesc(const std::pair<int, int> &a,
                   const std::pair<int, int> &b){
    return a.second > b.second;
}

void sortDegreeNodes(std::vector<std::pair<int, int>> &degrees) {
    std::sort(degrees.begin(), degrees.end(), sortbysecdesc);
}

std::pair<bool, int> findNodeInMap(std::map<int, std::vector<int>> colors, int node) {
    std::pair<bool, int> temp;
    for (std::map<int, std::vector<int>>::iterator ptr = colors.begin(); ptr != colors.end(); ptr++){
        if (std::find(ptr->second.begin(), ptr->second.end(), node) != ptr->second.end()) {
            temp.first = true;
            temp.second = ptr->first;
            return temp;
        }
    }
    temp.first = false;
    temp.second = node;
    return temp;
}

std::map<int, std::vector<int>> graphColoring(std::vector<std::vector<int>> matrix,
                                                     std::vector<std::pair<int, int>> degrees) {
    // 3.- Tomar el nodo de lista descendente ver si no está coloreado,
    // 3.1.- Si no está coloreado, buscar no adyacentes y colorearlos (con el color menos utilizado de los colores)
    // <Nodo, valor>
    // [<1, 3>, <2, 3>, <3, 3>, <4, 3>, <0, 2>]
    // 0 0 1 0 1  <0, 2> Procesado
    // 0 0 1 1 1  <1, 3> Procesado
    // 1 1 0 1 0  <2, 3> Procesado
    // 0 1 1 0 1  <3, 3> Procesado
    // 1 1 0 1 0  <4, 3> Procesado
    // map.insert{2, 3}
    // Color con valor de colores asignados a los nodos
    // Accedimos al nodo, en no adyacente
    // {0 : [0, 1], 1 : [2, 4], 2 : [3]}
    // Revisar en vectores del mapa, que el nodo actual no
    // esté visitado si ya ha sido visitado regresar true
    // si no ha sido visitado regresar false
    // Obtener el minimo de longitud de vectores del mapa
    // y agregar nodo al valor del key donde la longitud del mapa es menor, si son iguales, agregar en cualquier color
    std::map<int, std::vector<int>> colors;
    int n = 0;
    for (int i = 0; i < degrees.size() && n < matrix.size(); i++) {
        int node = degrees[i].first;
        std::vector<int> nodes;
        for (int col = 0; col < matrix.size(); col ++){
            if (i == 0 && matrix[node][col] != 1) {
                n++;
                nodes.push_back(col);
            }
            if (matrix[node][col] != 1 && i != 0) {
                // Helper function
                std::pair<bool, int> temp = findNodeInMap(colors, col);
                if(!temp.first) {
                    bool foundNode = false;
                    int tempNode;
                    if(temp.second < colors.size()) {
                        for (int x = 0; x < colors[temp.second].size() && foundNode; x++) {
                            tempNode = colors[temp.second][x];
                            if (matrix[tempNode][node] != 0) {
                                foundNode = true;
                            }
                        }
                    }
                    if (!foundNode) {
                        n++;
                        nodes.push_back(col);
                    }
                }
            }
        }
        colors[i] = nodes;
    }
    return colors;
}

void calculateDegreeNode(std::vector<std::vector<int>> matrix,
                        std::vector<std::pair<int, int>> &degrees) {
    // <Nodo, valor>
    // 0 0 1 0 1  <0, 2>
    // 0 0 1 1 1  <1, 3>
    // 1 1 0 1 0  <2, 3>
    // 0 1 1 0 1  <3, 3>
    // 1 1 0 1 0  <4, 3>
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
    // [<0, 2>, <1, 3>, <2, 3>, <4, 3>]
    // [<2, 3>, <3, 3>, <4, 3>, <0, 2>]
    sortDegreeNodes(degrees);
}

int main(int charc, char *argv[]) {
    int n = 5;
    std::vector<std::pair<int, int>> degrees;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> graph[i][j];
        }
    }
    calculateDegreeNode(graph, degrees);
    std::map<int, std::vector<int>> colors = graphColoring(graph, degrees);
    for (std::map<int, std::vector<int>>::iterator ptr = colors.begin(); ptr != colors.end(); ptr++) {
        std::cout << "Vértice: " << ptr->first << "," << " Color asignado: "
         << ptr->second.size() << std::endl;
    }
    // Algoritmo de Welsh-Powell de coloreo de grafos
    // 1.- Calcular grados de vértices
    // 2.- Orden Descendente de grado de vértices
    // 3.- Tomar el nodo de lista descendente ver si no está coloreado,
    // 3.1.- Si no está coloreado, buscar no adyacentes y colorearlos (con el color menos utilizado de los colores)

}