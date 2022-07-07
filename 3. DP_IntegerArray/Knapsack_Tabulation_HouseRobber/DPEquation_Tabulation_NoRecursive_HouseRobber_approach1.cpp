#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int totalHouses = nums.size();
        // Step 1: special case
        if (totalHouses==0)
            return 0;
        else
        {
            // Step 2: fill up Tabulation Table/DP equation
            // since we have 2 sets of possible house to rob => get results from 2 DP equation
            int max1 = findMax(nums, 0, totalHouses);
            int max2 = findMax(nums, 1, totalHouses);
            return max(max1, max2);
        }
    }
    int findMax(vector<int>& nums, int start, int end){
        int totalHouses = nums.size();
        int MaxProfit=0;
        int lastProfit=0;
        // Step 2.1: define and solve the "sub-problem": find maxProfit received from previous house.
        for (int currentHouse = start; currentHouse <end; currentHouse++ ){
            int lastMaxProfit = MaxProfit;
            MaxProfit = max(nums[currentHouse] +  lastProfit, lastMaxProfit); //DP equation
            lastProfit=lastMaxProfit;
        }
    return MaxProfit;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {100, 50, 400, 200, 100};
    vector<int> nums = {1,3,1,1,101};
    int result = sol.rob(nums);
    cout<<"Result "<<result<<endl;
}