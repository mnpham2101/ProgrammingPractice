#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = cost[0];
    dp[1] = cost[0];


    // state: the minCost at certain i-th step
    // recurrence relation: 
    // at each i-th step, the current cost is the cost taking 1 or 2 steps 
    // plus the accumulated cost from last step which is dp[i-j]
    // the minCost is the minimum of choosing taking 1 or 2 step or not taking the steps.
    for (int i = 2; i <= n; i++) {
        int minCost = INT_MAX;
        // use dynamic recurrence relation
        // can be applicable if the condition is to take up to K state.
        for (int j = 1; j <= 2 && i - j >= 0; j++) {                        
            minCost = std::min(minCost, dp[i - j] + cost[i - j]);
        }
        dp[i] = minCost;
    }

    return dp[n];
}

int main() {
    std::vector<int> cost = {10, 15, 20};
    std::cout << "Minimum cost: " << minCostClimbingStairs(cost) << std::endl;
    return 0;
}