#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    int neighborRelation[100+1][100+1];
    queue<int> dijkstraQueue;
    vector<bool> unvisited;
    vector<int> shortestDistance;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Initialization:
        // Step 1.a
        shortestDistance.resize(n+1, INT_MAX);
        shortestDistance[k]=0;
        // Step 1.b
        unvisited.resize(n+1);
        for (int i = 1; i<=n; i++){
            unvisited[i]= false;
        }
        // Step 1.c: update neighbor relation with information on delay time between 2 nodes
        for (int sourceVertex = 1; sourceVertex<=n; sourceVertex++){
            for (int destinationVertex = 1; destinationVertex<=n; destinationVertex++){
                neighborRelation[sourceVertex][destinationVertex]=INT_MAX;                  // INT_MAX indicate there is no info/direct path between source and dest
            }
        }
        for (auto info: times){
            int nodeA = info[0];
            int nodeB = info[1];
            int delay = info[2];
            neighborRelation[nodeA][nodeB]=delay;
        }
        // Step 1.d
        dijkstraQueue.push(k);
        // Step 2: Dijkstra process
        while(!dijkstraQueue.empty()){
            //Step 2a:
            int currentVertex = dijkstraQueue.front();
            dijkstraQueue.pop();
            unvisited[currentVertex] = true;
            //Step 2b: update the shortest distance from the starting Vertex to other vertices via the current vertex
            for (int vertex = 1; vertex <= n; vertex++) {
                if (unvisited[vertex] != true &&                                    // if the vertex is not visited
                    neighborRelation[currentVertex][vertex] != INT_MAX){            // if there is information
                    if (shortestDistance[vertex] > shortestDistance[currentVertex] + neighborRelation[currentVertex][vertex]){
                        shortestDistance[vertex] = shortestDistance[currentVertex] + neighborRelation[currentVertex][vertex];
                    }
                }
            }
            //Step 2c: add the next unvisited vertex and where the distance to source = k is the least to Dijkstra queue
            int minDelay = INT_MAX;
            int nextVertex = -1;
            for (int vertex = 1; vertex <= n; vertex++) {
                if (!unvisited[vertex] &&
                    minDelay > shortestDistance[vertex])
                {
                    minDelay = shortestDistance[vertex];
                    nextVertex = vertex;
                }
            }
            if (nextVertex != -1) {
                dijkstraQueue.push(nextVertex);
            }
        }
        // Step 3: query result
        int maxDelay=0;
        for (int vertex = 1; vertex <=n; vertex++){
            if (shortestDistance[vertex] == INT_MAX) return -1;
            maxDelay = max(maxDelay, shortestDistance[vertex]);
        }
        return maxDelay;
    }
};


int main(){
    vector<vector<int>> times;
    Solution sol;
    sol.networkDelayTime(times, 2, 1);
}