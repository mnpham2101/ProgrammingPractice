# Problem description
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
* After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
# Aprroach 1 (FAIL)
* *compare between longTermProfit (buy/sell 1 times) and shortSellProfit (buy/sell multiple times) 
`maxLongTermProfit`: get absolute minPrice, compare profit from selling at any price higher than minPrice to the maxLongTermProfit.
`shortSellProfit`: 
 - approach 1: get a many trades as possible, add a day for cool down time. ==> bad approach for case [7, 1, 2, 3, 5, 2, 5]
 - approach 2: to get as many trades as possible, the last day should be the sell day if price is high. Work in reverse order of time to get shorSellProfit
. ==> bad approach for case [7,1,2,3,5,2,5,3]

# Solution 1 - Using State Machine (3 states)
Resource: LeetCode solution
* 3 states to keep track of buy/sell/downdown time. 
* the brokers could be in any state on a day. 
* for each day pass, all 3 states progress from previous states => construct diagram to show the best path to get final result. 
## Data Structure
* 3 variable to keep track of the values that the broker earns on each day, if he was in any of the 3 states. 
* values are calculated from previous values of its state or other state as a day progresses ==> use for loop to update value of each states. 
## Algorithm
* O(n) 

# Solution 2 - Using State Machine (2 states with recursive call)
## Data Structure
## Algorithm

# Solution 3
## Data Structure
## Algorithm