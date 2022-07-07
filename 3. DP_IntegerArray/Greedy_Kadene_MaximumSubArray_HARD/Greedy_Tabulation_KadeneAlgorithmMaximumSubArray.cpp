#include <vector>
using namespace std;
// Kadane Algorithm - Once the sum is positive, continue adding up the sum, otherwise reset.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int sum=nums[0];
        for (int i = 1 ; i<nums.size(); i++){
            // sum = max(nums[i], sum+nums[i]);
            if (sum>0)                //same as if (nums[i]<sum[0]+nums[i])
                sum += nums[i];
            else
                sum = nums[i];
            if (sum>maxSum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};

/* Second implementation
*/

// Kadane Algorithm - Once the sum is negative, discard the subarray.
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int sum=nums[0];
        for (int i = 1 ; i<nums.size(); i++){
            if (sum<0) {
                sum=nums[i];        // set the subarray starting from i
            }
            else
                sum +=nums[i];
            if (sum>maxSum) {
                maxSum = sum;
            }
        }
        return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int>nums1 = {-2,-1};                      // subarray could be [-1] and sumMax <0
    vector<int>nums2 = {-2,1,-3,4,-1,2,1,-5,4};      // subarray [4,-1,2,1], fail code would run subarray from [-3,4,-1,2,1] or [4]
}