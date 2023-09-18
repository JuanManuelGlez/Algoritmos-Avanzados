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
 * @brief Se usa DFS para hacer expansión, pero se hace 
 * una ramnificación y se corta si no es válido ese camino
 * en algún punto al momento de hacer la expansión en las cuatro
 * direcciones
 * @Time Complexity O(M*N) en el peor caso se recorre todo el tablero
 * @param vector<vector<int>> board tablero
 * @param vector<vector<int>> ans matriz final
 * @param row row del inicio
 * @param col col del inicio
 * @return bool si hay respuesta o no
 */

bool dfs(vector<vector<int>> &board, int row, int col, vector<vector<int>> &ans)
{
    int numRows = board.size();
    int numCols = board[0].size();

    // Check if we have reached the goal
    if (row == numRows - 1 && col == numCols - 1 && board[row][col] == 1)
    {
        ans[row][col] = 1;
        return true;
    }

    // Explore adjacent cells (up, right, down, left)
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int dir = 0; dir < 4; ++dir)
    {
        int newRow = row + dr[dir];
        int newCol = col + dc[dir];

        if (isValid(board, newRow, newCol) && ans[newRow][newCol] == 0)
        {
            ans[newRow][newCol] = 1; // Mark as visited
            if (dfs(board, newRow, newCol, ans))
            {
                // If a valid path is found, return true
                return true;
            }
            // If the path from this cell is not valid, backtrack
            ans[newRow][newCol] = 0; // Unmark as visited
        }
    }

    return false;
}

bool branchAndBound(vector<vector<int>> board, int row, int col, vector<vector<int>> &ans)
{
    if (row == 0 && col == 0 && board[0][0] == 1)
    {
        ans[row][col] = 1;
        return dfs(board, row, col, ans);
    }

    return false;
}
