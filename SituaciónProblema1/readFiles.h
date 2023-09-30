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

#ifndef READFILES_H
#define READFILES_H
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * Función que sirve para crear strings de lectura
 * de mcodes, únicamente se modifica el vector de files
 * con la cantidad de files de casos de prueba
 * @param vector<string> files
 * @param string extension "mcode"
 * @return void
 * Time complexity O(1) porque sabemos cantidad de files
 * sino, sería O(n)
 */
void createStringsToRead(vector<string> &files, string extension) {
    for (int i = 0; i < 7; i++){
        int temp = 1;
        while (temp <= 3){
            files.push_back(extension + to_string(i) + to_string(temp) + ".txt");
            temp++;
        }
    }
}

/**
 * Función que sirve para crear strings de lectura
 * de transmission, únicamente se modifica el vector de files
 * con la cantidad de files de casos de prueba
 * @param vector<string> files
 * @param string extension "transmission"
 * @return void
 * Time complexity O(1) porque sabemos cantidad de files
 * sino, sería O(n)
 */
void createStringsToReadTransmission(vector<string> &files, string extension){
    for (int i = 0; i < 7; i++){
        int temp = 1;
        while (temp <= 2){
            files.push_back(extension + to_string(i) + to_string(temp) + ".txt");
            temp++;
        }
    }
}

/**
 * Función que sirve para leer un archivo transmissionY.txt
 * se hace línea por línea la lectura del file, y se hace conca-
 * tenación del contenido del file.
 * Se realiza la lectura de todos los archivos de tranmission de
 * par en par.
 * @param vector<string> transmissions files
 * @return vector<string> con contenido de cada transmisión
 * Time complexity O(n) porque sabemos cantidad de files
 * sino, sería O(n**2)
 */
vector<string> leerArchivo(vector<string> transmissions){
    vector<string> transmission;
    // Por cada archivo de transmisión, guardar string y hacer
    // push back
    for (int i = 0; i < transmissions.size(); i++){
        string longitudArchivo;
        string archivo = transmissions[i];

        ifstream inFile(archivo);
        string line;
        while (getline(inFile, line)){
            longitudArchivo += line;
        }
        transmission.push_back(longitudArchivo);
    }
    return transmission;
}

#endif