# Description: 
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

## Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

## Example 2:
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

## Example 3:
```
Input: nums = [], target = 0
Output: [-1,-1]
``` 

## Constraints:
```
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
```

# Solution: Binary Search
* Special cases:
    * when `nums.size() == 0`, default `result = {-1,-1}`
* Running 2 Binary Search to find the boundary of subarray that stores only the `target`
    * first BS: search for left boundary. 
        * if the first BS found no target in the nums, return default result. 
        * Note: no target is check if the index return by the first BS is out-of-bound or the nums[index] != target
    * second BS: search for right boundary
        * Note: the starting left boundary for this search is the result from the first search.
## Complexity Analysis:
* For first BS search: O(logN)
* For second BS search: O(log (N - start))  where start is the result of the first BS. But For worse case scenario, it could be start=0. Thus, the complexity is O(logN)
