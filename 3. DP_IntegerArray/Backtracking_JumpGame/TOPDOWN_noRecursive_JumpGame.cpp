#include <vector>

// Topdown solution with No recursive
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int goodPosition = nums.size() - 1;

        for (int position = nums.size()-2; position >= 0; position--){ // starting from index next to the last index
            for (int jump = 1; jump <= nums[position]; jump ++){
                if (position + jump == goodPosition) {
                    goodPosition = position;
                    break;
                }
            }
        } 
        if (goodPosition == 0) return true; 
        else return false;
    }
};

int main(){
    Solution sol; 
    vector<int>nums = {0};
    // vector<int>nums = {0, 1,2,3}
    // vector<int>nums = {1,0,1,0};  
    // vector<int>nums = {2,0};
    // vector<int>nums = {2,3,1,1,4};
    // vector<int>nums = {3,2,1,0,4};
    // vector<int>nums = {5,4,0,2,0,1,0,1,0};
    sol.canJump(nums);
}