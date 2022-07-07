#include<stack>
#include<vector>
using namespace std; 

// is there disconnected verticle ? 
class Solution {
    private:
        vector<bool>visited;
        vector<vector<int>> adjList;
        void dfs(vector<vector<int>>& edges, int verticle){
            stack<int>dfsStack;
            dfsStack.push(verticle);
            while (!dfsStack.empty()){
                int curr = dfsStack.top();
                dfsStack.pop();
                visited[curr]= true;
                // process neighbor
                for (int i = 0; i< adjList[curr].size(); i++){
                    int next = adjList[curr][i];
                    if (visited[next] == false){
                        dfsStack.push(next);
                    }
                }
            }
        }
    public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>result;
        visited.resize(n, false);
        adjList.resize(n);
        for (int i = 0; i <edges.size(); i++){
            int verticleA = edges[i][0];
            int verticleB = edges[i][1];
            adjList[verticleA].push_back(verticleB);
        }
        
        for (int verticle = 0; verticle <n ; verticle++){
            if (visited[verticle] == false){                        //BUG: this doesn't give minimum number 
                dfs(edges, verticle);
                result.push_back(verticle);
            }
        }
        return result;    
    }
};