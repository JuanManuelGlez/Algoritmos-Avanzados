#include "libraries.h"

/**
 * @brief Función que calcula la distancia euclidiana entre dos puntos
 * @note `Time Complexity - O(1)`
 * @param coord1 `std::pair<int, int>`
 * @param coord2 `std::pair<int, int>`
 * @returns `float - Distancia euclidiana`
*/
float euclideanDistance (std::pair<int, int> coord1, std::pair<int, int> coord2){
    return sqrt(pow(coord2.first - coord1.first, 2) + pow(coord2.second - coord1.second, 2));
}

/**
 * @brief Función que calcula la distancia minima entre un punto y un conjunto de puntos
 * @note `Time Complexity - O(n)`
 * @param points `std::vector <std::pair<int, int>>`
 * @param n `int`
 * @param newCentral `std::pair<int, int>`
 * @returns `std::string - Distancia minima`
*/
std::string minDistanceEuclidean (std::vector <std::pair<int, int>> points, int n, std::pair<int, int> newCentral){
    float min = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++){
        float dist = euclideanDistance(newCentral, points[i]);
        if (dist < min){
            index = i;
            min = dist;
        }
    }
    std::string minDistance = "La distancia minima es: " + std::to_string(min) + "\n" + "Entre los puntos: (" + std::to_string(points[index].first) + ", " + std::to_string(points[index].second) + ") y (" + std::to_string(newCentral.first) + ", " + std::to_string(newCentral.second) + ")\n";
    return minDistance;
}