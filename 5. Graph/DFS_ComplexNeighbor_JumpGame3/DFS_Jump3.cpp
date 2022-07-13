#include<stack>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        stack<int>dfsStack;
        int n = arr.size();
        vector<int> visited (n,0);
        // dfs
        dfsStack.push(start);
        while(!dfsStack.empty()){
            int curr = dfsStack.top();
            cout<<"curr "<<curr<<" ";
            dfsStack.pop();
            if (arr[curr] == 0)
                return true;
            visited[curr] = 1;
            
            int next1 = curr + arr[curr];
            int next2 = curr - arr[curr];
            
            if (next1 < n && next1>=0) {
                if (visited[next1] !=1){
                    cout<<"next1 "<<next1<<" ";
                    dfsStack.push(next1);
                }
            } 
            
            if (next2 < n && next2>=0){
                if (visited[next2] !=1){
                    cout<<"next2 "<<next2<<endl;
                    dfsStack.push(next2);
                }
            }
                
        }
        return false;
    }
};