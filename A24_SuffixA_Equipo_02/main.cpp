/**
 * Programa que genera una lista de sufijos de una cadena ordenados alfabeticamente
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 21/09/23 
 * Modificación 21/09/23
*/

#include <bits/stdc++.h>

using namespace std;


void generarSufijos(string palabra){
    vector<string> sufijos;
    for(int i = 0; i < palabra.length(); i++){
        sufijos.push_back(palabra.substr(i, palabra.length()));
    }
    sort(sufijos.begin(), sufijos.end());


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