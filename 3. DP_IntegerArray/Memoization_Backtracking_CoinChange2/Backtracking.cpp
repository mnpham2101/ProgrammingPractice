/*
Note that different combination of same coin denomination is not counted separatedly. 
for amount = 5, and coins=[1,2,5] the following changes are counted as the same: [1,2,1,1] or [1,1,2,1] or [1,1,1,2]
The following changes are made to correct bad backtracking:
1. 2D arrays: because cache[remainingAmount]= cache[2] =1 would reuse/recount the combination above.
2. recurrence relation, loop should have index start at currentCoin.
*/

#include <vector>
using namespace std;

class Solution {
    int numberOfCombinationPerRemaining(vector<int> coins, int remainingAmount, int currentCoin, vector<vector<int>>& cache){
    // int numberOfCombinationPerRemaining(vector<int> coins, int remainingAmount, int currentCoin, vector<int>& cache){    
        // cout<<"remainingAmount "<<remainingAmount<<" coinIndex"<<currentCoin<<endl;
        // base:
        if (remainingAmount <= 0){
            if (remainingAmount <0)
                return 0;
            else if (remainingAmount == 0)
                return 1;
        }
        // memoization
        if (cache[remainingAmount][currentCoin] != -1){
            return cache[remainingAmount][currentCoin];
        }

        int ans=0;
        // recurrence - backtracking logic
        for (int coinIndex=currentCoin; coinIndex < coins.size(); coinIndex++){
            // forward logic/going deeper to next child 
            remainingAmount -= coins[coinIndex];
            if (remainingAmount <0 ){                 // if coin
                // cache[remainingAmount]=0;
                // cout<<"    child node result "<<0<<endl;
                remainingAmount += coins[coinIndex];  
                continue;
            }
            else{
                ans += numberOfCombinationPerRemaining(coins, remainingAmount, coinIndex, cache);   // going deeper to next child, using the same coin
            }
            remainingAmount += coins[coinIndex];        // back-tracking to upper level, go to next branch
            // cout<<" backtracking, result accumulated for remaining:"<<remainingAmount<<" index "<<coinIndex<<" is "<<ans<<endl;
            // if(remainingAmount >= coins[coinIndex])
            //     ans += numberOfCombinationPerRemaining(coins,remainingAmount-coins[coinIndex],coinIndex,cache);
            //     cout<<" backtracking, result accumulated for remaining:"<<remainingAmount<<" is "<<ans<<endl;
        }
        // cout<<" backtracking all branch finishes, result accumulated for remaining:"<<remainingAmount<<" index "<<currentCoin<<" is "<<ans<<endl;
        cache[remainingAmount][currentCoin]=ans;
        return ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans=0, remainingAmount= amount, coinIndex=0;
        vector<vector<int>> cache (amount+1, vector<int>(coins.size()+1,-1));
        // special edge case:
        if (amount == 0)
            return 1;
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++){
            ans +=numberOfCombinationPerRemaining(coins, remainingAmount-coins[coinIndex], coinIndex, cache);
            // ans +=numberOfCombinationPerRemaining(coins, remainingAmount, coinIndex, cache);
            cout<<"top "<<ans<<endl;
        }
        return ans;
    }
};