#include <iostream>
#include <map>
#include "coin_change_dp.h"


int avaro(int monedas[], int entradas, int cambio){
    int monedasUsadas = 0;
    std::map<int, int> cantidadMonedas;
    int i = entradas - 1;
    for (; i >= 0; i--){
        while (cambio >= monedas[i]){
            cambio -= monedas[i];
            monedasUsadas++;
            cantidadMonedas[monedas[i]]++;
        }
    }
    iterateMap(cantidadMonedas);
    return monedasUsadas;
}
