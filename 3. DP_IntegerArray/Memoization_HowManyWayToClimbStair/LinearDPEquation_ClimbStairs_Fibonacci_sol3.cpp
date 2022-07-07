#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Fibonacci approach - DP equations
class Solution {
    public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;                    // 2 ways to reach 2nd step: 1 step + 1 step or 2 step
        for (int step = 3; step <=n; step++){
            dp[step]=dp[step-1]+dp[step-2];
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    int result = sol.climbStairs(5);
    cout<<"Result "<<result<<endl;
}