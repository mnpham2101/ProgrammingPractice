#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Implement DFS with stack
class Solution {
private:
    struct Node {
        int x;
        int y;
    };

    std::stack<Node> dfsStack;                              // dfsStack carries unvisited grid node whose value is '1'
    vector<vector<bool>> visited;
    int countIslands = 0;

    void DFS(vector<vector<char>> grid, Node s){

        dfsStack.push(s);
        visited[s.x][s.y] = true;

        while (dfsStack.size() > 0) {
            Node u = dfsStack.top();                                                            // LIFO
            dfsStack.pop();
            visited[u.x][u.y] = true;
            // get the neighbors of node s:
            int row[4] = { 1, -1, 0, 0};                                                        // index matrices to process neighbor nodes
            int col[4] = { 0, 0, -1, 1};
            vector<Node> neighborList;                                                          // 4 directional neigbors only
            for (int i = 0; i<4; i++){
                Node node;
                node.x = u.x + row[i];
                node.y = u.y + col[i];
                if (node.x<0 || node.x>= grid.size() || node.y<0 || node.y>=grid[0].size())
                    continue;
                else
                    neighborList.push_back(node);
            }
            // process the neighbor of node s to put into stackDfs:
            for (auto neighborNode : neighborList) {                                            // loop through neighbors
                if (visited[neighborNode.x][neighborNode.y] == false &&                         // if the neighbor node is not yet visited
                    grid[neighborNode.x][neighborNode.y]  == '1') {                             // and the neighbor is valid (an island)
                    dfsStack.push(neighborNode);                                                // push neighbor to stack
                }
            }
        }
        countIslands++;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size(), vector<bool>(grid[0].size()));
        Node node;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j< grid[0].size(); j++){
                if (visited[i][j]== false
                    && grid[i][j] == '1')
                {
                    node.x = i;
                    node.y = j;
                    DFS(grid,node);
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