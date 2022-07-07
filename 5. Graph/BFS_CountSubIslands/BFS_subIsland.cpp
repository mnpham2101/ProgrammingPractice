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
    int countSubIsland = 0;

    void BFS1(vector<vector<int>> & grid, Node s){
        bfsQueue.push(s);
        while (bfsQueue.size() > 0) {
            Node u = bfsQueue.front();
            bfsQueue.pop();                                                                // FIFO
            if (grid[u.x][u.y] == 2)
                continue;
            else {
                // cout<<"grid1 node: "<<u.x<<" "<<u.y<<endl;
                grid[u.x][u.y] = 2;
                // get the neighbors of node s:
                int row[4] = { 1, -1, 0, 0};                                               // index matrices to process neighbor nodes
                int col[4] = { 0, 0, -1, 1};
                vector<Node> neighborList;                                                 // 4 directional neigbors only
                for (int i = 0; i<4; i++){
                    Node node;
                    node.x = u.x + row[i];
                    node.y = u.y + col[i];
                    if (node.x<0 || node.x>= grid.size() || node.y<0 || node.y>=grid[0].size() || grid[node.x][node.y] == 0 || grid[node.x][node.y] == 2)
                        continue;
                    else
                        neighborList.push_back(node);
                }
                // process the neighbor of node s to put into stackDfs:
                for (auto neighborNode : neighborList) {                                     // loop through neighbors
                    if (grid[neighborNode.x][neighborNode.y]  == 1) {                        // and the neighbor is valid (an island)
                        bfsQueue.push(neighborNode);                                         // push neighbor to stack
                    }
                }
            }
        }
    }
    void BFS2(vector<vector<int>> & grid1, vector<vector<int>> & grid2, Node s){
        bfsQueue.push(s);
        bool subIsland = true;
        while (bfsQueue.size() > 0) {
            Node u = bfsQueue.front();
            bfsQueue.pop();

            if (grid2[u.x][u.y] == 0)
                continue;


            if (grid1[u.x][u.y] !=2){
                cout<<"node: "<<u.x<<" "<<u.y<<endl;
                subIsland = false;
                // countSubIsland++;                  // BUG if count increments here because it count individual cells of sub islands
                // break;                             // BUG if use break: because grids belongs to non-subisland are not mark visited and is used to in later BFS2
            }

            grid2[u.x][u.y] = 0;
            // get the neighbors of node s:
            int row[4] = { 1, -1, 0, 0};                                               // index matrices to process neighbor nodes
            int col[4] = { 0, 0, -1, 1};
            vector<Node> neighborList;                                                 // 4 directional neigbors only
            for (int i = 0; i<4; i++){
                Node node;
                node.x = u.x + row[i];
                node.y = u.y + col[i];
                if (node.x<0 || node.x>= grid2.size() || node.y<0 || node.y>=grid2[0].size() ||
                    grid2[node.x][node.y] == 0
                   )
                    continue;
                else
                    neighborList.push_back(node);
            }
            // process the neighbor of node s to put into stackDfs:
            for (auto neighborNode : neighborList) {                                     // loop through neighbors
                if (grid2[neighborNode.x][neighborNode.y] == 1) {                        // and the neighbor is valid (an island)
                    bfsQueue.push(neighborNode);                                         // push neighbor to stack
                }
            }

        }
        if (subIsland){
            countSubIsland++;                                       // increment count when a whole subIsland is found
            // cout<<"subislands: "<<countSubIsland<<endl;
        }

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)  {
        Node node;
        // run BFS on grid1 to mark all islands as 2
        for (int i =0; i< grid1.size(); i++){
            for (int j =0; j< grid1[i].size(); j++){
                if (grid1[i][j] == 1){
                    node.x = i;
                    node.y = j;
                    BFS1(grid1, node);
                }
            }
        }
        // Log print grid1 with marked big islands
        // for (int i =0; i< grid1.size(); i++){
        //     for (int j =0; j< grid1[i].size(); j++){
        //         cout<<grid1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // run BFS on grid2 check if it is a sub-island
        for (int i =0; i< grid1.size(); i++){
            for (int j =0; j< grid2[i].size(); j++){
                if (grid2[i][j] == 1){
                    node.x = i;
                    node.y = j;
                    // cout<<"subisland starts @ "<<node.x <<" "<<node.y<<endl;
                    BFS2(grid1, grid2, node);
                }
            }

        }
        return countSubIsland;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout<<sol.countSubIslands(grid1,grid2)<<endl;
}