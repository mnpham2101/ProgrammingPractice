#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    private:
        vector<bool>unsafe;
        void dfs(vector<vector<int>>& graph, int node, vector<int>& result){
            stack<int> dfsStack;
            vector<bool> visited(graph.size(),false);                 // Need improve since disjoin network <= graph.size()
            dfsStack.push(node);
            while (!dfsStack.empty()){
                int currNode = dfsStack.top();
                dfsStack.pop();

                // process neighbor:
                for (int i = 0; i < graph[currNode].size(); i++){
                    int nextNode = graph[currNode][i];
                    if (visited[nextNode]){         // BUG: 1->2->3->4 : 1,2,3,4 will be mark visited.
                                                    // 1->3->4 : since 3 was marked visited, 1,3 will be marked unsafe
                        unsafe[node]=true;
                        unsafe[currNode]=true;
                    }
                    else{
                        dfsStack.push(nextNode);
                        visited[nextNode] = true;
                    }
                }
            }
            if (!unsafe[node])
                result.push_back(node);
        }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;

        // find safe nodes:
        unsafe.resize(graph.size(), false);
        for (int node=0; node<graph.size(); node++){
            if (unsafe[node])
                continue;
            dfs(graph, node, result);
        }
        return result;
    }
};