#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <list>
using namespace std;
class Solution {
private:
    unordered_map<int, list<int>> subordinateList;
    stack<int> dfsStack;

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int subordinate = 0; subordinate <manager.size(); subordinate++){
            subordinateList[manager[subordinate]].push_back(subordinate);
        }
        dfsStack.push(headID);
        int result = informTime[headID];
        while (!dfsStack.empty()){
            int currentLeader = dfsStack.top();
            dfsStack.pop();
            int parentTime;
            if (manager[currentLeader] >= 0){
                parentTime = informTime[manager[currentLeader]];
            }
            else
                parentTime = 0;
            // int parentTime = manager[currentLeader] >= 0 ? informTime[manager[currentLeader]] : 0;
            informTime[currentLeader] += parentTime;
            result = max(result, informTime[currentLeader]);
            for (auto subordinate : subordinateList[currentLeader]){
                dfsStack.push(subordinate);
            }
        }
        return result;
    }
};