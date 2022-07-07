#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
private:
    stack<int>dfsStack;
    int time = 0;
    
    // dfs run from top (Header) down to subordinates
    void  dfs(vector<int>& manager, vector<int>& informTime, int currentLeader, int subordinate_time){

        // cout<<"currentLeader "<<currentLeader<<endl;         
        // Step 1: calculate time:
        // cout<<"prev_time "<<informTime[currentLeader]<<" subordinate_time "<<subordinate_time;
        time = max (time, subordinate_time);
        // cout<<" max time "<<time<<endl;
        // process subordinate and run dfs on ubordinates
        for (int subordinate = 0; subordinate < manager.size(); subordinate++){
            if (manager[subordinate] == currentLeader){
                // cout<<"   subordinate "<<subordinate<<" subordinate_ time: "<<subordinate_time<<endl;
                // Step 2:
                subordinate_time += informTime[subordinate];
                // push Id of subordinates, go down tree, call dfs
                dfs(manager, informTime, subordinate, subordinate_time);
                // Step 3:
                subordinate_time -= informTime[subordinate];
                // cout<<"   dfs_return, subordinate "<<subordinate<<" subordinate_ time: "<<subordinate_time<<endl;
            }
        }    
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        dfs(manager, informTime, headID, informTime[headID]);
        return time;          
    }
};