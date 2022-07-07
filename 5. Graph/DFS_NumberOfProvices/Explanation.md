# Description 

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where `isConnected[i][j] = 1` if the ith city and the jth city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the total number of provinces.

* **Example 1:**
```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
```
*** Example 2:**
```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
``` 

* **Constraints:**
```
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
```

# Solution: 
* Note that the input is a 2D array where:
    * each row list the neighbor cities that can connect to the city, named by the row index.
    * `city0` is index 0. `city1` is index 1 and so on.
    * the total number of cities are the array size isConnected.size();
* a dfs can add to `dfsStack` all the cities that are directly or indirected connected to a starting city
    * if dfsStack is empty, then there is no more connected city; a province is found. 
* for each city in input array `isConnected`, run a dfs to find all cities that could be connected to it; then increment `province count`
    * if a city has already been visited by any other city, marked by `visited`, there is no need to process that city.