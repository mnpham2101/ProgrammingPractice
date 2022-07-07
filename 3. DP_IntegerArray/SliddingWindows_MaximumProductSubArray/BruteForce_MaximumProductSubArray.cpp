#include <vector>
using namespace std;
// Brute Force
// consider product as accumulated from index 0
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];

        for (int i = 0; i < nums.size(); i++){
            int product = 1;
            for (int j=i; j <nums.size(); j++){
                product *= nums[j];
                if (maxProduct <product){
                    maxProduct= product;
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
    sol.maxProduct(nums);
}