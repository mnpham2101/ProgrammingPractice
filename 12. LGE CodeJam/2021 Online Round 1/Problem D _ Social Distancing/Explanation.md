# Description
Albert needs to help setup a Hackathon event, adhering to social distancing rules. There will be a long corridor (hallway) along which a booth with a desk, chair, and monitor will be installed. Each booth can accommodate one team. s teams will participate in the event, and there are n locations (electronic outlets) at which a booth can be set up. Let x[1], x[2], ..., x[n] be locations of the outlets (x[i] is the distance from the corridor entrance). That is, the i-th outlet is located at x[i] meters from the entrance.

Albert needs to select s locations out of n outlets while maximizing the distance (call it D) between two closest outlets.

For instance, suppose n = 3, s = 3, and x = [10, 100, 200]. In this case, because n = s, each booth must be set up at each location. The closest distance between booths is (100 - 10) = 90. In another example, suppose n = 6, s = 4, and x = [11, 19, 24, 26, 29, 30]. In this case, choosing four outlets at x[1] = 11, x[2] = 19, x[3] = 24, and x[4] = 29 ensures that the closest distance between booths is 5. Or, Albert can also choose x[1] = 11, x[2] = 19, x[3] = 24, and x[4] = 30 with the same closest distance. In this example, it is impossible to set up 4 booths with closest distance greater than or equal to 6.

Given n, s, and x[1], ..., x[n] as input, find the maximum D that Albert can achieve.

* **Input**
The first line will contain the number of test cases, T. Each test case will be described in two lines.

The first line will contain two integers, n and s, separated by a whitespace. The next line will contain n integers separated by a whitespace, describing n locations at which outlets are installed.

* **Output**
For each test case, output the maximum D that Albert can achieve.

* **Limit**
```
1 ≤ T ≤ 10
2 ≤ s ≤ n ≤ 200,000
1 ≤ x[i] ≤ 1,000,000,000
You may assume that x[i]'s are distinct.
```
* **Sample Input 1**
```
3
3 3
10 100 200
7 3
28 11 17 19 21 22 23
6 4
11 19 24 26 29 30
```
* **Sample Output 2**
```
90
8
5
```

# Solution:

A array of length N is given which represent the position of electronic outlets.

In this problem, we should find maximizing distance between two closest electronic outlets among s locations of electronic outlets.

Let's define the distance of two closest outlets as D.

It is easily think that if we increase D more and more to maximize its number, we may not select s locations of electronic outlets at some moment.

From this intuition, the final answer D can be obtained just before the moment we could not select s locations of electronic outlets.

So, to find answer, we need to keep inspect whether we can select s locations with current D.

* **Brute Force**
We can search maximum D from the smallest(=1) till the given condition does not meet.

This can be done in O(max{x[i]}) time complexity.

However, as x[i] can be large as 1,000,000,000, this method can not make solution within time limit boundary.

* **Binary Search**

We can select s locations of outlets with the smallest D(=1) initially, but we can not select s outlets anymore after meet some boundary value of D.

Which means, the condition whether we can select s outlets or not is dependent with D values and it is monotonic(True → False).

So, in this case we can apply binary search for the D.

From this method, time complexity is O(N log2(max{x[i]})) and can make solution for this problem.