#pragma once
#include "libraries.h"

/**
 * @brief Función que calcula la mejor optimización
 * de beneficio para el problema de la mochila
 * (knapsack problem), con programación dinámica.
 * @param std::vector<int> `weights` simboliza pesos
 * @param std::vector<int> `profits` simboliza beneficios
 * @param std::vector<std::vector<int>> &dp simboliza tabulador
 * @note `Time complexity - O(n²)`
 * @result Tabulador modificado con los beneficios máximos para cada estado
 */
void dynammicKnapsack(std::vector<int> weights,
                      std::vector<int> profits,
                      std::vector<std::vector<int>> &dp, int maxCapacity) {
    for (int i = 0; i < dp.size(); i++) {
        for (int w = 0; w < dp[0].size(); w++) {
            int currWeight = 0;
            // Renglon 0 y columna 0 rellenar con 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else {
                // Calcular para cada columna la diferencia con peso actual
                currWeight = w - weights[i - 1];
                if (currWeight < 0) {
                    // Si diferencia es menor a 0, obtener el valor ya computado
                    dp[i][w] = dp[i - 1][w];
                }
                else {
                    // Si diferencia es mayor o 0, obtener máximo
                    // de un valor ya computado en columna que
                    // pertenece a la diferencia de pesos más la suma del beneficio actual
                    // o un renglón anterior
                    dp[i][w] = std::max(dp[i - 1][currWeight] + profits[i - 1], dp[i - 1][w]);
                }
            }
        }
    }
}

/**
 * @brief Función que imprime el resultado del tabulador de 
 * programación dinámica después de optimización.
 * @param std::vector<std::vector<int>> dp simboliza tabulador
 * @note `Time complexity - O(n²)`
 * @result Se despliega en pantalla beneficio óptimo y la tabulación con beneficios máximos.
 */
void printKnapsack(std::vector<std::vector<int>> dp) {
    int optimumBenefit = 0;
    std::cout << "--------------------------" << std::endl;
    std::cout << "| Beneficio optimo | " << " " 
        << dp[dp.size() - 1][dp[0].size() - 1] << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;

    std::cout << "--------------------" << std::endl;
    std::cout << "|  Matriz generada |" << std::endl;
    std::cout << "--------------------" << std::endl;

    for (int i = 0; i < dp.size(); i++) {
        for (int w = 0; w < dp[0].size(); w++) {
            std::cout << std::left << std::setw(3) << dp[i][w] << " ";
        }
        std::cout << std::endl;
    }
}