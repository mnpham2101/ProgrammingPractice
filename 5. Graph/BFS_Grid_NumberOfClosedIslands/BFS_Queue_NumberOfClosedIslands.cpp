#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    struct Node {
        int x;
        int y;
    };

    std::queue<Node> bfsQueue;

    int countCloseIsland = 0;

    void BFS1(vector<vector<int>> & grid, Node s){

        bfsQueue.push(s);
        while (bfsQueue.size() > 0) {
            Node u = bfsQueue.front();
            bfsQueue.pop();                                                                // FIFO
            if (grid[u.x][u.y] == 1)
                continue;
            else {
                cout<<"border node: "<<u.x<<" "<<u.y<<endl;
                grid[u.x][u.y] = 1;
                // get the neighbors of node s:
                int row[4] = { 1, -1, 0, 0};                                               // index matrices to process neighbor nodes
                int col[4] = { 0, 0, -1, 1};
                vector<Node> neighborList;                                                 // 4 directional neigbors only
                for (int i = 0; i<4; i++){
                    Node node;
                    node.x = u.x + row[i];
                    node.y = u.y + col[i];
                    if (node.x<0 || node.x>= grid.size() || node.y<0 || node.y>=grid[0].size() || grid[node.x][node.y] == 1)
                        continue;
                    else
                        neighborList.push_back(node);
                }
                // process the neighbor of node s to put into bfsQueue:
                for (auto neighborNode : neighborList) {                                     // loop through neighbors
                    if (grid[neighborNode.x][neighborNode.y]  == 0) {                        // and the neighbor is valid (an island)
                        bfsQueue.push(neighborNode);                                         // push neighbor to stack
                    }
                }
            }
        }
    }
    void BFS2(vector<vector<int>> & grid, Node s){

        bfsQueue.push(s);
        while (bfsQueue.size() > 0) {
            Node u = bfsQueue.front();
            bfsQueue.pop();
            cout<<"node: "<<u.x<<" "<<u.y<<endl;
            if (grid[u.x][u.y] == 1)
                continue;
            else {
                grid[u.x][u.y] = 1;
                // get the neighbors of node s:
                int row[4] = { 1, -1, 0, 0};                                               // index matrices to process neighbor nodes
                int col[4] = { 0, 0, -1, 1};
                vector<Node> neighborList;                                                 // 4 directional neigbors only
                for (int i = 0; i<4; i++){
                    Node node;
                    node.x = u.x + row[i];
                    node.y = u.y + col[i];
                    if (node.x<0 || node.x>= grid.size() || node.y<0 || node.y>=grid[0].size() || grid[node.x][node.y] == 1)
                        continue;
                    else
                        neighborList.push_back(node);
                }
                // process the neighbor of node s to put into stackDfs:
                for (auto neighborNode : neighborList) {                                     // loop through neighbors
                    if (grid[neighborNode.x][neighborNode.y]  == 0) {                        // and the neighbor is valid (an island)
                        bfsQueue.push(neighborNode);                                         // push neighbor to stack
                    }
                }

            }
        }
        countCloseIsland++;
        cout<<"# of closed island: "<<countCloseIsland<<endl;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        Node node;
        int n = grid.size();
        // run BFS1 on grid nodes that are around the border of the grid to change any islands to sea.
        for (int row = 0; row < grid.size(); row++){
            if (grid[row][0] == 0) {                           // check the grid nodes on the left
               cout<<"left side"<<endl;
               node.x = row;
               node.y = 0;
               cout<<"borderIsland starts @ "<<node.x<<" "<<node.y<<endl;
               BFS1(grid,node);
            }
            if (grid[row][grid[row].size()-1] == 0) {          // check the grid nodes on the right border
               cout<<"right side"<<endl;
               node.x = row;
               node.y = grid[row].size()-1;
               cout<<"borderIsland starts @ "<<node.x<<" "<<node.y<<endl;
               BFS1(grid,node);
            }
            if (row == 0 || row == n-1){                        // check the grid nodes on the top and bottom side
                cout<<"top side or bottom side of grid"<<endl;
                for (int col = 0; col < grid[row].size(); col++){
                    if (grid[row][col] == 0){
                       node.x = row;
                       node.y = col;
                       cout<<"borderIsland starts @ "<<node.x<<" "<<node.y<<endl;
                       BFS1(grid,node);
                    }
                }
            }
        }
        // log: check grid after changing border grid node to "sea"
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"bfsQueue.size() "<<bfsQueue.size()<<endl;
        // count enclaves
        for (int row = 0; row< n; row++){
            for (int col = 0; col < grid[0].size(); col++){
                if (grid[row][col] == 0){
                    cout<<"star island @ xy: "<<row<<" "<<col<<endl;
                    node.x = row;
                    node.y = col;
                    BFS2(grid, node);
                }
            }
        }
        return countCloseIsland;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1,1,0,1,0,0,1,0},
                                {1,1,0,1,1,0,1,1,1,0},
                                {1,0,1,1,1,0,0,1,1,0},
                                {0,1,1,0,0,0,0,1,0,1},
                                {0,0,0,0,0,0,1,1,1,0},
                                {0,1,0,1,0,1,0,1,1,1},
                                {1,0,1,0,1,1,0,0,0,1},
                                {1,1,1,1,1,1,0,0,0,0},
                                {1,1,1,0,0,1,0,1,0,1},
                                {1,1,1,0,1,1,0,1,1,0}};
    Solution sol;
    sol.closedIsland(grid);
}