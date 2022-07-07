#include<vector>
#include<map>
using namespace std;

// hashmap - O(N*logN)
class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        int count = 0;
        map<int, int> sum_occurance;
        sum_occurance.insert({0,1});
        int cumulativeSum=0;
        // create subarray
        for (int i = 0; i < nums.size(); i++){          // start of sub array
            cumulativeSum += nums[i];

            if ( sum_occurance.count(cumulativeSum - K)==1){
                count += sum_occurance[cumulativeSum - K];
            }
            // add up the occurance after count is already calculated!
            sum_occurance [cumulativeSum]++;            // O(logN)
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