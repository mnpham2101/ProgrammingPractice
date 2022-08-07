# Description:

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

## Example 1:
```
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
```

## Example 2:
![image info](./2.png)
```
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
``` 

## Constraints:
```
1 <= n <= 231 - 1
```

# Solution: Brute Force
* Note that in the following code, post-decrement makes the codes incorrect solution
```
class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0, coinsPerRow=0;
        while ( n>0 ){
            row++; 
            n -= (coinsPerRow++);           // BUG: error 
            if (n<=coinsPerRow)             // not enough coins for next row
                return row;     
        }
        return row;
    }
};
```
## Complexity:
* O(n). The total steps would be an series that shows the decreasing coins: `(n-1)+ (n-2) + ..+ (n-(n-k)) where n <n-k` and `k` is the number of complete rows. 

## Soluion: Binary Search
* The total coins in all the completed rows could be expressed as a series: `1+2+3+...+k  = k(k+1)` where `k` is the number of completed rows. 
* Since the total number of coins in all the completed rows is less or equal to `n`, we have this equality : `k(k+1) <= n`
* The problem is now finding k such that `k(k+1) = n`. This could be achieved by binary search. 
## Complexity: 
* Like other binary search algorithm, the time complexity for this problem is O(logn), and improvement for large that set than 0(n)