//Juan Manuel González - A00572003
//Daniel Gutierrez Gomez - A01068056
//TC2038

#include <bits/stdc++.h>
using namespace std;

int calcularDiasProd(int camisas){
    int linea1 = ceil (rand() % 100);
    int linea2 = ceil (rand() % 100);
    int camisasXdia = linea1 + linea2;
    int res = camisas / camisasXdia;

    return res;
}


int main(){
    int camisas;
    cin >> camisas;
    cout << "Para producir "<<camisas<<" se necesitarán "<<calcularDiasProd(camisas) <<" dias." <<endl;
    return 0;
}
