#include "coin_change_dp.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]){
    std::vector<int> nums;
    int N;
    std::cout << "Dame número de monedas que quieres procesar ";
    std::cin >> N;
    while(N){
        int temp;
        std::cout << "Dame valor de moneda: ";
        std::cin >> temp;
        nums.push_back(temp);
        N--;
    }
    int P, Q;
    std::cout << "Dame costo del producto: ";
    std::cin >> P;
    std::cout << "Tu pago: ";
    std::cin >> Q;
    sort(nums.begin(), nums.end());
    int ans = dynammicCoinChange(nums, P, Q);
    std::cout << "Cantidad mínima de monedas para dar cambio fueron: " << ans;
    return 0;
}