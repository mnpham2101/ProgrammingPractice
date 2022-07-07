#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size()<3) return 0;
        int left = 0;
        int right = left+2;
        while (right <= nums.size()-1){
            int diff = nums[left+1] - nums[left];
            if (nums[right]-nums[right-1] == diff){         // if it is an arithmetic slide
                right++;
                count++;
            }
            else {                                          // if it is not an arithmetic slide
                left = right -1;                            // missing TC = {1,2,3,4, 9} => subarray = {1,2,3}, {1,2,3,4}, {2,3,4}
                right = left +2;
            }
        }
        return count;
    }
};


int main(){

}