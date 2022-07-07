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
    
    void BFS1(vector<vector<int>>& grid, Cell cell){
        queue<Cell> bfsQueue1;
        bfsQueue1.push(cell);
        while (! bfsQueue1.empty()){
            Cell currentCell = bfsQueue1.front();
            // cout<<"cell "<<cell.x<<" "<<cell.y<<endl; 
            bfsQueue1.pop();
            // get neighbor
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};
            Cell neighbor;
            // add neigbor to queue
            for (int i =0; i<4; i++){
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];
                if (neighbor.x <0 || neighbor.x>= grid.size() ||
                    neighbor.y <0 || neighbor.y>= grid[0].size()){
                    // cout<<"out of bound"<< neighbor.x<<" "<< neighbor.y<<endl;
                    continue;
                }
                    
                if (grid[neighbor.x][neighbor.y] != 1){
                    // cout<<" no island "<<neighbor.x<<" "<<neighbor.y<<endl;
                    continue;
                }
                // cout<<"island "<<neighbor.x<<" "<<neighbor.y<<endl;    
                bfsQueue1.push(neighbor);
                grid[neighbor.x][neighbor.y] = 2; 
            }
         }
        //log
        cout<<"bfsQueue size: "<<bfsQueue1.size()<<endl;
        // log
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        // finish marking the first island as 2 when bfsQueue1 is empty. 
    }
    int BFS2(vector<vector<int>> grid, Cell cell){         // pass by value cause copy of grid => Memory Limit Exceeded for large test case
        queue<Cell>bfsQueue2;
        bfsQueue2.push(cell);
        int distance=INT_MAX;
        while (!bfsQueue2.empty()){
            Cell currentCell = bfsQueue2.front();
            cout<<"current cell "<<currentCell.x<<" "<<currentCell.y<<" grid: " <<grid[currentCell.x][currentCell.y]<<endl; 
            bfsQueue2.pop(); 
            // get neighbor
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};
            Cell neighbor;
            // add neigbor to queue
            for (int i =0; i<4; i++){
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];
                if (neighbor.x <0 || neighbor.x>= grid.size() ||
                    neighbor.y <0 || neighbor.y>= grid[0].size()){
                    // cout<<"out of bound"<< neighbor.x<<" "<< neighbor.y<<endl;
                    continue;
                }
                if (grid[neighbor.x][neighbor.y] == 1){
                    // cout<<" destination "<<neighbor.x<<" "<<neighbor.y<<endl;
                    distance = grid[currentCell.x][currentCell.y] - 2;
                    return distance;
                }    
                if (grid[neighbor.x][neighbor.y] != 0){
                    // cout<<" visited "<<neighbor.x<<" "<<neighbor.y<<endl;
                    continue;
                }
                else if (grid[neighbor.x][neighbor.y] == 0){
                    // cout<<"path "<<neighbor.x<<" "<<neighbor.y<<endl;    
                    bfsQueue2.push(neighbor);
                    grid[neighbor.x][neighbor.y] = grid[currentCell.x][currentCell.y] + 1; 
                }
            }    
        }
        return distance;            // return INT_MAX if bfsQueue is empty and not path is found
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        // mark first island as `2`
        bool foundIsland = false;
        for (int i = 0; i < grid.size(); i++){
            if (foundIsland == true)
                break;
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    // cout<<"run BFS on Island 1, starting cell "<<i<<" "<< j<<endl;
                    Cell cell = {i,j};
                    grid[i][j] = 2;         // mark the first cell as visited, island = 2
                    BFS1(grid, cell);
                    foundIsland = true;
                    break;                  // mark only 1 island as `2`; BFS1 runs only 1 time for 1 island
                }
            }
        }
        
        int distance = INT_MAX;
        int minBridge = INT_MAX;
        // find shortest path from a cell in island '2' to island '1' (opposite direction wont work)
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    Cell cell = {i,j};
                    distance = BFS2(grid, cell);                        // for every cell in island '2' run bfs
                    // cout<<"found distance "<<distance<<endl;
                    minBridge = min (minBridge, distance);    
                    // cout<<"min distance "<<minBridge<<endl;
                }
            }
        }
        return minBridge;
    }
};

int main(){
    vector<vector<int>>grid1 = {{1,1,1,1,1},{1,3,4,0,1},{1,4,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    vector<vector<int>>grid2 = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    Solution sol;
    sol.shortestBridge(grid2);
}
