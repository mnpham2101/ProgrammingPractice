#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 2D vector to store road information - also used as adjacent vertex list
// row: vertex A, col: vertex B. Value is distance from vertexA to vertexB.
// Size NxN. N max is 100, +1 b/c index 0 is not a vertex number
int roadInformation[100 + 1][100 + 1];
// shortest distance from a vertex to the farthest vertex. Index = vertex number
int shortestDistanceTable[100 + 1];                  // N vertices, N max is 100; +1 b/c index 0 is not a vertex number
// list of unvisited vertices
bool unvisited[100 + 1];
queue<int> dijkstraQueue;
int N;              //number of factories/vertices
int M;              //number of road information
int answer = INT_MAX;

void InputData() {

    cin >> N >> M;

    for (int vertexA = 1; vertexA <= N; vertexA++) {
        for (int vertexB = 1; vertexB <= N; vertexB++) {
            roadInformation[vertexA][vertexB] = INT_MAX; // There is no information for direct path from vertexA <-> vertexB
        }
    }

    for (int i = 0; i < M; i++) {
        int vertexA, vertexB, distance;
        cin >> vertexA >> vertexB >> distance;
        roadInformation[vertexA][vertexB] = distance;
        roadInformation[vertexB][vertexA] = distance;
    }
}

void init(int startingVertex) {
    // Step 1
    for (int vertex = 1; vertex <= N; vertex++) {
        shortestDistanceTable[vertex] = INT_MAX;
        unvisited[vertex] = false;
    }
    shortestDistanceTable[startingVertex] = 0;       //distance from startingVertex to itself is 0
}

// return the longest distance from starting vertex to every other vertices where the path is OPTIMIZED (shortest path)
int dijkstra(int startingVertex) {
    dijkstraQueue.push(startingVertex);
    while (!dijkstraQueue.empty()) {
        //Step 2a
        int currentVertex = dijkstraQueue.front();
        dijkstraQueue.pop();
        unvisited[currentVertex] = true;
        //Step 2b: update the shortest distance from the starting Vertex to other vertices via the current vertex
        for (int vertex = 1; vertex <= N; vertex++) {
            if (unvisited[vertex] != true &&
                roadInformation[currentVertex][vertex] != INT_MAX           // if there is a direct path indicated in informationTable
                ) {
                // if there is a shorter path from starting vertex 1 to  vertex via current vertex
                if (shortestDistanceTable[vertex] > shortestDistanceTable[currentVertex] + roadInformation[currentVertex][vertex]) {
                    shortestDistanceTable[vertex] = shortestDistanceTable[currentVertex] + roadInformation[currentVertex][vertex];
                }
            }
        }
        // Step 2c: add the next unvisited vertex that has the shortest distance to Source Vertex to DijkstraQueue
        int minDistance = INT_MAX;
        int nextVertex = -1;
        for (int vertex = 1; vertex <= N; vertex++) {
            if (!unvisited[vertex] &&
                minDistance > shortestDistanceTable[vertex])
            {
                minDistance = shortestDistanceTable[vertex];
                nextVertex = vertex;
            }
        }
        if (nextVertex != -1) {
            dijkstraQueue.push(nextVertex);
        }
    }

    // Tìm khoảng cách lớn nhất từ đỉnh start đến các đỉnh còn lại và trả ra kết quả
    int maxDistance = shortestDistanceTable[1];
    for (int i = 2; i <= N; i++) {
        if (maxDistance < shortestDistanceTable[i]) {
            maxDistance = shortestDistanceTable[i];
        }
    }

    return maxDistance;
}


void Solve() {
    // for every vertex as startingVertex,
    // find the LONGEST distance from the starting vertex to other vertex via dijkstra
    for (int startingVertex = 1; startingVertex <= N; startingVertex++) {
        init(startingVertex);
        answer = min(answer, dijkstra(startingVertex));             // among the longest distance, find the shortest of them.
    }
}

void OutputData() {
    cout << answer << endl;
}

int main() {


    InputData();//	Input function

    //	Create the code
    Solve();

    OutputData();

    return 0;
}