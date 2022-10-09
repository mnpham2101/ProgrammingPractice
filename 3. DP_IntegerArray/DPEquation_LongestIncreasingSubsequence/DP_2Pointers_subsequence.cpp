#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int right = 0; right < n; right++)
            for (int left = 0; left < right; left++)
                if (nums[right] > nums[left] && dp[right] < dp[left] + 1)
                    dp[right] = dp[left] + 1;
        return *max_element(dp.begin(), dp.end());
    }
};