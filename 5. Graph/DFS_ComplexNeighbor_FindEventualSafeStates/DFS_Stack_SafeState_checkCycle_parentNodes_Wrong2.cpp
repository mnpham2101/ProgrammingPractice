#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    private:
        vector<int> visited;
        // mark nodes as Not Visited=0; "In DFS Progress" = 1; at terminal, all processed and connected to terminal = 2
        // 1) if a currentNode is a terminal => mark 2.
        // 2) if revisiting "In Progress node" (marked 1) => a back-edge is found.
        // 3) if next node is terminal, direct parent is marked 2
        void dfs(vector<vector<int>>& graph, int node){
            stack<int> dfsStack;
            vector<int> parentNodes; 
            dfsStack.push(node);

            while (!dfsStack.empty()){
                int currentNode = dfsStack.top();
                dfsStack.pop();
                
                parentNodes.push_back(currentNode);                  // push to parent Nodes  
                visited[currentNode] = 1;
                cout<<"  current "<< currentNode<<" "<<visited[currentNode]<<endl;
                
                for (int i = 0; i< graph[currentNode].size(); i++){
                    int nextNode = graph[currentNode][i];
                    if (graph[nextNode].size()==0){
                        cout<<"   next node is terminal "<<nextNode<<endl;
                        parentNodes.pop_back();                                 // BUG: bad backtracking, cause inf loop for TC: [[1,2,3,4],[1,2],[3,4],[0,4],[]]
                        continue;
                    }
                    // if nextNode is already visited
                    if (find(parentNodes.begin(), parentNodes.end(), nextNode) != parentNodes.end()){       // next node is a parent
                        cout<<"   back-edge found "<<nextNode<<endl; 
                        visited[node] = 1;
                        return;
                    }
                                        
                    // if nextNode is not visited
                    cout<<"    push next node to queue "<<nextNode<<endl;
                    dfsStack.push(nextNode);
                }
                
                
            }
            visited[node]=2;                    // starting node is safe if no edge node is found
        }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        visited.resize(graph.size(),0);                   // all nodes are not yet visited
        // run DFS from each node to find if the path has any back-edge
        for (int node=0; node<graph.size(); node++){
            cout<<"start node"<< node<<endl;
            dfs(graph, node);                             // run dfs to mark node as 1 or 2
            if (visited[node]==2)
                result.push_back(node);
        }
        
        return result;
    }
};