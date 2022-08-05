class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for (int row = 0; row<grid.size(); row++){
            for (int col = 0; col <grid[row].size(); col++){                //O(M*N)
                if(grid[row][col] <0) count++;
            }
        }
        return count;
    }
};