# Description
You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo `10^9 + 7`.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.

# Example 1:
```
Input: startPos = 1, endPos = 2, k = 3
Output: 3
```
## Explanation: 
We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.

## Example 2:
```
Input: startPos = 2, endPos = 5, k = 10
Output: 0
```
## Explanation: 
It is impossible to reach position 5 from position 2 in exactly 10 steps.
 

# Constraints:

1 <= startPos, endPos, k <= 1000

# Solution 1: Topdown method with recursive call
* Observe that the conditions to return valid steps are: 
  ```
  if ((startPos == endPos) &&
      (turn == turnLimit)) {
      return 1;                             // the number of way increase by 1
  ```
* Observe that no valid step is possible, return 0 when: 
  ```
  if (turn > turnLimit){
      return 0;
  }
  ```
* For other cases, we continue to traverse down the *decision tree* where `startPos = startPos+1` or `startPos = startPos -1` and increment the `turn` number. 
  * Define the recursive function as: 
  ```
  int topDown(int startPos, int endPos, int turn, int turnLimit)
  ```
  * The result is the sum of calling recursive function topDown:
  ```
  return result = (topDown(startPos+1, endPos, turn+1, turnLimit) + 
                topDown(startPos-1, endPos, turn+1, turnLimit)) % 1000000007;
  ```
# Solution 2: Optimize solution 1 with memoization. 
* we realize that for some combination of `startPos` and `turn` the remaining turns would be the same, and thus returns a *valid path*, which is a path from startPos to endPos within the turn limits.
  * create a cache array: `cache[startPos][turn]`
* because the position could get negative while the index of array cannot, we compensate by extending the cache size to maximum turn limit
   ```
   startPos+=1200;
   endPos+=1200;
   ```
## Complexity Analysis: 
* The total possibility to traverse the decision tree is dept of `decision tree * 2 = total child branches`. Thus the Complexity is O(N^2) where N = K+1. Memoization reduce the time by not traversing every branch. 