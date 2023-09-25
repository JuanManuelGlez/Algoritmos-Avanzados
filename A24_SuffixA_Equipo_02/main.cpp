/**
 * Programa que genera una lista de sufijos de una cadena ordenados alfabéticamente
 * Complejidad O(n log n)
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 22/09/23 
 * Modificación 22/09/23
*/

// Incluye la biblioteca estándar de C++ que contiene funcionalidades para entrada/salida.
#include <bits/stdc++.h>

// Usa el espacio de nombres estándar de C++ para evitar tener que anteponer "std::" a las funciones y objetos estándar.
using namespace std;

// Función que genera y muestra una lista de sufijos de una cadena dada, ordenados alfabéticamente.
void generarSufijos(string palabra){
    vector<string> sufijos;

    // Genera la lista de sufijos de la cadena.
    for(int i = 0; i < palabra.length(); i++){
        sufijos.push_back(palabra.substr(i, palabra.length()));
    }

    // Ordena la lista de sufijos de manera alfabética.
    sort(sufijos.begin(), sufijos.end());

    // Imprime la lista ordenada de sufijos junto con la posición inicial en la cadena original.
    for(int i = 0; i < sufijos.size(); i++){
        cout << i << " "<< palabra.length() - sufijos[i].length() << ": "<<sufijos[i] << endl;
    }
}

int main(int argc, char *argv[]){

    string palabra;
    cout<< "Ingresa la palabra: "<<endl;

    // Lee una cadena de entrada desde el usuario.
    cin >> palabra;

    // Llama a la función para generar y mostrar los sufijos de la cadena ingresada.
    generarSufijos(palabra);
}
