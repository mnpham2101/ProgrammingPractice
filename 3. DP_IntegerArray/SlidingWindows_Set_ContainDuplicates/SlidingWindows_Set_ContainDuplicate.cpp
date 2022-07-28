#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<int> values;
        
        //sliding window
        for(int i=0;i<nums.size();i++)
        {
            auto upper = values.upper_bound(nums[i]); //find greater value
            if(upper != values.end() && abs((long)nums[i] - *(upper)) <= t)
                return true;
            
            auto lower = values.lower_bound(nums[i]); //find smaller or equal value
            if(lower != values.end() && nums[i] == *(lower)) //return true if found equal value
                return true;
            if(lower != values.begin() && abs((long)nums[i] - *(--lower)) <= t) 
                return true;
            
            //Update sliding window
            if(i-k >= 0)
                values.erase(nums[i-k]); 
            
            if(k >= 1)
                values.insert(nums[i]);
        }
        
        return false;
    }
};