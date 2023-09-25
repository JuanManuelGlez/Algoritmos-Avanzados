/**
 * Parte uno de Situación Problema
 * Programa que sirve para saber si existe
 * una cadena de strings en este caso son
 * archivos de texto llamados "mcodeX.txt"
 * de los cuales, se tiene que saber si se
 * encuentra esa cadena en otro archivo de
 * transmisión "transmissionY.txt". El mapeo
 * que se hizo, es una comparación de que por
 * cada cadena "mcodeX.txt", se debe de hacer la
 * comparación a los dos archivos de "transmissionY.txt"
 * esto, 3 veces ya que hay tres archivos de "mcodeX.txt"
 * al final, sabremos la posición inicial y final
 * dentro del archivo "transmissionY.txt" si es que
 * se encontró la cadena de "mcodeX.txt" en "transmissionY.txt"
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 21/09/23, Modificación 23/09/23
 */

#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <fstream>
#include "../readFiles.h"
#include "kmpApplication.h"

using namespace std;
// Inicialización de variable global, vector de par
// de vectores con "relación" 3 mcodeX.txt a 2 transmissionY.txt
// ejemplo: [ <[mcode01.txt, mcode02.txt, mcode03.txt], [transmission01.txt, transmission02.txt]>,
//          <[mcode11.txt, mcode12.txt, mcode13.txt], [transmission11.txt, transmission12.txt]>]
vector<pair<vector<string>, vector<string>>> files;

/**
 * Función que genera relación de pares de files, 3 mcodeX.txt
 * con 2 de transmissionY.txt
 * @param vector<string> mcodes file extensions
 * @param vector<string> transmission file extensions
 * @return void, se hace push back a variable global de vector
 * de pares de vectores.
 * Time complexity O(n) porque sabemos cantidad de files
 */
void makePairsVectorFiles(vector<string> mcodes, vector<string> transcodes){
    // Por cada 3 de mcode son 2 de transmisión
    // calcular número de pares de vectores totales
    int numPairs = mcodes.size() / 3;

    for (int i = 0; i < numPairs; i++) {
        pair<vector<string>, vector<string>> temp;
        vector<string> mcodeTemp;
        vector<string> transTemp;
        for (int j = 0; j < 3 && (i + j) < mcodes.size(); j++) {
            mcodeTemp.push_back(mcodes[i * 3 + j]);
        }
        temp.first = mcodeTemp;
        for (int k = 0; k < 2 && (i + k) < transcodes.size(); k++) {
            transTemp.push_back(transcodes[i * 2 + k]);
        }
        temp.second = transTemp;
        files.push_back(temp);
    }
}

int main(int argc, char *argv[]){
    // Inicialización de variables globales dentro de main
    // archivos a leer, y textos con extensión de files
    string mcodeTemp = "../mcodes/mcode";
    string transTemp = "../transmission/transmission";
    vector<string> mcodeFiles;
    vector<string> transFiles;

    // Creación de los strings para leer archivos
    createStringsToRead(mcodeFiles, mcodeTemp);
    createStringsToReadTransmission(transFiles, transTemp);

    // Realizar vector de par de vectores para después hacer lectura
    // de la relación
    makePairsVectorFiles(mcodeFiles, transFiles);

    // Por cada par de vectores, abrir mcode, para generar LPSTable
    // a files.first (mcode)
    for (int i = 0; i < files.size(); i++){
        // Mcodes
        vector<string> firstMcode = files[i].first;
        // Transmissions
        vector<string> firstTrans = files[i].second;
        // Tablas LPS son 3 vectores para cada iteración
        vector<vector<int>> lpsTables;
        // Transmisiones, son dos por cada par de vectores
        vector<string> transmissions;
        // mcodes, son tres por cada par de vectores
        vector<string> mcodes;
        // Para cada vector dentro de Mcode
        // aplicar LPS, guardar en vector temporal de tablas
        // y aplicar KMP a cada transmission con cada LPS y cada
        // mcode string
        for (int j = 0; j < firstMcode.size(); j++){
            ifstream mCode(firstMcode[j]);
            if (mCode.is_open()){
                string temp;
                while (mCode.good()){
                    mCode >> temp;
                }
                // Generar tabla lps
                // con string leído del mcodeX.txt
                mcodes.push_back(temp);
                vector<int> lps(temp.size());
                makeLpsTable(temp, lps);
                lpsTables.push_back(lps);
                // Si no es palíndromo, voltear string
                // porque puede existir al revés el string
                // en transmission
                // if (!isPalindrome(0, temp.size() - 1, temp)) {
                //     reverse(temp.begin(), temp.end());
                //     mcodes.push_back(temp);
                //     makeLpsTable(temp, lps);
                //     lpsTables.push_back(lps);
                // }
                mCode.close();
            }
            else {
                cerr << "Unable to open file." << endl;
            }
        }
        // Leer archivo de transmisión una vez tenidas las tablas LPS
        transmissions = leerArchivo(firstTrans);
        // Aplicar KMP con:
        // 2 strings de transmisión
        // 3 tablas LPS
        // 3 patrones mcode
        kmpApplication(transmissions, lpsTables, mcodes, i, firstMcode);
        cout << endl;
    }
}