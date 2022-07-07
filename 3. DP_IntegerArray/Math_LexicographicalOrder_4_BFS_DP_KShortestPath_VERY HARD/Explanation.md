# Description
Alice and Bob enjoy finding the shortest path in a graph.

Bob, Alice's little brother, is little and often makes mistakes -- so, Alice is helping Bob practice with the following problem.

First, they choose an integer L (for "length"), and create a graph using 10L positive integers from 0 to (10^L-1) as follows:

`Nodes`: Each integer between 0 and (10^L-1) represents a node in the graph. In this graph, each node's label must have length L (by using leading zeros if necessary) -- hence, you may think of the label as a string of length L. For instance, if L = 2, the graph would contain 100 nodes with labels 00, 01, 02, ..., 98, and 99.

`Edges`: For any two nodes x and y, if their labels differ in only one position (out of L positions) and the difference must be exactly 1. For instance, when L = 2, there exists an edge between 00 and 01, between 01 and 11, between 27 and 37, and between 36 and 46; yet there is no edge between 00 and 02, between 01 and 10, between 36 and 47, or between 46 and 57.
The image below illustrates a part of the graph when L = 2.

![image info](./1.png)

After creating a graph, Alice would ask Bob to find the K-th shortest path (in lexicographic order) from x to y. For instance, suppose L = 2, x = 37, and y = 55. In this case, the shortest paths between x and y have length 4, and there exist 6 shortest paths. If K = 3, then the answer would be the third shortest path, 37 -- 36 -- 46 -- 56 -- 55.

```
37 -- 36 -- 35 -- 45 -- 55
37 -- 36 -- 46 -- 45 -- 55  (Because "35" comes before "46" lexicographically, the path above comes before this path, lexicographically.)
37 -- 36 -- 46 -- 56 -- 55  (Because "45" comes before "56" lexicographically, the path above comes before this path, lexicographically.)
37 -- 47 -- 46 -- 45 -- 55  (Because "36" comes before "47" lexicographically, the path above comes before this path, lexicographically.)
37 -- 47 -- 46 -- 56 -- 55  (Because "45" comes before "56" lexicographically, the path above comes before this path, lexicographically.)
37 -- 47 -- 57 -- 56 -- 55  (Because "46" comes before "57" lexicographically, the path above comes before this path, lexicographically.)
Given L, K, x, and y, help Bob find the K-th shortest path from x to y. If there exist fewer than K shortest paths from x to y, then output "NO" instead (see the sample test cases).
```

**Input**
The first line of the input will contain T, the number of test cases.

Each test case will be given by a single that will contain L, K, x, and y, separated by whitespace.

**Output**
Output the answer in each line.

If the K-th shortest path exists, then output the path. Otherwise, output "NO" (without quotes).

**Limit**
```
1 ≤ T ≤ 15
2 ≤ L ≤ 4
1 ≤ K ≤ 1018
0 ≤ x, y < 10L (In all test cases, x and y will be given as strings of length L by containing leading zeros if needed -- see the sample test cases)
```

**Sample Input**
```
7
2 1 20 22
2 2 20 22
3 3 008 258
3 22 008 258
4 10 2022 3141
4 61 2022 3141
4 1000000000000000000 0000 9999
```
**Sample Output**
```
20 21 22
NO
008 018 028 038 048 148 248 258
NO
2022 2021 3021 3031 3041 3141
NO
0000 0001 0002 1002 1012 1022 1122 1123 1133 1143 1243 2243 3243 3244 4244 4254 4354 4364 5364 6364 6464 6474 6484 6584 6684 7684 7784 7785 7786 7787 7788 7888 7988 8988 8998 9998 9999
```

# Solution 1: BFS

1. **BFS**

In general, most path problems can be solved with BFS. Therefore, you can try to solve this problem with BFS. One of the two numbers is selected as the root node, and the child nodes are searched by changing the number of each digit one by one. Whenever each child node is searched, the path it has passed is also saved. If the search result shows one remaining number, the path is saved, the search is stopped at the node, and another node is searched.

This method can be solved only when the number of digits is limited. This is because as the depth of the search increases once, the number of child nodes to be searched increases as much as (number of digits * 2)depth .

2. **Observation**

When moving, the possible move to make the shortest path is limited according to the magnitude relationship of each digit of x and y. If the digit of x < the digit of y, you can always move only in the direction of increasing that digit. Conversely, if the digit of x > the digit of y, you can always move only in the direction of decreasing digit.

If you don't move like this, you have to come back, so you can't make the shortest path.

Applying this observation to BFS, we can reduce the number of searches from (number of digits * 2)^depth to (number of digits)^depth .

3. **Multinomial Coefficient**
When x and y are 4 digit numbers, let the difference of each digit be D1, D2, D3, D4. According to the above observation, the length of the shortest path is D1 + D2 + D3 + D4. Therefore, if every move is different, the number of shortest possible paths is (D1 + D2 + D3 + D4)! .

