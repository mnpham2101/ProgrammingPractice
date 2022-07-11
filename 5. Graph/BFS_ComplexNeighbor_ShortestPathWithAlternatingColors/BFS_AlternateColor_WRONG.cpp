#include<vector>
#include<queue>
#include<iostream>
using namespace std; 

class Solution {
private:
    // neighbor storage row: node; col: neighbors of nodes
    vector<vector<int>> redNeighbor;            
    vector<vector<int>> blueNeighbor;         
    int bfs(int dest, int n){
        queue<int> bfsQueue;
        bfsQueue.push(0);
        
        vector<bool> visited (n,false);
        

        int redPath = -1;                           // current path color, -1 as starting point, can take either red (1) or blue path (0)
                                                    // A SINGLE FLAG to keep track of the edge color will make this problem a "State Machine Problem"
                                                    // BUG: the logic below cannot allow state machine to run all possible paths.
        vector<int> distanceRed (n,0);
        vector<int> distanceBlue(n,0);
        while(!bfsQueue.empty())
        {
            cout<<"--bfs--"<<endl;
            int curr;
            curr = bfsQueue.front();
            bfsQueue.pop();                       
            cout<<"  curr "<<curr<<" dist: "<< distanceRed[curr] <<" flag "<<redPath<<endl;
            if (redPath == 1 || redPath == -1){                            // BUG: from start, the bfs only takes the next blue edge
                redPath = 0;                        // current is red, next will be blue
                if (curr == dest){
                    return distanceRed[curr];      
                }     
            }
            else if (redPath == 0 || redPath == -1){                             // BUG: from start, the bfs only takes the next blue edge
                redPath = 1;                        // current is blue, next path is red
                if (curr == dest){
                    return distanceBlue[curr];
                }
            }   
            visited[curr] = true;                
            
            // process neighbor:
            if (redPath == 0 or redPath == -1){         // current is red, next is blue
                vector<int> neighborList = blueNeighbor[curr];
                for (int next: neighborList)
                {
                    if (visited[next] == false){
                        bfsQueue.push(next);
                        distanceBlue[next] = distanceRed[curr]+1;
                        cout<<"      next "<<next<<" dist "<<distanceBlue[next]<<" flag: "<<redPath<<endl;
                    }
                }
            }
            
            if (redPath == 1 or redPath == -1){             // current is blue, next is red
                vector<int> neighborList = redNeighbor[curr];
                for (int next: neighborList)
                {
                    if (visited[next] == false) {
                        bfsQueue.push(next);
                        distanceRed[next] = distanceBlue[curr]+1;
                        cout<<"      next "<<next<<" dist "<<distanceRed[next]<<" flag: "<<redPath<<endl;
                    }
                } 
            }
        }
        return -1;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> result(n);
        redNeighbor.resize(n);
        blueNeighbor.resize(n);
        // construct neighbor maps
        for (int i = 0 ; i< redEdges.size(); i++){
            int nodeA = redEdges[i][0];
            int nodeB = redEdges[i][1];
            redNeighbor[nodeA].push_back(nodeB);
        }
        for (int i = 0 ; i< blueEdges.size(); i++){
            int nodeA = blueEdges[i][0];
            int nodeB = blueEdges[i][1];
            redNeighbor[nodeA].push_back(nodeB);
        }
        
        // result from 0 to itself
        result[0]= 0; 
        
        for (int dest = 1; dest<n; dest++){
            cout<<"find new path to "<<dest<<endl;
            result[dest] = bfs(dest,n);
        }
        return result;
    }
};