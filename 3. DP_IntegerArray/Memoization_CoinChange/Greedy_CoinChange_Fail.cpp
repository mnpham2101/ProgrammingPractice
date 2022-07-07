#include <vector>
#include <algorithm>
using namespace std;


// Greedy - Fail TC [186,419,83,408] 6249
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());            // it can't be sure that the highest denominations is the best choice to choose.
        int result =0;
        while (!coins.empty() &&  amount>0) {
            if (amount % coins.back() == 0){
                result+=(amount/coins.back());
                amount = 0;
                coins.pop_back();
            }
            else {
                result += amount/(coins.back());
                amount = amount % (coins.back());
                coins.pop_back();
            }
        }
        if (amount > 0) return -1;
        return result;
    }
};