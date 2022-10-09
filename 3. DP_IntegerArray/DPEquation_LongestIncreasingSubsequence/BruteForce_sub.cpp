#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution { // 256 ms, faster than 42.84%
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int result=1;
        vector<int> dp(n, 1);
        // right of subsequence
        for (int right = 0; right < n; right++){
            // left of subsequence
            for (int left = 0; left <= right; left++){
                cout<<"** subsequence start at value: "<<nums[left]<<" end at value: "<<nums[right]<<" position "<<right<<" **"<<endl;
                int length=0;
                int largestInSubsequence = -pow(10,4)-1;
                // start adding increasing number on the left to subsequence:
                for (int i = left; i <=right; i++){
                    // basic case: subsequence 1, 2, 3 ..
                    if (nums[i]>largestInSubsequence && nums[i]<nums[right]){
                        length++;
                        largestInSubsequence = nums[i];
                        cout<<"basic case, i="<<i<<" ";
                        cout<<" add "<<nums[i]<<" length "<<length<<endl;
                    }
                    // border case 1, 2, 3, 4 when nums[right]=4 and i=4
                    if (nums[i]== nums[right] && i==right && nums[left] < nums[right]){
                        length++;
                        cout<<"border case, add "<<nums[i]<<" length "<<length<<endl;
                    }
                    // special case: 1, 2, 15, 4, 5, 6, 100, 200
                    // 
                }
                result = max(result, length);
                cout<<"     max length of subsequence so far "<<result<<endl;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int>nums = { 1,3,6,7,9,4,10,5,6};
    sol.lengthOfLIS((nums));
    return 0;
}