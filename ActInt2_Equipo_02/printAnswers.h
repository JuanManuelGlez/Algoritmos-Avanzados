#pragma once
#include "libraries.h"

/**
 * @brief Función que imprime resultado del algoritmo de Prims
 * @note `Time Complexity - O(n)`
 * @param MST `std::map<int, std::pair<int, int>>`
 * @returns `void - Imprime resultado`
 */
std::string printPrimsAnswer(std::map<int, std::pair<int, int>> MST) {
    std::string result;
    result += "Forma de cablear colonias: \n";
    int sumCable = 0;
    for (std::map<int, std::pair<int, int>>::iterator ptr = MST.begin(); ptr != MST.end(); ptr++) {
        result += "Colonia " + std::to_string(ptr->second.first + 1) + " a Colonia ";
        result += std::to_string(ptr->second.second + 1) + "\n";
        result += "Cantidad de cable: " + std::to_string(ptr->first) + "\n";
        sumCable += ptr->first;
    }
    result += "\n";
    result += "Cantidad mínima de cable necesitado para conectar colonias: \n";
    result += std::to_string(sumCable) + "\n";
    return result;
}

void outputAnswers(int itr, std::string primsResult, std::string minDistance, std::string  maxFlow) {
    std::string outputTxt = "Equipo_02_Salida_" + std::to_string(itr + 1) + ".txt";
    std::ofstream outputFile(outputTxt);

    if (outputFile.is_open()) {
        outputFile << "----- Min Span Tree -----\n";
        outputFile << primsResult;
        outputFile << "\n";
        outputFile << "----- Max Flow -----\n";
        outputFile << maxFlow;
        outputFile << "\n";
        outputFile << "----- Min Distance -----\n";
        outputFile << minDistance;
            outputFile.close();
        std::cout << "Data was written to output.txt\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }
}