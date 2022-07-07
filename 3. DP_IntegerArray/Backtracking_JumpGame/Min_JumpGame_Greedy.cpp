class Solution {
public:
    int jump(vector<int>& nums) {
        int counter = 0, farthest =0, currentJumpEnd=0;
        for (int currentPosition = 0; currentPosition < nums.size()-1; currentPosition++){
            int maxJumpFromCurrentPosition = currentPosition + nums[currentPosition];
            farthest = max (maxJumpFromCurrentPosition, farthest);
            if (currentPosition == currentJumpEnd){
                counter++;
                currentJumpEnd =farthest ;
            }
        }
        return counter;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    sol.jump(nums);
}