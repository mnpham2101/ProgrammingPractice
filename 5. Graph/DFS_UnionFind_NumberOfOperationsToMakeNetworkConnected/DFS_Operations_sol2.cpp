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
    void dfs(vector<vector<int>>& connections, int PC){
        int count=0;
        dfsStack.push(PC);
        visited[PC]= true;
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

        int disjoinedNetwork = 0;
        for (int PC=0; PC<n; PC++ ){
            if (visited[PC]== false){
                dfs(connections, PC);           // run DFS for every PC that was not marked connected
                disjoinedNetwork++;             // a disjoined network is found after DFS finishes
            }
        }
        // Log
        for (int i = 0; i<n; i++){              // for TC1: all PCs are connected but there are 2 disjoined networks.
            if (visited[i]== false)
                cout<<i<<" ";                   // nothing will be printed
        }
        return disjoinedNetwork-1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> connections = {{0,1}, {0,2}, {1,2}, {3,4}};
    cout<<sol.makeConnected(5, connections);
}

