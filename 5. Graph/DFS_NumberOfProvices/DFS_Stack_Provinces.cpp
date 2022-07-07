# include <vector>
# include <stack>
# include <iostream>
using namespace std; 

class Solution {
private:
    stack<int> dfsStack;
    vector<bool> visited;

    int dfs(vector<vector<int>>& isConnected, int city) {
        dfsStack.push(city);    
        while (!dfsStack.empty()){
            int currentCity = dfsStack.top();
            // cout<<"currentCity "<<currentCity<<endl;
            dfsStack.pop();
            visited[currentCity] = true;
            
            // get the neighbor & push neighbor to stacks    
            for (int neighborCity = 0; neighborCity <isConnected[currentCity].size(); neighborCity++){
                if (isConnected[currentCity][neighborCity] == 1 && visited[neighborCity] == false)
                    dfsStack.push(neighborCity);
            }
        }   // dfsQueue is empty => cannot connect more cities to provice
        return 1; 
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int countProvince = 0; 
        visited.resize(isConnected.size(),false);
        for (int startingCity = 0; startingCity< isConnected.size(); startingCity++){           // every row in isConnected represents a city
            if (visited[startingCity] == false){
                // cout<<"start dfs @ city "<<city<<endl;
                countProvince += dfs(isConnected, startingCity );                    // increment countProvince if dfsQueue is empty
            }
        }
        return countProvince;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    sol.findCircleNum(isConnected);
}