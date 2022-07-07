#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    static bool compare (vector<int> day1, vector<int> day2 ){
        return day1[0] < day2 [0];                          // day1 & day2 are vector with size 2. day1[0]: day, day2[0]: stock price on day.
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        // sort the stockPrices so that the days are consecutives 
        sort(stockPrices.begin(), stockPrices.end(), compare);          //minor bug: don't need compare to sort. Compare makes the program runs slower
        // log
        // for (int row = 0; row <stockPrices.size(); row++){
        //     for (int i = 0; i<2; i++){
        //         cout<< stockPrices[row][i]<<" ";
        //     }
        //     cout<<endl;
        // }

        long startX = stockPrices[0][0];             // use double because of range and scope could be decimals
        long startY = stockPrices[0][1];                                 
        long preScope = LONG_MAX;
        int count = 0;

        for (int row = 1; row< stockPrices.size(); row++){
            long x = stockPrices[row][0];            // bug: x will not be a next day from startX
            long y = stockPrices[row][1];            // row: day, col: price
            // Log
            // cout<<"x "<<x<<" y "<<y<<endl;
            // cout<<"startX "<<startX<<" startY "<<startY<<endl;
            long scope = (y-startY)/(x-startX);
            // Log
            // cout<<"scope "<<scope<<endl;
            // cout<<"preScope "<<preScope<<endl;
            if (scope != preScope) {
                count++;
                // cout<<"count "<<count<<endl;
            }
            startY = y;
            startX = x;
            preScope = scope; 
        }
        return count++;
    }
};

int main(){
    Solution sol;

    // vector<vector<int>> stockPrices = {{36,9},{17,93},{34,4},{30,11},{11,41},{53,36},{5,92},{81,92},{28,36},{3,45},{72,33},{64,1},{4,70},{16,73},{99,20},{49,33},{47,74},{83,91}};
    // vector<vector<int>> stockPrices = {{200,1},{201,499999999},{202,999999998},{203,1000000000}};
    vector<vector<int>> stockPrices = {{1,1},{500000000,499999999},{1000000000,999999998}} ;   // test case fail
    cout<<sol.minimumLines(stockPrices)<<endl;
}