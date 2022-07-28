#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i< nums.size(); i++){
            for (int j = i+1; j< nums.size(); j++){
                long long tmp1 = nums[i];
                long long tmp2 = nums[j];
                if (abs(tmp1-tmp2)<=t && abs(j-i) <=k){
                    return true;
                }
            }
        }
        return false;
    }
};

