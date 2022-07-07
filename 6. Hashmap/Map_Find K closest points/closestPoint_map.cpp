
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        double x, y;
        vector<vector<int>> closestPointList;
        multimap<int, vector<int>> pointDistanceMap;
        for (auto point : points){
            x=point[0];
            y=point[1];
            double distance = pow(x,2) + pow(y,2);
            pointDistanceMap.insert({distance, point});
        }
        // log
        // for (auto iterator = pointDistanceMap.begin(); iterator != pointDistanceMap.end(); ++iterator){
        //     cout<<"point : "<<iterator->second[0]<<" "<<iterator->second[1]<<" distance: "<<iterator->first<<endl;
        // }

        int count =1;
        // typedef multimap<int, vector<int>>::iterator it;
        auto it = pointDistanceMap.begin();
        while (count <= k){
            closestPointList.push_back(it->second);
            it++;
            count++;
        }
        // log
        for (auto item : closestPointList){
            cout<<"point : "<<item[0]<<" "<<item[1]<<endl;
        }

        return closestPointList;
    }
};

int main () {
    Solution sol;
    vector<vector<int>> points = {{-5,4},{-6,-5},{4,6}};
    sol.kClosest(points, 2);
}