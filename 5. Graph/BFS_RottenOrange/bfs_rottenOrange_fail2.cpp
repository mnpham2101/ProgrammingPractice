#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

/* 
 ==> search for all paths but shortest from rotten orange to fresh orange, change fresh oranges to rotten.
 ==> each times, multiple oranges are rotten. 
 ==> The problem implements: find shortest path from fresh orang to rotten orange, and change itself to rottent. Each loop, only 1 orange changes to rotten. 
*/ 

class Solution {
public:
    queue<pair<int,int>> rottenOrangeList = {};
    
    queue<pair<int,int>> makeRottenOrangeList (vector<vector<int>> grid){
        for ( int i = 0 ; i < grid.size(); i++){
            for (int j =0; j < grid[0].size(); j++){
                if (grid[i][j] == 2) {
                rottenOrangeList.push({i,j});
                }
            }
        }
        cout<<"Total Fresh Oranges: "<<freshOrange<<endl;
        return rottenOrangeList;
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int row = grid.size();
        int column = grid[0].size();
        // step 1: search through the grid for rotten orange, put to queue.
        makeRottenOrangeList(grid);
        /* step 2: loop through the rottenOrangeList queue to get their coordinates
           make the adjacent fresh orange to rotten
           loop until their is no fresh orange 
        */
        while (!rottenOrangeList.empty()  ){   
            cout<<"-- loop --"<<endl;       
            pair<int, int> currentRotten =  rottenOrangeList.front();
            rottenOrangeList.pop(); 
            // get the coordinates of the rotten orange
            int i = currentRotten.first;        
            int j = currentRotten.second;
            cout<<"current rotten coordinates: "<<i<<" "<<j<<endl;
            // manually make the adjecent fresh orange to rotten, push to queue, 
            // note: time increment when any if case hits.
            if (j+1 < row && grid[i][j+1] == 1) { grid[i][j+1] = 2; rottenOrangeList.push({i,j+1});}
            if (j-1 >= 0 && grid[i][j-1] == 1) { grid[i][j-1] = 2; rottenOrangeList.push({i,j-1}); }
            if (i+1 < column && grid[i+1][j] == 1) { grid[i+1][j] = 2; rottenOrangeList.push({i+1,j}); }
            if (i-1 >= 0 && grid[i-1][j] == 1) { grid[i-1][j] = 2; rottenOrangeList.push({i-1,j}); }

            // this condition implementation will not work. 
            if ( (j+1 < row && grid[i][j+1] != 1) && 
                 (j-1 >= 0 && grid[i][j-1] != 1) && 
                 (i+1 < column && grid[i+1][j] != 1) && 
                 (i-1 >= 0 && grid[i-1][j] != 1 ) 
                )
            {
                time++;
                cout<<"Time: "<<time<<endl;
            }
        }
        return time;
    };
};
 
int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    sol.orangesRotting(grid);
    return 0;
}