# Description
Albert sees n cars (from left to right) parked in a parking lot (for convenience, cars are numbered from 1 to n). Let x[i] be the i-th car's license plate. These n strings are distinct, and each only consists of exactly k English letters ('a'-'z' and 'A'-'Z') -- that is, license plates have the same-length strings.

For any two cars i and j, if their license plates x[i] and x[j] satisfy the following, then we say their plates are similar:

1. For each of the 26 English alphabet, the number of occurrences of the alphabet (if we ignore the letter case) in x[i] is the same as the number in x[j] (this condition must be met for each alphabet).

2. The number of uppercase alphabets in x[i] is the same as the number in x[j].

For instance, let n = 4, k = 3, and x = ["AtY", "YtA", "aTy", "Ayt"].

- 1st car and 2nd car's plates are similar: Both have one A/a, one T/t, and one Y/y, among which two are uppercase alphabets.
- 3rd car and 4th car's plates are similar: Both have one A/a, one T/t, and one Y/y, among which one is an uppercase alphabet.
- 1st car and 3rd car's plates are not similar: x[1] contains two uppercase alphabets and x[3] contains one uppercase alphabet (yet, the first condition on alphabets is satisfied).

Given n, k, and x[1], ..., x[n], let Albert help count the number of similar car plate pairs.

* **Input**
The first line of the input will contain a number, T, the number of test cases.

For each test case, the first line will contain n and k, separated by whitespace.

The second line of each test case will contain n strings of length k each, separated by whitespace.
* **Output**
For each test case, output the answer in a single line.'=
* **Limit**
- `1 ≤ T ≤ 20`
- `1 ≤ n ≤ 100,000`
- `1 ≤ k ≤ 20`
* **Sample Input 1**
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
* **Sample Output 1**
2
6
0
0
1


# Approach 1  - Brute Force, comparing characters by characters
- for each license plate, use harshmap to count *each letter* in lower case and number of upper case.
- compare each license, letter by letter
- if license are similar, increment count

# Approach 2 - generate harsh key for harshmap
Solution uses harshmap to store Plate as "value" and count the number of similar plates as "value"
1. Define a `struct Plate` :
  - member variable `capital` to store the number of upper case characters.
  - member array `alpha` to store the characters.
  - comparison operator overload
    + lesser comparison base on `capital`. If plate1 has less capital character => plate1 is less.
    + similar plate: same `alpha` array and same value of `capital`
  - input stream operator overload
    + `cin>>Plate` is called and defined via `friend istream& operator >>(istream& is, Plate& plate)`
**Notes**
  - a STL map<plate, int> can find a `plate` and knows it contains a given element plate by performing comparison lesser and greater. If both returns false, then it given element is already in the map. (= operator will return true) ==> we only need to define lesser overator.
  - also C++ constructs a map in a form of a binary tree.
  - ref: https://stackoverflow.com/questions/12331708/how-does-stl-map-know-that-map-contains-a-given-element
2. Define a `harshmap <Plate, int>`:
  - value = Plate
  - key   = number of plates that are similar.
3. Count the number of similar car plate `pairs`:
  - for every group of similar plates (indicated by values): the number of similar plates is key = n
    + the number of pairs is the combinatory formular n(n-1)/2. For example, if there are 4 similar plates, then there are 2 pairs.
  - total number is increments by the number of pairs for each group of similar plates.
