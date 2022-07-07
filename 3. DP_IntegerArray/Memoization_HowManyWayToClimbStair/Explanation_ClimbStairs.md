# Problem description
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
# Solution 1 Topdown - Brute Force - Decision Tree
* Construct a decision tree (as binary tree) to analyze how many ways we can reach target from 0.![image info](./Tree_ClimbStep.png).
* Could solve problem using DFS. Complexity = O(2^n) where n = heigh of the tree
## Data Structure
* set counter += 1 each time we reach the ending step.
## Algorithm
* populate the binary tree by recursively calling `climbSteps(startingStep, endStep, stepSize)`
* DFS implementation: going deeper by setting `startingStep = startingStep + stepSize`
* traverse every branch of the decision tree by recursively calling `climbingStep()`.
* each time startingStep = endStep: `return 1`, increment the `counter`.
## Complexity analysis
Complexity = O(2^n) where n = heigh of the tree

# Solution 2 Topdown Approach, Memoization
* Construct a decision tree (as binary tree) to analyze how many ways we can reach target from step 0 (Root of tree, Top) to destination (child left of tree, Down)
* Parts of the decision trees are repeated. Thus the problem depends on finding paths from 0, 1, 2, 3, 4,... n ![image info](./Tree_ClimbStep_simplified.png)
* Use Recursive from Top to Bottom, Result are returned from base case at the bottom.
## Data Structure
* ~~set counter += 1 each time we reach a destination.~~
* use `vector<int>cache` to store the result from earlier subproblem
* the subproblem is the number of ways to reach the endStep from a starting steps.
* cache is saved when cache[startingStep] >1 (there is a result from a starting Step to end step)
## Algorithm
* **Base cases**
1. return 1 if startingStep = endStep
2. return 0 if startingStep > endStep
* **Recursive cases**
1. if startingStep < endStep
2. traverse down the decision tree: startingStep = startingStep + stepSize until startingStep = endStep.
* memoization:
1. initialize `cache` to zero
2. save the `cache[startingStep]` = earlier result
3. retrieve result from `cache[startingStep]` if `cache[startingStep]>0`
![image info](./Tree_ClimbStep_illustration.png)
## Complexity analysis
Complexity = O(N) where n = heigh of the tree

# Solution 3 Use Fibonacci Equation as DP Equation
One can reach n step in one of the two ways:
1. Taking a single step from (i-1) step
2. Taking a step of 2 from (i-2) step
The total number of ways to reach n step is equal to *sum of ways of reaching (i-1) step and (i-2) step*:
dp[i] = dp[i-1]+dp[i-2]
## Data Structure
* create dp[] to store the number of steps to reach i step
## Algorithm
* it is top down approach, which base cases are top cases:
dp[0]=0
dp[1]=1
dp[2]=1
## Complexity analysis
O(n) for both time and space complexity.