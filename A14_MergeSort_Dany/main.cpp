/*  Programa que genera vectores con números random
    [0-100] de tamaño 10, son ordenados y desplegados
    en pantalla
    Daniel Gutiérrez Gómez A01068056
    Juan Manuel González Ascencio A00572003
    Julio César Pérez Rodríguez A01705763
    Creación 27/08/23, Modificación 27/08/23
*/
#include "mergeSort.h"
#include <iostream>
#include <vector>
#include <cstdlib>
/**
 * La función toma un vector (ordenado o no), un entero
 * un booleano para saber si está ordenado el vector
 * a imprimir o no
 * @param std::vector<int> Vector
 * @param int N (entradas, salidas)
 * @param bool está ordenado o no
 * Complejidad, recorrer N elementos
 * Sería O(n), en nuestro caso O(1) porque sabemos el número
 * de elementos que tiene el vector
*/
void printVector(std::vector<int> nums, int N, bool isSorted) {
    if(!isSorted) {
        std::cout << "Entrada " << N + 1 << ": ";
    }else {
        std::cout << " Salida " << N + 1 << ": ";
    }
    for(std::vector<int>::iterator ptr = nums.begin(); ptr != nums.end(); ++ptr){
        std::cout << *ptr;
        if (ptr != nums.end() - 1){
            std::cout << ", ";
        }
    }
    if(isSorted){
        std::cout << std::endl << std::endl;
    }
}

/**
 * La función toma un vector desordenado, un entero
 * un booleano para saber si está ordenado el vector
 * @param std::vector<int> Vector
 * @param int N (entradas, salidas)
 * @param bool está ordenado o no
 * Complejidad mergeSort O(n(log(n)))
 * Complejidad printVector O(n)
 */
void sort(std::vector<int> nums, int N, bool isSorted){
    std::vector<int> ans = mergeSort(nums);
    printVector(ans, N, isSorted);
}

/**
 * La función toma un entero que es el tamaño del
 * vector para generar vectores y otro entero para
 * generar entradas
 * @param int N tamaño del vector
 * @param int entries entradas a procesar
 * La complejidad en un escenario promedio, la 
 * será de O(n(log(n))), sin embargo, con entradas
 * más grandes, incrementaría a 
 * O(entries(n(log(n)))
 */
void generateVectors(int N, int entries) {
    int vectors = 0;
    int aux = entries;
    while(vectors < entries) {
        std::vector<int> temp;
        while(N) {
            temp.push_back(rand() % 100);
            N--;
        }
        printVector(temp, vectors, false);
        sort(temp, vectors, true);
        vectors++;
        N = aux;
    }
}

int main(int argc, char *argv[]) {
    int N;
    int vectors;
    std::cin >> N;
    std::cin >> vectors;
    generateVectors(N, vectors);
    return 0;
}