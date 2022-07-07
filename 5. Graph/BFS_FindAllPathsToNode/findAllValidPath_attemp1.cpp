#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std; 

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    queue<int> pathQueue;
    unordered_set<int> visited; 
    vector<int> finalPath; 
    int steps = 0;              // total reiteration
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        for (const auto& edge : edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        // step 1: add a starting vertex to the queue.
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
            if(!visited.count(currentVertex)){
                // step 2: remove a vertex from the back (FIFO) and mark it as visited,  if all the conditions pass
                finalPath.push_back(currentVertex);
                pathQueue.pop();
                visited.emplace(currentVertex);                            //mark visited
                cout<<"next Vertex to be in list: ";
                int nextVertex;
                // step 3: add neighboring vertex 
                // (even the one that has visited - we only remove the back of queue out and if the back has been visisted or be marked visited)
                for (auto& vertex : adjList.at(currentVertex)){
                    int nextVertex = vertex;
                    cout<<nextVertex<<" ";
                    pathQueue.push(nextVertex);
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
