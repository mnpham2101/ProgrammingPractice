#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPaths;                  // vector to store all paths
    vector<int> path;                              // "stack" to store available path via vertices
    
    
    // DFS
    void dfs(vector<vector<int>>& graph, int sourceVertex) {
        cout<<"---dfs---"<<endl;
        path.push_back(sourceVertex);
        cout<<"source vertex "<<sourceVertex<<endl;
        // log
        cout<<" path stack so far: "<<endl;
        for (auto vertex: path)
            cout<<vertex<<" ";
        cout<<endl;
        if (sourceVertex == graph.size() - 1) {     //if sourceVertex = destination
            allPaths.emplace_back(path);            //put all items in path stack to result paths     
            // log
            cout<<" result path: "<<endl;
            for (auto vertex: path)
                cout<<vertex<<" ";
            cout<<endl;
            return;
        }
        vector<int> adjVertex = graph[sourceVertex];  //graph definition: graph[i] list of all nodes that can be visited from i
        
        // log
        cout<<"adj list: "<<endl;
        for (int adj : adjVertex)
            cout<<adj <<" ";
        cout<<endl;
        
        for (int nextVertex : adjVertex) {
            cout<<"next vertex "<<nextVertex<<endl;
            dfs(graph, nextVertex);                     // dfs run: go deeper to neighbor of neighbor
            path.pop_back();                            // pop_back to try different paths from earlier nextVertex
            // log
            cout<<" path after pop out: "<<endl;
            for (auto& vertex: path)
                cout<<vertex<<" ";
            cout<<endl;
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        if (graph.size() == 0) {
            return allPaths;
        }
        dfs(graph, 0);     // source = vertex 0
        return allPaths;
    }
};

int main(){
    vector<vector<int>> graph = {{3,1},{4,6,7,2,5},{4,6,3},{6,4},{7,6,5},{6},{7},{}};
    Solution sol;
    sol.allPathsSourceTarget(graph);
    cout<<"Result:"<<endl;
    for (int i = 0; i< sol.allPaths.size(); i++){
        for (int j = 0; j< sol.allPaths[i].size(); j++){
            cout<<sol.allPaths[i][j]<<" ";
        }
        cout<<endl;
    }
}