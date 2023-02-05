#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using DP relation equation.
class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top = cost.size();
        // state: minCost or total cost at certain steps
        // state variable: the current step and the cost of taking such step
        int minCost[top+1];
        // base case
        minCost[0]=0;
        minCost[1]=0;
        for (int step = 2; step <= top; step++){
            // recurrence relation
            int takeOneStep = minCost[step-1]+ cost[step-1];
            int takeTwoStep = minCost[step-2]+ cost[step-2];        
            minCost[step]=min(takeOneStep, takeTwoStep);            
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