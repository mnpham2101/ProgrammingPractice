#include <vector>
/* approach: compare between longTermProfit (buy/sell 1 times) and shortSellProfit (buy/sell multiple times) 
longTermProfit: get absolute minPrice, compare profit from selling at any price higher than minPrice to the maxLongTermProfit.
shortSellProfit: 
 - approach 1: get a many trades as possible, add a day for cool down time. ==> bad approach for case [7, 1, 2, 3, 5, 2, 5]
 - approach 2: to get as many trades as possible, the last day should be the sell day if price is high. Work in reverse order of time to get shorSellProfit. 
*/
class Solution {
public:
    // approach: find min and max in the vector in 1 loop. 
    int maxProfit(vector<int>& prices) {
        int maxLongTermProfit = 0;
        int shortSellProfit = 0;
        
        int totalDay = prices.size();

        // get longTermProfit
        int minPrice = prices[0];
        for (int today = 0; today < totalDay; today++ ){
            if (prices[today] < minPrice) { 
                minPrice = prices[today]; 
            };
            if ((prices[today] - minPrice) > maxLongTermProfit) {  
                maxLongTermProfit = prices[today] - minPrice;
            }
        }
       
        // get shortSellProfit 
        int high = prices[totalDay-1];
        int cooldown = 0;
        for (int today = totalDay-1; today >0; today-- ){
            if (today == cooldown -1) {
                high = prices[today];
            }
            if (prices[today] < high && today != cooldown) {        // this wont work for case [7,1,2,3,5,2,5,3] 
                                                    // as high=3, buy=prices[2]=2 will satisfy the condition, but buy should be buy=prices[1]=1
                int transactionProfit = high - prices[today];
                shortSellProfit += transactionProfit;
                cooldown = today -1; 
            }
            if (prices[today] > high){
                high = prices[today];
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