#include <vector>

// Brute Force
// consider product as accumulated from index 0
// the following is WRONG APPROACH
/*if the accumulation product is less the previous product, don't continue the inner for loop, 
 but reset the subarray
 compare product to maxProduct to get maxProduct  */
// it fails because -2*3 decrease accumulatedProduct, but -2*3*(-4) would increase the accumulatedProduct

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];    
        for (int i = 0; i < nums.size(); i++){     
            int product = nums[i];
            if (maxProduct <product){                       // this check supports case [0,2] 
                maxProduct= product;
            }
            for (int j=i+1; j <nums.size(); j++){
                if (product > product *nums[j]){
                    i=j;
                    break;
                }
                else {
                    product *= nums[j];                     // this check supports case [2,3 -2, 4] 
                    if (maxProduct <product){           
                        maxProduct= product;
                    }
                }
            }
        }
        return maxProduct;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,2};               
    vector<int> nums = {2,3 -2, 4};
    vector<int> nums = {-2,3,-4}                // this case fails because -2*3 decrease accumulatedProduct, but -2*3*(-4) would increase the accumulatedProduct
    sol.maxProduct(nums);
}