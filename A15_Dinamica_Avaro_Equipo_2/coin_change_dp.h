/*  Programa de Cambio de Monedas, primeramente se recibe
    un número N que nos delimita los elementos con la
    dispoción de monedas o billetes de cierta cantidad, para
    después recibir estas cantidades hasta llegar a N. Después
    Recibir dos cantidades, costo de producto y con qué se pagó
    el producto. Nuestro programa calcula la menor cantidad de mone-
    das billetes con las que se puede dar el cambio apartir del pago.
    Algoritmo que utiliza la técnica de programación dinámica.
    Daniel Gutiérrez Gómez A01068056
    Juan Manuel González Ascencio A00572003
    Julio César Pérez Rodríguez A01705763
    Creación 30/08/23, Modificación 31/08/23
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/**
 * Apartir del estado final de la matriz de llenado de
 * programación dinámica, se inicia en la po-
 * sición final, con dos apuntadores, se itera hasta que
 * alguno de los dos sea igual o menor a 0. Se van tomando
 * los valores siguiendo las fórmulas en sentido opuesto para encontrar
 * la menor cantidad de monedas y su valor para devolver el cambio.
 * Complejidad O(n) en el peor caso, cuando hay únicamente monedas
 * de valor 1 y se quiere llegar a un cambio de n
 * @param std::<vector<std::vector>> Matriz en el estado final
 * @param std::vector<int> Monedas con su valor
 * @return std::vector<int> Vector de monedas utilizadas
 */
std::map<int, int> getCoins(std::vector<std::vector<int>> dp, std::vector<int> coins){
    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    std::map<int, int> ans;
    while (i > 0 && j > 0){
        /// Calcular el índice de la posición estado anterior
        int index = j - coins[i]; 
        if (index < 0){
            // Cuando el índice es menor a 0, sabemos que el mínimo puede
            // estar en una renglón anterior o en la misma columna, sí 
            // sucede que el valor de la columna - el valor de la moneda
            // de un renglón anterior es menor a 0, debemos de decrementar
            // el valor de la moneda hasta llegar a una diferencia de 0 
            if (j - coins[i - 1] < 0){
                while (j - coins[i] < 0){
                    i--;
                }
                // Mientras haya columnas (j > 0)
                // se asignará un valor extra a cada
                // key asociado (valor de la moneda)
                while (j){
                    ans[coins[i]]++;
                    j--;
                }
            }
            else {
                // Si el índice es menor a 0
                // y la diferencia de columna con el
                // valor de la moneda de renglón anterior
                // es >= 0, en el key del valor de la moneda
                // de renglón anterior sumarle un valor
                ans[coins[--i]]++;
            }
        }
        else {
            // Retroceder en el mismo renglón en columna (columna menos valor moneda)
            // o misma columna renglón pasado, saber cual es el menor, y hacer asignación
            // de valor extra al key del valor de la moneda en esa posición 
            int sameRow = dp[i][index] + 1;
            int pastRow = dp[i - 1][j];
            if (sameRow < pastRow){
                ans[coins[i]]++;
            }
            else{
                ans[coins[--i]]++;
            }
        }
        j -= coins[i]; // Siempre restar al elemento j el valor de la moneda
    }
    return ans;
}

/**
 * Iterar hash map con reverse std::iterator
 * de key, values para saber el número de las apariciones
 * de cada una de las monedas dadas
 * Complejidad O(1)
 * @param std::map<int, int> Key->Monedas, Val->Apariciones
 * @return void
*/
void iterateMap(std::map<int, int>ans) {
    std::map<int, int>::reverse_iterator ptr;
    for (ptr = ans.rbegin(); ptr != ans.rend(); ++ptr){
        std::cout << "Moneda de: " << ptr->first << ", apariciones: " << ptr->second << std::endl;
    }
}

/**
 * Cálculo de la menor cantidad de monedas de cambio apartir de
 * un costo y un pago. Se utilizó el algoritmo de bottom up 
 * programación dinámica.
 * Complejidad de O(n*Q-P)
 * @param std::vector<int> monedas a procesar
 * @param int Q pago del producto
 * @param int P costo del producto
 * @return int menor número de monedas posible para dar cambio
 */
int dynammicCoinChange(std::vector<int> coins, int P, int Q){
    /// Cálculo del cambio
    int change = Q - P;
    /// Incialización de matriz de estados 
    std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(change + 1)); 
    // Rellenar primer renglón de la matriz con índice
    for (int i = 0; i <= change; i++){
        dp[0][i] = i;
    }
    for (int i = 1; i < dp.size(); i++){
        for (int j = 0; j < dp[i].size(); j++){
            // Si el valor de la moneda es menor que valor de columna,
            // calcular el min de posición arriba
            // con la posición antes calculada
            // (mismo renglón y columna menos valor de moneda)
            if (coins[i] <= j){
                int index = j - coins[i];
                dp[i][j] = std::min(dp[i][index] + 1, dp[i - 1][j]);
            }
            else{
                // A fuerza, el menor valor está un renglón arriba
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // Llamada a función con matriz en estado final
    // y con vector de monedas
    std::map<int, int> ans = getCoins(dp, coins);
    /// Llamada para imprimir resultados
    iterateMap(ans); 
    return dp[coins.size() - 1][change];
}
