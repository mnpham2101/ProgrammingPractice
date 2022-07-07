# Problem description
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
# Solution 1 with DP and Tabulation Method - BAD SOLUTION
* this problem has minor update from previous House Robber problem in that the "houses" are in circular.
* it would requires return values for special cases:
1. if (totalHouses==0) return 0;
2. if (totalHouses==1) return num[0];
3. if (totalHouses==2) return max of (num[0], num[1]);
4. if (totalHouses==3) return max of (num[0], num[1], num[2]);

## Data Structure - BAD SOLUTION
* use array to store maxProfit. array size = total Houses
* I perform a bad implementation to show a bad DP:
`maxProfit[currentHouse] = max(nums[currentHouse] + maxProfit[currentHouse-2], nums[currentHouse] )` where `num` is the array the store profits for each house.
For example:
```
nums = {1,3,1,1,101}
if start from num[0] => profit can be get from {1,3,1,1}  => max_profit=1+1=2
if start from num[1] => profit can be get from {3,1,1,101} => max_profit=3+101=4. House {1, 1} are skipped
calculate DP equation result for set {1,3,1,1} and set {3,1,1,101}
But the DP equation doesn't. It gets the maxProfit from {1, 101}
```
## Algorithm
skip
## Complexity:
skip

# Solution 2 with DP and Tabulation Method - GOOD SOLUTION
* this problem has minor update from previous House Robber problem in that the "houses" are in circular.
* it would requires return values for special cases:
1. if (totalHouses==0) return 0;
2. if (totalHouses==1) return num[0];
3. if (totalHouses==2) return max of (num[0], num[1]);
4. if (totalHouses==3) return max of (num[0], num[1], num[2]);

## Data Structure - GOOD SOLUTION
* ~~use array to store maxProfit. array size = total Houses~~
* maxProfit is calculated via DP equation:
newMaxProfit = max(profit_from_current_house + lastMaxProfit, MaxProfit)
* use variables to calculates DP equations

## Algorithm
```
initialize MaxtProfit = 0;
initialize lastProfit =0;
for (currentHouse= start : currentHouse=end){
    initialize lastMaxProfit = MaxProfit
    MaxProfit = max(profit_from_current_house + profit_from_last_house, lastMaxProfit)
    profit_from_last_house = lastMaxProfit
}

```
## Complexity:
