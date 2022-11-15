class Solution {
    private:
    vector<vector<int>> cache;
    int nextOperation(vector<int> &nums, vector<int> &multipliers, int i, int left, int right){
        // base condition
        if(i==multipliers.size())
            return 0;
        // memoization
        if(cache[left][i]!=-1)
            return cache[left][i];
        // recurrence relation
        int scoreRight = multipliers[i]*nums[left] + nextOperation(nums, multipliers, i+1, left+1, right);
        int scoreLeft = multipliers[i]*nums[right] + nextOperation(nums, multipliers, i+1, left, right-1);
        cache[left][i] = max(scoreLeft, scoreRight);
        return cache[left][i];
    }
    public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        cache.resize(m, vector<int>(m,-1));
        return nextOperation(nums, multipliers, 0, 0, nums.size()-1);
    }
};