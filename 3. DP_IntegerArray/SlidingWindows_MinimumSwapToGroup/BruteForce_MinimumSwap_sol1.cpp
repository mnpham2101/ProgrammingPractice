#include <vector>
#include <algorithm>
using namespace std;

// Brute Force
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalNumberOfOnes=0;

        int currNumberOfSwap;
        int minSwap = INT_MAX;
        // count the total number of 1, set it at the max size for subArray.
        for (int i = 0; i<data.size(); i++){
            totalNumberOfOnes += data[i];
        }
        // create every subArray of size = totalNumberOfOnes
        for (int i = 0; i <= data.size() - totalNumberOfOnes; i++){             // condition equal is needed. Test Case: 1 0 0 1 1 1
            int currNumberOfOnes=0;
            // loop through every items in subArray count the number of 1 in the subarray
            for (int j = i; j < i + totalNumberOfOnes; j++){                    // condition equal is NOT needed
                currNumberOfOnes += data[j];            // add up  if data[i] == 1
            }
            // calculate number of swaps
            currNumberOfSwap = totalNumberOfOnes - currNumberOfOnes;
            minSwap = min(minSwap, currNumberOfSwap );
        }
        return minSwap;
    }
};

int main(){
    Solution sol;
    vector<int> data = {1,0,0,1,1,1};
    sol.minSwaps(data);
    return 0;
}