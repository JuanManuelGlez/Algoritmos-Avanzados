 /**
 * Titulo: A|1_Actividad Integradora 1
 * Integrantes: 
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Rodríguez Pérez A01705763
 * 
 * Materia: Análisis  y diseño de algoritmos avanzados 
 * Maestra: Ramona Fuentes Valdéz
 * 
 * Fecha de entrega: 01 - 10 - 2023
 */

#ifndef COMPARESUB_H
#define COMPARESUB_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

/**
 * Función que aplica la comparación de dos strings
 * Regresa un vector de pares con los índíces donde
 * existe un substring común desde el principal <1, 2>
 * al final del común substring. Se genera un tabulador
 * matriz que va generándose si se encuentran matches
 * en los substrings.
 * @param vector<vector<int>> tabulator
 * @param string subs1 transmission1
 * @param string subs2 transmission1
 * @note Time complexity O(n*m) worst case
 * @returns vector<pair<int, int>> con índices posInicial posFinal
 */
vector<pair<int, int>> longestCommonSubstring(vector<vector<int>> tabulator,
                                              string subs1, string subs2) {
    // Pares de índices posInicial posFinal
    vector<pair<int, int>> indices;
    // Calcular índices en base al maxInt
    int maxInt = 0;
    int endIndex = 0;
    // Creación de tabulador para realizar DP
    vector<int> lengthSubs(max(subs1.size(), subs2.size()));
    // Para cada renglón y columna
    for (int row = 0; row < tabulator.size(); row++) {
        for (int col = 0; col < tabulator[0].size(); col++) {
            // Columna y renglón 0 se llenan con 0
            if (col == 0 || row == 0) {
                tabulator[row][col] = 0;
            }
            else {
                // Si los caracteres son iguales en apuntadores - 1
                if (subs1[col - 1] == subs2[row - 1]) {
                   // El tabulador en los dos apuntadores
                   // será el máximo de o la diagonal derecha anterior
                   // o de una columna anterior + 1
                    tabulator[row][col] = max(tabulator[row - 1][col - 1] + 1,
                    tabulator[row][col - 1] + 1);
                }
                // Si no son iguales, tabulador en apuntadores es 0
                else {
                    tabulator[row][col] = 0;
                }
                // Si el maxInt es menor al tabulador en esa posición
                // hay un nuevo máximo de longitud de subcadenas iguales
                // endIndex es igual a la columna - 1
                if (maxInt < tabulator[row][col]) {
                    maxInt = tabulator[row][col];
                    endIndex = col - 1;
                }
            }
        }
        // Si al terminar toda una columna el maxInt es mayor a 0
        // Calcular posición inicial y final de substrings iguales
        // meter en vector de pares nuevas posiciones
        if (maxInt > 0) {
            int startIndex = (endIndex - maxInt + 1) + 1;
            indices.emplace_back(startIndex, endIndex + 1);
            maxInt = 0;
        }
    }
    return indices;
}
#endif