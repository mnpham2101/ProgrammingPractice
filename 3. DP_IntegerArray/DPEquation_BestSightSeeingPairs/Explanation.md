# Description
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

# Solution 1: Greedy
* observe that for each subproblem, we want to make choice:
```
    if (currentValues + currentPosition) > (bestPlaceSofar + bestPosition)
        bestPlaceSoFar = current;
        bestPlaceLocation = currentLocation;
```
* the final calculation:
```
    int current_score = bestPlaceSoFar + current + (bestPlaceLocation - currentLocation);
    // update best score
    if (current_score > bestScore){
        bestScore = current_score;
    }
```

# Solution 2: DP equations
* Since the score is calculated as `score = place1 + position1 + place2 - position2`
    - we need to find maximum of `place1 + position1` and `place2 - position2`
    - make 2 DP arrays to store some values such as `place + position` and `place2 - position2` and find the max of 2 arrays.
* however, since we visit i before j, we cannot just add the max of the 2 arrays to get score. In addition we can't just make `dp1[], dp2[]` to simply store `place + position` and `place2 - position2`

 ![image info](./1.png).

* we fix by:
    - make dp1[] dp2[] to only store best value of `place + position` and `place2 - position2`
    - update dp[1] from index = 0 to n-1
    - update dp[2] from index = n-1 to 0
    - get the score by getting `max of dp1[]+dp2[]`