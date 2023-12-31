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
 * 
 * Main el cual resuelve la parte 3 de la SP1
 */

#ifndef MAINDP_H
#define MAINDP_H

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
vector<pair<string, string>> filesDP;

// Variable global para concatenar string de files de directorio
string trans = "transmission/";

// Variable global de string con nombres de files transmission
vector<string> transmissions;

void mainDP() {
    // Generar los archivos para leer
    createStringsToReadTransmission(transmissions, "transmission");
    for(int i = 0; i < transmissions.size(); i+=2) {
        filesDP.emplace_back(transmissions[i], transmissions[i + 1]);
    }
    // Aplicar DP para cada par de files
    applyDpToFiles(filesDP, trans);
}

#endif