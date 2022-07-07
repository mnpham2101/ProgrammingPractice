#include <vector>
// approach: find min and max in the vector in 1 loop. 
// minPrice is updated when absolute min values if found
// profit from selling stock at price higher than min is compared to maxProfit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        // int maxPrice = prices[0];
        // int maxProfit = prices[0];
        int maxProfit = 0;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < minPrice ) { minPrice = prices[i]; }
            // if (prices[i] > maxPrice ) { maxPrice = prices[i];}
            if (prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }
        // int maxProfit = maxPrice - minPrice;
        return maxProfit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    sol.maxProfit(prices);
}