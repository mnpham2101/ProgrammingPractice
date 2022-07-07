#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Node {
        int x;
        int y;
    };

    std::queue<Node> bfsQueue;

    int maxArea = 0;

    void BFS(vector<vector<int>> & grid, Node s){
        bfsQueue.push(s);
        int islandArea = 0;
        while (bfsQueue.size() > 0) {
            Node u = bfsQueue.front();
            bfsQueue.pop();                                                                     // FIFO
            if (grid[u.x][u.y]!=0){

                grid[u.x][u.y] = 0;
                // get the neighbors of node s:
                int row[4] = { 1, -1, 0, 0};                                                    // index matrices to process neighbor nodes
                int col[4] = { 0, 0, -1, 1};
                vector<Node> neighborList(4);                                                   // 4 directional neigbors only
                for (int i = 0; i<4; i++){
                    Node node;
                    node.x = u.x + row[i];
                    node.y = u.y + col[i];
                    if (node.x<0 || node.x>= grid.size() || node.y<0 || node.y>=grid[0].size() || grid[node.x][node.y] == 0)
                        continue;
                    else
                        neighborList[i]=node;
                }
                // process the neighbor of node s to put into stackDfs:
                for (auto neighborNode : neighborList) {                                            // loop through neighbors
                    if (grid[neighborNode.x][neighborNode.y]  == 1) {                             // and the neighbor is valid (an island)
                        bfsQueue.push(neighborNode);                                                // push neighbor to stack
                    }
                }
                islandArea++;
                cout<<"node "<<u.x<<" "<<u.y<<" islandArea "<<islandArea<<endl;
            }
        }
        maxArea = max(maxArea, islandArea);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        Node node;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j< grid[0].size(); j++){
                if (grid[i][j] == 1)
                {
                    node.x = i;
                    node.y = j;
                    BFS(grid,node);
                }
            }
        }
        return maxArea;
    }
};

int main(){
    vector<vector<int>> grid = {
                                    {1,1,1},
                                    {0,1,0},
                                    {1,0,0},
                                    {1,0,1}
                                };
    Solution sol;
    sol.maxAreaOfIsland(grid);
}

//other TC
/*
[[0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0],
 [1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0]]

*/