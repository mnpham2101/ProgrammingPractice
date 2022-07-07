#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // create vector nums that contains n values from 1->n
        vector<int> nums(n);
        nums[0]=1;
        // create factorial part of Permutation number:
        vector<int> factorials(n);
        factorials[0]=1;
        for(int i = 1; i < n; ++i) {
            // generate factorial system bases 0!, 1!, ..., (n - 1)!
            factorials[i] = factorials[i - 1] * i;
            // generate vector nums; the permutation is of the vector nums
            nums[i]=i+1;
        }
        // delete -1 from K: for example: 3rd K is K = 2
        k--;
        // permutation result
        string permutationAtKthOrder;
        // compute factorial representation of K
        for (int i= n-1; i>=0; i-- ){
            // Step 1: calculate K_Coefficient from Kth order value
            int K_Coeff = k / factorials[i];
            k -= K_Coeff * factorials[i];
            // Step 2: add the element of nums, at the index = K_Coefficient to the permutation string
            permutationAtKthOrder.append(to_string(nums[K_Coeff]));
            // Step 3: remove the element of nums, at the index = K_Coefficient
            nums.erase(next(nums.begin()+K_Coeff-1));      // has to subtract 1 to compensate the value at nums.begin()
        }
        return permutationAtKthOrder;
    }
};

int main(){
    Solution sol;
    int n=3, k=3;
    sol.getPermutation(n, k);
}