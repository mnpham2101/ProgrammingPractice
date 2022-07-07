#include<vector>

using namespace std;

// prefixed Sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int count = 0;
        vector<int> prefixSum(nums.size()+1);
        prefixSum[0]=0;
        for (int i =1; i<prefixSum.size(); i++){
            prefixSum[i]=prefixSum[i-1]+nums[i-1] ;     // nums[i-1] because nums[0]=aValue; prefixSum[1] = nums[0]
        }
        // double for loop creates subarray start -> end
        // sum of subarray = prefixSum -nums[start]
        for (int start = 0; start < nums.size(); start++){
            for (int end = start+1; end <= nums.size(); end++){     // condition end=nums.size() is needed b/c of size prefixSum = nums.size+1
                if ((prefixSum[end]-prefixSum[start]) == K)
                count++;
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