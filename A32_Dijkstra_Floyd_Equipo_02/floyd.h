/**
 * Programa que encuentra el camino más corto entre dos nodos de un grafo usando la tecnica de FLoyd
 * Complejidad O(n³)
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 19/10/23 
 * Modificación 19/10/23
*/

#include <bits/stdc++.h>
using namespace std;

void Imprimir (vector<vector<int>> grafo, int n);

/**
 * @brief Se hace iteración de todos los nodos hasta visitar todos y encontrar el camino mínimo
 * @param vector<vector<int>> grafo
 * @param int n
 * Time complexity O(n³)
 */
void Floyd(vector<vector<int>> grafo, int n){

    int i, j, k; //Variables para poder iterar por todos los vértieces del grafo

    for (int k=0; k<n; k++){
        //Se toman todos los vertices como origen uno por uno
        for (int i=0; i<n; i++){
            //Se toman todos los vertices como destino para cada origen
            for (int j=0; j<n; j++){

                if (grafo[i][k] == -1){
                    grafo[i][k] = INT_MAX/2;
                }
                else if(grafo[k][j] == -1){
                    grafo[k][j] = INT_MAX/2;
                }
                else if(grafo[i][j] == -1){
                    grafo[i][j] = INT_MAX/2;
                }

                if (grafo[i][j] > (grafo[i][k] + grafo[k][j]) && grafo[i][k] != -1 && grafo[k][j] != -1){
                    //Si el camino de i a j es mayor que el camino de i a k + k a j, entonces se actualiza el camino de i a j
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
                }
            }
        }
    }

    Imprimir(grafo, n);

    
}

/**
 * @brief Se imprime la matriz de distancias
 * @param vector<vector<int>> matriz
 * @param int n
 * Time complexity O(n²)
 */
void Imprimir(vector<vector<int>> grafo, int n){

    cout<<"---------------------"<<endl;
    cout<<"Floyd"<<endl;
    cout<<"---------------------"<<endl;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

