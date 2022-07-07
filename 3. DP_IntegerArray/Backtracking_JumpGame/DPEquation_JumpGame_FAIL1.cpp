#include <iostream>
using namespace std;


/*** this solution fail because it keeps couting nextIndex 
which would certain becomes endingIndex for case such as {1,0,1,0}  ***/
class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int lastIndex = nums.size()-1;
        if (lastIndex == 0) return true;
        if (nums[0] ==0) return false;
        for (int i = 0; i<lastIndex; i++){
            int nextIndex=0;
            for (int j=0; j<=nums[i]; j++){
                nextIndex = i+j;
                if (nextIndex == lastIndex) return true; 
            }
        }
        return false;
    }
};

int main(){
    Solution sol; 
    // vector<int>nums = {0};
    // vector<int>nums = {0, 1,2,3}
    vector<int>nums = {1,0,1,0}   // fail case
    sol.canJump();
}