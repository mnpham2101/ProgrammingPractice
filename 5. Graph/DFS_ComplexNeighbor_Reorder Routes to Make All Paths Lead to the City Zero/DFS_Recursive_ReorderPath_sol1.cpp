#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int source = 0; 
    int destination = 1;
    vector<bool>visited;
    struct cityProp{
        int city;                                   // cityName
        int type;                                   // source or destination
    };
    
    vector<int> cityReorder;                        // cache storing number of re-ordered paths from that city to farther cities
    vector<vector<cityProp>> cityMap;               // map neighbor relations b/w cities
    int dfs(vector<vector<int>>& connections, int city){
        int count = 0;
        cout<<"city "<<city<<endl;
        visited[city] = true;
        
        // cache case:
        if (cityReorder[city] != -1){
            cout<<"cache "<<city<<" count "<< count<<endl;
            return count = cityReorder[city];
        }

        
        // normal cases: check neighbor cities, run recursive dfs
        for (int i = 0; i< cityMap[city].size(); i++){
            cityProp neighbor = cityMap[city][i];
            cout<<"     next city"<<neighbor.city<<endl;
            if (neighbor.type  == destination && visited[neighbor.city] == false){        // if the path is not toward 0, neighboring city is not a source
                cout<<"        reorder path, next city "<<neighbor.city<<" "<<endl;
                count += 1 + dfs(connections, neighbor.city);
                cityReorder[city] = count;
                cout<<"cityReorder[city] "<<cityReorder[city]<<endl;
            }
            else if (neighbor.type  == source && visited[neighbor.city] == false){
                cout<<"        dont reorder path next city "<<neighbor.city<<endl;
                cout<<count<<endl;
                count += dfs(connections, neighbor.city);
                cityReorder[city] = count;
                cout<<"city "<<city<<" cityReorder[city]="<<cityReorder[city]<<endl;
            }
        }
        // base case:
        cout<<"       last city "<<city<<endl;
        cityReorder[city] = count; 
        return count;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        cityReorder.resize(n, -1);
        cityMap.resize(n);
        visited.resize(n);
        // make a map of neighbor cities:
        for (int row = 0; row<connections.size(); row++){
            cityProp cityA, cityB;
            cityA.city = connections[row][0];
            cityB.city = connections[row][1];
            cityA.type = source;
            cityB.type = destination;
            cityMap[cityA.city].push_back(cityB);           
            cityMap[cityB.city].push_back(cityA);           
        }
        return dfs(connections, 0);   
    }
};