#pragma once
#include "libraries.h"

/**
 * @brief Función que pide al usuario valores del grafo a usar.
 * @param &graph `std::vector<std::vector<int>>`
 * @param n ´int´ tamaño de grafo
 * @note `Time complexity - O(n²)`
 * @result Matriz modificada con valores del usuario
 */
void getGraph(int n, std::vector<std::vector<int>> &graph) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }
}

/**
 * @brief Función que pide al usuario valores principales.
 * @param std::vector<int> `&x` simboliza número
 * @note `Time complexity - O(1)`
 * @result Número modificado con valor del usuario
 */
void getSizeGraph(int &x) {
    std::cin >> x;
}