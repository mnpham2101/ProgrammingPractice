# Explanation:

Given a sorted array of distinct integers and a `target` value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

## Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

## Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

## Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
``` 

## Constraints:
```
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
```

# Solution: Binary Search
* Binary search make use of the following conditions
    * If the target value is equal to the middle element, the job is done.
    * If the target value is less than the middle element, continue to search on the left.
    * If the target value is greater than the middle element, continue to search on the right.
## Algorithm:
* make `low=0`, `high=nums.size()`
* make `mid = (high + low)/2 but there is possible OVERFLOW BUG because max value of int is  2^{31} - 1
    * it is better to make `mid = low + (high - low)/2
* While loop:
    * Breaking condition: low<=high
    * Return condition: nums[mid] == target
    * Other cases: continue binary search.
## Complexity: 
* MASTER THEOREM gives complexity of O(logN)