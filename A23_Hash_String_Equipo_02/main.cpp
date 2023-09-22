#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

/**
 * Leer el archivo y generar vectores de string
 * Time Complexity O(n)
 * @param string nombre archivo
 * @param n validado
 * @param string longitud de archivo
 * @returns vector
 */

void leerArchivo(string archivo, int n, vector<string> &stringText, string longitudArchivo)
{
    archivo += ".txt";
    ifstream inFile(archivo);
    string line;
    while (getline(inFile, line))
    {
        longitudArchivo += line;
        stringText.push_back(line + "-");
    }
}

int main(int argc, char *argv[])
{
    string nombreArchivo, longitudArchivo;
    int n;
    vector<string> stringText;
    cout << "Ingresa el nombre del archivo de texto sin extensión: ";
    cout << endl;
    cin >> nombreArchivo;
    cout << "Ingresa múltiplo de 4 en un rango de 16 y 64: ";
    cin >> n;
    cout << endl;
    if (n % 4 != 0 || n < 16 || n > 64)
    {
        cout << "El valor de 'n' no cumple con los requisitos." << endl;
        return 1;
    }
    leerArchivo(nombreArchivo, n, stringText, longitudArchivo);
    double rows = ceil(static_cast<double>(longitudArchivo.length()) / n);

    vector<vector<char>> matrizHash(static_cast<int>(rows), vector<char>(n, '['));

    // Llenar matrizHash
    int charIndex = 0;
    for (int i = 0; i < matrizHash.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (charIndex < longitudArchivo.length())
            {
                matrizHash[i][j] = longitudArchivo[charIndex];
                charIndex++;
            }
        }
    }
    for (int i = 0; i < matrizHash.size(); i++)
    {
        for (int j = 0; j < matrizHash[0].size(); j++)
        {
            cout << matrizHash[i][j];
        }
        cout << endl;
    }
}