#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
private:
    int time = 0;
    unordered_map<int, list<int>> subordinateList;
    // dfs run from top (Header) down to subordinates
    void  dfs(vector<int>& manager, vector<int>& informTime, int currentLeader, int subordinate_time){
        // cout<<"currentLeader "<<currentLeader<<endl;         
        // calculate time:
        // cout<<"prev_time "<<time<<" subordinate_time "<<subordinate_time;
        time = max (time, subordinate_time);
        // cout<<" max time "<<time<<endl;
        // process subordinates & push subordinateList to queues
        for (auto subordinate : subordinateList[currentLeader]){
                // cout<<"   subordinate "<<subordinate<<" subordinate_ time: "<<subordinate_time<<endl;
                subordinate_time += informTime[subordinate];
                // push Id of subordinates, go down tree, call dfsvisited[subordinate] == false && manager[subordinate] == currentLeader
                dfs(manager, informTime, subordinate, subordinate_time);
                subordinate_time -= informTime[subordinate];
                // cout<<"   dfs_return, subordinate "<<subordinate<<" subordinate_ time: "<<subordinate_time<<endl;
        }    
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int subordinate = 0; subordinate <manager.size(); subordinate++){
            subordinateList[manager[subordinate]].push_back(subordinate);               // push in a list of subordinate for every manager
        }
        dfs(manager, informTime, headID, informTime[headID]);
        return time;          
    }
};