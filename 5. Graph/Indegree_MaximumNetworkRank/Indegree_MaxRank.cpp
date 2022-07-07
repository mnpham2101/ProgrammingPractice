#include <iostream>
#include <vector>
#include<unordered_set>
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> indegree(n);
         for (auto city: roads) {
                int node1 = city[0];
                int node2 = city[1];
                indegree[node1].insert(node2);
                indegree[node2].insert(node1);
            }
        int maxRank=0,countRank=0;
        for(int node1=0; node1<n; node1++){
            for(int node2=node1+1; node2<n; node2++){
                countRank  =indegree[node1].size();
                countRank +=indegree[node2].size();
                if(indegree[node2].count(node1))           // if city1(node1) is also connected to city2(node2)
                    countRank--;
            maxRank = max (maxRank,countRank);
            }
        }
        return maxRank;
    }
};