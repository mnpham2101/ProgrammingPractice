// the following code is bad due to incorrect forward logic.
class Solution {
    int numberOfCombinationPerRemaining(vector<int> coins, int remainingAmount, int currentCoin, vector<int>& cache){
        cout<<"remainingAmount "<<remainingAmount<<" coinIndex"<<currentCoin<<endl;
        // base:
        if (remainingAmount == 0){
            // cache[remainingAmount] = 1;
            cout<<"    child node result "<<1<<endl;
            return 1;
        }
        // memoization
        if (cache[remainingAmount] != -1){
            return cache[remainingAmount];
        }
        int ans=0;
        // recurrence - backtracking logic
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++){
            // forward logic/going deeper to next child ===>BAD
            // preparing data to go deeper
            remainingAmount -= coins[coinIndex];
            if (remainingAmount <0 ){                 
                // cache[remainingAmount]=0;
                cout<<"    child node result "<<0<<endl;
                return ans=0;                                   // return without going deeper, thus in this case, it would inadvertedly go back to upper layer. 
                                                                // could you continue ==> don't go deeper to next child level, must reset remainingAmount. 
            }
            else{
                ans += numberOfCombinationPerRemaining(coins, remainingAmount, coinIndex, cache);   // going deeper to next child, using the same coin
            }
            remainingAmount += coins[coinIndex];;        // back-tracking to upper level, go to next branch
            cout<<" backtracking, result accumulated for remaining:"<<remainingAmount<<" is "<<ans<<endl;
        }
        cout<<" backtracking all branch finishes, result accumulated for remaining:"<<remainingAmount<<" is "<<ans<<endl;
        cache[remainingAmount]=ans;
        return ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans=0, remainingAmount= amount;
        vector<int> cache (amount+1,-1);
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++)
            ans +=numberOfCombinationPerRemaining(coins, remainingAmount-coins[coinIndex], coinIndex, cache);
        return ans;
    }
};


/* fixing logic ==> works according to my understanding, but still incorrect
* the following logic would could all the branches by counting the last child nodes. 
* however, the problem would requires different ideas:
* 1+2+1+1 vs 1+1+1+2 would be counted as 2 by the following logic. But it should be counted just as 1. 
*/

class Solution {
    int numberOfCombinationPerRemaining(vector<int> coins, int remainingAmount, int currentCoin, vector<int>& cache){
        cout<<"remainingAmount "<<remainingAmount<<" coinIndex"<<currentCoin<<endl;
        // base:
        if (remainingAmount == 0){
            // cache[remainingAmount] = 1;
            cout<<"    child node result "<<1<<endl;
            return 1;
        }
        // memoization
        if (cache[remainingAmount] != -1){
            return cache[remainingAmount];
        }
        int ans=0;
        // recurrence - backtracking logic
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++){
            // forward logic/going deeper to next child ===>BAD
            remainingAmount -= coins[coinIndex];
            if (remainingAmount <0 ){                 // if condition fails, don't go to next child
                // cache[remainingAmount]=0;
                cout<<"    child node result "<<0<<endl;
                remainingAmount += coins[coinIndex];  // reset to stay in same level. 
                continue;
            }
            else{
                ans += numberOfCombinationPerRemaining(coins, remainingAmount, coinIndex, cache);   // going deeper to next child, using the same coin
            }
            remainingAmount += coins[coinIndex];        // back-tracking to upper level, go to next branch
            cout<<" backtracking, result accumulated for remaining:"<<remainingAmount<<" is "<<ans<<endl;
        }
        cout<<" backtracking all branch finishes, result accumulated for remaining:"<<remainingAmount<<" is "<<ans<<endl;
        cache[remainingAmount]=ans;
        return ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int ans=0, remainingAmount= amount;
        vector<int> cache (amount+1,-1);
        for (int coinIndex=0; coinIndex < coins.size(); coinIndex++){
            ans +=numberOfCombinationPerRemaining(coins, remainingAmount-coins[coinIndex], coinIndex, cache);
            cout<<"top "<<ans<<endl;
        }
        return ans;
    }
};