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
 * Main el cual resuelve la parte 2 de la SP1
 */

#ifndef MAINMANACHER_H
#define MAINMANACHER_H

#include <iostream>
#include "manacher.h"
#include "../readFiles.h"

void mainManacher() {
    //Creamos una variable para encontrar los archivos
    string transTemp = "transmission/transmission";
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
        std::cout << palindromo << " (para archivo de " <<transFiles[i].substr(13,14) <<")"<<std::endl;
    }
}

#endif