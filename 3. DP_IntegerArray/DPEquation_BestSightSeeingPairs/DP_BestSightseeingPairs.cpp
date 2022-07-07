#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestScore = INT_MIN;
        vector<int>dp1(values.size());
        vector<int>dp2(values.size());

        int maxValue=INT_MIN;
        // update dp[1] with maxValue from i -> end
        for (int i = 0; i< values.size(); i++){
            maxValue = max(maxValue, values[i]+i);
            dp1[i]= maxValue;
        }
        // update dp[1] with maxValue from end to i
        maxValue =INT_MIN;
        for (int i= values.size()-1; i>=0; i--){
            maxValue = max(maxValue, values[i]-i);
            dp2[i]= maxValue;
        }

        for (int i = 0; i< values.size()-1; i++){
            bestScore = max(bestScore, dp1[i]+ dp2[i+1]);

        }
        return bestScore;
    }
};

int main() {
    Solution sol;
    vector <int> values1 = {1,2};
    vector <int> values2 = {1,3,5};
    vector <int> values3 = {7,8,8,10};
    vector <int> values4 = {7,2,6,6,9,4,3};
    vector <int> values5 = {4,7,5,8};
    vector <int> values6 = {1,1,1};
}