#pragma once
#include "libraries.h"

/**
 * @brief Función que pide al usuario valores del grafo a usar.
 * @param &graph `std::vector<std::vector<int>>`
 * @param n ´int´ tamaño de grafo
 * @note `Time complexity - O(n²)`
 * @result Matriz modificada con valores del usuario
 */
void getGraph(int n, std::vector<std::vector<int>> &graph, int itr) {
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
void getSizeGraph(int &x, int itr) {
    std::cin >> x;
}

/**
 * @brief Función que genera mapa de grafos con archivos de prueba.
 * @param std::vector<int> `&x` simboliza número
 * @note `Time complexity - O(n²)`
 * @result `std::map<int, std::vector<std::vector<int>>>`
 */
void readInputTxt(int itr,
                  std::map<int, std::vector<std::vector<int>>> &graphsMap,
                  std::vector<std::pair<int, int>> &coords) {
    std::string readFile = "Equipo_02_Entrada_" + std::to_string(itr + 1) + ".txt";
    
    std::ifstream inputFile(readFile);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
    }
    int sizeGraph;
    int graphs = 0;

    inputFile >> sizeGraph;
    // Parte de grafos
    while(graphs < 2) {
        for(int i = 0; i < sizeGraph; i++) {
            std::vector<int> row;
            for(int j = 0; j < sizeGraph; j++) {
                int value;
                inputFile >> value;
                row.push_back(value);
            }
            graphsMap[graphs].push_back(row);
        }
        graphs++;
    }
    // Parte de coordenadas
    while (!inputFile.eof()) {
        int x, y;
        char openParenthesis, comma, closeParenthesis;
        inputFile >> openParenthesis >> x >> comma >> y >> closeParenthesis;

        if (inputFile.fail()) {
            break;
        }
        std::pair<int, int> tuple = {x, y};
        coords.push_back(tuple);
    }
}

/**
 * @brief Función que genera grafos apartir del mapa de vectores.
 * @param totalGraphs `int`
 * @param graphColonies `std::vector<std::vector<int>>`
 * @param graphFlow `std::vector<std::vector<int>>`
 * @param graphsMap `std::map<int, std::vector<std::vector<int>>>`
 * @note `Time complexity - O(n²)`
 * @result `Grafos para aplicaciones de algoritmos`
 */
void createGraphs(int totalGraphs,
                  std::vector<std::vector<int>> &graphColonies,
                  std::vector<std::vector<int>> &graphFlow,
                  std::map<int, std::vector<std::vector<int>>> graphsMap) {
    for (int x = 0; x < totalGraphs; x++) {
        for (int i = 0; i < graphsMap[x].size(); i++) {
            for (int j = 0; j < graphsMap[x].size(); j++) {
                if (!x) {
                    graphColonies[i][j] = graphsMap[x][i][j];
                }
                else {
                    graphFlow[i][j] = graphsMap[x][i][j];
                }
            }
        }
    }
}