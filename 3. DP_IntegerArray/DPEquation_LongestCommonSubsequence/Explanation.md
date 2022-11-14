# Explanation: 

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
 

## Example 1:
```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
```

Explanation: The longest common subsequence is "ace" and its length is 3.

## Example 2:
```
Input: text1 = "abc", text2 = "abc"
Output: 3
```

Explanation: The longest common subsequence is "abc" and its length is 3.

## Example 3:
```
Input: text1 = "abc", text2 = "def"
Output: 0
```

Explanation: There is no such common subsequence, so the result is 0.
 

## Constraints:
```
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
```

# Solution 1: Brute Force
## Problem analysis: 
* repeated character may appear in any text. For example: `text1 = abcae` and `text 2 = cae`, `cae` is the common subsequence, but `ace` is not. 
* consequently, if a character matches another character in the 2nd text, it must be in order. 
* iterate through each subsequence of the first string and check whether or not it is also a subsequence of the second string. (the characters in 2nd string could be put in a hashmap with key-value). The value would indicate the order in which the characters appear in the 2nd string.
* This will require exponential time to run. The number of subsequences in a string is up to 2^L , where L is the length of the string. This is because, for each character, we have two choices; it can either be in the subsequence or not in it. Duplicates characters reduce the number of unique subsequences a bit, although in the general case, it's still exponential.

# Solution 2: Topdown
## Approach: 
* consider a decision tree where each node is pair of substrings from `text1` and `text2`. The first character of the substrings are compared, and could be used or wont be used in the child node. 
* In order word, each state compares the 2 first characters of substrings from `text1`, and `text2`. 
* If the characters match, the characters are removed from both original strings.
* If the characters dont match, the character is kept from either string, and compared to the next character of the other string. 
* We now can defines the basic terms for DP solution:
  
1. `state`: each state compares the first characters of the `substrings` of `Text1`, `Text2`
2. `state variable`: `i` is index of first character in substring `Text1`; `j` is index of first character in substring of `text2`.
3. `recurrance relation`: For top-down solution, we define recursive call `compareNext`, where:
   * `ifCharactersMatch = 1 + compareNext(i,j)`     
   * `ifCharactersDontMatch = max(compareNext(i+1,j), compare(i,j+1)`
   * ifCharactersMatch : in the next state, we removed the characters from both string and compare the next characters of both string. Thus we compare `Text1[i+1]` and `Text2[j+1]`
   * ifCharactersDontMatch: we removed a character from either string, and keep the other. The character is then compared to the next charact of the other string.. Thus we compare between `Text1[i+1]` and `Text2[j]` or `Text1[i]` and `Text2[j+1]` .
4. `base case`: 