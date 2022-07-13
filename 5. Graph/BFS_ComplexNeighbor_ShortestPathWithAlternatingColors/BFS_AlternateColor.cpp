#include<vector>
#include<queue>
#include<iostream>
using namespace std; 

class Solution {
private:
    
    struct Node{
        int node;               // node       
        int edge;               // connecting edge, 0: red, 1: blue, identified by redEdges, blueEdges
        int distance=0;         // distance from node 0
    };
    
    // neighbor storage row: node; col: neighbors of nodes, neighbors could be on either red edge blue edge
    vector<vector<Node>> neighborList;              
    
    int bfs(int dest, int n){
        queue<Node> bfsQueue;
        bfsQueue.push({0,-1,0});                           // push node 0 to queue, marked it as visited, on neutral path
        vector<bool>visitedRed(n, false);                  // true = 1 : node cannot be revisited on red path 
        vector<bool>visitedBlue(n, false);                 // true = 1 : node cannot be revisited on blue path 
        while(!bfsQueue.empty())
        {
            // cout<<"--bfs--"<<endl;
            Node curr;
            curr = bfsQueue.front();
            if (curr.edge == 0 || curr.edge == -1 ){                   // node was connected by red edge or node 0
                visitedRed[curr.node] = true;                          // node cannot be add to queue if connecting path to it is red  
            } 
            if (curr.edge == 1 || curr.edge == -1 ){                   // node was connected by blue edge or node 0         
                visitedBlue[curr.node] = true;                         // node cannot be add to queue if path to it is blue    
            }
            
            bfsQueue.pop();                       
            // cout<<"  curr "<<curr.node<<" dist: "<<curr.distance <<" edge "<<curr.edge<<endl;                
            // if found destination:
            if (curr.node == dest){
                // cout<<"    dest found "<<dest<<" curr.node "<<curr.node<<endl;
                return curr.distance;
            }
            // process neighbor:
            for (auto next : neighborList[curr.node]){
                if ((curr.edge == -1 || curr.edge == 1) and 
                     next.edge == 0 and 
                     visitedRed[next.node] == true){           // next node must be on red edge, and node was visited 
                    // cout<<"     "<<next.node<<" visited on edge"<<next.edge<<endl;
                    continue;
                }
                if ((curr.edge == -1 || curr.edge == 0) and 
                     next.edge == 1 and 
                     visitedBlue[next.node] == true){         // next node must be on blue edge, and node was visited 
                    // cout<<"     "<<next.node<<" visited on edge"<<next.edge<<endl;
                    continue;
                }    
                if ((curr.edge == -1 || curr.edge == 0) and visitedBlue[next.node] == false){
                    if (next.edge == 1){                                   // change color edge for next's next edge
                        next.distance = curr.distance + 1;
                        // cout<<"       next "<<next.node<<" dist "<<next.distance<<" edge "<<next.edge<<endl;
                        bfsQueue.push(next);
                    }
                }
                if ((curr.edge == -1 || curr.edge == 1) and visitedRed[next.node] == false){
                    if (next.edge == 0){
                        next.distance = curr.distance + 1;
                        // cout<<"       next "<<next.node<<" dist "<<next.distance<<" edge "<<next.edge<<endl;
                        bfsQueue.push(next);
                    }
                }
            }
        }
        return -1;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> result(n);
        neighborList.resize(n);
        // construct neighbor maps
        for (int i = 0 ; i< redEdges.size(); i++){
            int nodeA = redEdges[i][0];
            int nodeB = redEdges[i][1];
            Node node = {nodeB, 0, 0};                      // nodeA -> nodeB: on redEdge,           
            neighborList[nodeA].push_back(node);
        }
        for (int i = 0 ; i< blueEdges.size(); i++){
            int nodeA = blueEdges[i][0];                          
            int nodeB = blueEdges[i][1];
            Node node = {nodeB, 1, 0};                      // nodeA -> nodeB: on blueEdge, 
            neighborList[nodeA].push_back(node);
        }
        
        // result from 0 to itself
        result[0]= 0; 
        
        for (int dest = 1; dest<n; dest++){
            // cout<<"find new path to "<<dest<<endl;
            result[dest] = bfs(dest,n);
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n=5;
    vector<vector<int>> redEdges = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> blueEdges = {{1,2},{2,3},{3,1}};
    sol.shortestAlternatingPaths(n,redEdges,blueEdges);
}
