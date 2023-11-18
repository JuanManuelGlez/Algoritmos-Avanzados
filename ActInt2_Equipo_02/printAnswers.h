#pragma once
#include "libraries.h"

/**
 * @brief Función que regresa resultado del algoritmo de Prims
 * @note `Time Complexity - O(n)`
 * @param MST `std::map<int, std::pair<int, int>> Minimum spanning tree`
 * @returns `std::string - resultado`
 */
std::string printPrimsAnswer(std::map<std::pair<int, int>, int> MST) {
    std::string result;
    result += "Forma de cablear colonias: \n";
    int sumCable = 0;

    for (std::map<std::pair<int, int>, int>::iterator it = MST.begin(); it != MST.end(); ++it) {
        result += "Colonia " + std::to_string((it->first).first + 1) + " a Colonia ";
        result += std::to_string((it->first).second + 1) + "\n";
        result += "Cantidad de cable: " + std::to_string(it->second) + "\n";
        sumCable += it->second;
    }

    result += "\n";
    result += "Cantidad mínima de cable necesitado para conectar colonias: \n";
    result += std::to_string(sumCable) + "\n";
    return result;
}

/**
 * @brief Función que escribe resultado de todo el programa.
 * @note `Time Complexity - O(n)`
 * @param itr `int iteración archivo de entrada`
 * @param primsResult `std::string resultado de Prims`
 * @param minDist `std::string resultado minDistancia`
 * @param resultTsp `std::string resultado TSP`
 * @param maxFlow `std::string resultado Ford Fulkerson`
 * @returns `void - Escribir resultado salida`
 */
void outputAnswers(int itr, std::string primsResult, std::string minDist, std::string resultTsp, std::string maxFlow) {
    std::string outputTxt = "Equipo_02_Salida_" + std::to_string(itr + 1) + ".txt";
    std::ofstream outputFile(outputTxt);

    if (outputFile.is_open()) {
        outputFile << "----- Min Span Tree -----\n";
        outputFile << primsResult;
        outputFile << "\n";
        outputFile << "------- TSP ------\n";
        outputFile << resultTsp;
        outputFile << "\n";
        outputFile << "----- Max Flow -----\n";
        outputFile << maxFlow;
        outputFile << "\n";
        outputFile << "----- Min Distance -----\n";
        outputFile << minDist;
        outputFile.close();
        std::cout << "Equipo_02_Salida_" + std::to_string(itr + 1) + ".txt" + "\n";
    }
    else {
        std::cerr << "Error opening file\n";
    }
}