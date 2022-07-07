#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int nums_left = 0; 
        int nums_right = 0;
        int score = 0;
        int size = nums.size();
        multimap<int, int, greater<int>> score_index;
        vector<int> result;
        // Step 1: add to score_index the score for case nums `nums_right` = entire vector `num`
        for (int i = 0; i< size; i++){
            if (nums[i]==1) {
                nums_right++;
            };
        }
        score = nums_right;
        // cout<<"score: "<<score<<endl;
        score_index.insert({nums_right, 0});
        nums_left =0;
        nums_right = 0;

        // Step 2.1: count nums_left for i = 0 to size of nums
        for (int i = 0; i< size; i++){
            int index = i+1;
            if (nums[i]==0) {
                nums_left++;
            };
            // cout<<"nums_left: "<<nums_left<<endl;
            // Step 2.2: makes nums_right_vector from nums vector, starting at position i
            vector<int> nums_right_vec;
            auto it = nums.begin()+i+1;
            nums_right = 0;
            std::copy(it, nums.end(), back_inserter(nums_right_vec));
            // print(nums_right_vec);
            // Step 2.3: count nums_right. 
            for (int j = 0; j <nums_right_vec.size(); j++){
                if (nums_right_vec[j]==1) {
                    nums_right++;
                };
            }
            // cout<<"nums_right: "<<nums_right<<endl;
            score = nums_left + nums_right; 
            // cout<<"score: "<<score<<endl;
            score_index.insert({score, index});     // sort by key = score
        }
        // for (auto i = score_index.begin(); i!=score_index.end(); i++ ){
        //     cout<<"score: "<<i->first<<" index: "<<i->second<<endl;
        // }
        
        // return result
        int highScore = score_index.begin()->first;
        // cout << "key begin: "<<highScore<<endl; 
        
        int nextHighScore = 0; 
        do{
            result.push_back(score_index.begin()->second);
            score_index.erase(score_index.begin());
            nextHighScore = score_index.begin()->first; 
            // cout << "nextHighScore: "<<nextHighScore<<endl; 
        }
        while(nextHighScore == highScore);

        return result;
    }
};

int main(){
    Solution sol; 
    vector<int> input = {{}};
    sol.maxScoreIndices(input);
    return 0;
}