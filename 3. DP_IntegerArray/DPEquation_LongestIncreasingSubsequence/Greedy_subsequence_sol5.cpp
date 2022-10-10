#include<vector>
#include<iostream>
using namespace std;
/*
Greedy solution:
- This method provides a way to keep a best sequence while we iterative over the array
- Starting case: The best sequence when i = 0 is nums[0]
- If we have a current best sequence and we meet a new val:
  (1) if val > all elements, can easily add it into the tail
  (2) if not, can replace lower_bound of val in the sequence by val because:
     + it doesn't change the current result and all next result (e.g 2 9 10 14 and 2 4 10 14, no matter what the next numbers are)
     + it is always better way to find an optimal sequence, because we reduce the condition for (1) as much as possible
*/

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