#pragma once
#include "libraries.h"

/**
 * @brief Función que pide al usuario valores de vectores utilizados.
 * @param std::vector<int> `&temp` simboliza vector a pedir al usuario
 * @note `Time complexity - O(n)`
 * @result Vector modificado con valores del usuario
 */
void getVector(int n, std::vector<int> &temp) {
    for (int i = 0; i < n; i++) {
        std::cin >> temp[i];
    }
}

/**
 * @brief Función que pide al usuario valores principales.
 * @param std::vector<int> `&x` simboliza número
 * @note `Time complexity - O(1)`
 * @result Número modificado con valor del usuario
 */
void getValues(int &x) {
    std::cin >> x;
}