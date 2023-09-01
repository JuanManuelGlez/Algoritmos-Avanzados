//Juan Manuel González - A00572003
//Daniel Gutierrez Gomez - A01068056    
//Julio Perez A0XXXXXXX
// Creación 28/08/2021
//Last change 28/08/2023
//TC2038
//Problema de cambio de monedas

// Solución con el diseño Ávaro
#include <bits/stdc++.h>
using namespace std;

int Avaro(int monedas[], int entradas, int cambio){
    int monedasUsadas = 0;
    int monedasTotales [entradas];

    for (int i = 0; i < entradas; i++){
        while (cambio >= monedas[i]){
            cambio -= monedas[i];
            monedasUsadas++;
            monedasTotales[i]++;
        }
    }

    return monedasUsadas;
}



int main (){

    //Entradas
    int entradas = 0;
    cout<< "Ingresa el numero de monedas"<<endl;
    cin >> entradas;
    //cout << entradas << endl;
    int monedas [entradas];

    cout << "Ingresa las monedas" << endl;
    for (int i = 0; i < entradas; i++){
        cin >> monedas[i];
    }

    cout<<"Ingresa el valor de P y Q"<< endl;
    int P, Q, cambio;
    cin >> P;
    cin >> Q;
    cambio = Q - P;
    sort(monedas, monedas + entradas, greater<int>());


    for (int i = 0; i < entradas; i++){
        cout << monedas[i] << " ";
    }

    cout << "El numero de monedas usadas es: " << Avaro(monedas, entradas, cambio) << endl; 


}