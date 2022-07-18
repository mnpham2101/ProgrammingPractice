# Description
Albert is working on a fun problem. If an array A contains n+1 numbers such that it contains each integer from 1 to n-1 exactly once and it contains n twice, then A is a good array. There are exactly (n+1)!/2 good arrays of length n+1.

If A is a good array of length n+1, Score(A) is defined as follows: The number of pairs (i, j) where 1 ≤ i < j ≤ n+1 and A[i] < A[j]. If A = [1, 2, 3, ..., n-1, n, n], then Score(A) = (n+2)(n-1)/2 (which is maximum) and if A = [n, n, n-1, n-2, ..., 2, 1], then Score(A) = 0 (which is minimum).

Given n and two integers a and b, Albert wants to count the number of good arrays A of length n+1 such that a ≤ Score(A) ≤ b. For instance, suppose that n = 3, a = 2, and b = 3. Out of 12 good arrays of length n+1, there exist 6 good arrays such that a ≤ Score(A) ≤ b.

```
A = [1, 2, 3, 3]: Score(A) = 5
A = [1, 3, 2, 3]: Score(A) = 4
A = [1, 3, 3, 2]: Score(A) = 3 (OK)
A = [2, 1, 3, 3]: Score(A) = 4
A = [2, 3, 1, 3]: Score(A) = 3 (OK)
A = [2, 3, 3, 1]: Score(A) = 2 (OK)
A = [3, 1, 2, 3]: Score(A) = 3 (OK)
A = [3, 1, 3, 2]: Score(A) = 2 (OK)
A = [3, 2, 1, 3]: Score(A) = 2 (OK)
A = [3, 2, 3, 1]: Score(A) = 1
A = [3, 3, 1, 2]: Score(A) = 1
A = [3, 3, 2, 1]: Score(A) = 0
```

Given n, a, and b, compute the number of good arrays A of length n+1 such that a ≤ Score(A) ≤ b is satisfied.

* **Input**
The first line will contain the number of test cases, T.

Each test case will be described in a single line that will contain n, a, and b, separated by a whitespace.

* **Output**
For each test case, output the answer in a single line.

Since the answer can be very large, output the answer modulo 109+7 (= 1,000,000,007).

* **Limit**
```
1 ≤ T ≤ 10,000
2 ≤ n ≤ 1,000
0 ≤ a ≤ b ≤ 1,000
```
* **Sample Input 1**
```
5
3 2 3
4 0 1
4 4 5
8 10 20
12 0 77
```
* **Sample Output 1**
```
6
4
22
123924
113510379
```
Case 1: Explained in the problem statement.

Case 2: These four arrays meet the requirements: [4, 4, 3, 2, 1], [4, 4, 3, 1, 2], [4, 4, 2, 3, 1], [4, 3, 4, 2, 1]

Case 3: No explanation is provided.

Case 4: No explanation is provided.

Case 5: All good arrays of length 13 satisfy the requirements, so the answer is 3113510400. However, you must output the answer modulo 10^9+7, which is 113510379.

# Solution:

If an array of size n+1 is given, and filled with 1,2,3,...., n-1, n,n, it is a good array.
A good array of Score is defined by the following equation.
Score(A) => Number of pairs (i, j) satisfying 1 ≤ i <j ≤ n+1 and A[i] <A[j]
Given n, a, and b, compute the number of good arrays A of length n+1 such that a ≤ Score(A) ≤ b is satisfied.
Solution
Brute Force
After arranging the elements of n+1 (remove duplicates), calculate the score value of each array.

The time complexity is n! * becomes n2.

Dynamic Programming


Let F(n,k) be defined as the number that satisfies score[k] of a good array of size n+1.

In the case of n=2,
   F(2,0) => 1 ( 2,2,1)

   F(2,1) => 1 (2,1,2)

   F(2,2) => 1 (1,2,2)



You can get the result of F(3,k) from F(2,k).
If add 0 to each digit in (2,2,1),
   (0,2,2,1)

   (2,0,2,1)

   (2,2,0,1)

   (2,2,1,0)


Since the score is comparison of a pair of numbers, score(0,2,2,1) equals score(1,3,3,2).
That is, it is a comparison of relative sizes, and the absolute numeric values ​​do not have to be the same.
We can get below equation:

```
F(n,k) = F(n-1, k-n) + F(n-1, k-n+1) + F(n-1, k-n+2) + .... + F(n-1, k)
score[i]    0   1   2   3   4   5
n = 2	    1	1	1	0	0	0
n = 3	    1	2	3	3	2	1
```

The time complexity becomes O(n*n*n).
It can be reduced to O(n*n) by using the prefix sum algorithm.