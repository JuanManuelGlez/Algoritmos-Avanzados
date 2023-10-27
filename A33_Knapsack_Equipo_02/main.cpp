/**
 * Programa que resuelve el problema de la mochila
 * con el uso de programación dinámica técnica iterativa
 * bottom up.
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 10/26/23, Modificación 10/26/23
 */
#include "knapsack_dp.h"
#include "libraries.h"
#include "ask_inputs.h"

int main(int argc, char *argv[]) {
    int n;
    int maxCapaciy;

    std::cout << "Numero de elementos" << std::endl;
    getValues(n);
    std::cout << "Peso maximo de mochila" << std::endl;
    getValues(maxCapaciy);

    std::vector<int> weights(n, 0);
    std::vector<int> profits(n, 0);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(maxCapaciy + 1, 0));

    std::cout << "Beneficios" << std::endl;
    getVector(n, profits);

    std::cout << "Pesos" << std::endl;
    getVector(n, weights);

    dynammicKnapsack(weights, profits, dp, maxCapaciy);
    printKnapsack(dp);
}