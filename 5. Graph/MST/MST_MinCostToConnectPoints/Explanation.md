# Problem Description
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]

Output: 20
# Approach 1:
## Data Structure:
* use priority_queue ```priority_queue<int, vector<int>, greater<int>> edges```to automatically sort the cost of connection between any points (sort the edges) from high to low
## Algorithm:
Applying concept of minimum spanning tree
1. Step 1: use double for loop to add the edges cost to ``` priority_queue edges```
```
// Step 2: add edge (distance) to the edges list
cout<<"-- loop add sorted edges --"<<endl;
for ( int currentPoints = 0; currentPoints < points.size(); currentPoints++) {                // row = number of points = points.size()

    for ( int nextPoint = currentPoints+1; nextPoint < points.size(); nextPoint++){          // go from 1 points to the immediate next.
        int x1 = points[currentPoints][0];
        int x2 = points[nextPoint][0];
        int y1 = points[currentPoints][1];
        int y2 = points[nextPoint][1];
        cout<<" (x1,y1)=("<<x1<<","<<y1<<"),(x2,y2)=("<<x2<<","<<y2<<") ";
        manhattan_distance =  abs(x1-x2) + abs(y1-y2)  ;                       //Note: abs has to be used or will go out of range

        edges.push(manhattan_distance);
        cout<<"add edge: "<<manhattan_distance<<endl;
    }
}
cout<<"-- end loop add sorted edges --"<<endl;
```
2. Step 2.1: check if the edge could make a loop. This approach fails because it doesn't perform this check. 
3. Step 2.2: note that only N-1 edges are needed to create a minimum spanning tree. Add up the total cost from the `priority_queue edges` with size N-1
```
for ( int currentPoints = 1; currentPoints < points.size(); currentPoints++){   // number of edges count from 1 to N-1
    ret += edges.top();
    edges.pop();
    cout<<"ret: "<<ret<<endl;
}
```

# Approach 2:
## Data Structure:
* a `struct point` to make a point with xy coordinates and defines if a points was visited via = overloaded operator
* a ` struct edge_point` to keep track of the edges'cost and defines if the cost is lower/greater via > overloaded operator
* a `vector visited` to keep track of visited points
* a `priority_queue sortedEdge` to keep track of the edges and sort them in descending order
## Algorithm:
Use Kruskal's algorithm
* I theorize that if the edges connects 2 visited points, they make a loop ==> **this is not correct.** 
* I made = operator overload to compare if the struct point were visited .
* I made > operator overload to short if the struct edge_point in descending order
1. Step 1:Create sorted weighted edges (descending order) data queue
2. Step 2:For loop to make `priority_queue sorted-edges`
3. Step 2.1: For loop to count the total cost from `priority_queue sorted_edges`. The number of edge should be N-1. And perform check if the edges would make a loop. 


# Approach 3: (Final Solution)
Use UNION to check if the edges has the same root. If they have the same root ==> they would make a loop
## Data Structure:
* ~~a `struct point` to make a point with xy coordinates and defines if a points was visited via = overloaded operator ~~
* a ` struct edgePoint` to keep track of the edges'cost and defines if the cost is lower/greater via > overloaded operator
* ~~a `vector visited` to keep track of visited points ~~
* a `priority_queue edgeList` to keep track of the edges'cost and sort them in descending order
## Algorithm:
* **UnionByRank's algorithm**
1. Step 0: Make 2 arrays to store `ROOT` and `RANK` of each edge.
2. Step 1: findRoot(nodeX) funtion to return the root of each nodeX.
3. Step 2: setUnion(nodeX, nodeY) funtion to connect 2 nodes. 
   * if they have higher rank => set the root of one nodeX to the root of the other nodeY that has higher rank ==> root array at a lower rank nodeX = root of the higher rank nodeY.
   * else increase the rank of nodeX 
In this problem, once and edge is created between 2 points, `unionSet(tmpEdge.point1, tmpEdge.point2)` will set 2 points with the same root.
4. Step 3: connected(nodeX, nodeY) returns true if root[nodeX] = root[nodeY]
In this problem, `looping(tmpPoint)` will check if the points have the same root and thus an edge connecting them will cause a loop.
* **Kruskal's algorithm**
6. Step 1:Create sorted weighted edges (descending order) data queue
7. Step 2:For loop to make `priority_queue sorted-edges`
8. Step 2.1: For loop to count the total cost from `priority_queue sorted_edges`. The number of edge should be N-1. And perform check if the edges would make a loop. 
