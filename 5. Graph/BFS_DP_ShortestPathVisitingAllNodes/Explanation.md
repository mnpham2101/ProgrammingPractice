# Description:

You have an undirected, connected graph of `n` nodes labeled from `0` to `n - 1`. You are given an array graph where `graph[i]` is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

## Example 1:
![image info](./1.png)
```
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
```

## Example 2:
```
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
``` 

## Constraints:
```
n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
```

# Solution 1: BFS by level
## Problem Analysis:
* The path, starting from different nodes, will have different length. 
    * Thus multiple BFS/DFS run for different nodes result in a shortest via the starting node only. The final answer is the shortest of all. 
* There is no disconnected node, as implicitly stated in the problem description.
* The path can revisit a node, reuse an edge many times. Is there a way to prevent infinitive loop? 
* Special case: `graph.size()==1` then `ans = 0` why??????
## ALgorithm:

