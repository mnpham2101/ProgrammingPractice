#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
Rescursive solution:
We must find all increasing subsequences and choose the longest one.
To find all increasing subsequences:
- For each position in the array, we have 2 option: (1) add the element into current subsequences and (2) ignore. For (1) the element must be strictly larger than the last element of current subsequence
- So for each position, tree decision splits into 2 branches. We can caculate easily with rescursive implemetation.
*/

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