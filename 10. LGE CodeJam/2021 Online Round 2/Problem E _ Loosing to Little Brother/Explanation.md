# Description:

Alice and Albert often play card games, and Alice deliberately loses to Albert since her little brother, Albert, gets too sad when he loses.

The game that these two kids play uses n cards, each of which has one uppercase English letter (A-Z) written on it.

They play the game according to the following rules, and Alice know exactly how Albert will play (since he is too little!).

* First, the two kids will put n cards on the floor from left to right in arbitrary order.
* They take one card each in turn, and a player can only take the leftmost card or the rightmost card.
* Albert goes first, and then they take turns.
    * During Albert's turn, if Albert takes any card that has one of the six letters in "ALBERT", then Albert scores 2 points.
    * During Alice's turn, if Alice takes any card that has one of the five letters in "ALICE", then Alice scores 1 point.
* Albert always takes a card according to the following pattern:
    * If both leftmost card and rightmost card can give him points, Albert always takes the leftmost card.
    * If neither of the two cards can give him points, Albert always takes the rightmost card.
    * If only one of the two cards can give him points, Albert always takes the card that can give him points.

Alice wants to lose to Albert, but she wants to minimize the score difference, (Albert's score - Alice's score).

For instance, suppose that n = 4 and the cards on the floor are "BCCB".

* Turn 1: Albert will take the leftmost card "B", and scores 2 points. The remaining cards are "CCB".
* Turn 2: Alice can take either the leftmost "C" or the rightmost "B".
    * If she takes the leftmost "C": She scores 1 point, and "CB" remain. Albert takes the rightmost "B", and Alice takes the final "C". Albert's score is 4 and Alice's score is 2 (the difference is 2).
    * If she takes the rightmost "B": She doesn't score any points, and "CC" remain. Albert takes the rightmost "C", and Alice takes the final "C". Albert's score is 2 and Alice's score is 1 (the difference is 1).
* In this example, if Alice tries her best to lose to Albert with smallest score difference, then she can barely lose with the difference of 1 point.

In another example, suppose that n = 4 and the cards on the floor are "CLCD".

* Turn 1: Albert will take the rightmost card "D", and scores 0 points. The remaining cards are "CLC".
* Turn 2: Alice can take either the leftmost "C" or the rightmost "C".
    * If she takes the leftmost "C": She scores 1 point, and "LC" remain. Albert takes the leftmost "L" (and scores 2) and Alice takes the final "C". It's a draw as both players score 2 points.
    * If she takes the rightmost "C": She scores 1 point, and "CL" remain. Albert takes the rightmost "L" (and scores 2), and Alice takes the final "C". It's a draw as both players score 2 points.
* In this example, if Albert were to take the leftmost "C" in turn 1, then Alice could have taken the rightmost "D", followed by Albert taking the rightmost "D" and Alice taking the final "L", which would have resulted in Alice losing by 1 point. However, Albert always takes the rightmost card when neither cards give him points, and therefore Alice cannot lose to Albert in this example.

Given n cards on the floor (from left to right), calculate the smallest score difference by which Alice can lose to Albert.

* **Input**
The first line will contain the number of test cases, T.

Each test case will be given in a single line that contains a string consisting only of uppercase English letters.

* **Output**

For each test case, output the smallest score difference when Alice deliberately loses to Albert.

If there is no way Alice can lose to Albert, output -1.

* **Limit**
```
1 ≤ T ≤ 30
1 ≤ n ≤ 150 (n: the length of the string)
Input strings will only consist of uppercase English alphabets (A-Z).
```

* **Sample Input**
```
5
ABA
BBB
BCCB
CLCD
ALBERT
```

* **Sample Output**
```
3
4
1
-1
4
```
Case 1: Albert takes the leftmost A (+2), Alice takes the rightmost A (+1점), and Albert takes the remaining B (+2점), which makes the score difference 3. There is no way to lose with score difference less than 3.

Case 2: Alice cannot score at all, and Albert will score 4 points.

Cases 3-4: Used in the problem statement.

Case 5: The two kids will take A, L, B, and E in this order (during the first four turns) so that Albert's score is 4 and Alice's score is 2.
Then, Albert would take R (his final score is 6) and Alice T (her final score is 2), and the score difference is 4.

