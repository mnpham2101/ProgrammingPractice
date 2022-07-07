# Description
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

# Approach 1: Bottom Up ==> time out result
* make recursive call `removeCharacter` with left = 0, right = s.length()-1, count = 0 where count is the number of removed characters
* **base cases**
    1. if `left> right` returns count
* **recursive cases**
    1. if `s[left]==s[right]` ==> removeCharacter(left++, right--), count doenst change
    2. if `s[left]!=s[right]` ==>  make 2 runs
    - removeCharacter(left++, right, count++)
    - removeCharacter(left, right--, count++)
    - result of count is min of the 2 runs.
* result = length - count
* because there is no cache, every tree branch is visited and thus causes time out result for large data set.

# Approach 2: Bottom Up + memoization => fail
* add memoization for cases:
  - `s[left] == s[right]`
  - `s[left] != s[right]`
  - `left >= right`
* reasons for failure:
  - the `count` result when left>= right is not the same for every branches.
  - the `count` result when s[left] != s[right] is not the same for every branches.
  - the `count` result when s[left] == s[right] is not the same for every branches.


# Approach 3: Bottom Up + memoization => pass
Resouce: https://leetcode.com/problems/longest-palindromic-subsequence/discuss/1871498/C%2B%2B-Easy-recursive-solution
* make recursive call `removeCharacter` with left = 0, right = s.length()-1, length = 0 where length is the number of characters in strings in based case ==> length is never changed in based case.
* **base case**
    1. if `left == right` return length =1
    2. if `s[left] == s[right] && right == left+1`  return length =2
* **recursive case**
    1. if `s[left] == s[right]` return removeCharacter(left++, right--)
    2. if `s[left] != s[right]` return max ((removeCharacter(left++, right, length), (removeCharacter(left,right++, length)