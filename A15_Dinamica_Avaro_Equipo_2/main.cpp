#include "coin_change_dp.h"
#include "coin_change_avaro.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]){
    std::vector<int> nums;
    int N;
    int i = 0;
    std::cout << "Dame numero de monedas que quieres procesar ";
    std::cin >> N;
    int monedasAvaro[N];
    while (N){
        int temp;
        std::cout << "Dame valor de moneda: ";
        std::cin >> temp;
        nums.push_back(temp);
        monedasAvaro[i++] = temp;
        N--;
    }
    int P, Q;
    std::cout << "Dame costo del producto: ";
    std::cin >> P;
    std::cout << "Tu pago: ";
    std::cin >> Q;
    std::sort(nums.begin(), nums.end());
    std::sort(monedasAvaro, monedasAvaro + i);
    std::cout << "Avaro: ";
    int ansAvaro = avaro(monedasAvaro, i, Q - P);
    std::cout << "Cantidad de monedas algoritmo avaro: " << ansAvaro;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Programacion dinamica: ";
    int ans = dynammicCoinChange(nums, P, Q);
    std::cout << "Cantidad minima de monedas para dar cambio fueron: " << ans;
    return 0;
}