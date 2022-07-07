#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
    struct Cell{
        int x;
        int y;
    };
    queue<Cell> bfsQueue1;          // queue for BFS1
    queue<Cell> bfsQueue2;          // queue for BFS2
public:    
    void BFS1(vector<vector<int>>& grid, Cell cell){
        
        bfsQueue1.push(cell);
        while (! bfsQueue1.empty()){
            Cell currentCell = bfsQueue1.front();
            // cout<<"cell "<<cell.x<<" "<<cell.y<<endl; 
            bfsQueue1.pop();
            bfsQueue2.push(currentCell);                // push every cell in 1st island to bfsQueue2
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
        // cout<<"bfsQueue size: "<<bfsQueue1.size()<<endl;
        // // log
        // for (int i = 0; i < grid.size(); i++){
        //     for (int j = 0; j < grid[0].size(); j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // finish marking the first island as 2 when bfsQueue1 is empty. 
    }
    int BFS2(vector<vector<int>> &grid){         // pass by ref is needed to reduce memory usage
                                                 // grid is changed by multiple BFS2
        int distance=0;
        while (!bfsQueue2.empty()){
            Cell currentCell = bfsQueue2.front();
            // cout<<"current cell "<<currentCell.x<<" "<<currentCell.y<<" grid: " <<grid[currentCell.x][currentCell.y]<<endl; 
            bfsQueue2.pop(); 
            // get neighbor
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};
            Cell neighbor;
            // add neigbor to queue
            for (int i =0; i<4; i++){
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];
                // cout<<"neighbor "<<neighbor.x<<" "<<neighbor.y<<endl;
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
                    // cout<<"on path "<<neighbor.x<<" "<<neighbor.y<<endl;    
                    bfsQueue2.push(neighbor);
                    grid[neighbor.x][neighbor.y] = grid[currentCell.x][currentCell.y] + 1; 
                }
            }    
        }
        return distance;            // return 0 if bfsQueue is empty and not path is found
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
        
        int distance = BFS2(grid);          // run BFS2 with all the cells from 1st islands that were pushed into bfsQueue2
        return distance;
    }
};

int main(){
    vector<vector<int>>grid1 = {{1,1,1,1,1},{1,3,4,0,1},{1,4,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    vector<vector<int>>grid2 = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    Solution sol;
    sol.shortestBridge(grid2);
}
