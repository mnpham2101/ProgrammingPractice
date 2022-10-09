# Explanation: 
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

## Example 1: 
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

## Example 2:
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

## Example 3:
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

# Approach 1: Brute Force.
### Analyze problems:
The following analysis shows all possible corner cases
* The subsequence is formed by moving from left to right in the nums array only once. :
  * For case `nums=[1,3,5,2,9,11,12]` ,  the `subsequence=1,2,3,5,9,11,12]` is not valid. We cannot rearrange the items in original nums array. 
* The subsequence can be formed from non-continuous items
  * For case `nums=[1,3,5,2,9,11,12]` , the valid subsequences are `[1,3,5,9,11,12]`, `[3,5,9,11,12]`,`[5,9,11,12]`,`[2,9,11,12]`, and `[1,2,9,11,12]`
* There could be repetitive items.
  * For case `nums=[0,1,0,3,2,3]`, the valid increasing subsequences are `[0,1,]`,`[0,1,3]`, `[0,1,2,3]`,`[0,2,3]`, and ,  `[1,3,3]` . However, `[0,0,2,3]` and `[0,1,3,3]` are not valid.