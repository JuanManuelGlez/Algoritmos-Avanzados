#include <iostream>
#include "manacher.h"
#include "../readFiles.h"

int main() {
    string transTemp = "../transmission/transmission";
    vector<string> transFiles;
    createStringsToReadTransmission(transFiles, transTemp);
    vector<string> transmissions;

    transmissions = leerArchivo(transFiles);

    for(int i=0;i<transmissions.size();i++){
        std::string palindromo = longestPalindrome(transmissions[i]);
        std::cout << std::endl;
        std::cout << palindromo << " (para archivo de " <<transFiles[i].substr(16,14) <<")"<<std::endl;
    }
    
    return 0;
}

