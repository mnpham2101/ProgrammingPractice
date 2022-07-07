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

    std::queue<Node> bfsQueue;                                              // stack keeps only nodes belong to islands

    int countIslands = 0;

    void BFS(vector<vector<char>> & grid, Node s){

        bfsQueue.push(s);

        while (bfsQueue.size() > 0) {                                       // while still have neighbor nodes as islands
            Node u = bfsQueue.front();                                      // LIFO
            // cout<<"grid: "<<u.x<<" "<<u.y<<endl;
            bfsQueue.pop();
            if (grid[u.x][u.y] =='0') continue;
            grid[u.x][u.y] = '0';                                           // mark the grid node as visited by setting it as "sea"
            // get the neighbors of node s:
            int row[4] = { 1, -1, 0, 0};                                    // index matrices to process neighbor nodes
            int col[4] = { 0, 0, -1, 1};
            vector<Node> neighborList(4);                                   // 4 directional neigbors only
            for (int i = 0; i<4; i++){
                Node node;
                node.x = u.x + row[i];
                node.y = u.y + col[i];
                if (node.x<0 || node.x>= grid.size() ||
                    node.y<0 || node.y>=grid[0].size() ||
                    grid[node.x][node.y] == '0')
                    continue;                                               // if the grid node is not valid, don't add to neighbor list
                else
                    neighborList[i]=node;
            }
            // process the neighbor of node s to put into stackDfs:
            for (auto neighborNode : neighborList) {                        // loop through neighbors
                if (grid[neighborNode.x][neighborNode.y]  == '1') {         // and the neighbor is valid (an island)
                    bfsQueue.push(neighborNode);                            // push neighbor node to stack
                }
            }
        }
        countIslands++;
        // cout<<"islands "<<countIslands<<endl;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        Node node;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j< grid[0].size(); j++){
                if (grid[i][j] == '1')
                {
                    node.x = i;
                    node.y = j;
                    BFS(grid,node);
                }
            }
        }
        return countIslands;
    }
};

int main(){
    vector<vector<char>> grid = {
                                    {'1','1','1'},
                                    {'0','1','0'},
                                    {'1','0','0'},
                                    {'1','0','1'}
                                };
    Solution sol;
    sol.numIslands(grid);
}