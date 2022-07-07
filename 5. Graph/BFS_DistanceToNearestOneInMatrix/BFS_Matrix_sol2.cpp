# include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
    private:
    struct Cell{
        int x;
        int y;
    };
    vector<vector<int>> result;
    queue<Cell> bfsQueue;                                               // 1 bfsQueue for all BFS() run

    int bfs(vector<vector<int>>& mat){
        while (!bfsQueue.empty()){
            Cell currentCell = bfsQueue.front();
            // cout<<"  current "<<currentCell.x<<" "<<currentCell.y<<" " <<tmp[currentCell.x][currentCell.y]<< endl;
            bfsQueue.pop();
            // process neighbor
            int row[4] = { -1, 1, 0, 0};
            int col[4] = {0, 0, -1, 1};
            Cell neighbor;
            for (int i =0; i<4; i++){
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];
                if (neighbor.x <0 || neighbor.x>= mat.size())
                    continue;
                if (neighbor.y <0 || neighbor.y>= mat[0].size())
                    continue;
                // check if cell is visited : result[neighbor.x][neighbor.y]!=INT_MAX
                if (result[neighbor.x][neighbor.y] > result[currentCell.x][currentCell.y]+1){
                    result[neighbor.x][neighbor.y] = result[currentCell.x][currentCell.y]+1;
                    // cout<<"   neighbor: "<<neighbor.x<<" "<<neighbor.y<<" nei "<<tmp[neighbor.x][neighbor.y] <<endl;
                    bfsQueue.push(neighbor);
                }
            }
        }
        return 0;
    }
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        result.resize(mat.size(), vector<int> (mat[0].size(), INT_MAX));             // final result;
        // Step 1:
        for (int row = 0; row < mat.size(); row++){
            for (int col = 0; col <mat[0].size(); col++){
                int distance = 0;
                if (mat[row][col]==0){
                    result[row][col] = 0;
                    Cell cell = {row, col};
                    bfsQueue.push(cell);                // push all cell=0 to bfsQueue
                }
            }
        }
        // Step 2:
        bfs(mat);           // update the distance from ALL cell=0 to ALL cell=1
        return result;
    }
};