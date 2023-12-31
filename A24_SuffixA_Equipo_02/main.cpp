/**
 * Programa que genera una lista de sufijos de una cadena ordenados alfabeticamente
 * Complejidad O(n log n)
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 22/09/23 
 * Modificación 22/09/23
*/

#include <bits/stdc++.h>

using namespace std;


void generarSufijos(string palabra){
    vector<string> sufijos;
    //Generar lista de sufijos.
    for(int i = 0; i < palabra.length(); i++){
        sufijos.push_back(palabra.substr(i, palabra.length()));
    }
    //Ordenamiento de la lista de sufijos de manera alfabética.
    sort(sufijos.begin(), sufijos.end());

    //Imprimir lista ordenada de sufijos con posición inicial.
    for(int i = 0; i < sufijos.size(); i++){
        cout << i << " "<< palabra.length() - sufijos[i].length() << ": "<<sufijos[i] << endl;
    }
}



int main(int argc, char *argv[]){

    string palabra;
    cout<< "Ingresa la palabra: "<<endl;
    cin >> palabra;


    generarSufijos(palabra);
    

}