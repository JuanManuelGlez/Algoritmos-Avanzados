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

#ifndef MANACHER_H
#define MANACHER_H

#include <string>
#include <vector>
#include <sstream>

/**
 * Funcion que aplica el algoritmo manacher para emcontrar el 
 * palindromo más largo en todos los archivos de transmision.
 * @param const string s
 * @return string, regresara un string con las posiciones 
 * de incio y final del palindromo mas grande.
 * Time complexity O(n)
*/

std::string longestPalindrome(const std::string& s) {
    // Transformar la cadena original en una con delimitadores entre cada caracter
    // y al principio y al final. Ejemplo: "abc" -> "^#a#b#c#$"
    std::string t = "^";
    for (int i = 0; i < s.size(); ++i) {
        t += "#" + s.substr(i, 1);
    }
    t += "#$";

    int n = t.size();
    std::vector<int> P(n, 0); // Arreglo que almacenará la longitud del radio del palíndromo centrado en la posición i.
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2*C - i; // Posición del espejo de i respecto a C.

        if (R > i) {
            P[i] = std::min(R - i, P[i_mirror]);
        }

        // Intentar expandir el palíndromo centrado en i.
        while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
            P[i]++;
        }

        // Si el palíndromo centrado en i se expande más allá de R, ajustar el centro y la derecha.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Encontrar el palíndromo más largo.
    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    // Extraer la subcadena palíndroma de la cadena original.
    //return s.substr((center_index - 1 - max_len) / 2, max_len);
    std::ostringstream oss;
    oss << (center_index - 1 - max_len) / 2 + 1 << " " << ((center_index - 1 - max_len) / 2) + max_len;
    return oss.str();
}

#endif