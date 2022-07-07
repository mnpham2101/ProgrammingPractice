#include <vector>
using namespace std;

// Bottom Up solution with recursive
class Solution {
    public:
    int goodPosition;
    int leftIndex;
    bool canJump(vector<int>& nums) {
        goodPosition = nums.size() - 1;
        leftIndex = goodPosition - 1;
        return canJumpFromPosition(leftIndex,nums);
    }
    bool canJumpFromPosition(int position, vector<int>& nums ){
        if (goodPosition == 0) return true;
        if (position <0) return false;
        else{
            for (int jump = 1; jump <= nums[position]; jump ++){
                if (position + jump == goodPosition) {
                    goodPosition = position;
                    leftIndex = position - 1;
                    return canJumpFromPosition(leftIndex, nums);
                }
            }
            leftIndex = position - 1;
            return canJumpFromPosition(leftIndex, nums);
        }
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