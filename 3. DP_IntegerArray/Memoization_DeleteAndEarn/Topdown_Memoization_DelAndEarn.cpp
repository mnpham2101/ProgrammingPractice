#include<iostream>
#include<vector>
#include<unordered_map>
using namespaces std;
// top down - brute force
class Solution {
    private:
        unordered_map<int,int> occurances;  // first: item in nums, second: occurances 
        vector<int> cache;      
        int maxPoints(vector<int>&nums, int num){
            // base case
            if (num==0)
                return 0;
            if (num == 1)
                return occurances[1];
            // cache case
            if(cache[num] !=-1)             // have to use -1 otherwise a lot of value wont be cached
               return cache[num];
            // recursive case
            int gain = num * occurances[num];
            return cache[num]=max(gain + maxPoints(nums, num-2),maxPoints(nums, num-1));
        }
    public:    
    
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber=0;            // 1<nums[i]<10^4
        cache.resize(100001,-1);
        for (int num : nums){
            occurances[num]++;
            maxNumber= max(maxNumber, num);
        }
        return maxPoints(nums,maxNumber);
    }
};
