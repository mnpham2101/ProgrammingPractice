#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    struct Cell{
        int x;
        int y;
    };
    queue<Cell> bfsQueue;
    int bfs(vector<vector<int>>& grid, Cell cell){
        // cout<<"cell "<<cell.x<<" "<<cell.y<<endl;
        if (cell.x == grid.size()-1 && cell.y == grid[0].size()-1){
            // cout<<"destination reached"<<endl;
            return grid[cell.x][cell.y]; 
        }
        if (!bfsQueue.empty()){
            bfsQueue.pop();
            // add neighbor to queue
            // directional matrices to show neighbor cells in left,right, up, down, and diagonal paths
            int r[8]= {-1, 1, 0, 0, -1, -1, 1, 1}; 
            int c[8]= { 0, 0,-1, 1, -1,  1,-1, 1};
            for (int i = 0; i<8; i++){
                Cell neighbor;
                neighbor.x = cell.x + r[i];
                neighbor.y = cell.y + c[i];
                if (neighbor.x <0 || neighbor.x >= grid.size() ||
                    neighbor.y <0 || neighbor.y >= grid[0].size()){
                    // cout<<"boundary "<<neighbor.x<<" "<<neighbor.y<<endl;
                    continue;
                }
                if (grid[neighbor.x][neighbor.y] !=0){
                    // cout<<"no path "<<neighbor.x<<" "<<neighbor.y<<endl;
                    continue;
                }     
                // cout<<"neighbor: "<<neighbor.x<<" "<<neighbor.y<<endl;
                grid[neighbor.x][neighbor.y] = 1 + grid[cell.x][cell.y];
                bfsQueue.push(neighbor);
            }
            // process next node
            Cell nextCell = bfsQueue.front();
            return bfs(grid, nextCell);                    
        }
        else{ 
            return -1;
        }       
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int count = 1;                      // count starts from 1.
        Cell cell = {0,0};
        if (grid[0][0]==1)
            return -1;
        bfsQueue.push(cell);
        grid[0][0]=1; 
        return bfs(grid, cell);     
    }
};

int main() {
    Solution sol; 
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    sol.shortestPathBinaryMatrix(grid);
}


 