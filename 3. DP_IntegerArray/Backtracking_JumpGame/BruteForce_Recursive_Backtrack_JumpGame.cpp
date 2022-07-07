// Brute Force solution
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0,nums);
    }
    bool canJumpFromPosition(int position, vector<int>& nums ){
        if (position == nums.size() -1){
            return true;
        }
        int a = position + nums[position];
        int b = nums.size() - 1;
        int furthestJump = min(a,b);
        // for (int nextPosition = position+1; nextPosition <= furthestJump; nextPosition++){
        for (int nextPosition = furthestJump; nextPosition > position; nextPosition--){
            if(canJumpFromPosition(nextPosition, nums) == true) return true;
        }
        return false;
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