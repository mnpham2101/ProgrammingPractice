#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
    private:
    struct Cell {
        int x;
        int y;
    };
    queue<Cell> bfsQueue;
    vector<vector<int>> visited;
    int BFS(vector<vector<char>>& maze){

        while(!bfsQueue.empty()){
            Cell currentCell = bfsQueue.front();

            bfsQueue.pop();
            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};

            // process neighbors
            for (int i = 0; i< 4; i++){
                bool exit = false;
                Cell neighbor;
                neighbor.x = currentCell.x + row[i];
                neighbor.y = currentCell.y + col[i];

                if (neighbor.x <0 || neighbor.x >= maze.size())
                    continue;
                if (neighbor.y <0 || neighbor.y >= maze[0].size())
                    continue;
                else {

                    if (neighbor.x == 0 || neighbor.x == maze.size()-1 ||                       // if at destination
                        neighbor.y == 0 || neighbor.y == maze[0].size()-1){
                        exit = true;
                    }
                    if ( exit                                                                   // if an exit
                        && maze[neighbor.x][neighbor.y] == '.'                                  // if a path
                        && visited[neighbor.x][neighbor.y] == 0){                               // if not visited
                        visited[neighbor.x][neighbor.y] = visited[currentCell.x][currentCell.y];

                        return visited[neighbor.x][neighbor.y];
                    }
                    if (maze[neighbor.x][neighbor.y] == '.' &&          // if a path
                        visited[neighbor.x][neighbor.y] == 0            // if not visited
                       ){
                        visited[neighbor.x][neighbor.y] = visited[currentCell.x][currentCell.y]+1;
                        bfsQueue.push(neighbor);

                    }

                }
            }
        }
        // special case 1: entrance is at the border=> not count as exit => this case is eliminated by algo
        // special case 2: no exit
        return -1;                      // special case: when there is no path
    }
    public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        visited.resize(maze.size(), vector<int> (maze[0].size(),0));
        Cell cell = {entrance[0], entrance[1]};
        bfsQueue.push(cell);
        visited[cell.x][cell.y] = 1;           //set starting distance = 1
        return BFS(maze);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> maze = {{'+','.','+','+','+','+','+'},
                                 {'+','.','+','.','.','.','+'},
                                 {'+','.','+','.','+','.','+'},
                                 {'+','.','.','.','+','.','+'},
                                 {'+','+','+','+','+','.','+'}
                                 } ;
    vector<int> entrance = {0,1};
    cout<<sol.nearestExit(maze, entrance)<<endl;
}