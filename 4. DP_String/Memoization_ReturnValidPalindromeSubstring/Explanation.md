# Description:
Given a string s, return the longest palindromic substring in s.
# Approach 1: DP solution, Bottom Up, Memoization
My solution follows closely to the suggest DP solution by Leetcode.

1. a palindrome is identified via recursive call, with base cases:
* left == right => return true
* s[left] == s[right] and right == left+ 1 => return true.
* left>right return false

2. other cases return true if
* s[left] == s[right]
* isPalindrome(left+1, right -1)

Basically, if I have a string abcba
a) left = 0 and right = 5, we have s[left]=s[right] = 'a'
b) left++, right--, we have s[left]=s[right]='b'
c) left++, right--, we have s[left]=s[right]='c'
(c) returns true, and thus recursively returns to (b) to (a) true

Time complexity should be log(n) where n = (left-right)/2

3. Perform double for loop to find palindrome
For example, if left = 0, right = 3, => check if the substring abcb is a palindrome.
It is not, thus, right is incremented, => check if the substring abcba is a palindrome => return true => check if size is max, and save the max value.
Note: there cannot be a break if false result is return.
Time complexity should be log (n^2).

So far time complexity is bad: log(n^3).

4. Optimize with cache.
Cache[left][right] = true/false. It stored the values so that isPalindrome doesn't have to run all the recursive functions.
In addition, using `Cache[left][right] = -1/0/1 further distinguished invalid initialized value vs result as true/false.