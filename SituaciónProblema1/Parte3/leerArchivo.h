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

#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Función que lee los documentos apartir de un string
 * de transmisión además se regresa el string de transmisión
 * @param string de transmission modificado con la lectura del archivo
 * @param string de transmission modificado con la lectura del archivo
 * @note Time complexity O(n) worst case
 * @returns string de file transmisión modificado
 */
void leerArchivoTrans(string &transmission, string transFile) {
    ifstream inFile(transFile);
    string line;
    while (getline(inFile, line)) {
        transmission += line;
    }
}

#endif