#pragma once
#include "libraries.h"

/**
 * @brief Función que imprime resultado del algoritmo de Prims
 * @note `Time Complexity - O(n)`
 * @param MST `std::map<int, std::pair<int, int>>`
 * @returns `void - Imprime resultado`
 */
void printPrimsAnswer(std::map<int, std::pair<int, int>> MST) {
    std::cout << "Forma de cablear colonias: " << std::endl;
    int sumCable = 0;
    for (std::map<int, std::pair<int, int>>::iterator ptr = MST.begin(); ptr != MST.end(); ptr++) {
        std::cout << "Cantidad de cable: " << ptr->first << std::endl;
        std::cout << "("<< ptr->second.first << ", ";
        std::cout << ptr->second.second << ")" << std::endl;
        sumCable += ptr->first;
    }
    std::cout << "Cantidad de cable necesitado para conectar colonias: " << std::endl;
    std::cout << sumCable << std::endl;
}