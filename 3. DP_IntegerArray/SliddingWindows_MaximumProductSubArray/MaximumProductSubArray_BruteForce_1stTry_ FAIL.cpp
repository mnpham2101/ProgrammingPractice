#include <vector>
using namespace std;
// Brute Force
// fail on test case [0,2] as this cannot take max product from subArray=[2]
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        for (int i =0; i < nums.size(); i++){
            int product = nums[i];                      // when else case hit => i=j and product[j+1],
                                                        // but if j+1>nums.size() max is never set to product because inner loop exits. if case doesn't run
                                                        // even when product is the max
            for (int j=i+1; j <nums.size(); j++){
                product *=nums[j];
                if (maxProduct < product){
                    maxProduct= product;
                }
                else{
                    i = j;
                    break;
                }
            }
        }
        return maxProduct;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {2,3 -2, 4};
    vector<int> nums = {0,2};                   // this TC fails

    sol.maxProduct(nums);
}