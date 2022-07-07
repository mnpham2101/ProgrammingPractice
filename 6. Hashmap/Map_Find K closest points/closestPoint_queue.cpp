#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         //Answer vector
        vector<vector<int>> result(k);
        //maxheap storage initialization
        priority_queue<vector<int>> maxHeap;
        //Construction of maxheap
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        for (int i = 0; i < maxHeap.size(); ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }

        return result;
    }
};

int main () {
    Solution sol;
    vector<vector<int>> points = {{-5,4},{-6,-5},{4,6}};
    sol.kClosest(points, 3);
}