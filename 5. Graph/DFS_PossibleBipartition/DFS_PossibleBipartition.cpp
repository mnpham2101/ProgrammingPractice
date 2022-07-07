#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

class Solution {
private:
    stack<int>dfsStack;
    vector<vector<int>> relation;
    vector<int>group;
    bool dfs(vector<vector<int>>& dislikes, int & person){
        dfsStack.push(person);
        while (!dfsStack.empty()){
            int curr = dfsStack.top();
            
            dfsStack.pop();
            //if the person is not yet in a group
            // the person is in a disjoined set, and can be added to any group. 
            if (group[curr] == 0)                                        
                group[curr] = 1;
            // cout<<"curr "<<curr<<" group "<<group[curr]<<endl;
            for (int i = 0; i < relation[curr].size(); i++){
                int next = relation[curr][i];
                if (group[next] == 0){
                    if (group[curr] == 1)
                        group[next] = 2;
                    else if (group[curr]==2)
                        group[next] =1;
                    dfsStack.push(next);
                }
                else if (group[curr] == group[next]){
                    // cout<<"    next "<<next<<" group "<<group[next]<<endl;
                    return false;
                }
                
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        relation.resize(n+1);                           // person count from 1 -> n
        group.resize(n+1, 0);
        for (int i=0; i<dislikes.size(); i++){
            int personA = dislikes[i][0];
            int personB = dislikes[i][1];
            relation[personA].push_back(personB);
            relation[personB].push_back(personA);
        }
        bool result=true;
        for (int person = 1; person<=n; person++){
            if (group[person] == 0)
                result = dfs(dislikes, person);
        }
        return result;
    }
};