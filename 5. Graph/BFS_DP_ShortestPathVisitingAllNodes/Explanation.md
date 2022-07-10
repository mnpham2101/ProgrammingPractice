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
    * Use math to count the path, instead of incrementing the count when the nodes are visited.
    * For each level, from top node to child nodes, the total path would be `count = 2*n-1`;
    * For example: In ![image info](./1.png). The top node `0` is connected to 3 node, the total path would be `count = 2*3 -1 = 65`.
    * If we rearrange the graph and let 1 as the top node, we have ![image info](./3.png), the path length is then: `count = 1 + 2*2-1 = = 4 = path length from 1 to zero + path length from zero to 2 and 3`.
    * We still mark the nodes as visited when each BFS run visit a node. 
## ALgorith:
* *Construct graph*:
    * Current Nodes: mark each current node visited.
    * Neighbor nodes: 
        * for each row of `graph` is a vector `adjList` containing adjacent nodes to the node defined by row index.
        * increment `count += 2 * adjList.size() -1`
* run BFS by level  
```
bfsQueue.push(node);
while (!bfsQueue.empty()){
    int n = bfsQueue.size();         // the size of bfsQueue is the number of nodes at the same level
    int count = 0;
    // count is increments once at each level
    count + = 2 * graph[bfsQueue.front()].size() - 1;           
    for (int i = 0; i<n; i++){
        int curr = bfsQueue.front();
        // more bfs logic
        
        // add children node to bfsQueue
    }
}
 

```