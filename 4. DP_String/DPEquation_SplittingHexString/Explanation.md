# Description
Consider splitting a string S of length n into k substrings, T1, T2, ..., Tk, according to the rules below:

1 ≤ k ≤ n
For each i with 1 ≤ i ≤ k, Ti must be a substring of S with length at least 1 (that is, Ti must consist of consecutive character(s) in S).
If you concatenate T1, T2, ..., Tk in this order, it results in the original string S.
For instance, if S = "FED", then we can split it into four different ways as follows:

- Option 1: T1 = "FED" (in this case, k = 1)
- Option 2: T1 = "F", T2 = "ED" (in this case, k = 2)
- Option 3: T1 = "FE", T2 = "D" (in this case, k = 2)
- Option 4: T1 = "F", T2 = "E", T3 = "D" (in this case, k = 3)

For your information, there are 2n-1 ways to split a string of length n according to the rules above.

In this problem, we assume that S is a hexadecimal string that only consists of '0'-'9' and 'A'-'F'.

Albert wants to know in how many ways he can split S into T1, T2, ..., Tk such that the substrings form a non-decreasing sequence.

Formally, Albert wants to ensure that T1 ≤ T2 ≤ ... ≤ Tk is satisfied if each substring is interpreted as a hexadecimal number.

In the example above, those four options lead to the following sequences:

- Option 1: [FED(16) = 4077] (a non-decreasing sequence)
- Option 2: [F(16) = 15, ED(16) = 237] (a non-decreasing sequence)
- Option 3: [FE(16) = 254, D(16) = 13]
- Option 4: [F(16) = 15, E(16) = 14, D(16) = 13]
In this case, the first two options lead to non-decreasing sequences, so the answer will be 2.

In another example where S = "0070", there are four ways to obtain non-decreasing sequences.

- Option 1: T1 = "0070"
- Option 2: T1 = "0", T2 = "0", T3 = "70" (in this case, the sequence is [0, 0, 70(16) = 112])
- Option 3: T1 = "00", T2 = "70"
- Option 4: T1 = "0", T2 = "070"

As you can see in option 1, option 3, and option 4, substrings are allowed to contain leading zero(s).

Given a hexadecimal string S, compute the number of ways in which Albert can split S into substrings such that the resulting sequence is a non-decreasing sequence.

**Input**

The first line of the input will contain a single number, T, the number of test cases.

In each of the following T lines, an input string S will be given.

S will only consist of 0-9 (digits) and A-F (uppercase) that are used in hexadecimal numbers.

**Output**

For each test case, output the answer in a single line.

**Limit**
```
1 ≤ T ≤ 20
1 ≤ n ≤ 15
S will consist only of 0-9 and A-F.
```

**Sample Input**
```
4
0070
FED
42
002021
```
**Sample Output**
```
4
2
1
12
```
# Approach 1 - Brute Force:
* make recursive call to create substring: `recursiveCall (originalString, newRightIndex, previousSubstring)`
  - `originalString` the given string from test case
  - `newRightIndex = newRightIndex + 1` ; leftIndex is defined in outer for loop.
  ```
  for(int rightIndex = 0; rightIndex < originalString.length(); rightIndex++) {
    // get hexadecimal substring
    leftIndex = rightIndex;
    substring = originalString.substr(rightIndex, leftIndex - rightIndex + 1)
    // other logic to check decreasing hexadeximal string value
    // recursive logic to get new substring
    ret += recursiveCall(originalString, leftIndex + 1, previousSubstring);
    }
  ```
  - get a hexadecimal value from a substring by `stoll(substring, nullprt, baseValue)`

# Approach 2 - DP Equation:
(Explanation from LG)

We can use Dynamic Programming for better optimization.

Let's define f(a,b) as the number of non-decreasing sequences that can be attached to substrings of string[0:a-1].

Then the answer we get is f(0,n-1) + f(1,n-1) + f(2,n-1) + ..... + f(n-2, n-1).

For example, if the string is "0070,"

```
f(0,0) = 1 => 0
f(1,1) =  1 => 0 + 0
f(0,1) = 1 => 00
f(2,2) = 2 => 00 + 7, 0 + 07
f(1,2) = 2 => 0 + 07
f(0,2) = 1 => 007
f(3,3) = 0
f(2,3) = 2 => 0 + 0 + 70, 00+ 70
f(1,3) = 1 => 0 + 070
f(0,3) = 1 => 0070
```

As you can see, the equation is defined as below.

f(x,y) = sum of f(n,x-1) ( 0<= n <= x-1, and in case string[n:x-1] is equal or smaller than string[x:y])

Below is an implementation of the code, and the time complexity is O(n^3).

## Algorith
1. use nested for loop to create the substring
    - let Y be the left anchor of substringLeft
    - let X be the right anchor of substring1 ==> `substringLeft = s.substr(x, y-x+1)`
    - let X be the left anchor of substringRight
    - let i be the right anchor of substring2 ==> `substringRight = s.substr(i, x-i)`
```
for (int y = 0; y< s.length(); y++){
    for (int x = y; x>0; x--){
        for (int i =0; i <x ; i++){
            substringLeft = s.substr(x,y-x+1);
            substringRight = s.substr(i,x-i+1);
        }
    }
}
```
2. update the DP equations:

```
dp[x][y] = += dp[i][x-1]                // why ????
```

3. couting the result:

```
for (int i = 0; i <n ; i++){
    sum += dp[i][n-1];                  // sum is added up by the last element of each row of the DP array. WHY???
}
```
Example, for case `str = FED`

* decreasing sequences 1: `FE` `D`
    - `substringLeft = FE, substringRight = D`
    - `y=2, x=2, i=0`
* decreasing sequences 2: `F` `E` `D`
    - `substringLeft = F, substringRight = E`
    - `y=1, x=1, i=0`
    - `substringLeft = E , substringRight =D`
* non-decreasing sequences 1: `F` `ED`
    - `substringLeft = ED, substringRight = F`
    - `y=2, x=1, i=0`
    - `dp[x][y] += dp[i][x - 1]` or `dp[1][2] += dp[0][1]`
* non-decreasing sequences 2: `FED`
    - `substringLeft = FED, substringRight = null`
    - `y=2, x=0, i=0`
    - `dp[x][y] = dp[i][x - 1]` or `dp[0][2] = dp[0][0]`