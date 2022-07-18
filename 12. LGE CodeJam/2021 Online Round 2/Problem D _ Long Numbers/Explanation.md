# Description:

Albert is interested in arithmetic sequences, and is creating interesting problems.

First, he'd pick two positive integers a and b, and define an arithmetic sequence x: xi := a + b * (i-1). That is, x1 = a, x2 = a+b, x3 = a+b*2, and so on.

Albert didn't think carefully when he wrote x1, x2, x3, ... with no spaces in-between (from left to right), and ended up writing a really long number.
At this point, Albert is now curious what the c-th digit (from the left) would be in this long number.

For instance, when a = 1 and b = 1, Albert would have written the following number (for the first 21 numbers in the sequence): 123456789101112131415161718192021... Then, the 15th digit is "2" (coming from "12") and the 16th digit is 1 (coming from "13").

Another example: when a = 3 and b = 7, the long number would be (for the first 11 numbers in the sequence): 310172431384552596673...

Then, the 15th digit is "2' (coming from "52") and the 16th digit is 5 (coming from "59").

Given a, b, and c, find the c-th digit (from the left) in the long number that Albert obtains by writing the arithmetic sequence xi = a + b * (i-1) with no spaces.

* **Input**
The first line will contain the number of test cases, T.

Each test case will be given in a single line that contains a, b, and c separated by a whitespace.

* **Output**

Output the answer for each test case in a single line.

* **Limit**
```
1 ≤ T ≤ 5,000
1 ≤ a, b, ≤ 10^6
1 ≤ c ≤ 10^12
```

* **Sample Input**
```
8
1 1 15
1 1 16
3 7 15
3 7 16
21 1 15
21 1 16
4 3 1000000000
400 300 100000000
```

* **Sample Output**
```
2
1
2
5
2
8
4
1
```

# Solution
When creating an arithmetic sequence with a given input, you need to be able to track how many single digits appear, how many two digits appear, how many three digits appear, and so on, to find the c-th digit of the large number. In other words, we need to track all digits that appear before reaching the c-th position. To do this, we need to perform the following three steps.

* Step 1. Find the number of digits that the c-th digit is placed on.

Iterate xi = a + b * (i - 1) by increasing i and accumulate all the appeared digits until getting greater than c. This way, we can figure out the number of digits that the c-th digit is placed on. For your information, the number of digits of each number can be obtained using log10.

* Step 2. Find out how many more times to repeat within the digits.

Perform a similar process to the previous step. Find out how many more times to repeat with i until reaching the c-th position. This can be obtained by dividing the remaining number of digits by what we obtained from step 1.

* Step 3. Find the exact c-th digit within the final number.

'c' minus 'the number of digits that have been accumulated so far', this value would be the position of the final number.