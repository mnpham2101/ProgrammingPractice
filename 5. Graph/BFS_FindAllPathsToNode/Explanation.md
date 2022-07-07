# Problem Discription
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex start to vertex end.
Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.
Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
# Solution 1
## Data Structure
* data structure to store adjacent nodes: `unordered_map<int, vector<int>> adjList`
* data structure to store queue to process traversing: `queue<int> pathQueue`
* data structure to to keep track of visited node: `unordered_set<int> visited`
* data structure to to keep track of resulting path: `vector<int> finalPath`
## Algorithm
Follow BSF Steps, use recursive BFS
1. Step 1: Make adjacent List of all node.
2. Step 2.1: Make a queue to process traversing.
3. Step 2.2: Make data structure to keep track of resulting path if needed.
4. Step 3: Decide a loop condition for traversing process: Loop continuously if queue is NOT empty.  ==> !pathQueue.empty()
   ---- Traversing loop ---
5. Step 3.1: Add the starting node to pathQueue.
6. Step 3.2: Pop the top node from pathQueue. Make it currentNode. Push currentNode to finalPath
7. Step 3.3: Add adjacent nodes of the node that was pop out to the back of the pathQueue. 
   ---- End Traversing loop ---
8. Step 4: Decide any extra Inner loops to satisfy problem requirements
## Result: 
* total reiteration = 18;
* step 3.3: when pushing the neighbor vertex of current vertex to pathQueue (the stack the stores the path through vertex), no check oif the neighbor vertex has been visited is done ==> extra iteration steps
* if a vertex has no neighbor, finding item in adjList should be skipped. 

# Solution 2
Improvement of Solution 1.
## Data Structure
* data structure to store adjacent nodes: `unordered_map<int, vector<int>> adjList`
* data structure to store queue to process traversing: `queue<int> pathQueue`
* data structure to to keep track of visited node: `unordered_set<int> visited`
* data structure to to keep track of resulting path: `vector<int> finalPath`
## Algorithm
1. Step 1: Make adjacent List of all node.
2. Step 2.1: Make a queue to process traversing.
3. Step 2.2: Make data structure to keep track of resulting path if needed.
4. Step 3: Decide a loop condition for traversing process: Loop continuously if queue is NOT empty.  ==> !pathQueue.empty()
   ---- Traversing loop ---
5. Step 3.1: Add the starting node to pathQueue.
6. Step 3.2: Pop the top node from pathQueue. Make it currentNode. Push currentNode to finalPath
7. Step 3.3: Add adjacent nodes of the node that was pop out to the back of the queue. 
   ---- End Traversing loop ---
8. Step 4: Decide any extra Inner loops to satisfy problem requirements
   * If a vertex has no neighbor, pop it from the pathQueue, don't need to find it in visistedQueue
```
else if (!adjList.count(currentVertex)) {
    cout<<"current vertex "<<currentVertex<<" has no neighbor, skip searching adj list"<<endl;
    pathQueue.pop();
    return bfs(adjList, start, end);
}
```

9. Step 4:
   * add extra logic to step 3.3: when adding adj vertex of current vertex to pathQueue, check if the adjacent vertex has been visited. 
    
```
// step 3.3: add neighboring vertices to traversing queue
for (auto& vertex : adjList.at(currentVertex)){
    if (visited.count(vertex)) {
        cout<<vertex<<"(visited, not add to pathQueue), ";
        continue;
    }
    nextVertex = vertex;
    cout<<nextVertex<<" ";
    pathQueue.push(nextVertex);
    // visited.emplace(nextVertex);    //mark visited
}
```

# Solution 3
Improvement of Solution 2.
## Data Structure
* data structure to store adjacent nodes: `unordered_map<int, vector<int>> adjList`
* data structure to store queue to process traversing: `queue<int> pathQueue`
* ~~data structure to to keep track of visited node: `unordered_set<int> visited`~~
* data structure to to keep track of resulting path: `vector<int> finalPath`
## Algorithm
* Dont ust recursive BFS. Use while loop instead. Traverse until pathQueue is empty. 
* Step 3.2 Use for range-based loop to implement "popping currentVertext off the pathQueue" as each time counter increments, the nextVertex is processed.








