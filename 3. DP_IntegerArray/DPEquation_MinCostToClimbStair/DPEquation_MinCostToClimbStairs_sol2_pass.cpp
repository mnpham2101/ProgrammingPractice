#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using DP relation equation.
class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        int minCost[top+1];
        minCost[0]=0;
        minCost[1]=0;
        for (int step = 2; step <= top; step++){
            int takeOneStep = minCost[step-1]+ cost[step-1];
            int takeTwoStep = minCost[step-2]+ cost[step-2];
            minCost[step]=min(takeOneStep, takeTwoStep);            // DP relation equation.
        }
        return minCost[top];
    }
};

int main() {
    Solution sol;
    vector<int> cost = {1,100,2,100,4};
    int result = sol.minCostClimbingStairs(cost);
    cout<<"Result "<<result<<endl;
}