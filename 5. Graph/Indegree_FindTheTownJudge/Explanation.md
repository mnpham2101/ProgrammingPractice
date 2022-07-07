# Description:

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`.

Return the label of the town judge if the town judge exists and can be identified, or return `-1` otherwise.

* Example 1:
```
Input: n = 2, trust = [[1,2]]
Output: 2
```

* Example 2:
```
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
```
* Example 3:
```
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

# Solution 1: DFS
## Problem Analysis:
* There cannot be a 2nd judge as it would violate condition 2.
* ans: found judge when condition `1` and `2` occur. 
* there can be "disjoined network": 2 different groups of people that don't have trust relations.
    * run multiple dfs. Each for a `personA`, to traverse all persons that are connected to the `personA`.
## Algorithm:
* *construct graph*: 
    * each node is a person. Mark the person as visited/not visited.
    * neighbor: 
        * construct 2D vectors `trustMap` to store the number of people that trust this person. `row= person`, `col= trusters`. Number of col for each row: number of people the trust this person.
        * `next = trustMap[curr][i]`
* each DFS returns -1 or the judge.

# Solution 2: Hashmap
## Problem Analysis:
* Consider the directed graph:
    * *Outdegree* of a vertex (person)* is the number of directed edges going into it. So here, it represents the number of people trusted by that person. For this graph, the outdegree of the vertex represents the number of other people that person trusts.
    * *Indegree* of a vertex (person) is the number of directed edges going into it. So here, it represents the number of people trusted by that person.
* note that there is no need to construct a graph as this problem only needs to calculate the *outdegree* and *indegree* of each vertex.
* ans: found judge when condition `1` and `2` occur. 
    * construct data structure to query every person and check if the 2 conditions are satisfied. 
## Algorithm:
* create 2 maps `truster` (outdegree), and `trustee` (indegree). Key= person, value: the number of people that the person trust or is trusted.
* for every person in `trustee`
    * check that he doesn't trust any one (can't find him in `truster`)   ==> O(logN)
    * check that the number of people that trust him is `n-1`

# Solution 3: Indegree-Outdegree using 1 Array
## Algorithm:
* Instead of using 2 arrays, each for *Outdegree* and *Indegree*, use 1. 
* Observe that the judge has every one trust him  (indegree = n-1) and he trusts noone (outdegree=0). Thus the definition of a judge is: 
    * `indegree - outdegree = n-1`
* Construct a vector to store `score`: 
    * each person gains 1 if he is trusted by someone. 
    * each person loose 1 if he trusts someone else.
    * if score[person] = n-1, the judge is found. 
