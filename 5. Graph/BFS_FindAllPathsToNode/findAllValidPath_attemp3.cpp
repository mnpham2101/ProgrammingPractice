#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    // Step 1: Make adjacent List of all nodes.
    unordered_map<int, vector<int>> adj;
    // Step 2: Make a queue to process traversing.
    vector<int> pathQueue;
    // Step 2.2: Make data structure to keep track of resulting paths
    vector<int> finalPath;
    int steps = 0;              // total reiteration
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return bfs(adj, start, end) >= 0;
    }

private:
    int bfs(const unordered_map<int, vector<int>>& adj,
               const int start,
               const int target) {
        // Step 3.1: Add the starting node to queue
        pathQueue.push_back(start);
        unordered_set<int> visited;
        int currentVertex = pathQueue.front();
        cout<<"currentVertex "<<currentVertex<< endl;
        while (!pathQueue.empty()) {
            cout<<"cycle: "<<steps<<endl;
            vector<int> new_q;
            // Step 3.2: Pop the top node from queue
            // because of increment through for loop, pathQueue is considered pop-out
            for (const auto& currentVertex : pathQueue) {
                cout<<"currentVertex "<<currentVertex<< endl;
                finalPath.push_back(currentVertex);
                if (currentVertex == target) {
                    cout<<"reach the end"<<endl;
                    return steps;
                }
                if (!adj.count(currentVertex)) {
                    cout<<"current vertex "<<currentVertex<<" has no neighbor, skip searching adj list "<<endl;
                    continue;
                }
                cout<<"next Vertex to be in list: ";
                // Step 3.3: add neighboring vertices to traversing queue
                for (const auto& nei : adj.at(currentVertex)) {
                    if (visited.count(nei)) {
                        cout<<nei<<"(visited, not add to pathQueue), ";
                        continue;
                    }
                    visited.emplace(nei);
                    new_q.emplace_back(nei);
                    cout<<nei<<" ";
                }
                cout<<endl;
            }
            // quick copy all neighbor of current vertex to pathQueue
            pathQueue = move(new_q);
            ++steps;

        }
        return -1;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{1,5},{5,6},{5,7},{7,8},{8,9}};
    // vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    Solution obj;
    if (obj.validPath(6, edges, 3, 9)){
        cout << "result: true" <<endl;
    }
    else
        cout<< "result: false" <<endl;

    cout<<"final path:";
    for (auto & vertex : obj.finalPath){
        cout<<vertex<<" ";
    }
    cout<<endl;

    cout<<"total reiteration: "<<obj.steps<<endl;
    return 0;
}