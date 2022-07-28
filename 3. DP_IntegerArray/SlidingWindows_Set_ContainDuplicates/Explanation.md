# Explanation: 
Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

## Example 1:
```
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

## Example 2:
```
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

## Example 3:
```
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

## Constraints:
```
1 <= nums.length <= 2 * 104
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 104
0 <= t <= 231 - 1
```

# Solution 1: Brute Force
## Problem Analysis:
* Special case: 
    * if `nums.size()==1`, ans= 0 because the problem requires 2 index `i`, `j`
* Data type: since nums[i] has limit 2^31, the value `abs(nums[i]-nums[j])` has to be long long
## Algorithm:
```
for (int i = 0; i< nums.size(); i++){
    for (int j = i+1; j< nums.size(); j++){
        ll tmp1 = nums[i];
        ll tmp2 = nums[j];
        if (abs(tmp1-tmp2)<=t && abs(j-i) <=k){
            return true;
        }
    }
}
return false;
```
## Complexity: 
* O(N^2) for double for loop