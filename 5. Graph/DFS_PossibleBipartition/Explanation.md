# Explanation
We want to split a group of `n` people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array dislikes where `dislikes[i] = [ai, bi]` indicates that the person labeled `ai` does not like the person labeled `bi`, return `true` if it is possible to split everyone into two groups in this way.

## Example 1:
```
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
```

## Example 2:
```
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
```

## Example 3:
```
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false 
``` 

# Solution: DFS
## Problem Analysis: 
* answer true:  all persons are marked as `1` or `2` or not marked at all. 
* answer false: persons marked as `1` but remarked as `2`.
* is there a person that is not hated by/ doesn't hate anyone ? YES
    * that person can be in any group.
* is there a disjoin set? YES 
    * Must run multiple DFS, each for a `person` to visit all candidates that have direct or indirect relation with the  first person
    * each DFS traverse all personals belonging to the same "relation network".
* is it assumed that the hatee also hate the hater ? YES, hate is a 2-way relation.
## Algorithm:
* run multiple DFS for each person, from 1 to n to assign group1, group2 to everyone that has relations. 
	* each each DFS runs will mark everyone in the same network. 
	* next DFS runs only start with personals that were not assigned to any group.
* *construct graph*:
    * node: person, id 1-> n; mark visited `1` or `2` for `group1`, `group2`.
    * neighbor nodes: 
        * create 2D vectors, row: hater, col: hatees to store relation between everyone. Assume hatee also hate the hater.
        * add neighbor to dfsStack: add everyone to queue, mark the neighbor with opponent group. (if mark[curr]==1, mark[neigh]=2)
* for each DFS run:
    * break from loop and return false if neighbor was marked the same group with curr. 
    * otherwise, dfsStack is empty, return true.  