In reality, because all movements of same digit cannot be distinguished, the number of shortest possible paths is (D1 + D2 + D3 + D4)! /(D1! D2! D3! D4!) .

The above equation is called multinomial coefficient.

4. **Efficient Search**

Based on the observations above, we know the four numbers that can be moved from the current number. And the lexicographic order of the four numbers can also be known. And the number of shortest paths from each of the four numbers to y can be calculated with the multinomial coefficient above.

Therefore, it is possible to determine which number of the four numbers to be visited to find the k-th shortest path.

In this case, the time complexity can be reduced to O(L^2 log L).

![image info](./2.png)

# Approach 2
The solution follows 4 steps:
1. **Step 1**: generate all possible nodes and neighbor nodes from range 0 to 99, 999, or 9999, depending on L=2,3,4
2. **Step 2**: use BFS to find the **shortest distance** from `destination` to every node.
3. **Step 3**: use BFS and DP to mark nodes on the shortest path from `destination` to `source`
4. **Step 4**: use the DP result in `3` to return result = Kth shortest path.

# Algorithm:
1. **Step 1**:
    - if L = 3, node= 2 ==> `00` has to be concatenated to node => use string concatenation technique.
    ```
    for (int j = 0; j < l - size; j++) {            // concatenate `0` to v_str,
            v_str = "0" + v_str;                        // if l==3 => add `00`, if l==4 => add `000`  , first `0` was initialized
        }
    ```
    - neighbor of nodes are the character incrementation => can use arithmetic to increment
2. **Step 2**:
    - use BFS to find distance from destination to source.
    - base case: distance of a node to itself is zero.
    - other cases:
        - distance of a node to neighbor is 1.
        - distance of a node to neighbor of neighbor is accumulative `dis[neighbor] = dis[element] + 1`

Example result: distance from `33` to `20`, dist[] hold the distance value.
```
dist[20]=4----dist[21]=3----dist[22]=2----dist[23]=1
    |             |             |             |
    |             |             |             |
dist[30]=3----dist[31]=2----dist[32]=1----dist[33]=0
```
3. **Step 3** *(HARDEST - MOST IMPORTANT)*
    - use bfs + dynamic programming approach to quickly find HOW MANY SHORTEST PATHS from y to x and MARK the Kth path.
    - dp[x] stores the total paths that have shortest path from y to x
    - backtracking:
        - For example if `element = 22`, `neighbor = 23`, `dist[23] == dist[22] - 1` (22 and 21 are immediate neighbor)  ==> dp[22] = +dp[23]  ==> increase from 0 to 1
        - For example if `element = 22`, `neighbor = 32`, `dist[32] == dist[22] - 1` (22 and 32 are immediate neighbor)  ==> dp[22] = +dp[32]  ==> increase from 1 to 2

Example: sample case for path from 20 <-> 33

```
dp[20] = 4----dp[21] = 3----dp[22] = 2----dp[23] = 1      // dp[22] = dp[23+1]
|             |             |             |
|             |             |             |
dp[30] = 1----dp[31] = 1----dp[32] = 1----dp[33] = 1

Notes that: path going throught 22, then down to 32 will be the K-2nd path!
```

4. **Step 4** *(SECOND HARDEST)*
    - Note that from step 3 we already mark the nodes with Kth-path.
    - to get Kth path, loop from source to destination:
        - start with current node = source.
        - add the neighbor of current node to list to consider for K-th path.
        - the node is in K-th path if `dp[node] >= tracking value`
Example:
Sample case for path from 20 <-> 33

```
dp[21] = 3 indicates it is in 3rd, 2nd, 1st K-path
dp[22] = 2 indicates it is in 2nd, and 1st K-path
if K = 3, 22 is not in the path. The path would be 20 21 32 32 33
if K = 2, 22 is in the path. The path would be 20 21 22 32 33
dp[20] = 4----dp[21] = 3----dp[22] = 2----dp[23] = 1
|             |             |             |
|             |             |             |
dp[30] = 1----dp[31] = 1----dp[32] = 1----dp[33] = 1
```

# Approach 4 - not applicable but is worth considered.
* This problem is very similar to problem https://leetcode.com/problems/permutation-sequence/solution/
* the path in this problem is the same as the permutation of all number in the sequence from x -> y
  - the path is lexigraphically ordered in the same way as the permutation is ordered.

For example: nums = {20, 21, 22}
All permutations are as followed:
```
20 21 22
20 22 21
21 20 22
21 22 20
22 20 21
22 21 20
```
However, since the problem only cares the path from 20 -> 21: there is only 1 result `20 21 22`.

* Fundamental differences:
  - the source and destination are given, and not from 1 to destination as in leetcode problem.
  - thus Kth value in this problem is different from the leetcode problem
  - we can't simple use Factorial Base Representation System to find Kth order shortest path.