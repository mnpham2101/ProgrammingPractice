#include<vector>
#include<iostream>
using namespace std;

int lengthOfLISGreedy(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> bestArr;
    bestArr.push_back(nums[0]);

    for (int i = 1; i < n; ++i) {
        auto it = lower_bound(bestArr.begin(), bestArr.end(), nums[i]);

        if (it == bestArr.end()) bestArr.push_back(nums[i]);
        else *it = nums[i];
    }

    return bestArr.size();
}

int main() {
    vector<int> test = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLISGreedy(test) << endl;
    
    return 0;
}