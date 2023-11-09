#pragma once
#include "libraries.h"

/**
 * @brief Función que imprime respuesta del colore de grafo.
 * @param colors `std::map<int, std::vector<int>>` simboliza vector a pedir al usuario
 * @note `Time complexity - O(n²)`
 * @result Impresión coloreo de grafo
 */
void resultingGraph(std::map<int, std::vector<int>> colors) {
    for (std::map<int, std::vector<int>>::iterator ptr = colors.begin(); ptr != colors.end(); ptr++) {
        for (int i = 0; i < ptr->second.size(); i++) {
            std::cout << "Vértice: " << ptr->second[i] << ","
                      << " Color asignado: "
                      << ptr->first << std::endl;
        }
    }
}