#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// fail because I didn't calculate slope from consecutive days
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int startX = stockPrices[0][0]; 
        int startY = stockPrices[0][1];                                 
        int preScope = 0;
        int count = 0;
        for (int row = 1; row< stockPrices.size(); row++){
            int x = stockPrices[row][0];            // bug: x will not be a next day from startX
            int y = stockPrices[row][1];            // row: day, col: price
            cout<<"x "<<x<<" y "<<y<<endl;
            cout<<"startX "<<startX<<" startY "<<startY<<endl;
            int scope = (y-startY)/(x-startX);
            if (scope != preScope) {
                count++;
                cout<<"scope "<<scope<<endl;
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

    vector<vector<int>> stockPrices = {{36,9},{17,93},{34,4},{30,11},{11,41},{53,36},{5,92},{81,92},{28,36},{3,45},{72,33},{64,1},{4,70},{16,73},{99,20},{49,33},{47,74},{83,91}};
    cout<<sol.minimumLines(stockPrices)<<endl;
}