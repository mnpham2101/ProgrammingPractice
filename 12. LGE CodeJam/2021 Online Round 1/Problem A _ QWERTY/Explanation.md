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