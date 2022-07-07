# Description
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

```
Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
```

# Approach 1: Greedy
* if rotation can be done, only the value top[0] or bottom[0] is needed to be considered.
* rotate such that top[i] = top[0] or bottom[0]  = top[0]
* rotate can return result for top[0]  ==> no need to check rotation needs to make all = bottom[0]  ==> it is hard to understand, but debugging can confirm it.

# Approach 2:
* Resource: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/1865373/C%2B%2B-oror-2-Approaches-oror-Explained-With-Algorithm-oror-Easy-and-Simple
* count the occurance of top[i] and bottom[i] ==> save to `faceA[top[i]]` and `faceB[bottom[i]]`
* if there is `top[i] == bottom[j]` , the rotation is the min to rotate top or bottom such that they have the same vaue
For examples:
- tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
- faceA[2] = 4 , as tops[0] = tops[2] = tops[4] = tops[5]
- faceB[2] = 3, as bottoms[1] = bottoms[3] = bottoms[5]
- same[2] = 1, as tops[5] = bottoms[5]
- Therefore we have faceA[2] + faceB[2] - same[2] = 6, (size of arr)
- Therfore we can make 2 in a whole row.
- the minimum rotation is `minRotation = min(minRotation , min(faceA[i],faceB[i]) - same[i])`

# Approach 3:
* Resource: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/1865373/C%2B%2B-oror-2-Approaches-oror-Explained-With-Algorithm-oror-Easy-and-Simple
