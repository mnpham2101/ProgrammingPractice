#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()+1;
        vector<int> dp(n,0);

        for(int i=1; i<n; i++){
            if(i==1)
                dp[i] = nums[i-1];
            else{
                dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 50, 400, 200, 100};
    int result = sol.rob(nums);
    cout<<"Result "<<result<<endl;
    return 0;
}
