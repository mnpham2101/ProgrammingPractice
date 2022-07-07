#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int answer = 0;
int N;                                                          // map size 2<N<100
vector<vector<int>> landPrice;
vector<vector<int>> shortestDistance;                           // store shortest distance from [0][0] to [N-2][N-1] via [x][y]
queue<pair<int, int>> dijkstraQueue;                            // process queue keeps track of each node (x,y)
vector<vector<int>> unvisited;                                  // mark the coordinate(x,y) as visited = 1, unvisited = 0 = false
void InputData() {
    cin >> N;
    string input;

    // vector<vector<int>> landPrice(N, vector<int>(N));
    landPrice.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            landPrice[i][j] = input[j] - '0';
        }
    }
}

// use Dijkstra algo
void Solve() {
    // Step 1: Initialization:
    // Step 1.a
    shortestDistance.resize(N, vector<int>(N, INT_MAX));
    shortestDistance[0][0] = 0;
    // Step 1.b
    unvisited.resize(N, vector<int>(N, 0));
    // Step 1.c: make adjacent list - there is no need as adjacent node can be access by coordinate x,y values and landPrice[x][y]

    // Step 1.d
    dijkstraQueue.push({ 0,0 });
    // Step 2: Dijkstra process
    while (!dijkstraQueue.empty()) {
        //Step 2a:
        pair<int, int> currentVertex = dijkstraQueue.front();
        dijkstraQueue.pop();
        int currentX = currentVertex.first;
        int currentY = currentVertex.second;
        unvisited[currentX][currentY] = 1;
        //Step 2b: update the shortest distance from the starting Vertex to other vertices via the current vertex
        // update the shortestDistance table at the next directly connected vertex only.
        // update next down vertex
        int x = currentX + 1;
        int y = currentY;
        if (x < N) {
            if (unvisited[x][y] != 1) {
                if (shortestDistance[x][y] > shortestDistance[currentX][currentY] + landPrice[x][y])
                    shortestDistance[x][y] = shortestDistance[currentX][currentY] + landPrice[x][y];
            }
        }
        // update next right vertex
        x = currentX;
        y = currentY + 1;
        if (y < N) {
            if (unvisited[x][y] != 1) {
                if (shortestDistance[x][y] > shortestDistance[currentX][currentY] + landPrice[x][y])
                    shortestDistance[x][y] = shortestDistance[currentX][currentY] + landPrice[x][y];
            }
        }

        // update next up vertex
        x = currentX - 1;
        y = currentY;
        if (x >= 0) {
            if (unvisited[x][y] != 1) {
                if (shortestDistance[x][y] > shortestDistance[currentX][currentY] + landPrice[x][y])
                    shortestDistance[x][y] = shortestDistance[currentX][currentY] + landPrice[x][y];
            }
        }

        // update next left vertex
        x = currentX;
        y = currentY-1;
        if (y >= 0) {
            if (unvisited[x][y] != 1) {
                if (shortestDistance[x][y] > shortestDistance[currentX][currentY] + landPrice[x][y])
                    shortestDistance[x][y] = shortestDistance[currentX][currentY] + landPrice[x][y];
            }
        }

        //Step 2c: add the next unvisited vertex and where the distance to source = k is the least to Dijkstra queue
        int minDistance = INT_MAX;
        int nextX=INT_MAX;                          // coordinates of next vertext to be pushed in Dijkstra queue
        int nextY=INT_MAX;
        for (x = 0; x < N; x++) {
            for (y = 0; y < N; y++) {
                if (unvisited[x][y] != 1 ) {
                    if (minDistance > shortestDistance[x][y]) {
                        minDistance = shortestDistance[x][y];
                        nextX = x;
                        nextY = y;
                    }
                }
            }
        }

        if (nextX != INT_MAX && nextY != INT_MAX)
            dijkstraQueue.push({ nextX,nextY });
    }
    // Step 3: query result
    answer = shortestDistance[N - 1][N - 1];
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