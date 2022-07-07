#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_set>
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
        
        /* using to_string and string addition to achieve the same result*/
        // string result;
        // if (direction == "backward"){
        //      result = curr.substr( 0 , wheel )+to_string( curr[wheel] == '0' ? 9 : curr[wheel] - '0' - 1 ) + curr.substr( wheel+1 );
        // }
        // if (direction == "forward"){
        //      result = curr.substr( 0 , wheel )+to_string( curr[wheel] == '9' ? 0 : curr[wheel] - '0' + 1 ) + curr.substr( wheel+1 );
        // }
        // return result ;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        
        unordered_set<string> visited(deadends.begin(),deadends.end());
        // special case:
        if (find(deadends.begin(), deadends.end(), start) != deadends.end())
            return -1;
        int count =0;
        
        queue<string>bfsQueue;
        bfsQueue.push(start);
        visited.insert(start);                                      // use deadends as to check visited node
        while (!bfsQueue.empty()){
            int levelSize = bfsQueue.size();
            for (int i = 0; i < levelSize; i++){
                string curr = bfsQueue.front();
                bfsQueue.pop(); 
                if (curr == target)
                    return count;
                // process neighbors
                for (int wheel = 0; wheel<4; wheel++){                  // for each wheel, mack new combination
                    string nextForward = generateNext(curr, wheel, target, "forward");    
                    string nextBackward = generateNext(curr, wheel, target, "backward");                         
                                       
                    if(!visited.count(nextForward)){
                        //string is not in deadend.
                        // we do not want to encounter this node again
                        visited.insert(nextForward);
                        bfsQueue.push(nextForward);
                    }
                    
                    if(!visited.count(nextBackward)){
                        visited.insert(nextBackward);
                        bfsQueue.push(nextBackward);
                    }
                }
            }
            count++;
        }
        
        return -1;      // if bfsQueue is empty => cannot reach the target
    }
};