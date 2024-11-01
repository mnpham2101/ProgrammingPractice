class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int row = grid.size()-1; row>=0; row--){
            for(int col = grid[0].size()-1; col>=0; col--){
                cout<<"row "<< row <<" col "<<col<<endl;
                if (row == grid.size()-1 && col == grid[0].size()-1){}
                else if (row == grid.size()-1)
                    grid[row][col] = grid[row][col+1] + grid[row][col];
                else if (col == grid[0].size()-1)
                    grid[row][col] = grid[row+1][col] + grid[row][col];
                else{
                    grid[row][col] = min(grid[row+1][col]+ grid[row][col],
                                        grid[row][col+1]+ grid[row][col]);
                }
            }
        }
        return grid[0][0];
    }
};