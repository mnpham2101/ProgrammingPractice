#include <vector>
#include <algorithm>
// approach: compare between longTermProfit (buy/sell 1 times) and shortSellProfit (buy/sell multiple times)
class Solution {
public:
    // approach: find min and max in the vector in 1 loop.
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int lastLow = prices[0];
        int maxLongTermProfit = 0;
        int shortSellProfit = 0;
        for (int i=0; i<prices.size(); i++){
            // calculate profit from buying/selling only 1 time
            // minPrice is absolute min value from array
            if (prices[i] < minPrice ) { minPrice = prices[i]; }
            // profit from selling stock at higher values is compared with save maxLongTermProfit
            if (prices[i] - minPrice > maxLongTermProfit){
                maxLongTermProfit = prices[i] - minPrice;
            }
            // calculate profit from buying/selling at every high/low
            // profit from buying/selling at every peak is max if every high/low is done ==> add profit from every transaction
            // very price lower than previous last low values is considered a good buy
            if (prices[i] <lastLow) {
                lastLow = prices[i];
            }
            // every price higher than previous low is considered a good sell
            if (prices[i] > lastLow){
                int transactionProfit = prices[i] - lastLow;
                shortSellProfit += transactionProfit;
                lastLow = prices[i];
            }
        }
        return max(maxLongTermProfit, shortSellProfit);
    }
};

int main(){
    Solution sol;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {1, 2, 3, 4, 6};
    sol.maxProfit(prices1);
}