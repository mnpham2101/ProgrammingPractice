#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    private:
        vector<int> visited;
        // mark nodes as Not Visited=0; "In DFS Progress" = 1; at terminal, all processed and connected to terminal = 2
        // 1) if a currentNode is a terminal => mark 2.
        // 2) if revisiting "In Progress node" (marked 1) => a back-edge is found.   BUG: how to recognise a forward node vs a parent node, both marked `1`
        // 3) if no back-edge is found, mark the root node as safe (2)
        void dfs(vector<vector<int>>& graph, int node){
            stack<int> dfsStack;
            stack<int> parentNodes;
            dfsStack.push(node);

            if (graph[node].size() == 0){
                cout<<"terminal node "<<node<<endl;
                visited[node]=2;
                return;
            }

            while (!dfsStack.empty()){
                int currentNode = dfsStack.top();
                dfsStack.pop();
                visited[currentNode] = 1;
                cout<<"current "<< currentNode<<" "<<visited[currentNode]<<endl;
                for (int i = 0; i< graph[currentNode].size(); i++){
                    int nextNode = graph[currentNode][i];
                    // if nextNode is terminal:
                    if (graph[nextNode].size() == 0){
                        cout<<"   next node safe "<<nextNode<<" current "<<currentNode<<endl;
                        visited[nextNode] = 2;
                        continue;
                    }
                    // if nextNode is already visited
                    if (visited[nextNode] == 1){
                        cout<<"   next node not safe "<<nextNode<<endl;         // BUG1 TC [[1,2],[2],[3],[]] (cannot recognise valid forward-edge)
                        visited[currentNode] = 1;
                        visited[node] = 1;
                        return;
                    }

                    // if (visited[nextNode] == 2){                    
                    //     visited[currentNode] = 2;            // BUG2 TC [[1,2,3,4],[1,2],[3,4],[0,4],[]], fail to detect back-edge 3->2
                    //     continue;
                    // }
                                        
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
            dfs(graph, node);                             // run dfs to mark node as 1 or 2
        }
        // push to answer if the node is safe node (marked as 2)
        for (int node = 0; node< graph.size(); node++){
            if (visited[node]==2)
                result.push_back(node);
        }
        return result;
    }
};


