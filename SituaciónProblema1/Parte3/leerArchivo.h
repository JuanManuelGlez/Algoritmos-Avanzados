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