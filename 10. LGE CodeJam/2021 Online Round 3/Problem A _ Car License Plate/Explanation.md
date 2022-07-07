# Description

Albert sees n cars (from left to right) parked in a parking lot (for convenience, cars are numbered from 1 to n). Let x[i] be the i-th car's license plate. These n strings are distinct, and each only consists of exactly k English letters ('a'-'z' and 'A'-'Z') -- that is, license plates have the same-length strings.

For any two cars i and j, if their license plates x[i] and x[j] satisfy the following, then we say their plates are similar:

* For each of the 26 English alphabet, the number of occurrences of the alphabet (if we ignore the letter case) in x[i] is the same as the number in x[j] (this condition must be met for each alphabet).
* The number of uppercase alphabets in x[i] is the same as the number in x[j].

For instance, let n = 4, k = 3, and x = ["AtY", "YtA", "aTy", "Ayt"].

* 1st car and 2nd car's plates are similar: Both have one A/a, one T/t, and one Y/y, among which two are uppercase alphabets.
* 3rd car and 4th car's plates are similar: Both have one A/a, one T/t, and one Y/y, among which one is an uppercase alphabet.
* 1st car and 3rd car's plates are not similar: x[1] contains two uppercase alphabets and x[3] contains one uppercase alphabet (yet, the first condition on alphabets is satisfied).

Given n, k, and x[1], ..., x[n], let Albert help count the number of similar car plate pairs.

* **Input**
The first line of the input will contain a number, T, the number of test cases.

For each test case, the first line will contain n and k, separated by whitespace.

The second line of each test case will contain n strings of length k each, separated by whitespace.
* **Output**
For each test case, output the answer in a single line.

* **Limit**
```
1 ≤ T ≤ 20
1 ≤ n ≤ 100,000
1 ≤ k ≤ 20
```
* **Sample Input**
```
5
4 3
AtY YtA aTy Ayt
4 4
AAaa AaAa aaAA AaaA
5 4
AAAA aaaa AAaa AAAa Aaaa
10 1
A a B b C c D d E e
2 10
ABCDEabcde abcdeEDCBA
```
* **Sample Output**
```
2
6
0
0
1
```

Case 1: Discussed in the problem statement.

Case 2: All pairs of plates are similar.

Case 3: Plates contain different numbers of uppercase letters, and therefore no similar plates exist.

Case 4: No explanation provided.

Case 5: No explanation provided.

# Solution:

This problem can be solved in two steps:

Step 1) Classify similar license plates and check the size of each group: Tree Map - O(NlogN), Hash Map - O(N)
In order to classify similar license plates, you can count the number of letters on each license plate (condition 1), and count the number of capital letters (condition 2), and compare whether the two conditions are the same.

If you use std::map data structure implemented by binary search tree, the time complexity to store all N license plates is O(NlogN).

(If you can make a hash function without hash collision on the license plates, you can use std::unordered_map to store N plates in O(N))



Step 2) Count the number of ways to choose two from each group of license plates : O(N)
Since we already know the size of each group, the combinatorial formula gives us the number of ways to choose 2 out of N in random order.
```
nCr=n!/((n−r)!r!)
nC2=n!/((n−2)!2!)=(n−1)∗n/2
```
