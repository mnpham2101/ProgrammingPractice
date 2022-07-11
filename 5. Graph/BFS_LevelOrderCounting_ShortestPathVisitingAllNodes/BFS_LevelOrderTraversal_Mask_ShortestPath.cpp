#include<queue>
#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution {
private:
    
    int bfs(vector<vector<int>>& graph, int node){
        vector<vector<bool>> visited;
        int endingMask;
        int n = graph.size();
        endingMask = (1<<n)-1;
        visited.resize(n, vector<bool>(endingMask));
    
        queue<pair<int,int>>bfsQueue;           // bfsQueue stores pair. First = nodeId, Second: mask indicates the nodes that this path is taking
        int mask = 1<<node;
        pair<int, int> thisNode = {node, mask};
        bfsQueue.push(thisNode);
        
        int length = 0;
        while (!bfsQueue.empty()){
            int n = bfsQueue.size();
            // cout<<"   pathLength: "<<length<<endl;
            for (int i = 0; i<n; i++){                      // level ordered traversal, length is incremented after nodes on the same level have been processed.
                pair<int, int> curr = bfsQueue.front();
                // mask indicate the node that was visited on current path 1: visited. bit position = node index
                int nodeId = curr.first;
                int mask   = curr.second;
                visited[nodeId][mask]=true; 
                // cout<<"     current "<<nodeId<<" mask "<<bitset<4>(mask)<<endl;
                bfsQueue.pop();
                for ( int i = 0; i < graph[nodeId].size(); i++){
                    int nextNode = graph[nodeId][i];
                    int nextMask = (mask | (1<<nextNode));
                    // case return result
                    if (nextMask == endingMask){
                        // cout<<"        nextMask == endingMask"<<bitset<5>(nextMask)<<endl;
                        length++;         // length is incremented in the last level node
                        return length;
                    }

                    // case incrementing length
                    if (visited[nextNode][nextMask] == false){
                        visited[nextNode][nextMask] = true;
                        // cout<<"        nextNode: "<<nextNode<<" mask "<<bitset<4>(nextMask)<<endl;
                        bfsQueue.push({nextNode, nextMask});
                    }
                }
            }
            length++;
        }
        return INT_MAX;             // expect bfs always return value before bfsQueue is empty
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int result = INT_MAX;
        int n = graph.size();
        
        if (graph.size()==1)
            return 0;
        for (int node = 0; node<n; node++){
            // cout<<"startingNode "<<node<<endl;
            int pathLength = bfs(graph, node);
            result = min(pathLength, result);
        }
        return result;
    }
};