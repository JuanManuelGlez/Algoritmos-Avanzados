#include <iostream>
#include "manacher.h"
#include "../readFiles.h"

int main() {
    //Creamos una variable para encontrar los archivos
    string transTemp = "../transmission/transmission";
    //Creamos un vector de string para el nombre de los archivos
    vector<string> transFiles;
    //Ejecutamos la funcion para obtener todos los archivos
    createStringsToReadTransmission(transFiles, transTemp);
    //Creamos un vector para tener todas las transmiciones leidas
    vector<string> transmissions;
    //Leemos las transmiciones 
    transmissions = leerArchivo(transFiles);
    //Por cada transmicion obtenemos su palindromo mas largo
    for(int i=0;i<transmissions.size();i++){
        //LLamamos la funcion para obtener el palindromo mas largo
        std::string palindromo = longestPalindrome(transmissions[i]);
        std::cout << std::endl;
        //Imprimimos las posiciones en la que inicia y termina, ademas del nombre del archivo
        std::cout << palindromo << " (para archivo de " <<transFiles[i].substr(16,14) <<")"<<std::endl;
    }
    
    return 0;
}

