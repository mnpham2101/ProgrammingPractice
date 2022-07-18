# Description:

You have N plushie toys that are numbered from 1 to N.  You want to partition them into two groups.
Some pairs are not so friendly to each other (e.g., a doggy toy and a kitty toy, or a Batman toy and a Joker toy), and you can't keep such pairs in the same group.

For instance, let N = 3 and { (1, 2), (2, 3), (3, 1) } represent unfriendly pairs of toys (that is, toy 1 and toy 2 cannot be in the same group, and so on). In this case, it is impossible to divide toys into two groups while keeping unfriendly pairs separated.
In another example, let N = 4 and { (1, 2), (2, 3), (3, 4), (4, 1) } represent unfriendly pairs of toys. In this case, we can divide them into two groups {1, 3} and {2, 4} so that all unfriendly pairs are separated.

Given N toys and M unfriendly pairs, decide whether you can divide them into two groups so that every unfriendly pair would be separated.

## **Input**
The first line will contain the number of test cases, T.

For each test case, the first line will contain two integers, N and M, separated by a whitespace.

Each of the next M lines will contain a pair of integers (an unfriendly pair) separated by a whitespace.

## **Output**
For each test case, output "YES" if N toys can be divided into two groups with all unfriendly pairs separated; otherwise output "NO" (all in uppercase except quotes; quotes here are for clarity).

## **Limit**
```
1 ≤ T ≤ 10
Each unfriendly pair will contain two distinct numbers
In each test case, no unfriendly pairs will be given as input more than once (i.e., if "x y" is a part of input, then no more "x y" or "y x" will be given for the same test case)
Subtask 1 (4 Points)
3 ≤ N ≤ 16
1 ≤ M ≤ 16
Subtask 2 (8 Points)
3 ≤ N ≤ 300,000
1 ≤ M ≤ 300,000
```

## **Sample Input 1**
```
3
3 3
1 2
2 3
3 1
4 4
1 2
2 3
3 4
4 1
6 6
1 2
2 3
1 4
1 5
6 2
4 6
```
## **Sample Output 1**
```
NO
YES
YES
```
* Case 1 and Case 2 were discussed in the problem statement.

* In Case 3, {1, 3, 6} and {2, 4, 5} would be a valid partition.

# Solution: Brute Force

Since the total number of cases in which the toy can be placed is 2^N, and the number of conditions to be checked in each case is M, the time complexity is O(2^N *M) when using the Brute Force algorithm that checks the number of all cases.

In case of subtask1, N value is 16 or less. So it is necessary to calculate up to 2^16 * 16 = 1048576 times, which is a level that can be solved by the Brute Force algorithm.

# Solution: Disjoined set

If you think of the N toys as the vertices of the graph, and the list of pairs that cannot be a given alliance as the list of edges of the graph, you can see that it is a problem of discriminating a binary graph.

(Neighboring vertices (=toys) must belong to different groups (=alliance).) To determine the bipartite graph, the entire vertex can be solved by visiting BFS (or DFS).

In case of BFS, when checking the connected vertex from the current vertex, if it is the first vertex visited, set the vertex to reverse group and add it to the list of vertices to be visited later.

If the vertex has already been visited, check the group of the vertex. If the groups are designated the same, it is not a binary graph because it does not satisfy the condition. "The neighboring vertices (= toys) must belong to different groups (= allies)."

The time complexity is O(N+M) because the entire vertex and edge are searched.


And you can also use "Disjoint Set" data structure to solve this problem.

As this problem requires to separate toys in 2 groups, you can make this group by considering the proposition "Enemies of my allies are also my enemies"(refer to the c++ implementation, merge & enemy functions).

You only need to check whether this proposition was broken or not to get answer.

When you using "Disjoint Set" data structure to grouping toys, operation time can be significantly improved by "path compression & union by rank" methods  which described in below code and https://en.wikipedia.org/wiki/Disjoint-set_data_structure.

