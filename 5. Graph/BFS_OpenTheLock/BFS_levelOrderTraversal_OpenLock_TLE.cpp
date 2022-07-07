#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 

class Solution {
private:
    string generateNext(string curr, int wheel, string & target, string direction){
        if (direction == "forward"){
            if (curr[wheel] == '9')
                curr[wheel] = '0';
            else
                curr[wheel] = curr[wheel] + 1; 
        }
        if (direction == "backward"){
            if (curr[wheel] == '0')
                curr[wheel] = '9';
            else
                curr[wheel] = curr[wheel] - 1; 
        }
        return curr; 
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        // special case:
        if (find(deadends.begin(), deadends.end(), start) != deadends.end())
            return -1;
        int count =0;
        
        queue<string>bfsQueue;
        bfsQueue.push(start);
        deadends.push_back(start);                                      // use deadends as to check visited node
        while (!bfsQueue.empty()){
            int levelSize = bfsQueue.size();
            // cout<<"count "<<count<<endl;
            for (int i = 0; i < levelSize; i++){
                string curr = bfsQueue.front();
                // cout<<"curr: "<<curr<<endl;
                bfsQueue.pop(); 
                if (curr == target)
                    return count;
                // process neighbors
                for (int wheel = 0; wheel<4; wheel++){                  // for each wheel, mack new combination
                    string nextForward = generateNext(curr, wheel, target, "forward");
                    string nextBackward = generateNext(curr, wheel, target, "backward");  
                    
                    // cout<<"     next "<<nextForward<<endl;
                    if ( find(deadends.begin(), deadends.end(), nextForward ) == deadends.end() )  {
                        bfsQueue.push(nextForward);
                        deadends.push_back(nextForward);                           // use deadends as to check visited node
                    }                        
                                                
                    // cout<<"     next "<<nextBackward<<endl;
                    if ( find(deadends.begin(), deadends.end(), nextBackward ) == deadends.end() )  {
                        bfsQueue.push(nextBackward);
                        deadends.push_back(nextBackward);                           // use deadends as to check visited node 
                    }                        
                }
            }
            count++;
        }
        
        return -1;      // if bfsQueue is empty => cannot reach the target
    }
};