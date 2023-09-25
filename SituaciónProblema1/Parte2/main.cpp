#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include "../readFiles.h"

using namespace std;

vector<pair<string, string>> files;

vector<pair<int, int>> longestCommonSubstring(vector<vector<int>> tabulator,
                                              string subs1, string subs2) {
    vector<pair<int, int>> indices;
    int maxInt = 0;
    int endIndex = 0;
    vector<int> lengthSubs(max(subs1.size(), subs2.size()));
    for(int row = 0; row < tabulator.size(); row ++) {
        for(int col = 0; col < tabulator[0].size(); col++) {
            if(col == 0 || row == 0){
                tabulator[row][col] = 0;
            }
            else {
                if (subs1[col - 1] == subs2[row - 1]) {
                    tabulator[row][col] = max(tabulator[row - 1][col - 1] + 1, tabulator[row][col - 1] + 1);
                } else {
                    tabulator[row][col] = 0;
                }
                if(maxInt < tabulator[row][col]) {
                    maxInt = tabulator[row][col];
                    endIndex = col - 1;
                }
            }
        }
        if (maxInt > 0){
            int startIndex = (endIndex - maxInt + 1) + 1;
            indices.emplace_back(startIndex, endIndex + 1);
            maxInt = 0;
        }
    }
    return indices;
}

void leerArchivoTrans(string &transmission, string transFile) {
    ifstream inFile(transFile);
    string line;
    while (getline(inFile, line)) {
        transmission += line;
    }
}

int main(int argc, char *argv[]) {
    string trans = "../transmission/";
    vector<string> transmissions;
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
        cout << "En archivo: " << files[i].first + ".txt";
        cout << " El substring común más largo empieza en: " << start;
        cout << " termina en: " << end << endl;
    }
}