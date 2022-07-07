# Description
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

**Example 1:**
```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```
**Example 2:**
```
Input: s = "eccbbbbdec"
Output: [10]
```

# Approach 1 - Greedy
* a partition is defined by leftMost and rightMost. Its length is:  `rightMost - leftMost + 1`
* algorithm:
  - increment from left to right, for every character, find a repead of itself. => use 2 for loops
  - if there is a repeat, compared with rightMost, and set rightMost.
  - if there is no repeat, continue until right < left
* rightMost is found when:
  - inner for loop from length-1 to leftMost (decreasing)
  - s[left] = s[right]
  - rightMost = max(rightMost, right)
  - break condition: right < left
* a partition is found when:
  - outer for loop from leftMost to length-1
  - break condition: left = rightMost.
  - when a partition is found:
  1. push_back rightMost to result vector
  2. set rightMost++, ==> new rightMost for new partition.
  3. set leftMost++,  ==> start new partition from leftMost
