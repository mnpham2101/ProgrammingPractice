// CPP program to find all subsets by backtracking.
#include<vector>
#include<iostream>
using namespace std;

// backtracking by length
void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int& length, int startIndex) {
    if (subset.size() == length) {
        result.push_back(subset);
        return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        // Step 1: add item to subset
        subset.push_back(nums[i]);
        // Step 2: continue to add item from i=startIndex+1 to subset until subset of lenght is filled
        // i+1 is needed because it is like a double for loop, for every item from startIndex, add to subset until subset is filled
        backtrack(nums, result, subset, length, i + 1);
        // Step 3: backtrack
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int>subset;
    int startIndex = 0;
    for (int length = 0; length <= nums.size(); length++) {
        backtrack(nums, result, subset, length, startIndex);

    }

    return result;
}

int main()
{
    // find the subsets of below vector.
    vector<int> A = { 1,2,3 };
    vector<vector<int>> subsetList;

    subsetList = subsets(A);

    // Print result
    for (int i = 0; i < subsetList.size(); i++) {
        for (int j = 0; j < subsetList[i].size(); j++)
            cout << subsetList[i][j] << " ";
        cout << endl;
    }

    return 0;
}