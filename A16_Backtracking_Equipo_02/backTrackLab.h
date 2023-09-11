/**  Programa que implementa técnica recursiva de
 * backtracking, en la que se van explorando diferentes
 * caminos para llegar a la meta, si se encuentran cami-
 * nos nos validos, se regresa (backtrack) y se deja en
 * el estado anterior a la matriz en este caso del llenado
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 06/09/23, Modificación 08/09/23
 */

#include <vector>
using namespace std;

/**
 * @brief Función helper que nos dice si estamos en una posición
 * valida para que se pueda avanzar en cierta dirección
 * @param vector<vector<int>> board
 * @param int row renglón en el que estamos
 * @param int col columna en la que estamos
 * @return bool true si es válida la casilla dentro de matriz
*/
bool isValid(vector<vector<int>> board, int row, int col) {
    return row <= board.size() - 1 && col <= board[0].size() - 1 && board[row][col] == 1;
}

/**
 * @brief Se implementó técnica recursiva backtracking para
 * poder llegar a la posición M-1, N-1 de la matriz
 * "board", decidimos explorar todas las direcciones
 * para pasar todos los casos prueba propuestos
 * Time Complexity: O(4ˆ(M*N) exponencial
 * @param vector<vector<int>> board
 * @param int row renglón en el que estamos
 * @param int col columna en la que estamos
 * @param vector<vector<int>> ans, para el llenado de matriz
 * @return bool true si se llegó al caso base de DFS, sino
 * se explorarán más direcciones haciendo backtracking
*/
bool backTracking(vector<vector<int>> board, int row, int col, vector<vector<int>> &ans) {
    // Caso base (llegamos a M-1, N-1 y hay un 1 en esa casilla)
    if (row == board.size() - 1 && col == board[0].size() - 1 && board[row][col] == 1) {
        ans[row][col] = 1;
        return true;
    }
    // Antes de explorar caminos, revisar que estamos en casilla válida
    if (isValid(board, row, col)) {
        // Antes de marcar la matriz de llenado, verificar
        // que no se haya pasado por esa casilla
        if (ans[row][col] == 1) {
            return false;
        }
        ans[row][col] = 1;
        // Exploración hacia abajo
        if (backTracking(board, row + 1, col, ans)) {
            return true;
        }
        // Exploración hacia derecha
        if (backTracking(board, row, col + 1, ans)) {
            return true;
        }
        // Exploración hacia izquierda
        if (backTracking(board, row, col - 1, ans)) {
            return true;
        }
        // Exploración hacia arriba
        if (backTracking(board, row - 1, col, ans)) {
            return true;
        }
        // Backtrack, regresar al estado anterior
        ans[row][col] = 0;
    }
    return false;
}