# Solution:

We can gather the following observations from intuition.

It is possible to have a selection in ALICE's turn only(total floor(N/2) times)
So, we need to have a optimal selections(draw a card from the front or the back of remaining deck) in all ALICE's turn to make the smallest score difference at last.
It is not easy to get the optimal selections if we only consider some part of information(current score differences, previous selections, etc) mentioned #2.
(As we didn't know whether current score difference is the best or not)
So, we can see that it's not possible to get the solution with some greedy approach(make decisions at ALICE's turn based on considering some part of the information).

We need to consider the whole possible cases.

Brute Force
As talked above, most simply let's consider whole possible cases.

This means, simulating every selection of ALICE's(take a card from the front or the back) while accumulating each players(ALICE and ALBERT) scores.

In this method, we can find solution by comparing every possible score differences if and only if score(ALICE) < score(ALBERT) at the end of the game(there's no remaining card deck).

However, the time complexity of this method is O(2N/2). As given N<=150, we can not solve this problem within time limit boundary.

* **Dynamic Programming**
As we checked above, we can not solve this problem neither greedy approach(because we can not find optimal) or brute force approach(required time for computation is too big).

So, let's consider lessen computation by dynamic programming.

First, let's define sub problem's state as below.

D(left, right, G1, G2) : represent ALBERT has G1 score and ALICE has G2 score while remaining range of cards deck index is [left, right)

And now let's check whether it has overlapped computation or not.

As we can see the below example, there can be overlapped state exists.

![image info](./1.png)

By using memoization table, we can compute these overlapped states only once.



We can find the smallest score difference by checking every possible G1, G2 pairs(G1>G2) whenever left==right(condition of there's no remaining card deck) with state of each sub problem and memoization table.



Here's the recurrence relation rules.

D(left, right, G1, G2) =
In ALBERT's turn,
(left-1)-th letter is in "ALBERT" → D(left-1, right, G1-2, G2)
(left-1)-th letter is NOT in "ALBERT",
(right+1)-th letter is in "ALBERT" → D(left, right+1, G1-2, G2)
(right+1)-th letter is NOT in "ALBERT" → D(left, right+1, G1, G2)

In ALICE's turn(OR both 1 & 2 conditions),
1. (left-1)-th letter is in "ALICE" → D(left-1, right, G1, G2-1)
    (left-1)-th letter is NOT in "ALICE" → D(left-1, right, G1, G2)
2. (right+1)-th letter in "ALICE" → D(left, right+1, G1, G2-1)
    (right+1)-th letter is NOT in "ALICE" → D(left, right+1, G1, G2)

Now let's check space & time complexities.

Every possible card deck ranges are O(N2), and for each range, ALICE & ALBERT can have the score range O(N) for each.

So, required space & time complexities are O(N4).

This is not applicable for given N<=150, because it cause time or memory limit exceed error.

However, let's consider state carefully.

Actually we don't need to consider a state with score distributions for ALBERT and ALICE separately.

This is because we only care about the score differences between ALBERT and ALICE.

So, let's refine our sub problem's state as below,

D(left, right, Gdiff): represent score differences(score(ALBERT)-score(ALICE)) is Gdiff while remaining range of cards deck index is [left, right)


As score difference can be smaller than 0, we need to have some "offset" to handle this if we consider using array.

Recurrence relations are shown below,

* D(left, right, Gdiff) =
    * In ALBERT's turn,
        * (left-1)-th letter is in "ALBERT" → D(left-1, right, Gdiff-2)
        * (left-1)-th letter is NOT in "ALBERT",
            * (right+1)-th letter is in "ALBERT" → D(left, right+1, Gdiff-2)
            * (right+1)-th letter is NOT in "ALBERT" → D(left, right+1, Gdiff)


* In ALICE's turn(OR both 1 & 2 conditions),
    * (left-1)-th letter is in "ALICE" → D(left-1, right, Gdiff+1)
        * (left-1)-th letter is NOT in "ALICE" → D(left-1, right, Gdiff)
    * (right+1)-th letter in "ALICE" → D(left, right+1, Gdiff+1)
        * (right+1)-th letter is NOT in "ALICE" → D(left, right+1, Gdiff)


This is required O(N3) space & time complexities. And we can solve this problem with this approach.