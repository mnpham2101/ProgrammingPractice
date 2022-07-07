#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Cell {
        int x;
        int y;
    };
    queue<Cell> bfsQueue;
    int maxDistance(vector<vector<int>>& grid) {
        int maxDistance = -1;
    
        for (int i=0; i< grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    Cell cell = {i,j};
                    bfsQueue.push(cell);
                }
            }
        }
        if (bfsQueue.empty())             // there is no land
            return -1;
        while (!bfsQueue.empty()){
            Cell cell = bfsQueue.front();
            // cout <<"Cell: "<<cell.x<<" "<<cell.y<<" value "<<grid[cell.x][cell.y]<<endl;
            bfsQueue.pop();
            // process adj cells 
            int row[4] = { -1, 1, 0, 0};
            int col[4] = { 0, 0, -1, 1};
            for (int i = 0; i < 4; i++){
                Cell neighbor;
                neighbor.x = cell.x + row[i];
                neighbor.y = cell.y + col[i]; 
                // cout<<neighbor.x<<" " <<neighbor.y<<endl;
                if(neighbor.x <0 || neighbor.x > grid.size()-1 ||
                    neighbor.y <0 || neighbor.y > grid[0].size()-1){
                    // cout<<"out of bound "<<neighbor.x<<" " <<neighbor.y<<endl;
                    continue;
                }
                    
                if(grid[neighbor.x][neighbor.y] != 0){
                    // cout<<"visited "<<neighbor.x<<" " <<neighbor.y<<endl;
                    continue;
                }
                    
                bfsQueue.push(neighbor);
                grid[neighbor.x][neighbor.y] = 1 + grid[cell.x][cell.y];
                maxDistance = grid[neighbor.x][neighbor.y]-1;
                // cout <<"neighbor: "<<neighbor.x<<" "<<neighbor.y<<" value "<<grid[neighbor.x][neighbor.y]<<endl;
            }  
        }    
        return maxDistance;
    }
};

int main () {
    Solution sol; 
    vector<vector<int>> grid = {{1,0,1}, {0,0,0}, {1,0,1}};
    sol.maxDistance(grid);
}