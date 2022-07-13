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
        bool dfs(vector<vector<int>>& graph, int node){
            // cout<<"  current node "<<node<<endl;
            
            // base case:
            if (visited[node]>0)
                return visited[node] == 2; 
            visited[node] = 1;                          // mark the node as visited
            // recursive case:
            for (int i = 0; i <graph[node].size(); i++){
               int nextNode = graph[node][i];
               if (visited[nextNode] == 1) {                      // if nextNode was visited has a back-edge
                   //  cout<<"    next node is revisited node "<<nextNode<<endl;
                   return false;
               }
                   // cout<<"    run dfs on descendents"<<endl;
               if (!dfs(graph, nextNode)){              // if dfs starting from nextNode has a back-edge
                   
                   return false;
               }
            }
            // backtracking: set parent node as processed
            visited[node] = 2;                          // if all descendent has been processed
            return true;
        }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        visited.resize(graph.size(),0);                   // all nodes are not yet visited
        // run DFS from each node to find if the path has any back-edge
        for (int node=0; node<graph.size(); node++){
            // cout<<"start node"<< node<<endl;
            if (dfs(graph, node))                             // run dfs to mark node as 1 or 2 on starting node
                result.push_back(node);
        }
        
        return result;
    }
};