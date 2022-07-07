# Description
A "bracket sequence" is a string that consists only of six bracket characters: "(", ")", "[", "]", "{", "}".

"Balanced" bracket sequences are defined as follows:

1. The following three bracket sequences are balanced: "()" "[]" "{}"
2. If two strings "X" and "Y" are balanced bracket sequences, then the strings "XY" and "YX" are also balanced bracket strings.
3. If a string "Z" is a balanced bracket sequence, then the following are also balanced bracket sequences: "(Z)", "{Z}", "[Z]".
4. Lastly, for convenience, an empty string ("") is also defined to be a balanced bracket sequence.

For instance, "[](){}", "[[()]]", and "{}[()]" are balanced bracket sequences, whereas "[][[", "()(}", and "{]" are not.

In this problem, we will consider the strings that contain bracket characters and a wildcard character ("*"). Each wildcard character can be replaced by one of the six bracket characters. For instance, consider the string S = "[**)". If we replace the first wildcard by "]" and the second by "(", then we would obtain a new string S' = "[]()" which is a balanced bracket sequence. If the first wild card is replaced by "(" and the second by "]", then we obtain S'' = "[(])" which is not a balanced bracket sequence.

Given a string that only consists of the six bracket characters and wildcards, you want to turn it into a (longest possible) balanced bracket sequence. You may need to remove some characters and/or replace each wildcard by one of the six bracket characters. For instance, suppose an input string is A = "***". A balanced bracket sequence cannot contain an odd number of characters, so we must remove one of the three characters, and the remaining two wildcards must be replaced by "()" or "[]" or "{}". In another example, consider B = "[{([" where the longest possible balanced bracket sequence would be an empty string (which we can obtain after removing all characters). Lastly, consider C = "(]{}){([)}" where we can remove "]" and "[" to obtain a balanced bracket sequence of length 6 ("({}){()}").

Given a string that consists of bracket characters and wildcards, compute the minimum number of characters you must remove in order to obtain a (longest possible) balanced bracket sequence.

## Input
The first line will contain the number of test cases, T.

Each of the following T lines will contain a string.

## Output
For each test case, output the minimum number of characters you must remove in order to obtain a balanced bracket sequence.

## Limit
```
1 ≤ T ≤ 10
1 ≤ Length of an input string ≤ 500
Subtask 1 (6 Points)
Each input string will only contain one type of bracket characters and no wildcard characters. That is, each input string will entirely consist of "[]"s or of "{}"s or "()"s with no wildcards.
Subtask 2 (16 Points)
Each input string will only contain the six bracket characters and wildcard character.
```
## Sample Input 1
6
***
[{([
(]{}){([)}
**(][)
(*]*[)
[]
## Sample Output 1
1
4
2
2
2
0

* Cases 1, 2, and 3 are discussed in the problem statement.

* Case 4:

The wildcards can be replaced by a pair of brackets (e.g., "{}"), and the square bracket pair "][" can be removed. This gives us a balanced bracket sequence of length 4.

* Case 5:

Among many solutions, one is to remove the two square brackets, and to obtain "()()". Another is to replace the first wild card by "[", and remove the second wild card and the subsequent character ("[") to obtain "([])".

* Case 6:

If the input string is already balanced, then we do not have to remove any characters.

# Solution:

* (Task1) Input string consists only 1 type of brackets("[]" or "{}" or "()" without wildcards)
As noted, there's only 1 type of brackets in given string. We can refer them to "opening" and "closing".

In this constraints, we can easily determine how many characters to be removed by counting accumulated number of remained "opening" bracket through given sequence.

Here's the details.

Starting from 0, we accumulate numbers. For the "opening" and "closing" brackets, we assign +1, -1 accordingly.

The remaining number represent minimum number of characters to be removed.

However, we need to check whether accumulated number to be lower than 0.
Which represent not balanced brackets sequence until current position.

In this situation, we change accumulated number to 0 and collect how many times this occurs.
This number to be added to the final results.

The time complexity of this method is O(N).

* (Task2) Input string consists all 6 types of brackets and wildcards
There's no restriction in given sequences. We can't get the correct answer using previous approaches.

Let's look at the given restriction of the problem . The length of given sequence N is not greater than 500.

So, maybe we can check every combinations while avoid computing duplicated operations with cache.

* **subarray dynamic programming**
Let's define the minimum number of characters to be removed for subarray [L, R].

D(L,R) = min(D(L,k)+D(k+1,R)), for L<=k<R


In this definition, we should check whether charaters in positions L & R are matched.
If they matched, then subarray [L+1, R-1] will be the same as subarray [L, R]. So, we need to consider this case as well to get minimum.

D(L,R) = min(D(L,R), D(L+1,R-1)), iff s[L] & s[R] matched

It's easy to check whether characters in position L & R matched.

The only possible condition is s[L] is a type of opening bracket or wildcard character and s[R] is a type of closing bracket or wildcard character.

From the equation mentioned so far, we can get the answer from D(0,N-1).

The time complexity of this method is O(N3) because we need to consider every possible subarray of s[L, R]