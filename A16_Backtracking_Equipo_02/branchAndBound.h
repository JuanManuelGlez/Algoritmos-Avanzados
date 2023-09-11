/**  Programa que implementa la técnica de
 * ramnificación y poda por el método de BFS
 * que, básicamente es hacer una búsqueda en expansión.
 * Cómo existe prioiridad en branch and bound, para llegar
 * al estado final, hemos decidido una prioridad de:
 * Derecha, abajo, arriba e izquierda
 * @author Daniel Gutiérrez Gómez A01068056
 * @author Juan Manuel González Ascencio A00572003
 * @author Julio César Pérez Rodríguez A01705763
 * Creación 10/09/23, Modificación 10/09/23
 */

#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

/**
 * @brief Distancia euclidiana para saber el camino más corto posible
 * @param int row de la posición actualo
 * @param int col de la posición actual
 * @param targetRow row del objetivo
 * @param targetCol col del objetivo
 * @return double con la distancia euclidiana en ese nodo
*/
double euclideanDistance(int row, int col, int targetRow, int targetCol){
    int dx = row - targetRow;
    int dy = col - targetCol;
    return sqrt(dx * dx + dy * dy);
}
/**
 * @brief estructura que hace comparación de dos pares ordenados
 * regresa el que mayor distancia tiene (pq)
 * hacer inserción al priority queue
 */
struct ComparePairs{
    pair<int, int> objective;
    ComparePairs(const pair<int, int> &obj) : objective(obj) {}
    /**
     * @param pair nodo actual
     * @param pair objetico
     * @return double con la distancia euclidiana en ese nodo para
     *
     */
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
        double euclideanDistA = euclideanDistance(a.first, a.second, objective.first, objective.second);
        double euclideanDistB = euclideanDistance(b.first, b.second, objective.first, objective.second);
        return euclideanDistA > euclideanDistB;
    }
};

/**
 * @brief Se usa BFS, en el cual se van explorando todos
 * los caminos, siempre y cuando se tenga una distancia
 * euclidiana menor para cada nodo, así hasta llegar al final
 * de no ser así, regresar false
 * @Time Complexity O(M*N) en el peor caso se recorre todo el tablero
 * @param vector<vector<int>> board tablero
 * @param vector<vector<int>> ans matriz final
 * @param row row del inicio
 * @param col col del inicio
 * @return bool si hay respuesta o no
 */
bool branchAndBound(vector<vector<int>> board, int row, int col, vector<vector<int>> &ans){
    // Primer parámetro lo que se guardará en pq, segundo como será el acceso
    // tercero, para cada nodo insertado (pair) guardar el de menor distancia
    // euclidiana
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   ComparePairs>
        bfs(ComparePairs({board.size() - 1, board[0].size() - 1}));
    if (row == 0 && col == 0 && board[0][0] == 1){
        pair<int, int> temp;
        bfs.push(make_pair(row, col));
        ans[row][col] = 1;
    }

    while (!bfs.empty()){
        pair<int, int> temp;
        temp = bfs.top();

        bfs.pop();
        int rowBfs = temp.first;
        int colBfs = temp.second;
        if (rowBfs == board.size() - 1 && colBfs == board[0].size() - 1 && board[rowBfs][colBfs] == 1){
            ans[rowBfs][colBfs] = 1;
            return true;
        }
        ans[rowBfs][colBfs] = 1;
        if (isValid(board, rowBfs, colBfs + 1) && !(ans[rowBfs][colBfs + 1])){
            bfs.push(make_pair(rowBfs, colBfs + 1));
        }
        if (isValid(board, rowBfs + 1, colBfs) && !(ans[rowBfs + 1][colBfs])){
            bfs.push(make_pair(rowBfs + 1, colBfs));
        }
        if (isValid(board, rowBfs - 1, colBfs) && !(ans[rowBfs - 1][colBfs])){
            bfs.push(make_pair(rowBfs - 1, colBfs));
        }
        if (isValid(board, rowBfs, colBfs - 1) && !(ans[rowBfs][colBfs - 1])){
            bfs.push(make_pair(rowBfs, colBfs - 1));
        }
    }
    return false;
}