// CPP program to find all subsets by backtracking.
#include<vector>
#include<iostream>
using namespace std;

// generate subset by traversing a tree-like path
void generateSubset(vector<int>& A, int index, vector<int>& subset, vector<vector<int>>& subsetList) {
    if (index == A.size()) {
        subsetList.push_back(subset);
    }
    else {
        // 1st recursive call -> after returning result, add new item to previous subset, and call the 2nd recursive
        generateSubset(A, index + 1, subset, subsetList);
        subset.push_back(A[index]);
        // 2st recursive call -> after returning result, remove item frome previous subset to prepare space for new subsets.
        generateSubset(A, index + 1, subset, subsetList);
        subset.pop_back();
    }

}

// Driver Code.
int main()
{
    // find the subsets of below vector.
    vector<int> A = { 1, 2, 3 };

    vector<int> subset;
    vector<vector<int>> subsetList;
    generateSubset(A, 0, subset, subsetList);

    // Print result
    for (int i = 0; i < subsetList.size(); i++) {
        for (int j = 0; j < subsetList[i].size(); j++)
            cout << subsetList[i][j] << " ";
        cout << endl;
    }
    return 0;
}