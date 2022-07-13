#include<vector>
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

    int bfs(vector<vector<int>>& mat, Cell cell){
        int distance = 0;
        // must initialize a new bfsQueue for each BFS()
        queue<Cell> bfsQueue;
        bfsQueue.push(cell);
        // tmp vector to store and calculate distance from each cell
        vector<vector<int>> tmp;
        tmp.resize(mat.size(), vector<int> (mat[0].size(),0));            // initial value is zero
        tmp[cell.x][cell.y]=2;                                            // mark visited
        // cout<<"start "<<cell.x<<" "<<cell.y<<" "<<tmp[cell.x][cell.y]<<endl;
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
                if (mat[neighbor.x][neighbor.y] == 0){
                    tmp[neighbor.x][neighbor.y] = tmp[currentCell.x][currentCell.y]+1;
                    distance = tmp[neighbor.x][neighbor.y] - 2;
                    // cout<<"   neighbor: "<<neighbor.x<<" "<<neighbor.y<<" nei "<<tmp[neighbor.x][neighbor.y]<<" dis "<<distance<<endl;
                    return distance;                            // Bug: when return bfsQueue is not empty.
                                                                //      next BFS() will process the remaining items in bfsQueue
                                                                // Fix: initialize bfsQueue for each BFS()
                }
                if (mat[neighbor.x][neighbor.y] != 0){
                    tmp[neighbor.x][neighbor.y] = tmp[currentCell.x][currentCell.y]+1;
                    // cout<<"   neighbor: "<<neighbor.x<<" "<<neighbor.y<<" nei "<<tmp[neighbor.x][neighbor.y] <<endl;
                    bfsQueue.push(neighbor);
                }
            }
        }
        return 0;
    }
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        result.resize(mat.size(), vector<int> (mat[0].size()));             // final result;
        for (int row = 0; row < mat.size(); row++){
            for (int col = 0; col <mat[0].size(); col++){
                int distance = 0;
                if (mat[row][col]==0){
                    result[row][col] = 0;
                    // cout<<"update result "<<row<<" "<<col<<" = "<<result[row][col]<<endl;
                }

                else{
                    Cell cell = {row, col};

                    distance = bfs(mat, cell);       // find the distance from each cell=0 to cell=1, the first cell=1 found is the nearest cell

                    result[row][col] = distance;
                    // cout<<"update result "<<row<<" "<<col<<" = "<<result[row][col]<<endl;
                }
            }
        }
        return result;
    }
};