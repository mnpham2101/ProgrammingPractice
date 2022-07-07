#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int max = nums[0];
        vector <int> result(k);
        copy(nums.begin(), nums.begin()+k, result.begin());

        for (int i = 0; i <= nums.size()-k; i++){         // the right-most subarray has index = size -k
            if (nums[i]> max) {
                max = nums[i];
                // result.clear();                         // bug: clear reset the array to size 0 and copy won't work
                auto start = nums.begin()+i;
                auto end = nums.begin()+i+k;
                copy(start, end, result.begin());
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector <int> nums = { 1,4,5,2,3};
    sol.largestSubarray(nums, 3);
    return 0;
}