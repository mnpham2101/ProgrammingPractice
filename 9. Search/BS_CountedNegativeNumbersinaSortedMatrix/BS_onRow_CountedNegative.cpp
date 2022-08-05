class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result=0;
        
        for(int row =0 ; row < grid.size() ; row++)
        {
            int low =0 ; 
            int high = grid[row].size()-1;
            int negPerRow=0;                              // number of negative on a row

            if(grid[row][grid[row].size()-1]>=0)    // if the whole row is positive, skip
                continue;

            if(grid[row][0]<0){                     // if the whole row is negative, increment ans1 by the row size
                result+=grid[row].size();
                continue;   
            }

            while(low<=high)                       // run binary search on each row to find negative
            {
                int mid = low + (high- low)/2;
                if(grid[row][mid]>=0)              // if not negative, search on the left
                {
                    low = mid+1;
                }
                else if(grid[row][mid]<0)           // if negative, there maybe more negative on the right, search more on the right   
                {
                    high=mid-1;
                }
                negPerRow=low;                            // number of negative is the same as low index

            }

            result+=grid[row].size()-negPerRow;
        }
        return result;
    }
};