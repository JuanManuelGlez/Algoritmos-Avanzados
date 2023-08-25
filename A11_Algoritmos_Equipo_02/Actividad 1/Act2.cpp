//Juan Manuel González - A00572003
//Daniel Gutierrez Gomez - A01068056
//TC2038

#include <bits/stdc++.h>
using namespace std;

float calcularVolumen(float radio, float altura){
    float volumen = M_PI * radio * radio * altura;
    return volumen;
}

int calcularBotellas(float volumen, int M){
    int cubicos = volumen * 1000000;
    int res = cubicos / M;
    return res;
}

int main(){

    float radio, altura;
    int M;
    cin >> radio >> altura >> M;

    float volumen = calcularVolumen(radio, altura);
    int botellas = calcularBotellas(volumen, M);

    cout << botellas << endl;

    return 0;

}
