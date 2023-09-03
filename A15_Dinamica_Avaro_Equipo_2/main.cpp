/*  
    Este programa utiliza las clases coin_change_dp y coin_change_avaro
    para mostrar los resultados al entregar cambio con los diferentes 
    métodos, el avaro y el dinámico.  

    Daniel Gutiérrez Gómez A01068056
    Juan Manuel González Ascencio A00572003
    Julio César Pérez Rodríguez A01705763
    Creación 30/08/23, Modificación 31/08/23
*/
#include "coin_change_dp.h"
#include "coin_change_avaro.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]){
    std::vector<int> nums;
    int N;
    int i = 0;
    //Ingresamos los valores 
    std::cout << "Dame numero de monedas que quieres procesar ";
    std::cin >> N;
    int monedasAvaro[N];
    //Obtenemos los valores de las monedas
    while (N){
        int temp;
        std::cout << "Dame valor de moneda: ";
        std::cin >> temp;
        nums.push_back(temp);
        monedasAvaro[i++] = temp;
        N--;
    }
    int P, Q;
    //Obtenemos el costo y el pago para calcular el cambio
    std::cout << "Dame costo del producto: ";
    std::cin >> P;
    std::cout << "Tu pago: ";
    std::cin >> Q;
    std::sort(nums.begin(), nums.end());
    std::sort(monedasAvaro, monedasAvaro + i);
    //Calculamos el numero de monedas que vamos a utilizar con el metodo Avaro    
    std::cout << "Avaro: ";
    int ansAvaro = avaro(monedasAvaro, i, Q - P);
    std::cout << "Cantidad de monedas algoritmo avaro: " << ansAvaro;
    std::cout << std::endl;
    std::cout << std::endl;
    //Calculamos el numero de monedas que vamos a utilizar con el metodo Dinamico  
    std::cout << "Programacion dinamica: ";
    int ans = dynammicCoinChange(nums, P, Q);
    std::cout << "Cantidad minima de monedas para dar cambio fueron: " << ans;
    return 0;
}