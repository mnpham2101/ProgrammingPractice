class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int i=0;
        int j=cols-1;
        int count=0;
        while((i>=0&&i<rows)&&(j>=0&&j<cols))
        {
            if(grid[i][j]<0)
            {
                count+=rows-i;
                j--;
            }
            else
                if(grid[i][j]>=0)
                    i++;
            
        }
        return count;
    }
};