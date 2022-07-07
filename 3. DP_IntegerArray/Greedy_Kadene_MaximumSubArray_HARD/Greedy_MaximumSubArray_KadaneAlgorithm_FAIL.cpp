#include <vector>
using namespace std;
// Kadane Algorithm - Once the sum is negative, discard the subarray.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        for (int i = 0; i<nums.size(); i++){
            int sum=nums[i];
            if (sum>maxSum) {       // subarray could be one item, thus sumMax is first compared by one item.
                maxSum = sum;
            }
            for (int j=i+1; j<nums.size(); j++){
                sum +=nums[j];
                if (sum<0) {
                    i =j-1;        // set the subarray starting from j
                    break;       // dont count sum if sum is negative
                }
            }
        }
        return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {-2,-1};                      // subarray could be [-1] and sumMax <0
    vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};      // subarray [4,-1,2,1], fail code would run subarray from [-3,4,-1,2,1] or [4]
}

