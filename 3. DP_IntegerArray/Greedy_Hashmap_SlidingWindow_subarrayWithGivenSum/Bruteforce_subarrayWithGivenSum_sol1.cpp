#include<vector>
using namespace std;

class Solution {
public:
    //Note: subarray includes items from array with continuous indexes
    //Single item of array is also a subarray itself
    // O (O^3)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        // create subarray
        for (int start = 0; start < nums.size(); start++){          // start of sub array
            for (int end = start+1; end <= nums.size(); end++){           // end of sub array
                int sum=0;
                for (int j = start; j<end; j++){                    // loop through subarray
                    sum += nums[j];
                }
                if (sum == k){
                    count++;
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