# Description:

Write an efficient algorithm that searches for a value target in an `m x n` integer matrix matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

## Example 1:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

## Example 2:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
``` 

## Constraints:
```
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
```

# Solution 1: Run binary search on every row
* linear loop over every row, and perform Binary Search to find target results in time complexity O(m*logn)
```
for (row = 0; row< matrix.size(); row++){
    result = binarySearch(matrix, target);
}
```

# Solution 2: Run Binary Search on Column and Row
* because of the condition "The first integer of each row is greater than the last integer of the previous row" the target is guaranteed to be in a row if: `target > matrix[row][0]` and `target<matrix[row+1][0]` 
* Thus we could use first Binary Search to find the row that would contain the target value. Return false rightaway if we can't.
* Second Binary Search is used to find the target in a row.
## Algorithm:
* run binary search to find the row that has the target
* run binary search to find the target in the row
```
int row=0;
if (!searchRow(matrix, target,row))
    return false;
else
    return searchTargetInRow(matrix,target,row);
```
## Complexity:
* O(logM + logN)

# Solution 3: Create linear array from 2D matrix

## Algorithm:

## Complexity:
* O(log(M*N)) = O(logM + logN)