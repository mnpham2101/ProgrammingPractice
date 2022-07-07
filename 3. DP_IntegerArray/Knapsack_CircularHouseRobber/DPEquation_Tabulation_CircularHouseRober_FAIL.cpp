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
        {   // Step 2: fill up Tabulation Table/DP equation
            int max1 = findMax(nums, 0, totalHouses);
            int max2 = findMax(nums, 1, totalHouses);
            return max(max1, max2);
        }
    }
    int findMax(vector<int>& nums, int start, int end){
        int totalHouses = nums.size();
        vector<int> maxProfit(totalHouses);
        int t1=0;
        int t2=0;
        for (int currentHouse = start; currentHouse<end; currentHouse= currentHouse+2){   
            // Step 2.1: define and solve the "sub-problem": find maxProfit received from previous house.
            maxProfit[currentHouse] = nums[currentHouse]+t1;          //this DP Equation won't sufficient for case [2,7,9,3,4,10]                  
            t1 = maxProfit[currentHouse];
        }
    return *max_element(maxProfit.begin(), maxProfit.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,9,3,4,10};
    // vector<int> nums = {100, 50, 400, 200, 100};
    vector<int> nums = {1,3,1,1,101};
    int result = sol.rob(nums);
    cout<<"Result "<<result<<endl;
}