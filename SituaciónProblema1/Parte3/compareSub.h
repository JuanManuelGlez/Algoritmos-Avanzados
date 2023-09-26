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
    vector<pair<int, int>> indices;
    int maxInt = 0;
    int endIndex = 0;
    vector<int> lengthSubs(max(subs1.size(), subs2.size()));
    for (int row = 0; row < tabulator.size(); row++) {
        for (int col = 0; col < tabulator[0].size(); col++) {
            if (col == 0 || row == 0) {
                tabulator[row][col] = 0;
            }
            else {
                if (subs1[col - 1] == subs2[row - 1]) {
                    tabulator[row][col] = max(tabulator[row - 1][col - 1] + 1,
                     tabulator[row][col - 1] + 1);
                }
                else {
                    tabulator[row][col] = 0;
                }
                if (maxInt < tabulator[row][col]) {
                    maxInt = tabulator[row][col];
                    endIndex = col - 1;
                }
            }
        }
        if (maxInt > 0) {
            int startIndex = (endIndex - maxInt + 1) + 1;
            indices.emplace_back(startIndex, endIndex + 1);
            maxInt = 0;
        }
    }
    return indices;
}
