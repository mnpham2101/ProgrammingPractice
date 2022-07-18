# Description

Orca and Dolphin love to play a card game together.

Every card is colored red (R), yellow (Y), or blue (B), and it has a digit (0-9) written on it.

There may exist more than one card with the same color and number.

Orca has been losing every game lately, and is beginning to suspect whether Dolphin is cheating by swapping card(s) while they are playing the game.

Orca has a great memory, and therefore can remember the n cards he saw before they played a game as well as the n cards that were played during the game.

However, Orca is not good at checking whether Dolphin cheated or not.

For instance, suppose they are playing a game with n = 5 cards as follows:
```
R0
B9
R5
Y3
R2
```
After the game was played, Orca recalls that the following five cards were played during the game:
```
R0
B8
R5
Y3
R2
```
Dolphin must have swapped B 9 (one of the cards in the original deck) with B 8 (which was not present in the original deck)!

You ought to write a program that can help Orca decide whether Dolphin cheated or not.

## **Input
The first line will contain the number of test cases T.

Each test case will be given by three lines of input.

The first line will contain n, the number of cards in the deck.

The second line will contain n strings, separated by a whitespace, where each string contains two characters. The first character is one of R, Y, and B (color) and the second character is a digit (between 0 and 9). These n strings represent the n cards in the original deck that Orca remembers.

The third line will also contain n strings in the same manner, which represent the n cards that were played during the game.

## Output
For each test case, if there is evidence that Dolphin cheated (by swapping a card in the deck with a different card not in the deck), then output "CHEATER".

Otherwise, output "NOT CHEATER".

For each test case, your output must be printed within a single line without quotes.

## Limit
```
1 ≤ T ≤ 10
1 ≤ n ≤ 200
```

## Sample Input 1
```
4
5
R0 B9 R5 Y3 R2
R0 B8 R6 Y3 R2
1
R0
R0
3
R1 R0 R0
R0 R1 R1
3
R1 R1 R0
R0 R1 R1
```
## Sample Output 1
```
CHEATER
NOT CHEATER
CHEATER
NOT CHEATER
```

## Solution 1