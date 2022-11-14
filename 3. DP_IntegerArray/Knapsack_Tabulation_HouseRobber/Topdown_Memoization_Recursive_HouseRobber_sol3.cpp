#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> cache;
    int robFrom(int i, vector<int>& nums,vector<int>& cache){
        cout<<"I: "<<i<<endl;
        if (i >= nums.size()){
            cout<<"return nums[i]=0 "<<endl;
            return 0;
        }
        else if (cache[i] != INT_MAX){
            cout<<"I: "<<i<<" cache "<<cache[i]<<endl;
            return cache[i];
        }
        else{
            int left = robFrom(i+1,nums,cache);
            int right = robFrom(i+2,nums,cache);
            cout<<"I: "<<i<<" left: "<<left<<" right: "<<right<<endl;
            return cache[i] = max(robFrom(i+1,nums,cache), nums[i] + robFrom(i+2,nums,cache));
        }
    }

    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), INT_MAX);

        return robFrom(0,nums,cache);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 50, 400, 200, 100};
    int result = sol.rob(nums);
    cout<<"Result "<<result<<endl;
    return 0;
}