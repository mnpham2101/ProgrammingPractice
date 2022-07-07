# Description:

A matrix with size NxN shows a map and the land price. A headquarter is place at coordinate `[0,0]` and factory at `[N-1][N-1]`.

A road is constructed to connect headquarter and factory. The road can only go up/down, left/right but not diagonal.

Find the minimum cost to construct the road.

Example: The following shows the best road ![image info](./1.png)

* **Input**
- 1st line: map size N (2<=N<=100)
- next lines: input N single-digit land price information from the second line to N lines as a string

# Solution 1: Bottom Up Memoization (5/10 TC passes)
* use recursive to construct a tree and calculate cost.
* use memoization to prone tree.

Example: The following shows the tree from sample case.

 ![image info](./2.png)

## Algorithm:
* recursive function takes in the coordinates of the road. `cost = recursive(coordinateX, coordinateY)`, starting from `[0][0]`
* base case: when [coordinateX], [coordinateY] = [N-1][N-1]
* recursive cases:
    - costIfGoRight = recursive(coordinateX+1, coordinateY);
    - costIfGoDown = recursive(coordinateX+1, coordinateY);
    - cost = min (costIfGoRight, costIfGoDown);
* memoization:
    - initialize `cache[coordinateX][coodinateY] = INT_MAX`
    - save cost to `cache[coordinateX][coodinateY]` at both base case and recursive cases when they return values
    - if `cache[coordinateX][coodinateY] = !INT_MAX` retrieve value from cache.
## Complexity:
- double for loop to fill up matrix of land cost: N^2
- building tree with recursive call: the will have  levels and N branches => worst case scenarios is O(log<sub>2</sub>N)

# Solution 2: Dijsktra algorithm

# Solution 3: Backtracking ???? Need review
* consider that we have `coordinateX`, `coordinateY` values 1, 2, ... n, backtracking explores all potential candidates
* it starts at the first candidate `[0,0]`, then explore the potential next candidates by making recursive call `recursive(coordinateX, coordinateY)`.
* unvisited candiates are marked in `matrix[coordinateX][coordinateY]`
* result of backtracking creates tree structure => complexity is N!:
 - for each level of the tree: we have N options.
 - for each options, we have N-1 options.
 - there fore, for each level we have N*(N-1)*(N-2)*(N-3)*...*2*1= N!
 - there are N levels.
 - total we have  N*N ????