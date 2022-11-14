#include<iostream>
#include<vector>
using namespaces std;
// top down - brute force - no memoization
class Solution {
    private:
        unordered_map<int,int> occurances;  // first: item in nums, second: occurances
        int maxPoints(vector<int>&nums, int num){
            cout<<"Num: "<<num<<" ";
            // base case
            if (num==0)
                return 0;
            if (num == 1)
                return occurances[1];
            // cache case
            // recursive case
            int gain = num * occurances[num];
            cout<<"gain "<<gain<<endl;
            int score1 = gain + maxPoints(nums, num-2);
            int score2 = maxPoints(nums, num-1);
            int score = max(score1,score2 );
            cout<<"score "<<score1<<" "<<score2<<" "<<score<<endl;
            return score;
        }
    public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber=0;            // 1<nums[i]<10^4
        for (int num : nums){
            occurances[num]++;
            maxNumber= max(maxNumber, num);
        }
        return maxPoints(nums,maxNumber);
    }
};