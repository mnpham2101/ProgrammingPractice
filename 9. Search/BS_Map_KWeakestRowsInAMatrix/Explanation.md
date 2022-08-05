# Description: 
You are given an `m x n` binary matrix mat of `1`'s (representing soldiers) and `0`'s (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row `i` is weaker than a row `j` if one of the following is true:

* The number of soldiers in row i is less than the number of soldiers in row j.
* Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

# Solution: Multimap + linear seach
* use multimap where:
    * key = rowStrength
    * value = row index
* the multimap will automatically sort the items based on rowStrenth.
* use linear search to loop through each row and calculate the strength of each row.
## Complexity Analysis:
* Time complexity `O(m*(n+logm))`
    * For m row, calculating `rowStrength` would take O(m*n)
    * multi map perform sorting based on key (`rowStrength`), it would take `O(mlogm)` where `m` is the number of rows
    * total complexity is `O(m*n+mlogm)=O(m(n+logm)`
* Space complexity: O(m)

# Solution: Multimap + binary search
* the 1st solution was inefficient because it uses linear search to calculate `rowStrength`. 
* this solution uses binary search to calculate `rowStrength`
    * it is noted that all `1` appear on the left, and `0` on the right. Thus we can search for the first `0`. 
    * if nums[row][mid] == 0, there maybe more `0` on the right, search more the right high = mid -1
    * if nums[row][mid] == 1, search on the left: low = mid + 1
    * when left>right, break loop, calculate rowStrength = low+1