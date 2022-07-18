# Description
Albert wants to solve a problem as 2020 is over and 2021 is here. For any positive integer, if the first four digits are "2020" and the last four digits are "2021", then the number is said to be meaningful. For instance, 202021 and 20202021 are meaningful, but 2020021 or 2020221 are not.

Given n integers A[1], A[2], ..., A[n], Albert wants to calculate the number of pairs of integers whose sum is "meaningful." That is, he wants to compute the number of pairs (i, j) with 1 ≤ i < j ≤ n such that A[i] + A[j] is meaningful. For instance, suppose that there are n = 4 integers, A = [101010, 101010, 101011, 101011]. In this case, A[1] + A[3] = A[1] + A[4] = A[2] + A[3] = A[2] + A[4] = 202021, and thus there are four pairs of interest: ((1, 3), (1, 4), (2, 3), (2, 4)).

Given n integers, compute the number of pairs of integers whose sum is meaningful.

* **Input**
The first line will contain the number of test cases, T. Each test case will be described in two lines.

The first line will contain n, the number of integers to be given. The second line will contain n integers (separated by a whitespace).

* **Output**
For each test case, output the number of pairs of numbers whose sum is meaningful.

* **Limit**
```
1 ≤ T ≤ 10
2 ≤ n ≤ 100,000
-2^28 ≤ A[i] ≤ 2^28
```
* **Sample Input 1**
```
3
4
101010 101010 101011 101011
5
100000 100000 100000 101011 101011
4
202021 0 1 202020
```
* **Sample Output 2**
```
4
0
2
```

Case 1: Explained in the problem statement.

Case 2: No pair of integers adds to a meaningful number.

Case 3: There exist two pairs: (1, 2) and (3, 4) as 202021 + 0 and 1 + 202020 are both meaningful.

# Solution:

* **Brute Force**

There are n * (n-1) / 2 pairs of sum with given N numbers. Naively, we can check every pairs whether its sum is "meaningful number".
Although we can get correct answer for this problem with this method, expected time complexity is O(n*n).
And as we can see the problem statement, given n is up to 100,000, maybe we cannot avoid "time limit exceeded" error with this method.


* **Check possible "meaningful number"s**
Instead of check every pair sum, we can make set of possible "meaningful number"s and searching pair whose sum to be one of those set of possible "meaningful number".
If there're small number of "meaningful number"s actually exists, then we can solve this problem with better time complexity.

Let us check then.
As given N integers has its value between -2^28 and 2^28, so that sum of these two can be maximum 2^29. And this value can not exceed 9 digit number.
So, we can see that actual possible set of "meaningful number"s with given N numbers are below.

"202021"
"20202021"
"2020"+"0"~"9"+"2021"

Total number of possible set of "meaningful number"s are 12.
Now if we choose some number A[i] from given A, then we can check whether ("meaningful number" - A[i]) exists in given A as well.
This can be easily done with Hash Table data structure.

By using Hash Table data structure, we can do this check with O(12 * n) time complexity in average and can be solve this problem.

