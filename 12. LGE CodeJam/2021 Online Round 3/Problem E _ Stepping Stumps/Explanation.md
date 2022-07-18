# Description:

Albert wants to build stepping stumps using toy stumps of various size.

![image info](./1.png)


Each toy is numbered from 1 to n, and the i-th toy's height is H[i] and its radius is R[i].

Albert wants to line up the n toys from left to right while satisfying the following rules.

* Rule 1: Height of the toys should be strictly increasing from the leftmost toy to the k-th leftmost toy and then strictly decreasing from the k-th leftmost toy to the last toy. (In addition, k must satisfy 1 < k < n)
* Rule 2: Radii of the toys from left right must be decreasing, increasing, decreasing, ... OR increasing, decreasing, increasing, ...
That is, two consecutive toys' radii must differ and the difference must be alternating between increasing and decreasing.

For instance, suppose  n = 3, H = [10, 20, 30], and R = [2, 3, 4].

* If Albert lines up 1st toy, 2nd toy, and 3rd toy:
    * Rule 1: No k would satisfy this rule (note that k = 3 would violate the condition "k < n").
    * Rule 2: The radii of toys go increasing (2 to 3) and then increasing (3 to 4) again, so Rule 2 is not satisfied.
* If Albert lines up 1st toy, 3rd toy, and 2nd toy:
    * Rule 1: The first two toys' height strictly increases and the lsat two toys' height strictly decreases -- hence, Rule 1 is satisfied when k = 2.
    * Rule 2: The radii of toys go from 2 to 4 to 3 (increasing then decreasing), so Rule 2 is satisfied.
* If Albert lines up 2nd toy, 1st toy, and 3rd toy:
    * Rule 1: The heights are [20, 10, 30], which is strictly decreasing then strictly increasing (this violates Rule 1).
    * Rule 2 :The raddi of toys go from 3 to 2 to 4 (decreasing then increasing), so Rule 2 is satisfied.

In this example, Albert can line up the toys in order of (1st, 3rd, 2nd) as well as (2nd, 3rd, 1st) to satisfy both rules.

In another example, suppose n = 3, H = [10, 20, 30], and R = [2, 5, 2].

In this case, no ordering (out of six possible orderings of 3 toys) satisfies both rules.

Lastly, suppose n = 5, H = [10, 20, 30, 40, 50], and R = [2, 7, 3, 4, 6].

In this case, there are 4 ways to line up the toys to satisfy the two rules.

* Ordering as (1st, 2nd, 3rd, 5th, 4th):
    * Rule 1: Heights are [10, 20, 30, 50, 40], which satisfies Rule 1 with k = 4.
    * Rule 2: Radii are [2, 7, 3, 6, 4], which strictly increases, decreases, increases, and decreases.
(The figure above illustrates this ordering.)
* Ordering as (1st, 2nd, 4th, 5th, 3rd):
    * Rule 1: Heights are [10, 20, 40, 50, 30], which satisfies Rule 1 with k = 4.
    * Rule 2: Radii are [2, 7, 4, 6, 3], which strictly increases, decreases, increases, and decreases.
In addition, ordering toys as (3rd, 5th, 4th, 2nd, 1st) or (4th, 5th, 3rd, 2nd, 1st) would satisfy both rules.

Given n and the toys' heights & radii, determine if Albert can line up n toys according to the two rules.

## Input

The first line of the input will contain a single integer, T, the number of test cases.

Each test case will consist of three lines.

The first line will contain n. The second line will contain n integers, describing the heights of n toys (H[i]), separated by whitespace. The third line will contain n integers, describing the radii of n toys (R[i]), separated by whitespace.

# Output

For each test case, output the answer in a single line.

If there is a way to line up toys, output n toy numbers separated by whitespace in a single line. If there exists multiple answers, you may output any one of them.
If there is no way, output -1.

# Limit
```
1 ≤ T ≤ 20
1 < n ≤ 400
1 ≤ H[i], R[i] ≤ 1,000,000,000
Subtask 1 (10 Points)
1 < n ≤ 15
Subtask 2 (20 Points)
1 < n ≤ 400
```
## Sample Input 1
```
8
3
10 20 30
2 5 2
3
10 20 30
2 3 4
5
10 20 30 40 50
2 7 3 4 6
3
2 4 5
6 1 4
3
1 2 3
2 6 2
5
1 1 2 6 7
4 6 4 2 8
5
2 6 4 4 8
6 4 2 5 1
5
1 2 3 4 5
2 7 6 4 3
```
## Sample Output 1
```
-1
1 3 2
1 2 3 5 4
-1
-1
2 3 5 4 1
4 5 2 3 1
-1
```

Cases 1-3: Discussed in the problem statement.

Cases 4-8: No explanation provided.

# Solution:
* **Subtask 1**

Arrange the toys in height order.
And think of it as arranging toys on either side of the tallest toy.
Since they are sorted in height order, you only need to decide whether each toy will be on the left or on the right, based on the tallest toy.
Then, while making each case, check whether the radius rule is satisfied.

It takes O(2^n) to decide whether each toy comes from the left or the right.

* **Subtask 2**

After sorting in height order, the toys are arranged on either side of the tallest toy.
Things to consider when arranging each toy are as follows.

* Is the height of the toys on the left or right of the arranged part greater than the current toy?
* Is it the case that the toys on the left or right of the arranged part have a larger(or smaller) radius than the toy in front of them?

If the above two conditions are the same, other toys (the toys inside the arranged toys) do not need to be considered.
That is, if the above two conditions are the same when arranging a certain toy, the subsequent results are the same.
Therefore, if memoization is applied to these parts, the overlapping parts can be reduced.

Set the memoization cache to isVisited[up_lf][up_rt][i_lf][i_rt].

* up_lf : 1 if the radius of the toy on the left is greater than the radius of the toy on the right, 0 otherwise
* up_rt : 1 if the radius of the toy on the right is greater than the radius of the left toy, 0 otherwise
* i_lf : index of the left toy
* i_rt : index of right toy

The value of isVisited is if the current case has already been checked. That is, in the current state, if there is no case that can be arranged, it becomes True and no further progress is made.

If the condition is satisfied up to the toy with the lowest height and the arrangement is completed, the arrangement order is obtained by backtracking.

The time complexity is O(n^2) because each visit to the above cache takes (n*n*2*2) time.
