/**
 * Programa que aplica DP para dos strings de files
 * de transmisión por cada par, imprime los índices
 * del primer archivo de transmisión del string
 * común más grande.
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 25/09/23
 * Modificación 26/09/23
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include "applyDP.h"

using namespace std;

// Variable global para guardar los files en pares de strings
// para realizar la lectura
vector<pair<string, string>> files;

// Variable global para concatenar string de files de directorio
string trans = "../transmission/";

// Variable global de string con nombres de files transmission
vector<string> transmissions;

int main(int argc, char *argv[]) {
    // Generar los archivos para leer
    createStringsToReadTransmission(transmissions, "transmission");
    for(int i = 0; i < transmissions.size(); i+=2) {
        files.emplace_back(transmissions[i], transmissions[i + 1]);
    }
    // Aplicar DP para cada par de files
    applyDpToFiles(files, trans);
}