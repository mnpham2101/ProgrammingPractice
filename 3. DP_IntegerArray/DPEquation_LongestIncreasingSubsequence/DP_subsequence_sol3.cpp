#include<vector>
#include<iostream>
using namespace std;
/*
dp solution
Observe: 
- The answer for subarray of size i is dp[i]
dp[i] = the max answer of all dp[j] that j < i and nums[j] < nums[i]
*/

int lengthOfLISDP(vector<int>& nums) {
    vector<int> dp (nums.size(), -1);
    int n = nums.size();
    int ans = 0;

    for(int i = 0; i < nums.size(); ++i) {
        int maxLen = 0;
        for(int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) 
                maxLen = max(maxLen, dp[j]);
        }
        dp[i] = maxLen + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    vector<int> test = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << lengthOfLISDP(test) << endl;
    
    return 0;
}