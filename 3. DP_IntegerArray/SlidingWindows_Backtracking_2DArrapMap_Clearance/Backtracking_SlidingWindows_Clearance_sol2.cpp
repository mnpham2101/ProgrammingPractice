#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N = 0;      // product number
    int M = 0;      // product type
    vector<int>nums;                                // original product arrangement
    unordered_map<int, int> productOccurance;

    vector<int> permutationOfProductType;
    unordered_map<int, bool> productTypeMark;

    int minSwap = INT_MAX;

    void Input() {
        cin >> N >> M;
        nums.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            productOccurance[nums[i]]++;
        }
    }

    // partition the nums into subArrays
    // the goal is set each subArray have only 1 productType such as [1 1 1], [2 2 2 2]
    // the max size of the subArray is number of occurance of each productType
    // sliding window increase from 0 to max size => up date the number of swap needed to get the subArray of only 1 productType.
    int calculateSwap() {
        int swap = 0;
        int right = 0, left = 0;                         // two-pointers are left and right border of subArray
        // productType for the subArray is from the permutation
        for (int productType : permutationOfProductType) {
            // Step 1: set max windowSize of each subArray of productType
            int windowSize = productOccurance[productType];
            int currNumberOfProductType = 0;

            // Step 2: create subArray and slide subArray toward the right
            // increase subArray's window size until max size, update currNumberOfProductType in subArray
            while (right - left + 1 <= windowSize) {
                if (nums[right] == productType) {
                    currNumberOfProductType++;
                }
                if (right - left + 1 == windowSize) {                   // subArray size is maxSize
                   // Step 3: calculate the number of swap needed to make current subArray have the same product type
                    swap += (windowSize - currNumberOfProductType);
                    // update border for next windowSize
                    left = right + 1;
                    right = right + 1;
                    break;                               // go to next productType, and next subArray
                }
                right++;
            }
        }
        return swap;
    }

    void backtracking(int index) {
        // base case: at the lowest level of permutation tree, the index is equal to number of product type M
        if (index == M) {
            int swap = calculateSwap();        // when a permutation of product config is returned, calculate the number of swaps needed to get this permutation
            minSwap = min(minSwap, swap);
            return;
        }
        // recursive case: create a permutation tree
        // index indicates the level of permutation tree and the position of the candidate (productType) in the permutation
        //
        for (int productType = 1; productType <= M; productType++) {
            if (productTypeMark[productType] != true) {
                productTypeMark[productType] = true;
                permutationOfProductType[index] = productType;
                backtracking(index + 1);
                productTypeMark[productType] = false;
            }
        }
    }

    void Solve() {
        // mark all the product type as false to use on backtracking algorithm
        for (int productType = 1; productType <= N; productType++) {
            productTypeMark[productType] = false;
        }
        // each permutation of product type has the size equal to number of product type
        permutationOfProductType.resize(M);
        // create permutation for product types group. There are M product types.
        // for each permutation, count the swap
        backtracking(0);
    }

    void Output() {
        cout << minSwap << endl;
    }
};

int main() {
    Solution sol;
    sol.Input();
    sol.Solve();
    sol.Output();
}