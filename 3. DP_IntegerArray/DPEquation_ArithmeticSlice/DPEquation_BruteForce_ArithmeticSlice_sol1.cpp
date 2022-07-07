#include <vector>
using namespace std;

class Solution {
public:
    // O(N^2)
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size()<3) return 0;
        // use double for loop to create subarray
        for (int start = 0; start < nums.size() - 2; start++) {
            int diff = nums[start + 1] - nums[start];                   // different between 2 first items in subarray are calculated
            for (int end = start + 2; end < nums.size(); end++) {
                if (nums[end] - nums[end - 1] == diff)                  // compare different of remaining items in subarrays
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,2,3,4,5,6,7};
    sol.numberOfArithmeticSlices(nums);
}