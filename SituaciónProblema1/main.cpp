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