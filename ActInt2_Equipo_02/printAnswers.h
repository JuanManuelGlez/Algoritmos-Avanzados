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
        result += "Cantidad de cable: " + std::to_string(ptr->first) + "\n";
        result += "(" + std::to_string(ptr->second.first) + ", ";
        result += std::to_string(ptr->second.second) + ")\n";
        sumCable += ptr->first;
    }
    result += "Cantidad de cable necesitado para conectar colonias: \n";
    result += std::to_string(sumCable) + "\n";
    return result;
}

void outputAnswers(int itr, std::string primsResult, std::string maxFlow, std::string minDistance) {
    std::string outputTxt = "Equipo_02_Salida_" + std::to_string(itr + 1) + ".txt";
    std::ofstream outputFile(outputTxt);

    if (outputFile.is_open()) {
        outputFile << "----- Min Span Tree -----\n";
        outputFile << primsResult;
        outputFile << "----- Max Flow -----\n";
        outputFile << maxFlow; 
        outputFile << "----- Min Distance -----\n";
        outputFile << minDistance;
            outputFile.close();
        std::cout << "Data was written to output.txt\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }
}