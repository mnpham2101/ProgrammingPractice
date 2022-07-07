# Explanation:

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example: ![image info](./1.png)

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

# Solution: Dijsktra
* Dijkstra algorithm helps:
  1. find the shortest distance from any vertices to ALL other vertices.
  2. find the the shortest distance for a pair of any 2 vertices.

This problem can use Dijkstra to find the shortest path from K to all other vertices. In addition, the time it takes to for all nodes to receives signal from node k is the longest time (among the shortest delay over the most opmized path). I will use "distance" instead of "time delay" so that it is more intuitive when dealing with graph

## Algorithm:
* **Step 1 Initialization process**
* **Step 1.a**: Create a table `ShortestDistanceTable` to keep track of the shortest distance from a vertex in question to every other vertex. Initialize the distance to infinitive. Initialize the distance from k to itself as zero. Size of the array should be n+1 (since we don't have node 0 to match with index 0)
* **Step 1.b**: Create a array of `unvisitedVertex`. Mark every vertex as unvisited. Size of the array should be n+1 (since we don't have node 0 to match with index 0).
* **Step 1.c**: Fill up a 2D array to keep track of neighbor relation, distance of direct path between the nodes. Note that this is directed path. Thus I made myself a convention: `row=sourceVertex`, `col=destinationVertex`. If `[2,1,1]` is provided then `neighborRelation[2][1]=1`
* **Step 1.d**: push `startingVertex=k` to `DijakstraQueue`
* **Step 2 Dijsktra process**: Processing the `DijkstraQueue`, starting from the `startingVertex` in question, find the *LONGEST distance* when the path from `startingVertex` to every vertex via a `CurrentVertex` is *optimized*.
* **Step 2a**: get `CurrentVertex = DijkstraQueue.front()`. Pop the front vertex from the queue.
* **Step 2b**: Update the shortest path from the `startingVertex` to every `unvisitedVertex` via `currentVertex` to other vertices in `ShortestDistanceTable`.
* **Step 2c**: add the next unmarked vertex that has *the shortest distance* from `startingVertex` to queue.
* **Step 2d**:  Go back to step 2a: get `currentVertex = DijkstraQueue.front()`, pop the queue, and update the shortest path from the `startingVertex` to all other vertices via the `currentVertex`. Continue until queue is empty. 
* **Step 3**: get the result, the longest distance among the shortest distances found on optimized paths.

Example: For network in sample problem, the following illustrate Dijskstra process ![image info](./2.png)