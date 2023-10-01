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
 */

#ifndef KMPAPPLICATION_H
#define KMPAPPLICATION_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/**
 * Función que genera tablas LPS, de cada mcodeX.txt
 * string
 * @param string mcode
 * @param vector<string> lpsTable que se modifica
 * @return void, se modifica vector de lps de tamaño
 * mcode
 * Time complexity O(n) donde n es longitud de mcode
 */
void makeLpsTable(string mcode, vector<int> &lpsTable)
{
  int j = 0;

  lpsTable[0] = 0;

  int i = 1;
  while (i < mcode.length())
  {
    if (mcode[i] == mcode[j])
    {
      j++;
      lpsTable[i] = j;
      i++;
    }
    else
    {
      if (j != 0)
      {
        j = lpsTable[j - 1];
      }
      else
      {
        lpsTable[i] = 0;
        i++;
      }
    }
  }
}

/**
 * Función que aplica el algoritmo de kmp para cada tranmission
 * se hace la comparación con 3 de mcode files, aplicando el KMP
 * algorithm con tablas LPS previamente calculadas.
 * @param vector<string> transmission strings
 * @param vector<vector<int>> lps tables
 * @param vector<string> target mcode strings
 * @return void, solo imprimir resultado de matcheo y posiciones
 * Time complexity O(6*(n+m)) porque sabemos cantidad de files
 * sino, sería O(x*y(n+m))
 */
void kmpApplication(vector<string> transmissions,
                    vector<vector<int>> lpsTables, vector<string> target, int posFile,
                    vector<string> mcodeFiles) {
  for (int x = 0; x < transmissions.size(); x++) { // Iterar dos veces para cada transmssion
    for (int y = 0; y < target.size(); y++) { // Iterar tres veces para cada mcode
      // Apuntadores para hacer comparaciones con algoritmo KMP
      int i = 0;
      int j = 0;
      int k = 0;
      // String temporal de la transmisión
      string temp = transmissions[x];
      while (i < temp.length()) {
        // Comparación mcode con transmision char por char
        // si son iguales, aumentar en
        if (target[y][j] == transmissions[x][i]) {
          i++;
          j++;
        }
        // Comparación si j llegó a la longitud de la palabra de mcode
        // setear j a 0, porque puede haber más apariciones
        if (j == target[y].length()) {
          k++;
          j = 0;
          cout << "(True) En la posicion inicial: "
               << (i - target[y].length()) + 1
               << " y final: " << i;
          cout << " en el archivo de transmission" << posFile << x + 1 << ".txt";
          cout << " en archivo: " << mcodeFiles[y].substr(7);
          cout << endl;
        }
        // Si la i todavía no llega al final del string y no hay match de caracteres
        else if (i < temp.length() && target[y][j] != transmissions[x][i]) {
          // Si j no es 0, retrasar a j, porque puede existir un prefijo
          if (j != 0) {
            j = lpsTables[y][j - 1];
          }
          // Si no, avanzar en i
          else {
            i++;
          }
        }
      }
      if (k < 1) {
        cout << "(False) El archivo transmission" << posFile << x + 1 << ".txt";
        cout << " no contiene el codigo contenido en el archivo: " << mcodeFiles[y].substr(7) << endl;
      }
    }
  }
}

/**
 * Revisar si un string es palíndromo o no
 * @param int left pointer
 * @param int right pointer
 * @param string mcode
 * @return bool isPalindrome or not
 * Time complexity O(n)
 */
bool isPalindrome(int left, int right, string mcode) {
  // Mientras apuntador izquierdo
  // sea menor al derecho, revisar
  // si los chars son diferentes, en ese
  // caso, regresar false, de otra manera
  // aumentar apuntadores
  while (left <= right) {
    if (mcode[left] != mcode[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

#endif