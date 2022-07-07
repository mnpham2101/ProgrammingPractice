#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int prod=1;


        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
            ans=max(ans,prod);

            if(prod==0) prod=1;
        }

        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod=prod*nums[i];
            ans=max(prod,ans);

            if(prod==0) prod=1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {0,2};
    // vector<int> nums = {2,3 -2, 4};
    // vector<int> nums = {-2,3,-4};
    // vector<int> nums = {3,-1,4};
    vector<int> nums = {2,-5,-2,-4,3};      // this TC fails
    sol.maxProduct(nums);
}