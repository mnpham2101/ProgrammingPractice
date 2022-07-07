#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

/* 
 ==> search for all paths from rotten orange to fresh orange, change fresh oranges to rotten.
 ==> each times, multiple oranges are rotten. 
 ==> The problem implements: find shortest path from fresh orang to rotten orange, and change itself to rottent. Each loop, only 1 orange changes to rotten. 
*/ 

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    queue<int> pathQueue;
    unordered_set<int> visited;
    vector<int> finalPath;
    int steps =0; 
    
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        // step 0: make adj list
        for (const auto& grid : grid) {
            adjList[grid[0]].emplace_back(grid[1]);
            adjList[grid[1]].emplace_back(grid[0]);
        }
        
        
    for ( auto& inner : grid) {
      for ( auto& item : inner) {
          // step 1: add a starting vertex to the queue.
          pathQueue.push(item);
          cout<<" --- find rotten loop ---"<<endl;
          cout<<"current orange is (2:rotten, 1:fresh)"<<item<<endl;
          if (item ==1){
              if (bfs(adjList, item, 2)){
              item = 2;
              time++;
              cout<<"found a rotten orange, change the item to rotten: "<<item<<" time: "<<time<<endl;
              }
          }
          
          cout<<"--- end find rotten loop---"<<endl;
      }
    } 
    
        return time;
    }
    bool bfs (unordered_map<int, vector<int>> adjList, int start, int end){
        cout<<"---bfs---"<<endl;
        steps++;
        if (!pathQueue.empty()){
            int currentVertex = pathQueue.front();
            cout<<"currentVertex "<<currentVertex<< endl;
            if(currentVertex == end){
                cout<<"reach the end"<<endl;
                finalPath.push_back(currentVertex);
                return true;
            }
            else if (!adjList.count(currentVertex)) {
                cout<<"current vertex "<<currentVertex<<" has no neighbor, skip searching adj list"<<endl;
                pathQueue.pop();
                return bfs(adjList, start, end);
            }    
            else if(!visited.count(currentVertex)){
                // step 2: remove a vertex from the back (FIFO) and mark it as visited,  if all the conditions pass
                finalPath.push_back(currentVertex);
                pathQueue.pop();
                visited.emplace(currentVertex);    //mark visited
                cout<<"next Vertex to be in list: ";
                int nextVertex;
                // step 3: add neighboring vertex
                // (even the one that has visited - we only remove the back of queue out and if the back has been visisted or be marked visited)
                for (auto& vertex : adjList.at(currentVertex)){
                    if (visited.count(vertex)) {
                        cout<<vertex<<"(visited, not add to pathQueue), ";
                        continue;
                    }
                    nextVertex = vertex;
                    cout<<nextVertex<<" ";
                    pathQueue.push(nextVertex);
                    // visited.emplace(nextVertex);    //mark visited
                }
                cout<<endl;       
                return bfs(adjList, start, end);
            }
            else{
                cout<<"current vertex is visited "<<currentVertex<<endl;
                pathQueue.pop();
                return bfs(adjList, start, end);
            }         
        }   
        else return false;
    }
};
 
int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    sol.orangesRotting(grid);
    return 0;
}