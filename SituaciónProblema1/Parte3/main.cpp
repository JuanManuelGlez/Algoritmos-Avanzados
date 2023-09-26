#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include "../readFiles.h"
#include "compareSub.h"
#include "leerArchivo.h"

using namespace std;

// Variable global para guardar los files en pares de strings
// para realizar la lectura
vector<pair<string, string>> files;

// Variable global para concatenar string de files de directorio
string trans = "../transmission/";

// Variable global de string con nombres de files transmission
vector<string> transmissions;

int main(int argc, char *argv[]) {
    createStringsToReadTransmission(transmissions, "transmission");
    for(int i = 0; i < transmissions.size(); i+=2) {
        files.emplace_back(transmissions[i], transmissions[i + 1]);
    }
    // Aplicar comparación de strings para cada par de files leídos
    for(int i = 0; i < files.size(); i++) {
        string subs1;
        string subs2;
        leerArchivoTrans(subs1, trans + files[i].first);
        leerArchivoTrans(subs2, trans + files[i].second);
        vector<vector<int>> tabulator(subs2.size(), vector<int>(subs1.size()));
        vector<pair<int, int>> indices = longestCommonSubstring(tabulator, subs1, subs2);
        int diff = 0;
        int start = 0;
        int end = 0;
        for(int x = 0; x < indices.size(); x++){
            if (diff <= (indices[x].second - indices[x].first)){
                diff = indices[x].second - indices[x].first;
                start = indices[x].first;
                end = indices[x].second;
            }
        }
        cout << "En archivo: " << files[i].first;
        cout << " el substring común más largo empieza en: " << start;
        cout << " termina en: " << end + 1 << endl;
    }
}