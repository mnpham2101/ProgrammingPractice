// CPP program to find all subsets by backtracking.
#include<vector>
#include<iostream>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> resultSubsetList;
    resultSubsetList.push_back({});

    for (int i = 0; i < nums.size(); i++) {
        vector<vector<int>> newSubsetList;
        for (vector<int>subset : resultSubsetList) {
            subset.push_back(nums[i]);
            newSubsetList.push_back(subset);
        }
        for (vector<int>subset : newSubsetList) {
            resultSubsetList.push_back(subset);
        }
    }

    return resultSubsetList;
}

// Driver Code.
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