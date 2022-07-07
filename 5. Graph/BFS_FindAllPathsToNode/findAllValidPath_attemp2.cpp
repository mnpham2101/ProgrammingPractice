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
    unordered_map<int, vector<int>> adjList;
    // Step 2: Make a queue to process traversing.
    queue<int> pathQueue;
    unordered_set<int> visited;
    // Step 2.2: Make data structure to keep track of resulting paths
    vector<int> finalPath;
    int steps = 0;              // total reiteration
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        for (const auto& edge : edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        // step 3.1: add a starting vertex to the queue.
        pathQueue.push(start);
        return bfs(adjList, start, end);
    }
    bool bfs (unordered_map<int, vector<int>> adjList, int start, int end){
        cout<<"---bfs---"<<endl;
        steps++;
        if (!pathQueue.empty()){
            int currentVertex = pathQueue.front();
            cout<<"currentVertex "<<currentVertex<< endl;
            if(currentVertex == end){
                cout<<"reach the end"<<endl;
                finalPath.push_back(currentVertex);
                return true;
            }
            else if (!adjList.count(currentVertex)) {
                cout<<"current vertex "<<currentVertex<<" has no neighbor, skip searching adj list"<<endl;
                pathQueue.pop();
                return bfs(adjList, start, end);
            }
            else if(!visited.count(currentVertex)){
                // step 3.2: remove a vertex from the back (FIFO) and mark it as visited,  if all the conditions pass
                finalPath.push_back(currentVertex);
                pathQueue.pop();
                visited.emplace(currentVertex);    //mark visited
                cout<<"next Vertex to be in list: ";
                int nextVertex;
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
                cout<<endl;
                return bfs(adjList, start, end);
            }
            else{
                cout<<"current vertex is visited "<<currentVertex<<endl;
                pathQueue.pop();
                return bfs(adjList, start, end);
            }
        }
        else return false;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{1,5},{5,6},{5,7},{7,8},{8,9}};
    // vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    Solution obj;
    if (obj.validPath(9, edges, 3, 9)){
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