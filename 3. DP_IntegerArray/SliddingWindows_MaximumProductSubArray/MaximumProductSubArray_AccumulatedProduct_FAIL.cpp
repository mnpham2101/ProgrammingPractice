#include <vector>
using namespace std;
// this approach make use that the product will accumulate from left to right.
// if the product is negative, keep multiplyfing to the next item in nums, it may goes positive
// the product is compared with saved maxProduct
// Reason for failure: there is not enough comparisons to make final results.
// The maxProduct may comes from a subArray that starts from the middle of nums.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int product = 1;
        for (int i = 0; i < nums.size(); i++){
                product *= nums[i];
            // fails to compare maxproduct with nums[i] and keep maxProduct = product = num[i]
            // there is not enough comparison to make final result
            if (maxProduct < product){
                maxProduct = product;
            }
            if (maxProduct < nums[i]){
                maxProduct = nums[i];
            }
            else if (product == 0){
                product = 1;
            }
        }
        return maxProduct;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {0,2};
    // vector<int> nums = {2,3 -2, 4};
    // vector<int> nums = {-2,3,-4};
    // vector<int> nums = {3,-1,4};
    vector<int> nums = {2,-5,-2,-4,3};      // this TC fails
    sol.maxProduct(nums);
}