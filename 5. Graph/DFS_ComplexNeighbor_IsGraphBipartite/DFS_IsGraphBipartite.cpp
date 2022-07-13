#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

class Solution {
private: 
    stack<int> dfsStack;
    vector<int>group;
    bool dfs(vector<vector<int>>& graph, int node){
        dfsStack.push(node);
        group[node]= 1;
        while (!dfsStack.empty()){
            int curr = dfsStack.top();
            // cout<<"curr "<<curr<<" group "<<group[curr]<<endl;
            dfsStack.pop();
            for (int i=0; i<graph[curr].size(); i++){
                int next = graph[curr][i];
                if (group[next] == 0){
                    if (group[curr]==1)
                        group[next]=2;
                    else 
                        group[next]=1;
                    dfsStack.push(next);
                    // cout<<"    next "<<next<<" group "<<group[next]<<endl;
                }
                else if(group[next] == group[curr]){
                    // cout<<"    next "<<next<<" group "<<group[next]<<" false"<<endl;
                    return false;
                }
                    
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        group.resize(n, 0);
        for (int node = 0; node<graph.size(); node++){
            if (group[node] == 0)
                if( dfs(graph, node) == false)
                    return false;
        }
        
        return true; 
    }
};