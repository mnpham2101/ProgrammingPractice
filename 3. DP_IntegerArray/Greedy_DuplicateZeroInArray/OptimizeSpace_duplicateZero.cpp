/*
instead of creating a vector and pushback while looping throught the input array, we can perform in-place. 
1) loop through the array, if zero is found
    shift the subarray from the index to the right by looping backward!!!
    time complexity is O(n)
*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                // Shift elements to the right
                for (int j = n - 1; j > i; --j) {
                    arr[j] = arr[j - 1];
                }
                // Duplicate the zero
                if (i + 1 < n) {
                    arr[i + 1] = 0;
                }
                // Skip the next element as it's already processed
                ++i;
            }
        }
    }
};
