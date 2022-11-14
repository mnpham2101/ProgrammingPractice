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
        else if (totalHouses==1)
            return nums[0];
        else{
            int maxProfit[totalHouses];
            // Step 2: base case
            maxProfit[0]= nums[0];
            maxProfit[1]= nums[1];
            // Step 3: construct tabulation table from DP equation
            for (int currentHouse = 2; currentHouse <totalHouses; currentHouse++){
                maxProfit[currentHouse] = nums[currentHouse] + findMax(maxProfit, currentHouse-1);  // DP equation
            }
            return findMax(maxProfit, totalHouses);
        }
    }

    int findMax(int maxProfit[], int TotalHouse){
        int* max = max_element (maxProfit, maxProfit + TotalHouse);
        return *max;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 50, 400, 200, 100};
    int result = sol.rob(nums);
    cout<<"Result "<<result<<endl;
}