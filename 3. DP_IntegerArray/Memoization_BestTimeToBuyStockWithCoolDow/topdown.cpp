#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// private:
//     int profit = 0;
//     int nextDayProfit(int day, int tradeMode, vector<int>& prices){
//         int currProfit = prices[day];
//         if (day >= prices.size())
//             return 0;
//         if (tradeMode == 0)  //buy
//         {
//             tradeMode =1;
//             profit = max (profit, -currProfit +  nextDayProfit(day+2, tradeMode, prices));
//         }
//         else if (tradeMode == 1)   //sell
//         {
//             tradeMode =0;
//             profit = max (profit, +currProfit +  nextDayProfit(day+1, tradeMode, prices));
//         }
//         return profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         return nextDayProfit(0, 0, prices);
//     }
// };

// class Solution {
// private:
//     int profit = 0;
    
//     std::vector<int> dp = std::vector<int>(5000,-1);

//     int nextDayProfit(int day, int tradeMode, vector<int>& prices){
        
//         if (day >= prices.size())
//             return 0;
        
//         if (dp[day] != -1)
//             return dp[day];
        
//         int currProfit = prices[day];
        
//         if (tradeMode == 0)  //buy
//         {
//             tradeMode =1;
//             profit = max (profit, -currProfit +  nextDayProfit(day+1, tradeMode, prices));
//         }
//         else if (tradeMode == 1)   //sell
//         {
//             tradeMode =0;
//             profit = max (profit, +currProfit +  nextDayProfit(day+2, tradeMode, prices));
//         }
//         dp[day] = profit;
//         return profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         return nextDayProfit(0, 0, prices);
//     }
// };    // fail TC [1,2,3,0,2], TC[1,2]

// improve with 2D memoization cache
// class Solution {
// private:
//     // std::vector<std::vector<int>> dp (5000, std::vector<int>(2,-1));
//     vector<std::vector<int>> dp;

//     int nextDayProfit(int day, int tradeMode, vector<int>& prices){        
//         if (day >= prices.size())
//             return 0;        
//         if (dp[day][tradeMode] != -1)
//             return dp[day][tradeMode];        
//         int currProfit = prices[day];  
//         int profit = nextDayProfit(day+1, tradeMode, prices);
        
//         if (tradeMode == 0)  //buy
//         {
//             tradeMode =1;
//             profit = max (profit, -currProfit +  nextDayProfit(day+1, tradeMode, prices));
//         }
//         else if (tradeMode == 1)   //sell
//         {
//             tradeMode =0;
//             profit = max (profit, +currProfit +  nextDayProfit(day+2, tradeMode, prices));
//         }
//         dp[day][tradeMode] = profit;
//         return profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         dp.resize(50001, vector<int>(2,-1));
//         return nextDayProfit(0, 0, prices);
//     }
// };// fail TC [1,2,3,0,2], TC[1,2]

//correct
class Solution {
private:
    // std::vector<std::vector<int>> dp (5000, std::vector<int>(2,-1));
    vector<std::vector<int>> dp;

    int nextDayProfit(int day, int tradeMode, vector<int>& prices){        
        if (day >= prices.size())
            return 0;        
        if (dp[day][tradeMode] != -1)
            return dp[day][tradeMode];        
        int currProfit = prices[day];  
        int profit = nextDayProfit(day+1, tradeMode, prices);
        
        if (tradeMode > 0 )   //sell
        {
            // tradeMode =0;
            profit = max (profit, +currProfit +  nextDayProfit(day+2, tradeMode-1, prices));
        }
        else if (tradeMode == 0)  //buy
        {
            // tradeMode =1;
            profit = max (profit, -currProfit +  nextDayProfit(day+1, tradeMode+1, prices));
        }
        dp[day][tradeMode] = profit;
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(50001, vector<int>(2,-1));
        return nextDayProfit(0, 0, prices);
    }
};