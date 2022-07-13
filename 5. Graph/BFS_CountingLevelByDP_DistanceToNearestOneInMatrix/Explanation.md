# Description

Given an m x n binary matrix mat, return the distance of the nearest 0 for *each cell*.

The distance between two adjacent cells is 1.

# Solution 1: BFS - calculate distance from 0 to 1 -TLE
* Clarify the problem:
    * result is 2D vector that fills the distance from a cell to `the nearest cell = 0`.
        * `result[i][j]=5` distance from cell [i][j] to nearest cell= 0 is 5.
        * `result` has the same size and dimension as input matrix.
    * distance from `cell = 0` to `the nearest cell = 0` is 0
    * distance from `cell = 1` to `an adjacent cell = 0` is 1
    * The problem is similar to find the distance from `every cell = 1` to `nearest cell=0`.
## Algorithm:
* for each BFS() run, update the distance from `cell=1` to `nearest cell=0`
0. create:
    * `bfsQueue`
        * **potential bug**: bfsQueue is NOT EMPTY when `inputArray[neighbor.x][neighbor.y]==0` and while loop is "break", and returns distance. Next BFS runs will process remain items in the bfsQueue.
        * **FIX**: initialize new BFS for every run.
    * `tmp[][]` to mark visited cell and store value.
        * **potential bug**: The cells visited by other cells in earlier BFS runs may not yet be VISITED by the cell in current BFS() run. ![image info](./2.png)
        * **FIX**: initialize `tmp[][]` for every BFS() run
    * mark "starting distance" = `tmp[startingCell.x][startingcell.y]=2`
1. add `cell=1` to queue.
2. pop `currentCell` from queue.
3. process neighbors:
    * if cell is out-of-bound, skipped.
    * if cell=0, return distance = `tmp[neighbor.x][neighbor.y]+tmp[currentCell.x][currentCell.y]-2`     // BUG: when returns, the bfsQueue is NOT EMPTY. Thus we need to initialize bfsQueue when starting a new BFS.
    * otherwise:
        * mark *distance*: `tmp[neighbor.x][neighbor.y] = tmp[currentCell][currentCell]+1`
        * mark *visited* : if `originalArray[neighbor.x][neighbor.y] !=0` don't add to queue.


# Solution 2: Improve BFS.
* in Sol1: for each BFS() run, update the distance from `cell=1` to `nearest cell=0`.
    * maintain a new `bfsQueue`, `result[][]` for each BFS() run.
* to optimized Sol1:
    * use global `bfsQueue`, `tmp[][]`.
        * result[][] is to store distance and mark "visited cells"
        * result[][]= INT_MAX , visited cells will have result[cell.x][cell.y] != INT_MAX or  `result[neighbor.x][neighbor.y] < result[currentCell.x][currentCell.y] + 1`
        * `result[x][y] = 0 if inputArray[x][y] = 0`
        * `result[neighbor.x][neighbor.y] = result[currentCell.x][currentCell.y] + 1`
    * add all cell=0 to bfsQueue.
    * find distance from all cell=0 to all cell=1 in one BFS() run.
## Complexity:
* Time complexity: O (row x col). Since, the new cells are added to the queue only if their current distance is greater than the calculated distance, cells are not likely to be added multiple times.
* Space complexity: O (row x col) to maintain `bfsQueue`

# Solution 3: DP  ????????????

## Complexity:
* Time complexity: O (row x col)
* Space complexity: 1
