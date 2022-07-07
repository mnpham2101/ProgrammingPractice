# Description
Alice and Albert often play card games, and Alice deliberately loses to Albert since her little brother, Albert, gets too sad when he loses.

The game that these two kids play uses n cards, each of which has one uppercase English letter (A-Z) written on it.
They play the game according to the following rules, and Alice know exactly how Albert will play (since he is too little!).

First, the two kids will put n cards on the floor from left to right in arbitrary order.
They take one card each in turn, and a player can only take the leftmost card or the rightmost card.
Albert goes first, and then they take turns.
During Albert's turn, if Albert takes any card that has one of the six letters in "ALBERT", then Albert scores 2 points.
During Alice's turn, if Alice takes any card that has one of the five letters in "ALICE", then Alice scores 1 point.
Albert always takes a card according to the following pattern:
If both leftmost card and rightmost card can give him points, Albert always takes the leftmost card.
If neither of the two cards can give him points, Albert always takes the rightmost card.
If only one of the two cards can give him points, Albert always takes the card that can give him points.
Alice wants to lose to Albert, but she wants to minimize the score difference, (Albert's score - Alice's score).

For instance, suppose that n = 4 and the cards on the floor are "BCCB".

Turn 1: Albert will take the leftmost card "B", and scores 2 points. The remaining cards are "CCB".
Turn 2: Alice can take either the leftmost "C" or the rightmost "B".
If she takes the leftmost "C": She scores 1 point, and "CB" remain. Albert takes the rightmost "B", and Alice takes the final "C". Albert's score is 4 and Alice's score is 2 (the difference is 2).
If she takes the rightmost "B": She doesn't score any points, and "CC" remain. Albert takes the rightmost "C", and Alice takes the final "C". Albert's score is 2 and Alice's score is 1 (the difference is 1).
In this example, if Alice tries her best to lose to Albert with smallest score difference, then she can barely lose with the difference of 1 point.
In another example, suppose that n = 4 and the cards on the floor are "CLCD".

Turn 1: Albert will take the rightmost card "D", and scores 0 points. The remaining cards are "CLC".
Turn 2: Alice can take either the leftmost "C" or the rightmost "C".
If she takes the leftmost "C": She scores 1 point, and "LC" remain. Albert takes the leftmost "L" (and scores 2) and Alice takes the final "C". It's a draw as both players score 2 points.
If she takes the rightmost "C": She scores 1 point, and "CL" remain. Albert takes the rightmost "L" (and scores 2), and Alice takes the final "C". It's a draw as both players score 2 points.
In this example, if Albert were to take the leftmost "C" in turn 1, then Alice could have taken the rightmost "D", followed by Albert taking the rightmost "D" and Alice taking the final "L", which would have resulted in Alice losing by 1 point. However, Albert always takes the rightmost card when neither cards give him points, and therefore Alice cannot lose to Albert in this example.
Given n cards on the floor (from left to right), calculate the smallest score difference by which Alice can lose to Albert.

**Input**
The first line will contain the number of test cases, T.

Each test case will be given in a single line that contains a string consisting only of uppercase English letters.

**Output**
For each test case, output the smallest score difference when Alice deliberately loses to Albert.

If there is no way Alice can lose to Albert, output -1.

**Limit**
1 ≤ T ≤ 30
1 ≤ n ≤ 150 (n: the length of the string)
Input strings will only consist of uppercase English alphabets (A-Z).

**Sample Inputs**
5
ABA
BBB
BCCB
CLCD
ALBERT
**Sample Outputs**
3
4
1
-1
4

# Approach 1: Brute Force. 
* make recursive call for every turn.
* The recursive call defines: 
  - left position
  - right position
  - scores for Albert and Alice
  - player turn indicator.
* make function to perform character comparison. 

# Solution 1: Memoization
* similar problem 1: Stone Game
* similar problem 2: 

To be updated....
