#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& ans, vector<int>& color, vector<vector<int>>& ingraph, int node){
        vector<int> stk;
        stk.push_back(node);
        while(!stk.empty()){
            int curr = stk.back();
            stk.pop_back();
            if(color[curr]==0 && ingraph[curr].empty()){
                color[curr]=2;
                ans.push_back(curr);
            } 
            else {
                color[curr]=1;
            }
            for(auto nei:ingraph[curr]){
                if(color[nei]==0){
                    stk.push_back(nei);
                }
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ingraph(n, vector<int>()); // in-edges labeled
        vector<int> color(n, 0);// 0:unvisited, 1:visited & not terminal, 2:visited & terminal
        vector<int> ans;
        for(auto e:edges){
            ingraph[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(color[i]==0 && ingraph[i].empty()){// no in edges, must be added
                color[i]=2;
                ans.push_back(i);
            }
            else if(color[i]==0){
                //back-track along the in-edges, until we find nodes all visited or without in-edge.
                dfs(ans, color, ingraph, i);
            }
        }
        return ans;
    }
};