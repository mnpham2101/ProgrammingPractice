#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int length = nums.size();
        int result = 0;
        if (length <3) return 0;
        // make airithmetic subarray from left to right
        int right = nums[1];
        int left = nums[0];
        int dif = right - left;
        for (int i = 2; i< length; i++){
            right = nums[i];
            if ((right - left) == i*dif) {
                result++;
            }
            else {
                left = nums[i-1];
                dif = right - left;
            }
        }

        // make arithmetic subarray from right to left
        int start = length-1;
        right = nums[start];
        left = nums[start-1];
        dif = left - right;
        for (int i = length-3; i>0; i--){
            left = nums[i];
            int interval = start-i;
            if ((left - right) == interval*dif) {
                result++;
            }
            else {
                right = nums[i+1];
                dif = left - right;
            }
        }
        return result;          // TC = {1,2,3,4,5,6} fails
    }
};

int main(){

}