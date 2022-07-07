# Description

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

* **Example 1:**
![image info](./1.png)
```
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
```

* **Example 2:**
![image info](./2.png)
```
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
```

* **Constraints:**
```
m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.
```

# Solution:
* Run BFS1 to mark all islands on Grid1 as `2`.
* Run BFS2 to check if the island cells at a coordinates on Grid2 has the value `2` on Grid1
    * use `bool subIsland` to mark if the island on Grid2 is a subisland or not.
    * increment countingSubIsland when found a whole subIsland

    For example:
    ```
    Grid1:
    [[1,0,1,0,1],
     [1,1,1,1,1],
     [0,0,0,0,0],
     [1,1,1,1,1],
     [1,0,1,0,1]]

    Grid2:
    [[0,0,0,0,0],
     [1,1,1,1,1],
     [0,1,0,1,0],
     [0,1,0,1,0],
     [1,0,0,0,1]]

    The 2 sub-islands are at left corner `[4][0]` and right corner `[4][4]
    ```

    * each BFS2 run, while the stack is not empty, processes a single island.