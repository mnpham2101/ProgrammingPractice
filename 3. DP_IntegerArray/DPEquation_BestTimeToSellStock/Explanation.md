# Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# Solution 1: Greedy
* compare between longTermProfit (buy/sell 1 times) and shortSellProfit (buy/sell multiple times)
* buy @ min price, `maxLongTermProfit = currentPrice - minPrice`
* shortSellProfit is achieve at buy/sell at every opportunity: `shortSellProfit = currentPrice - lastLowPrice`

# Solution 2: DP equation
* DP[] stores the profit.
* `DP[i] = price[i] - minPrice`
* once DP[] is calculated, max profit can be retrieved.