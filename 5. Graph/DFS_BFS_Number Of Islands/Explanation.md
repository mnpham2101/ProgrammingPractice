# Description:

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

* **Example 1:**
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

* **Example 2:**
```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

* **Constraints:**
```
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
```

# Solution 1: Implement DFS with Stack
* Use stack (LIFO) to process islands.
  * immediate neighbors of each `grid[x][y]` are push to stack.
  * top of stacks are process first, LIFO; therefore, processes are traversing down the tree.
* Each island is defined as '1' => DFS runs until the stack is empty => increment count
* Mark the `grid[x][y]` as visited or not.