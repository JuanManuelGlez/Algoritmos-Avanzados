/*  Programa de ordenamiento MergeSort realizar particiones calculando
    siempre la mitad (parte de divide) y cuando se llega al caso
    base de un solo elemento en las particiones, vencerás
    al juntar los elementos partidos haciendo la unión
    Daniel Gutiérrez Gómez A01068056
    Juan Manuel González Ascencio A00572003
    Julio César Pérez Rodríguez A01705763
    Creación 26/08/23, Modificación 26/08/23
*/
#include <vector>
#include <iostream>
/**
    La función toma dos vectores, se inician dos
    apuntadores se compara elemento con elemento, y se devuelve
    un vector ordenado
    @param std::vector<int> Vector de 0 a la mitad - 1 (L)
    @param std::vector<int> Vector de la mitad hasta el final (R)
    @return std::vector<int> Vector(L + R) ordenado
    Complejidad, recorrer N elementos en el peor caso
*/
std::vector<int> mergeVectors(std::vector<int>L, std::vector<int>R) {
    int i = 0; // Apuntador para vector izquierdo
    int j = 0; // Apuntador para vector derecho
    std::vector<int> temp; // Vector temporal para guardar elementos
    while(i < L.size() && j < R.size()){
        if (L[i] < R[j]){
            temp.push_back(L[i]);
            i++;
        }
        else temp.push_back(R[j]), j++;
    }
    // Mientras haya elementos en el vector derechco
    while(j < R.size()){
        temp.push_back(R[j]);
        j++;
    }
    // Mientras haya elementos en el vector izquierdo
    while (i < L.size()){
        temp.push_back(L[i]);
        i++;
    }
    return temp;
}

/**
    La función toma un vector se hacen particiones
    por cada vector, dos particiones hasta llegar
    al caso base de un elemento, cuando pasa esto
    se juntan los vectores haciendo la llamada a
    juntar los vectores del lado izquierdo y derecho
    @param std::vector<int> nums 
    @return std::vector<int> recursión caso base o unión de vectores
    Complejidad, mitades de particiones del vector O(log(n)) de particiones
    Y la llamada a mergeVectors O(n) 
    Complejidad total O(nlog(n))
*/
std::vector<int> mergeSort(std::vector<int>nums){
    // Caso base cuando solo hay un elemento en el vector
    if(nums.size() == 1){
        return nums;
    }
    int mid = nums.size() / 2; // Elemento en la mitad del vector
    // Hacer el vector izquierdo
    std::vector<int> leftVec;
    for(int i = 0; i < mid; i++){
        leftVec.push_back(nums[i]);
    }
    // Hacer el vector derecho
    std::vector<int> rightVec;
    for(int i = mid; i < nums.size(); i++){
        rightVec.push_back(nums[i]);
    }
    std::vector<int>L = mergeSort(leftVec);
    std::vector<int>R = mergeSort(rightVec);
    return mergeVectors(L, R);
}