#include<iostream>
using namespace std;

class Solution {
/*
                                        [2,4,1],2
                    -2+ ([4,1],1)                                           [4,1],2                          if (buy)
        -2+4+([1],0)            -2+ ([1],1)             -4+([1],1)           [1],2                              profit = max(buy + trade(prices, day+1, remaininigDay-1, flag=sell), trade(prices, day+1, remainingDay-1, flag=buy))
             0                   -2+1+([],0)                                                                  if (sell)
                                     0                                                                           profit = max(sell + trade(prices, day+1, remaininigDay-1, flag=buy), trade(prices, day+1, remainingDay-1, flag=sell)

*/   
public:
    int trade( vector<int>& prices, int day, int remainingDay, bool buy, vector<vector<vector<int>>> &cache ){
        if (remainingDay == 0 || day >=  prices.size() ){
            return 0;
        }
        if (cache[day][remainingDay][buy] != -1) {
            return cache[day][remainingDay][buy];
        }
        else {
            int take = 0, not_take = 0;
            if (buy) {
                take = -prices[day] + trade(prices, day + 1, remainingDay, false, cache);
                not_take = trade(prices, day + 1, remainingDay, true, cache);
            } else {
                take = prices[day] + trade(prices, day + 1, remainingDay - 1, true, cache);
                not_take = trade(prices, day + 1, remainingDay, false, cache);
            }
            
            return cache[day][remainingDay][buy] = max(take, not_take);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> cache(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return trade(prices, 0, k, true, cache);
    }
};

