/* When approaching the problem of searching for a target value in a sorted 2D matrix 
where each row and column is sorted,
 my initial thoughts would be to leverage the sorted nature of the matrix for an efficient search. 
 Starting from the top-right corner allows us to make decisions based on comparisons with the target, 
 either moving downward or leftward iteratively until the target is found or all possibilities are exhausted
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = col - 1;
        while(rowIndex < row && colIndex >= 0){
            int ele = matrix[rowIndex][colIndex];
            if(ele == target) return 1;
            if(ele < target) rowIndex++;  // Move downward
            else colIndex--; // Shift left
        }
        return 0;
    }
};