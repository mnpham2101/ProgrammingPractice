/*
[[17,2,17],
 [16,16,5],
 [14,3,19]]      

25  10  33 
19  30  8 
14  3  19
 0  0  0
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // n+1 by 3 vector to store cost calculate
        vector<vector<int>> costCount (costs.size()+1, vector<int>(3,0));
        for (int row = costs.size()-1; row >= 0; row--){
            for (int col = 0; col <3; col++){
                if (col == 0)
                    costCount[row][col] = costs[row][col] + min(costCount[row+1][col+1], costCount[row+1][col+2]);
                if (col == 1)
                    costCount[row][col] = costs[row][col] + min(costCount[row+1][col-1], costCount[row+1][col+1]);
                if (col == 2)
                    costCount[row][col] = costs[row][col] + min(costCount[row+1][col-2], costCount[row+1][col-1]);
            }         
        }
        int res = INT_MAX;
        for (int col = 0; col< 3; col++){
            res = min(res, costCount[0][col]);
        }
        return res;
    }
};