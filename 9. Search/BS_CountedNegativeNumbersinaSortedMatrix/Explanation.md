# Description: 
Given a `m x n` matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

## Example 1:
```
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```
## Example 2:
```
Input: grid = [[3,2],[1,0]]
Output: 0
``` 

## Constraints:
```
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
```

# Solution: Brute Force.
* Loop through row, and col to find negative using double for loop.
```
int countNegatives(vector<vector<int>>& grid) {
    int count=0;
    for (int row = 0; row<grid.size(); row++){
        for (int col = 0; col <grid[row].size(); col++){
            if(grid[row][col] <0) count++;
        }
    }
    return count;
}
```
* Time complexity: O (m*n)

# Solution: Binary search on row
* Improve time complexity when searching for negative at each row by using binary search
```
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
```
* Time complexity: O (m*log(n))

# Solution: Full Binary Search
* recognise that if the item at the right most column of upper row is 