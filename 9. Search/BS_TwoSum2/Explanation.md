# Description:
Given a **1-indexed** array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

## Example 1:
```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

## Example 2:
```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

## Example 3:
```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```
 
## Constraints:
```
2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
```

# Solution: Binary Search Solution
* Note: there is always a *unique* solution, thus BS will always return a solution. 
* Binary search: 
    * For each item on the array, perform BS to find `target - item`
    * the subarray is bounded by the index of the item.
        * if `target - item > item` search the left subarray for second item
        * if `target - item < item` search the right subarray for second item
## Algorithm:
* Running binary search on right subarray: for every item at index `i`, run a binary search of subarray on the right of index `i`
    * `leftbound = i;`
    * `left = leftbound, right = numbers.size()-1`
    * `firstNumber = numbers[leftbound]`
    * `if (target -numbers[mid] == firstNumber) && (mid != leftbound)` found secondNumber. 
    * otherwise: search on left or right of mid, within the subarray.
* *Notice the corner case:*
    * the requirement is that we cannot use the same index twice.
    * For test case: [1,2,3,4,4,9,56,90] target=8 
        * when searching in subarray from index = 3 to index = 7, mid will fall to index with value = 5, 3, 4. When mid = 3 the condition (target -numbers[mid] == firstNumber), but it is not acceptable
* **Note**: it turns out that we dont even have to worry about doing binary search on right subarray because the original `numbers` is sorted
## Complexity Analysis: 
* O(logN)

# Solution: Two Pointers
* This solution optimize the solution 1: we improve from O(logN) to O(N)
## Complexity Analysis: 
* O(N)
