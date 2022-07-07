#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {     
        int n = nums.size();
        vector<int>num_right(n+1);
        vector<int>num_left(n+1);
        map<int, vector<int>> score_index;
        int score;
        num_right[0] = 0;                   // special case when numLeft is entire nums, must initialize the size of num_right first or use push_back()
        // Step 1: make nums_right[] 
        for (int i = 1; i<n+1; i++){
            if(nums[i-1] == 0){
                num_right[i] = num_right[i-1] + 1; 
            }
            else {
                num_right[i] = num_right[i-1]; 
            }
        }

        // Log: 
        cout<<"print num_right"<<endl;
        for (int i = 0; i<n+1; i++){
            cout<<"num_right[i] "<<num_right[i]<<endl;
        }

        // Step 2: make nums_left[]
        num_left[n]=0;                      // special case when numRight is entire nums, must initialize the size of num_left first or use push_back()
        for (int i = n-1; i>=0; i--){
            if(nums[i] == 1){
                num_left[i] = num_left[i+1]+1;
            }
            else{
                num_left[i] = num_left[i+1];
            }              
        }

        // Log: 
        cout<<"print num_left"<<endl;
        for (int i = 0; i<n+1; i++){
            cout<<"num_left[i] "<<num_left[i]<<endl;
        }

        // Step 3.1: makes score, add score, index to map
        for (int i =0; i<n+1;i++){
            score = num_right[i]+ num_left[i];
            score_index[score].push_back(i);
        }

        return score_index.rbegin()->second;
    }
};

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