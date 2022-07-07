#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    static vector<int>result;
    vector<int> maxScoreIndices(vector<int>& nums) {     
        int nums_right=0, nums_left=0;
        int score = 0, maxScore = 0;
        
        // Step 1: get `nums_left` at index=0 by counting all `1`
        for (int i : nums ){
            nums_left += i;     // count `1` by sum of vector
        }

        // Step 2.1: run for loop from index=0-> index<size, update `nums_right` and `nums_left` to count `1` and `0`
        for (int index =0; index <= nums.size(); index++){
            score = nums_left + nums_right;
            if (score > maxScore){
                result.clear();             // clear previously stored index
                result.push_back(index);
                maxScore = score;
            }
            else if (score == maxScore){
                result.push_back(index);    // dont clear previously stored index 
            }
            // Step 2.2: update `nums_right` and `nums_left` to count `1` and `0`
            if (index != nums.size()){
                if(nums[index]==0) { 
                    nums_right++; 
                    // Log
                    // cout<<"nums_right: "<<nums_right<<endl;
                }
                if(nums[index]==1) { 
                    nums_left--; 
                    // Log
                    // cout<<"nums_left: "<<nums_left<<endl; 
                }
            }
        }
        return result; 
    }
};

vector<int> Solution::result = {0};   // must have initialization outside class definition for static member

int main(){
    Solution sol; 
    // vector<int> input = {0,0,1,0,0};
    vector<int> input = {1,0,0,1,1,0};
    // vector<int> input = {0,0,1,0};
    vector<int>result; 
    result = sol.maxScoreIndices(input);
    cout<<"Result: ";
    for (int i = 0; i< result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}