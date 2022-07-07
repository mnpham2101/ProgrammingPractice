#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];               // store max positive product
        int min_so_far = nums[0];               // stores min negative product
        int result = max_so_far;
        for (int i = 1; i < nums.size(); i++){
            int current = nums[i];
            int currentProduct = max (max_so_far*current, min_so_far*current);
            int tmp = max (current, currentProduct);
            min_so_far = min (current, min (min_so_far*current, max_so_far*current));
            max_so_far = tmp;
            result = max (max_so_far, result);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,2};
    vector<int> nums = {2,3 -2, 4};
    vector<int> nums = {-2,3,-4};
    vector<int> nums = {3,-1,4};
    vector<int> nums = {2,-5,-2,-4,3};
    sol.maxProduct(nums);
}