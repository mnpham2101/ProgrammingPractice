# Description:
Alice and Bob are pirates, and they have discovered N treasure boxes in an island.

They decided to split the boxes by taking turns and claiming one treasure box at a time.

It's difficult to measure the value of each treasure box, so Alice and Bob would write down their respective valuations of each of the boxes, and share the numbers.

In other words, the i-th treasure box is worth A[i] dollars for Alice and worth B[i] dollars for Bob.

To split N treasure boxes, Alice would go first and take one of the (unclaimed) treasure boxes. Then, Bob would take one, and so on until all boxes have been claimed.

Let ScoreA (ScoreB) be the sum of the values of the treasure boxes that Alice (Bob) claimed according to her (his) valuation, respectively.

Alice wants to maximize (ScoreA - ScoreB) and Bob wants to maximize (ScoreB - ScoreA) because they both want to "win" over the other person.

Let's assume that both pirates would choose treasure boxes, optimally.

For instance, suppose that N = 3 and the following are valuations of the boxes according to Alice and Bob.

* Treasure Box 1: A[1] = 10, B[1] = 5
* Treasure Box 2: A[2] = 100, B[2] = 90
* Treasure Box 3: A[3] = 2, B[3] = 0

If Alice takes Box 2 first, followed by Bob's choice of Box 1, followed by Alice taking Box 3, then ScoreA would be 102 (dollars) and ScoreB would be 5 (dollars).

If Alice takes a different box than Box 2 in her first turn, then Bob would take Box 2 in his turn, which would result in ScoreA = 12 and ScoreB = 90.

Hence, if Alice plays optimally, she must take Box 2 in her vey first turn.

Given N and the valuations of the boxes from the two pirates, compute the value of (ScoreA-ScoreB) provided that both pirates would play optimally.

## **Input**
The first line will contain the number of test cases, T.

For each test case, the first line will contain the number of treasure boxes, N.

Each of the next N lines will contain two integers, corresponding to the valuations of a treasure box (Alice's first followed by Bob's), separated by a whitespace.

## **Output**
For each test case, your program must output the value of (ScoreA - ScoreB) provided that both play optimally.

## **Limit**
1 ≤ T ≤ 10
1 ≤ N ≤ 100,000
0 ≤ A[i], B[i] ≤ 100,000

## **Sample Input**
```
5
3
10 5
100 90
2 0
3
90 100
5 10
0 2
3
10 100
100 10
50 60
4
20 10
15 20
5 8
8 9
3
0 100
0 1000
0 10
```

## **Sample Output**
```
97
80
50
5
-100
```

## Explanation of Samples:
* Case 1

This case was described in the problem statement.

* Case 2

Alice and Bob's valuations are flipped, when compared to Case 1. In this case, Alice should take Box 1 (worth 90 dollars), and Bob would then take Box 2 (worth 10 dollars). Lastly, Alice would take Box 3, and (ScoreA-ScoreB) = 80 would be the final result.

* Case 3

In this case, regardless of which box Alice or Bob chooses in each turn, the result will be the same.

* Case 4

Alice would take Box 2 in her first turn (which is the optimal choice for Alice), and Bob would take Box 1 in his first turn (likewise, this is the optimal choice for Bob), and Alice would take Box 4 in her second turn followed by Box 3 for Bob's last turn. Therefore, we have ScoreA = 15+8=23, ScoreB = 10 + 8 = 18, which leads to  ScoreA-ScoreB = 5.

* Case 5

Alice will always end up with boxes that are worth 0 dollars. Yet, if Alice takes Box 2 in her first turn, then Bob can only take Box 1 in his first turn,  which leads to ScoreA - ScoreB = -100 that is optimal for Alice (even though it's a negative number).

# Solution:

Assume that there is a box called X, and pirate A has valued the box as X_A and pirate B has valued the box as X_B.

If A takes X, S_A will increase its value by X_A than otherwise, and S_B will decrease its value by X_B.

Therefore, S_A-S_B will increase its value by X_A+X_B.

In other words, it is best for both A and B to take X which maximizes the value of X_A+X_B.

In order to solve the problem, sort the value of (X_A+X_B) by descending order, then select the boxes from the beginning in turns.

Sum up S_A and S_B. Print S_A-S_B.

Time complexity is O(n log n), same as sorting time complexity.