# Description
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

# Solution 1: Backtracking - Recursive
* consider that we have n values 1, 2, ... n, backtracking explres all potential candidates - configurations
* it starts at the first candidate `candidate0`, then explore the potential next candidates by making recursive call `swap (candidate1, candidate2)`.
* result of backtracking creates tree structure => complexity is N!:
 - for each level of the tree: we have N options.
 - for each options, we have N-1 options.
 - there fore, for each level we have N*(N-1)*(N-2)*(N-3)*...*2*1= N!
 - there are N levels.
 - total we have  N*N!

For example: ![image info](./2.png)

# Algorithm
* Data structures to be used:

```
vector<vector<int>> permutationList;                    // a list of permutation configs
vector<int>permutation;                                 // a single permutation config
unordered_map<int,bool>markCandidates;                  // indicates if the candidate is used for permutation already (true) or not (false)
```

* **Step 1**: mark all candidate as false to indicate they have not been used in permutation.
* **Step 2**: perform backtracking starting at index = 0, create a permutation tree where each level is indicated by index
    - *recursive cases*:
        - at level 0, push to permutation 1st candidate
        - mark the candidate as true => it has been used in this permutation config
        - go to next index, make recursive call backtracking => traversing down a level
    - *base case condition*:
        - reaching the lowest level of permutation tree , also when all possible candidates have been used in permutation config
        - return the permutation.
        ```
        // base case
        if (index > nums.size()-1){
            permutationList.push_back(permutation);
            return;
        }
        ```
    - *returning from recursive cases*: go back to higher level after base case returning results.
        - restore condition: remark the candidate as false, so that when going back to higher level, it could be used in another permutation config.
        ```
        markCandidates[candidate]= false;
        ```
