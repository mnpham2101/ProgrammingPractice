#include <vector>
using namespace std;
// Kadane Algorithm - Once the sum is negative, discard the subarray.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        for (int i = 0; i<nums.size(); i++){
            int sum=0;
            for (int j=i; j<nums.size(); j++){
                sum +=nums[j];
                if (sum>maxSum) {
                    maxSum = sum;       //maxSum could still be negative
                }
                if (sum<0) {
                    i =j;        // set the subarray starting from j
                    break;       // dont count sum if sum is negative
                }
            }
        }
        return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {-2,-1};
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
