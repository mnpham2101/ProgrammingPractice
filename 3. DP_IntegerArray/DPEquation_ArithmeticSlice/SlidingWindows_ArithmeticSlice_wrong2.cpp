#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        if (nums.size()<3) return 0;                                        // corner case 1 TC={0}
        int left = 0;
        int right = left+2;
        int anchor = 0;
        while (right <= nums.size()){
            if (right == nums.size() && right - left -1 >=3){               // corner case 3: TC={1,2,3,4}, answ {1,2,3}, {1,2,3,4} and {2,3,4}
                left++;
                right = nums.size()-1;
            }
            else if ((right != nums.size() && (right - left +1 >=3))){
                int diff = nums[left+1] - nums[left];
                if (nums[right]-nums[right-1] == diff){
                    count++;
                    anchor = right;
                    right++;
                }
                else if (nums[right]-nums[right-1] != diff && left + 1 <= anchor-2){
                    right = anchor;
                    left++;
                }
                else {                                                      // corner case 3: TC={1,2,3,4,6}, answ {1,2,3}, {1,2,3,4} and {2,3,4}
                    left++;
                    right++;
                    anchor = right;
                }
            }
            else
                break;                      // missing corner case 4: TC={1,2,3,4,5,6}
                                            // {2,3,4,5} ,{2,3,4} can't be covered
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,6,3,2,1,1,1};
    vector<int> nums = {0};
    Solution sol;
    sol.numberOfArithmeticSlices(nums);
}