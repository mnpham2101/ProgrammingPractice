#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
private:
    stack<int>dfsStack;
    vector<bool> visited;                   // mark if employee is visited or not
    int  dfs(vector<int>& manager, vector<int>& informTime, int higherLeader){
        
        dfsStack.push(higherLeader);
        // check re-visit condition & return condition
        if (visited[higherLeader] == true){     // employee already visited, informTime[employee] already calculated
            return informTime[higherLeader];
        }
        while (!dfsStack.empty()){          // calculate informTime[employee] by traversing all child branches(subordinates) of employees
            int currentLeader = dfsStack.top();
            cout<<"currentLeader "<<currentLeader<<endl;
            dfsStack.pop();
            visited[currentLeader] = true;
            cout<<"mark employee visited "<<currentLeader<<" "<<visited[currentLeader] <<endl;
            // calculate new time: 
            /****** BUG 
             * cannot backtrack the time to parent node, and compare accumulated time between child nodes.
             * **************/
            informTime[higherLeader] = max (informTime[higherLeader] + informTime[currentLeader], informTime[higherLeader]);
            cout<<"informTime[higherLeader] "<<informTime[higherLeader]<<endl;
            // process neighbors & push to queues
            for (int subordinate = 0; subordinate < manager.size(); subordinate++){
                if (visited[subordinate] == false && manager[subordinate] == currentLeader){
                    // push Id of subordinates, go down tree.
                    dfsStack.push(subordinate);                               
                    cout<<"subordinate "<<subordinate<<" new, informTime[subordinate] "<<informTime[subordinate]<<endl;
                }
            }  
        } // dfsStack is empty when there is no subordinates of current employee, return informTime
          // condition to return values: dfsStack empty
        return informTime[higherLeader];        // total time for each employee is the longest time for his subordinates
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        visited.resize(n, false);
        for (int employee =0; employee < manager.size(); employee++){
            informTime[employee] = dfs(manager, informTime, employee);
        }
        
        return informTime[headID];          // result, informTime[header] = max time of child branches
    }
};