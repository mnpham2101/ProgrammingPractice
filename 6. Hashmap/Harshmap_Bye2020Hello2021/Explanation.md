# Description
Albert wants to solve a problem as 2020 is over and 2021 is here. For any positive integer, if the first four digits are "2020" and the last four digits are "2021", then the number is said to be meaningful. For instance, 202021 and 20202021 are meaningful, but 2020021 or 2020221 are not.

Given n integers A[1], A[2], ..., A[n], Albert wants to calculate the number of pairs of integers whose sum is "meaningful." That is, he wants to compute the number of pairs (i, j) with 1 ≤ i < j ≤ n such that A[i] + A[j] is meaningful. For instance, suppose that there are n = 4 integers, A = [101010, 101010, 101011, 101011]. In this case, A[1] + A[3] = A[1] + A[4] = A[2] + A[3] = A[2] + A[4] = 202021, and thus there are four pairs of interest: ((1, 3), (1, 4), (2, 3), (2, 4)).

Given n integers, compute the number of pairs of integers whose sum is meaningful.

**Input**
The first line will contain the number of test cases, T. Each test case will be described in two lines.

The first line will contain n, the number of integers to be given. The second line will contain n integers (separated by a whitespace).

**Output**
For each test case, output the number of pairs of numbers whose sum is meaningful.

**Limit**
```
1 ≤ T ≤ 10
2 ≤ n ≤ 100,000
-228 ≤ A[i] ≤ 228
```

**Input**
```
3
4
101010 101010 101011 101011
5
100000 100000 100000 101011 101011
4
202021 0 1 202020
```
**Output**
```
4
0
2
```

# Approach
* This problem is similar to problem "Two Sum" in leetcode, or SumOfBinaryNumbers
* Since the value of A[i] is < 2^28  ==> the sum has only 9 digits
* input numbers could be repeated => count the occurance of each number, and put to harshMap
```
unordered_map<int, ll> numbers;
for (int i = 0; i < n; ++i) {
    cin >> num;
    numbers[num] += 1;
}
```
* All possible sums are therefore:
    - 202021
    - 20202021
    - 2020**0**2021
    - 2020**1**2021
    - 2020**2**2021
    - 2020**3**2021
    - 2020**4**2021
    - 2020**5**2021
    - 2020**6**2021
    - 2020**7**2021
    - 2020**8**2021
    - 2020**9**2021
* Use harshmap to find keys such that sums adds up to target.
    - count occurance of numbers when they are input
    - search key through harshmap when targetSum - key: `find(possibleSum - harshMap[number])`
    - if found, return `all possible pairs = occurance of numberA * occurance of numberB` or `ans += harshMap[numberA] + harshMap[numberB]`
