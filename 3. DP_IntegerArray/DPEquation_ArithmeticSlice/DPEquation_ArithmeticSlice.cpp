#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size()<3)                  // corner case
            return 0;
        vector<int>dp(nums.size());
        dp[0]=0;
        dp[1]=0;
        for (int i = 2; i<nums.size(); i++){
            if (nums[i-1]-nums[i-2] == nums[i]-nums[i-1])
            dp[i] = 1+ dp[i-1];
            count += dp[i];
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,6,3,2,1,1,1};
    vector<int> nums = {0};
    Solution sol;
    sol.numberOfArithmeticSlices(nums);
}