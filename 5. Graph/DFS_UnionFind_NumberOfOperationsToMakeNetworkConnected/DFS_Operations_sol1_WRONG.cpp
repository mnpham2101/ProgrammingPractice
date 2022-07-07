#include<vector>
#include<list>
#include<unordered_map>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
    private:
    vector<bool> visited;
    stack<int> dfsStack;
    unordered_map<int, list<int>> neighborPCs;              // use list to allow constant complexity when adding item
    int dfs(vector<vector<int>>& connections){
        int count=0;
        while (!dfsStack.empty()){
            int currPC = dfsStack.top();
            dfsStack.pop();
            // process neighbor
            for (auto neighbor : neighborPCs[currPC]){
                if (visited[neighbor]==true)
                    continue;
                dfsStack.push(neighbor);
                visited[neighbor] = true;
            }
        }
        for (auto PC : visited){
            if (PC == false){
                count++;                            // BUG: all PC maybe connected, yet belong to different disjoined networks.
            }
        }
        return count;
    }
    public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int numberOfConnections = connections.size();
        if (numberOfConnections < n-1)
            return -1;
        // make list of adjacentPCs
        for (int i = 0; i< numberOfConnections; i++){
            int PC1= connections[i][0];
            int PC2= connections[i][1];
            neighborPCs[PC1].push_back(PC2);
            neighborPCs[PC2].push_back(PC1);
        }

        visited.resize(n, false);
        dfsStack.push(connections[0][0]);
        visited[connections[0][0]]= true;

        return dfs(connections);                                // bug: a single BFS will leaved out PC in other disjoined networks.
    }
};