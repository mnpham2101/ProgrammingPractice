// bottom down - tabulation - dp equation
class Solution {
    public:    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> occurances;
        int maxNumber=0;
        for (int num : nums){
            occurances[num]++;
            maxNumber= max(maxNumber, num);
        }
        vector<int> dp(maxNumber+1);
        // base case:
        dp[1] = occurances[1];
        // recurance relations is expressed via 1D dp equation:
        for (int num=2; num <= maxNumber; num++){
            int gain = occurances[num]* num;
            dp[num]=max(dp[num-1], gain+ dp[num-2]);
        }
        return dp[maxNumber];
    }
};
