# Description
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

**Input**: s = "abccccdd"
**Output**: 7
**Explanation**: One longest palindrome that can be built is "dccaccd", whose length is 7.

## Approach: Greedy.
* Greedy approach is based on observation and made of local optimum choice which hopefully leads to ultimate optimum choice.
* Observation 1: every character that made up a Palindrom would be an even number. 
* Observation 2: a single character whose count is odd could be put in the middle. 
* Observation 2.1: it happens only when the length of palindrome is even.
* Observation 2.2: if the character count is odd, and the length of the palindrome is not even ==> only an even number of the character is used to to make the palindrome. In order words, if there was already a character to be placed in the middle, the only 4 of `ddddd` is used to make the palindrome. 
* Observation 3: since the characters could be rearranged, we don't have to check position index of a characters, or compare left or right.


