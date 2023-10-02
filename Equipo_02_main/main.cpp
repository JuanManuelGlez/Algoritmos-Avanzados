/**
 * 
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
 * Este archivo ejecuta las diferentes partes de la actividad
 * las cuales son mainKMP, mainManacher y mainDP.
 */

#include "Parte1/mainKMP.h"
#include "Parte2/mainManacher.h"
#include "Parte3/mainDP.h"


int main(int argc, char *argv[]) {
    cout<<endl;
    cout<<"----- PARTE 1 ------"<<endl;

    mainKMP();

    cout<<endl;
    cout<<"----- PARTE 2 ------"<<endl;

    mainManacher();

    cout<<endl;    
    cout<<"----- PARTE 3 ------"<<endl;
    
    mainDP();
}