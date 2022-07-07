#include<vector>
using namespace std;

class Solution {
public:

    // Note: subarray includes items from array with continuous indexes
    // Single item of array is also a subarray itself
    // the following codes have bugs:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            int sum=nums[i];
            if (sum == k){          // corner case 1:  if a single item is already K
                count++;
                continue;
            }
            for (int j = i+1; j<nums.size(); j++){
                sum += nums[j];
                if (sum == k){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {1,1,1}; int k=2;
    // vector<int>nums = {0,0}; int k=0;         // corner case 3: subarrays are {0}, {0,0}, and {0} in the last 0
    // vector<int>nums = {1,-1,0}; int k=0;         // corner case 2: subarrays are {1,-1}, {1,-1,0}, {0}
    // vector<int>nums = {1,2,3}; int k=3;          // corner case 1
    sol.subarraySum(nums,k);
}