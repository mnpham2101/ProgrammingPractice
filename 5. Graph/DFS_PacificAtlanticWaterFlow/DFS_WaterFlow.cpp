# include <vector>
# include <iostream>
# include <stack>
using namespace std;

class Solution {
private:
    bool toPacific = true;
    bool toAtlantic = false;
    struct Cell {
        int x;
        int y;
    };
    stack<Cell> dfsStack;
    vector<vector<int>> visited;                                    // mark 1 if the cell can reach pacific, add 1 if the cell can reach the other
    vector<vector<int>> result;
    // mark 1 if the cell flow to Pacific
    // mark +2 if the cell flow to Atlantic
    // mark 3 if the cell flow to both oceans
    void dfs(vector<vector<int>> heights, Cell cell, bool where){
        while (!dfsStack.empty()){
            Cell currentCell = dfsStack.top();
            dfsStack.pop();
            // add valid neighbor cells to stack
            int row[4]={-1,1,0,0};
            int col[4]={0,0,-1,1};
            for (int i = 0; i<4; i++){
                Cell neighbor;
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];
                if (neighbor.x <0 || neighbor.x >= heights.size())                      // out-of-bound
                    continue;
                if (neighbor.y <0 || neighbor.y >= heights[0].size())                   // out-of-bound
                    continue;
                if (visited[neighbor.x][neighbor.y] == 1 && where == toPacific){        // bfs already visited cell on path to Pacific
                    continue;
                }
                if (visited[neighbor.x][neighbor.y] == 2 || visited[neighbor.x][neighbor.y] == 3
                    && where == toAtlantic){       // bfs already visited cell on path to Atlantic
                    continue;
                }
                if (heights[neighbor.x][neighbor.y] < heights[currentCell.x][currentCell.y]) {              // if highers, water cannot flow.
                    // cout<<"lower neighbor @ "<<neighbor.x<<" "<<neighbor.y<<endl;
                    continue;
                }
                // cout<<"higher neighbor @ "<<neighbor.x<<" "<<neighbor.y<<endl;
                dfsStack.push(neighbor);
                if (where == toPacific)
                    visited[neighbor.x][neighbor.y] += 1;
                if (where == toAtlantic)
                    visited[neighbor.x][neighbor.y] += 2;
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        visited.resize( heights.size(), vector<int>(heights[0].size(), 0));
        for (int row = 0; row < heights.size(); row++){
            Cell cell = {row, 0};
            dfsStack.push(cell);
            visited[cell.x][cell.y] = 1;
            // cout<<"     Start PacificPath: "<<cell.x<<" "<<cell.y<<endl;
            dfs(heights, cell, toPacific);         // run dfs to find every cell connect to pacific ocean from the west
        }
        for (int col = 0; col < heights[0].size(); col++){
            Cell cell = {0, col};
            dfsStack.push(cell);
            visited[cell.x][cell.y] = 1;
            // cout<<"     Start PacificPath: "<<cell.x<<" "<<cell.y<<endl;
            dfs(heights, cell, toPacific);         // run dfs to find every cell connect to pacific ocean from the north
        }
        for (int row = 0; row < heights.size(); row++){
            int col = heights[0].size()-1;
            Cell cell = {row, col};
            dfsStack.push(cell);
            if (visited[cell.x][cell.y] == 0 || visited[cell.x][cell.y] == 2)
                visited[cell.x][cell.y] = 2;
            else
                visited[cell.x][cell.y] = 3;
            // cout<<"     Start Atlantic: "<<cell.x<<" "<<cell.y<<endl;
            dfs(heights, cell, toAtlantic);         // run dfs to find every cell connect to atlantic ocean from the east
        }
        for (int col = 0; col < heights[0].size(); col++){
            int row = heights.size()-1;
            Cell cell = {row, col};
            dfsStack.push(cell);
            if (visited[cell.x][cell.y] == 0 || visited[cell.x][cell.y] == 2)
                visited[cell.x][cell.y] = 2;
            else
                visited[cell.x][cell.y] = 3;
            // cout<<"     Start Atlantic: "<<cell.x<<" "<<cell.y<<endl;
            dfs(heights, cell, toAtlantic);         // run dfs to find every cell connect to atlantic ocean from the south
        }
        for (int row = 0; row <heights.size(); row++){
            for (int col=0; col < heights[0].size(); col++){
                if (visited[row][col] == 3)
                    result.push_back({row, col});
            }
        }
        return result;
    }
};

