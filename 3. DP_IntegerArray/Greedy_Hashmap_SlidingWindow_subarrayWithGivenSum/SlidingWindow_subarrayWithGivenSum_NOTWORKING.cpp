#include<vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int count = 0;
        int left=0, right=0;
        int sum=nums[right];
        while(right<nums.size() -1){
            if (sum<K){
                right++;                // expand sliding windows
                sum += nums[right];     // new cumulative sum for next iteration
            }
            else if (sum>K){
                sum -= nums[left];      // adjust cumulative sum
                left++;                 // move left to shrink slidingWindow
            }
            else if (sum == K){
                count++;
                right++;
                sum += nums[right];     // new cumulative sum for next iteration
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {3,4,7,2,-3,1,4,2}; int k=7;
    // vector<int>nums = {1,1,1}; int k=2;
    // vector<int>nums = {0,0}; int k=0;         // corner case 3: subarrays are {0}, {0,0}, and {0} in the last 0
    // vector<int>nums = {1,-1,0}; int k=0;         // corner case 2: subarrays are {1,-1}, {1,-1,0}, {0}
    // vector<int>nums = {1,2,3}; int k=3;          // corner case 1
    sol.subarraySum(nums,k);
}