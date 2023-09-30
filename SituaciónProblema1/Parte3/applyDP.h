#ifndef APPLYDP_H
#define APPLYDP_H

#include <vector>
#include <utility>
#include <string>
#include "../readFiles.h"
#include "compareSub.h"
#include "leerArchivo.h"

using namespace std;

/**
 * Aplicación de DP a cada par de files
 * @param vector<pair<string, string>> pares de files para aplicar comparación
 * @param string trans variable global en main para realizar lectura de archivos
 * @note Time complexity O(n^2*m) porque sabemos cuantos files son, sino incrementa
 * @returns void, solamente imprime los índices comúnes del primer transmission file
 * inicial y final iniciando en 1
 */
void applyDpToFiles(vector<pair<string, string>> files,
                    string trans) {
    // Aplicar comparación de strings para cada par de files leídos
    for (int i = 0; i < files.size(); i++) {
        string subs1;
        string subs2;
        leerArchivoTrans(subs1, trans + files[i].first);
        leerArchivoTrans(subs2, trans + files[i].second);
        // Creación de tabulador para calcular el substring común más largo
        vector<vector<int>> tabulator(subs2.size(), vector<int>(subs1.size()));

        // Índices con los substrings comúnes de transmissionX1.txt transmissionX2.txt
        vector<pair<int, int>> indices = longestCommonSubstring(tabulator, subs1, subs2);
        int diff = 0;
        int start = 0;
        int end = 0;
        // Calcular la diferencia de los pares más grande, y esos
        // serán los índices del substring común más largo encontrado
        for (int x = 0; x < indices.size(); x++) {
            if (diff <= (indices[x].second - indices[x].first)) {
                diff = indices[x].second - indices[x].first;
                start = indices[x].first;
                end = indices[x].second;
            }
        }
        cout << endl;
        cout << "           Substring             "; 
        cout << endl;
        cout << subs1.substr(start - 1, diff);
        cout << endl;
        cout << "En archivo: " << files[i].first;
        cout << endl;
        cout << "Posicion inicial: " << start;
        cout << " Posicion final: " << end << endl;
        cout << endl;
    }
}

#endif