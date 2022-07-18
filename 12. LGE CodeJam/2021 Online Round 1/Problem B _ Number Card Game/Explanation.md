# Description
Albert has n cards with digits written on them. Each card has exactly one of the digits between 0 and 9 written on it, and cards with a 6 or a 9 cannot be distinguished (you can rotate the card to turn 6 to 9 or turn 9 to 6).

Albert wants to make two numbers using all of his cards such that the product of the two numbers would be maximized. He must use all of his n cards, and each number must use 1 card (and at most n-1 cards). Cards with a 6 or a 9 can be rotated arbitrarily.

For instance, suppose that n = 8 and Alber's cards are given by [2, 0, 2, 0, 2, 0, 2, 1]. Then, Albert can make two numbers "2200" and "2210", whose product is 4862000. Or, he can make "2020" and "2021", whose product is 4082420. In this example, the maximum product Albert can achieve is 4862000.

Given n cards, find the maximum product Albert can achieve.

* **Input**
The first line will contain the number of test cases, T.

In each of the next T lines, Albert's cards will be described as a string consisting of digits ('0'-'9') without space.

* **Output**
For each test case, output the maximum product Albert can achieve.

* **Limit**
```
1 ≤ T ≤ 10
2 ≤ n ≤ 18
You may assume that the answer is at most 10^18 for all test cases.
```
* **Sample Input 1**
```
5
90000
66
102030
20202021
999999999999999999
```
* **Sample Output 2**
```
0
81
63000
4862000
999999998000000001
```

Case 1: No matter how you make two numbers, one of the must be 0.

Case 2: Albert can rotate the two cards to make 9*9 = 81.

Case 3: 21000 * 3 = 63000.

Case 4: Explained in the problem statement.

Case 5: 999999999 * 999999999 = 999999998000000001.

# Solution:
* **Brute force**
Find all permutations of given cards.

Then, separate each permutation into two numbers, and find the maximum for all cases.

The time complexity becomes O(n!).

Because n is up to 18, it exceeds time limit with this method.

* **Brute force + Greedy**
When we choose k cards and n-k cards to make two numbers, is it necessary to check all permutations?

To get the maximum product, we must make the largest number using cards that belong to each number. For this, we can sort the cards in descending order.

Therefore,

1. Choose k cards to make a number A. At this time, make a number by sorting to make the largest number.
2. Make a number B with the remaining n-k cards. At this time, make a number by sorting to make the largest number.

You can find the maximum product of the number A and B created through steps 1 and 2.

What about the time complexity?

The time complexity is O(2^n) because it must be calculated whether each card of n cards belongs to the number A or B.

Because n is up to 18, it does not exceed time limit with this method.

* **Greedy**

Is there any way to know which number each card belongs to?

Assuming that the cards are sorted in descending order, let's find out which number each card belongs to.

Let the number A = X, the number B = X + Y, and the next card = Z. (Number B is greater than number A by the natural number X.)

When Z is concatenated to A, and when Z is concatenated to B, the each product can be calculated as follows.

* Z is concatenated to A	(10A + Z) * B = 10X^2 + XZ + (10X + Z)Y
* Z is concatenated to B	A * (10B + Z) = 10X^2 + XZ + 10XY

We can see that the product becomes larger when the next card is attached to the smaller number.

Using this, you can obtain the maximum product by comparing the two numbers before placing the cards and concatenating it to the smaller one.

In this method, it is O(n) to make two numbers and to find the product, but since O(n log n) is required for sorting, the time complexity of this method is O(n log n).

It does not exceed time limit with this method.