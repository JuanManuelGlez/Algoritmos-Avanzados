/*  
    Programa para entregrar el cambio usando un metodo Avaro

    El programa resive las monedas validas, la entrada y el cambio que se debe de dar.

    Daniel Gutiérrez Gómez A01068056
    Juan Manuel González Ascencio A00572003
    Julio César Pérez Rodríguez A01705763
    Creación 30/08/23, Modificación 31/08/23
*/

#include <iostream>
#include <map>
#include "coin_change_dp.h"

/*
    Este codigo tiene una complejidad de O(n log m), debido a que el primer ciclo 
    tiene una complejidad de O(n) donde n es la cantidad de monedas que tenemos 
    disponibles, y el segundo ciclo tiene una complejidad de O(log m) donde m es 
    la cantidad de cambio que tiene que dar en base al valor de las monedas. 
*/
int avaro(int monedas[], int entradas, int cambio){
    //Este contador los usaremos para imprimir las monedas que vamos a usar
    int monedasUsadas = 0;
    std::map<int, int> cantidadMonedas;
    int i = entradas - 1;
    for (; i >= 0; i--){
        /*Comprobamos el cambio con el tamaño de la moneda, para entregar
        las monedas mas grandes primero y para luego completar las que siguen
        en valor y asi hasta completar el cambio.*/
        while (cambio >= monedas[i]){
            cambio -= monedas[i];
            //Sumamos la cantidad de monedas que estamos usando
            monedasUsadas++;
            cantidadMonedas[monedas[i]]++;
        }
    }
    iterateMap(cantidadMonedas);
    return monedasUsadas;
}
