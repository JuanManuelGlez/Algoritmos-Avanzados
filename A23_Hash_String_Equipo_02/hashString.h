#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <iomanip>

using namespace std;

/**
 * Leer el archivo y generar vectores de string
 * Time Complexity O(n)
 * @param string nombre archivo
 * @param n validado
 * @param string longitud de archivo
 */

void leerArchivo(string archivo, int n, string &longitudArchivo)
{
    archivo += ".txt";
    ifstream inFile(archivo);
    string line;
    while (getline(inFile, line))
    {
        longitudArchivo += line;
        longitudArchivo += "-";
    }
    longitudArchivo = longitudArchivo.substr(0, longitudArchivo.size() - 1);
}

/**
 * Generar matriz de rows y columnas en base
 * a la longitud del archivo
 * Time Complexity O(n**2)
 * @param vector<vector<string>> matriz
 * @param string longitud de archivo
 * @param n longitud de validacion
 */

void generarMatrizLlenado(vector<vector<char>> &matriz, string longitudArchivo, int n){
    int charIndex = 0;
    for (int i = 0; i < matriz.size(); i++){
        for (int j = 0; j < n; j++){
            if (charIndex < longitudArchivo.length()){
                matriz[i][j] = longitudArchivo[charIndex];
                charIndex++;
            }
        }
    }
}

/**
 * Calcular y sumar ASCII de columnas
 * a la longitud del archivo
 * Time Complexity O(n**2)
 * @param vector<vector<string>> matriz
 * @param vector<int> sumaColumnas
 * @param int n columnas
 * @return col suma de ascii
 */
void calcularColumnasAscii(vector<vector<char>> matriz, vector<int> &sumaColumnas, int n){
    for (int j = 0; j < matriz[0].size(); j++){
        for (int i = 0; i < matriz.size(); i++){
            if (matriz[i][j] == '['){
                sumaColumnas[j] += n;
            }
            else{
                sumaColumnas[j] += static_cast<int>(matriz[i][j]);
            }
        }
    }
}

/**
 * Calcular modulo de sumaColumnas y retraer strings Hexadecimales
 * Time Complexity O(n)
 * @param vector<int> sumaColumnas
 * @param vector<string> hexadecimales
 * @param vector<int> modulusVec
 * @param int concatenar hexadecimales
 */
void generarHexadecimales(vector<int> sumaColumnas, vector<string> &hexadecimales, int concat, vector<int> &modulusVec)
{
    stringstream ss;
    string ssUppercase;
    for (int i = 0; i < sumaColumnas.size(); i++){
        int temporal = sumaColumnas[i] % 256;
        modulusVec.push_back(temporal);
        ss << hex << setw(2) << setfill('0') << temporal;
        ssUppercase = ss.str();
        if ((i + 1) % concat == 0){
            transform(ssUppercase.begin(), ssUppercase.end(), ssUppercase.begin(), ::toupper);
            hexadecimales.push_back(ssUppercase);
            ss.str("");
            ssUppercase = "";
        }
    }
}
