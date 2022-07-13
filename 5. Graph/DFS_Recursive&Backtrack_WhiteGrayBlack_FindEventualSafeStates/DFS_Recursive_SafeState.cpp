#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
    bool dfs(int node , vector<vector<int>>& graph , vector<bool> &visited, vector<bool> &isSafe){    
        if(isSafe[node]==true)return true;
        if(visited[node])return false;
        visited[node] = true;
        
        for(auto i:graph[node]){
            if(!dfs(i , graph , visited , isSafe)){
                return false;
            }
        }
        return isSafe[node] = true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> isSafe(n , false);
        vector<bool> visited(n , false);
        
        for(int i=0;i<n;i++){
            dfs(i , graph , visited , isSafe);
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};