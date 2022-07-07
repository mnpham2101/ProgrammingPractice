# Description:

Alice likes making rhymes with English words. Bob who is too little to make good rhymes wants to do the same -- so, Alice suggested Bob  to play the "Pseudo-rhyme Game."

First, Bob would write down n different words of length L each (for convenience, call them W[1], W[2], ..., W[n]).

For any pair of words W[i] and W[j], if their longest common suffix is of length F or more, these two words can form a pseudo-rhyme (we call such pair "a pseudo-rhyme pair").

In the "Pseudo-rhyme Game," the objective is to make as many pseudo-rhyme pairs as possible using the given n words where each word can belong to at most one pseudo-rhyme pair.

For instance, suppose n = 4, L = 4 and the 4 words are as follows: W = [ "WALK", "TALK", "MILK", "BULK" ]
```
If F ≤ 2, any pairing would result in two pseudo-rhyme pairs (e.g., WALK-BULK and TALK-MILK).
If F = 3, WALK-TALK can form a pseudo-rhyme pair, but it is not possible to have two or more piars.
If F ≥ 4, there is no way to make any pseudo-rhyme pair.
```
Given F and n words of length L, compute the maximum number of pseudo-rhyme pairs that Bob can make.

* **Input**
The first line of the input will contain T, the number of test cases.

Each test case will be given over two lines. The first line will contain n, L, and F, separated by whitespace. The second line will contain n words of length L (W[1], W[2], ..., W[n]), separated by whitespace.

* **Output**
Output the answer for each test case in each separate line.

* **Limit**
```
1 ≤ T ≤ 10
1 ≤ F ≤ L ≤ 10
2 ≤ n ≤ 500
```
Each word W[i] will consist only of uppercase English letters ('A'-'Z').
In each test case, the n words will be distinct.