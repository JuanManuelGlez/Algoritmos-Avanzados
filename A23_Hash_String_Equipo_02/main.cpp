/**
 * Programa que genera hash strings
 * en base a una longitud de cadenas y un tamaño n
 * para generar ese hash de manera hexadecimal
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 21/09/23 
 * Modificación 21/09/23
*/

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include "hashString.h"

using namespace std;

int main(int argc, char *argv[]){
    string nombreArchivo, longitudArchivo;
    vector<string> hexadecimales;
    vector<int> modulosNumeros;
    int n;
    cout << "Ingresa el nombre del archivo de texto sin extensión: ";
    cout << endl;
    cin >> nombreArchivo;
    cout << "Ingresa múltiplo de 4 en un rango de 16 y 64: ";
    cin >> n;
    cout << endl;
    if (n % 4 != 0 || n < 16 || n > 64){
        cout << "El valor de 'n' no cumple con los requisitos." << endl;
        return 1;
    }
    leerArchivo(nombreArchivo, n, longitudArchivo);
    double rows = ceil(static_cast<double>(longitudArchivo.length()) / n);
    vector<vector<char>> matrizHash(static_cast<int>(rows), vector<char>(n, '['));
    generarMatrizLlenado(matrizHash, longitudArchivo, n);
    cout << "Matriz generada por el algoritmo, los saltos de línea se representan con '-' y espacios rellenados con '['";
    cout << endl;
    for (int i = 0; i < matrizHash.size(); i++){
        for (int j = 0; j < matrizHash[0].size(); j++){
            cout << matrizHash[i][j];
        }
        cout << endl;
    }
    vector<int> sumaColumnas(matrizHash[0].size(), 0);

    calcularColumnasAscii(matrizHash, sumaColumnas, n);

    generarHexadecimales(sumaColumnas, hexadecimales, n / 4, modulosNumeros);
    cout << endl;
    cout << "Arreglo de longitud 'n' que muestra la suma de las columnas con el modulo 256: ";
    cout << endl;
    for (int i = 0; i < modulosNumeros.size(); i++){
        cout << modulosNumeros[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Representación hexadecimal";
    cout << endl;
    for (int i = 0; i < hexadecimales.size(); i++){
        cout << hexadecimales[i] << " ";
    }
}