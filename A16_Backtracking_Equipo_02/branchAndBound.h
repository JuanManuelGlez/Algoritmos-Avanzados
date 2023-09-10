/**  Programa que implementa técnica recursiva de
 * backtracking, en la que se van explorando diferentes
 * caminos para llegar a la meta, si se encuentran cami-
 * nos nos validos, se regresa (backtrack) y se deja en 
 * el estado anterior a la matriz en este caso del llenado
 * Daniel Gutiérrez Gómez A01068056
 * Juan Manuel González Ascencio A00572003
 * Julio César Pérez Rodríguez A01705763
 * Creación 06/09/23, Modificación 08/09/23
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;


/* 
1.- Guardar el primer elemento (row 0 col 0) en el queue (solo si es un 1)
2.- Mientras la queue no este vacia, guardar el nodo de enfrente (row col) como set.
2.1.- Remover el nodo de enfrente del queue.
3.- Revisar si la posicion es la meta, si lo es, regresar true y marcar en la matriz de estados con 1.
4.- Verificar si la la posicion en col + 1, row + 1, row -1, col -1 es valida (es 1 y no ha sido visidada), si lo es, actualizar matriz de estados.
4.1.- Si la posicion es valida, guardar en el queue.
5.- En caso de no llegar a la meta y tener la queue vacia, regresar false.
*/

bool branchAndBound(vector<vector<int>> board, int row, int col, vector<vector<int>> &ans){
    queue<pair<int, int>>bfs;


    if (row == 0 && col == 0 && board[0][0]== 1){
        pair<int, int>temp;
        temp.first=row;
        temp.second=col;

        bfs.push(temp);
        ans[row][col]=1;
    }

    while (!bfs.empty()){
        pair<int, int>temp;
        temp = bfs.front();
        bfs.pop();
        int rowBfs = temp.first;
        int colBfs = temp.second;
        

        if (rowBfs == board.size()-1 && colBfs == board[0].size()-1 && board[rowBfs][colBfs] == 1){
            ans[rowBfs][colBfs] = 1;
            return true;
        }

        if(isValid(board, rowBfs, colBfs+1) && !ans[rowBfs][colBfs+1] == 1){
            pair<int, int> right;
            right.first = rowBfs;
            right.second =colBfs+1;
            bfs.push(right);
            ans[rowBfs][colBfs+1]=1;
        }
            else if(isValid(board, rowBfs+1, colBfs) && !ans[rowBfs+1][colBfs] == 1){
                pair<int, int> down;
                down.first = rowBfs+1;
                down.second =colBfs;
                bfs.push(down);
                ans[rowBfs+1][colBfs]=1;
        }
            else if(isValid(board, rowBfs-1, colBfs) && !ans[rowBfs-1][colBfs] == 1){
                    pair<int, int> up;
                    up.first = rowBfs-1;
                    up.second =colBfs;
                    bfs.push(up);
                    ans[rowBfs-1][colBfs]=1;
        }
            else if(isValid(board, rowBfs, colBfs-1) && !ans[rowBfs][colBfs-1] == 1){
                pair<int, int> left;
                left.first = rowBfs;
                left.second =colBfs-1;
                bfs.push(left);
                ans[rowBfs][colBfs-1]=1;
        }
        
    }
            return false;
}
