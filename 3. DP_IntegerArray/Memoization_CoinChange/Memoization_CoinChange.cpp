#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> cache;
    int recursiveCall(vector<int>& coins, int amount){
        // cout<<"amount: "<<amount<<endl;
        // base case
        if (amount <0) {
            return -1;          // cannot make more as the remainder is less than coin denominator
        }
        if (amount ==0){
            return 0;           // no longer make change, use no coin
        }
        if (cache[amount-1] != INT_MAX){            // amount -1 is to compensate with indexing. For example, if amount = 1, cache[0] is saved.
            // cout<<"return cache []"<< amount -1 <<"] "<<cache[amount-1]<<endl;
            return cache[amount-1];
        }
        // recursive cases
        int coinCountTmp = 0;
        int accumulatedCount = INT_MAX;
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++){         // result based on exchange by every coint denomination
            coinCountTmp = recursiveCall(coins, amount - coins[coinIndex]);
            // get minimum coins counts
            if (coinCountTmp>=0 &&                          // if the child branch returns a valid result, not -1
                coinCountTmp < accumulatedCount){           // and if the child branch returns min value: value that is less than the accumulated value
                                                            // because of this comparison, accumulatedCount was initilized to INT_MAX
                accumulatedCount = 1 + coinCountTmp;
            }
            // cout<<"amount "<<amount<<" accumulatedCount "<<accumulatedCount<<endl;
        }

        if (accumulatedCount == INT_MAX) {     // if the result is invalid
            cache[amount-1] = -1;             // amount -1 is to compensate with indexing. For example, if amount = 1, cache[0] is saved.
            return -1;         // if previous child branch returns -1, then there is invalid result. return -1
        }
        else{
            cache[amount-1] = accumulatedCount;
            return accumulatedCount;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int result;
        cache.resize(amount, INT_MAX);
        int coinCount = recursiveCall(coins, amount);
        return coinCount;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1,2,5};
    sol.coinChange(coins, 100);
    return 0;
}