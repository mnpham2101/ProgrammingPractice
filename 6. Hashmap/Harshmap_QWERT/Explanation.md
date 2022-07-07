# Description

![image info](./1.png)

Albert wants to enter a string that consists of uppercase English letters ('A'-'Z') using a QWERTY keyboard (see the image above). Albert isn't good at typing yet, and only wants to use his left index finger.

It takes 1 second to press a button to enter one character, and moving the finger from one button to its adjacent button takes 2 seconds (assume that the finger never leaves the keyboard while entering a string.

Each button has up to six adjacent buttons. For instance, moving the finger from S to A, W, E, D, X, or Z takes 2 seconds.

Albert starts by placing his index finger on the button for the first character in the string, and then measures time.

```
If "QWERTY" is to be entered, then it takes 16 seconds to enter it as follows:
First, place the finger on button Q. (Time to do this is not measured.)
Pressing and releasing the button (to enter Q) takes 1 second. (Total: 1 second)
Moving to W takes 2 seconds. (Total: 3 seconds)
Pressing and releasing the button (to enter W) takes 1 second. (Total: 4 seconds)
Moving to E takes 2 seconds. (Total: 6 seconds)
Pressing and releasing the button (to enter E) takes 1 second. (Total: 7 seconds)
Moving to R takes 2 seconds. (Total: 9 seconds)
Pressing and releasing the button (to enter R) takes 1 second. (Total: 10 seconds)
Moving to T takes 2 seconds. (Total: 12 seconds)
Pressing and releasing the button (to enter T) takes 1 second. (Total: 13 seconds)
Moving to Y takes 2 seconds. (Total: 15 seconds)
Pressing and releasing the button (to enter Y) takes 1 second. (Total: 16 seconds)
```
```
It takes 9 seconds to enter "LOM".

Pressing and releasing the button (to enter L) takes 1 second. (Total: 1 second)
Moving to O takes 2 seconds. (Total: 3 seconds)
Pressing and releasing the button (to enter O) takes 1 second. (Total: 4 seconds)
Moving to M takes 4 seconds (O -> K -> M is the fastest way to move). (Total: 8 seconds)
Pressing and releasing the button (to enter M) takes 1 second. (Total: 9 seconds)
Given a string consisting only of uppercase English alphabets ('A'-'Z'), compute the fastest time (in seconds) needed for Albert to enter the string.
```

**Input**

The first line of input will contain T, the number of test cases.

For each test case, a single will contain a string (with no whitespaces) consisting of uppercase English alphabets.

**Output**

For each test case, output the least amount of time (in seconds) that Albert needs to enter the given string.

**Limit**
```
1 ≤ T ≤ 10
2 ≤ Length of an input string ≤ 100
Each string only contains uppercase English alphabets ('A'-'Z')
```
# Approach 1 - Brute Force - find distance via BFS
* use 2D array to illustrate the layout of the keyboard
```
int array [3][9] =  { { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' },
                      { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                      { 'Z', 'X', 'C', 'V', 'B', 'N', 'M'} }

```
1. How to know the index of the source, destination key?

if `vector<vector<int>>` is used, std::find('A') could be used.

2. How to know the adjacent keys ? use a lot of if conditions to add neighborlist

* if `array[0][0]` => neighbor are ...
* if `array[1][0]` => neighbor are ...
* if `array[2][0]` => neighbor are ...
* if `array[0][9]` => neighbor are ...
* if `array[1][8]` => neighbor are ...
* if `array[3][7]` => neighbor are ...
* else there are 6 neighbor keys ...

3. How to know the distance between source and destination?
* use bfs to find shortest path -> pathQueue size returns the number of keys that has to be traversed.
* *note* the distance is not subtraction between the indexes of the 2 keys.

4. What is the answer?
ans = length of string + distance between all keys.

# Approach 1 - Greedy - find distance by indexes.
* use 2D array to illustrate the layout of the keyboard

```
                         0    1    2    3    4    5    6    7    8    9
int array [3][9] =  { { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' },     0
                      { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},           1
                      { 'Z', 'X', 'C', 'V', 'B', 'N', 'M'} }                    2
```
1. How to know the index of the source, destination key?

use `map<pair<int, int>> keyPostion` to store and easily retrieve the key and its position.

2. How to know the adjacent keys ? use a lot of if conditions to add neighborlist

* there is no need to track adjecent keys and store adjacent keys.

3. How to know the distance between source and destination?

* case 1: `W` -> `B`: `distance = (4-1) + (2-0) = 5`                ok
* case 2: `F` -> `B`: `distance = (4-3) + (2-1) = 2`                ok
* case 3: `G` -> `B`: `distance = (4-4) + (2-1) = 1`                ok
* case 4: `F` -> `D`: `distance = (2-3) + (1-1) = -1`               not ok
instead: `distance = abs((2-3)) + abs((1-1)) = 1`                   to be revisited
* case 5: `F` -> `T`: `distance = (4-3) + (0-1) = 0`                not ok
                      `distance = abs((4-3)) + abs((0-1)) = 2`      not ok
instead: `distance = max ( abs (4-3), abs(0-1)) = 1`                ok
* review case 4: `F` -> `D`: `distance = max ( -1, max ( abs(2-3), abs(1,1) ) = 1`
* case 6: `Y` -> `Z`: ``distance = max ( abs( (2-0) + (0-5) ), max ( abs(2-0), abs(0-5) ) = 5`

**general formula**

```
distance = max ( abs ((row1-row2)+(col1-col2)), max (abs(row1-row2), abs(row1, row2)))
```