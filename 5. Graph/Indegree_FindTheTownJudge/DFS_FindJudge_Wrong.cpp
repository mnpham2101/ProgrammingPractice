#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // trust map
        vector<vector<int>> trustMap(n+1);
        for (int i = 0; i<trust.size(); i++){
            int firstPerson = trust[i][0];
            int secondPerson = trust[i][1];
            trustMap[firstPerson].push_back(secondPerson);
        }
        
        // run dfs to visit all people by their trust
        stack<int>dfsStack;
        dfsStack.push(1);
        vector<bool>visited(n+1);
        while(!dfsStack.empty()){
            int curr = dfsStack.top();
            visited[curr] = true;
            cout<<"curr "<<curr<<endl;
            dfsStack.pop();
            // found the judge - he doesn't trust anybody 
            if(trustMap[curr].size() == 0 ){     // BUG: it doesn't satifies condition: everyone trusts the judge
                cout<<"   found judge"<<endl;
                return curr;
            }
            // process next trusted persons
            for (int i = 0; i< trustMap[curr].size(); i++){
                int next = trustMap[curr][i];
                cout<<"  next "<<next<<endl;
                if (visited[next] != true){
                    dfsStack.push(next);
                }    
            }
        }
        return -1;  // if dfsStack is empty: everyone is visited and trust one another
    }
};