#include <vector>
#include <algorithm>
using namespace std;

// Sliding Windows + Two Pointers
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalNumberOfOnes=0;
        int currNumberOfSwap= 0;
        int maxNumberOfOnes = 0;
        int minSwap = INT_MAX;
        //Step 1:
        for (int i = 0; i<data.size(); i++){
            totalNumberOfOnes += data[i];           // maxWindowSize = totalNumberOfOnes
        }
        int currNumberOfOnes = 0;
        int maxOnesInWindows = 0;
        int left = 0, right =0;                     // two-pointers are left and right border
        // Step 2: create windows and slide windows toward the right
        for (right=0; right< data.size(); right++){
            currNumberOfOnes +=data[right];
            if (right >= totalNumberOfOnes){        // if right > maxWindowSize then shift the left border and update count
                left = right-totalNumberOfOnes;         // shift left border
                currNumberOfOnes -= data[left];      // update currNumberOfOnes by subtracting the `1` at data[left]
            }
        // Step 3: update the condition
            maxNumberOfOnes = max(maxNumberOfOnes, currNumberOfOnes);
        }
        minSwap = totalNumberOfOnes - maxNumberOfOnes;
        return minSwap;
    }
};

int main(){
    Solution sol;
    vector<int> data = {1,0,0,1,1,1};
    sol.minSwaps(data);
    return 0;
}