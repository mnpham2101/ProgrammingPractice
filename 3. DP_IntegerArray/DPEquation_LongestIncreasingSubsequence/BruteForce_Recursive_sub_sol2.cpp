#include <bits/stdc++.h>
#include <vector>
using namespace std;



int solve(vector<int>& nums, int idx, int val) {
    /* Base case */
    if (idx == nums.size()) return 0;
    
    int ans = 0;
    /* if the last value < current value, both (1) and (2) are possible */
    if (val < nums[idx]) {
        ans = std::max(solve(nums, idx + 1, val), 1 + solve(nums, idx + 1, nums[idx]));
    }
    /* else, can not add the current element into subsequence */
    else {
        ans = solve(nums, idx + 1, val);
    }
    
    return ans;
}

int lengthOfLISBruteForce(vector<int>& nums) {
    /* the 2nd param is the starting index, the 3rd param is the value of the last element in the current subsequence */
    return solve(nums, 0, INT_MIN);
}

int main() {
    vector<int> test = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << lengthOfLISBruteForce(test) << endl;
    
    return 0;
}