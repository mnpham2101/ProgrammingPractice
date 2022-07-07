# Problem description
You are given a 0-indexed binary array `nums` of length n. `nums` can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) `numsleft` and `numsright`:
# Solution 1 with map (Time Limitted Reach)
## Data Structure
* data structure to store result: `vector<int> result`
* counter `nums_left` and `nums_right` to count the `0` and `1`
* data structure to make `nums Right` from `nums`: `vector<int>nums_right_vector`
* data structure to store the `score = numsleft + numsright` at index: `multimap<int, int>score_index`: key = score, index = int
* the maxHarshMap will sort out based on key, highest at beginning.
## Algorithm

1. Step 1: add to score_index the score for case `nums_right` = entire vector `num`
2. Step 2.1: count `0` in nums_left from i = 0 to size of nums
3. Step 2.2: makes nums_right_vector from nums vector, starting at position i: for every `nums_left` from i, generate `nums_right_vector`

|input                         |Array                        |is                          |vector                      |nums={0,0,1,0,0}      |
| -----------------------------|:---------------------------:|:--------------------------:|:--------------------------:|:--------------------:|
|i=0                           |i=1                          |i=2                         |i=3                         |i=4                   |
|nums_right_vector={0,1,0,0}   |nums_right_vector={1,0,0}    |nums_right_vector={0,0}     |nums_right_vector={0}       |nums_right_vector={}  |
|nums_right=1                  |nums_right=1                 |nums_right=0                |nums_right=0                |nums_right=0          |
|nums_left=1                   |nums_left=2                  |nums_left=2                 |nums_left=3                 |nums_left=4           |
|score=2                       |score=3                      |score=2                     |score=3                     |score=4               |
1. Step 2.3: count `1`, add to nums_right from `nums_right_vector`
2. Step 2.4: add score, insert {score, index} to `score_index map`

## Complexity analysis
1. Step 2.1 : is O(N).
2. Step 2.2 : is O(logN) because of double for loop.
3. Step 2.4 : is O(logN) because of STL map sorting key.
4. Overal complexity is > O(N+ 2logN)
# Solution 2 with prefix sum vector and map and O(n)
* Improvement over Solution 1
* Source: Leetcode user: raj250301 @ https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/discuss/1738308/C++-Simple-Prefix-Sum-Approach-or-O(n)?fbclid=IwAR2ZrVEbxpJjUtxU9tPBtDOlScJ8bvx1vibbOzVGvXolufeLK9R4N37It7w
* Construct prefix sum vectors
## Data Structure
* data structure to store result: `vector<int> result`
* ~~counter `nums_left` and `nums_right` to count the `0` and `1`~~
* ~~data structure to make `nums Right` from `nums`: `vector<int>nums_right_vector`~~
* data structure `nums_right` & `nums_left` to keep track of the couting of  `0` and `1` in `nums Right` and `nums left` from `num`. Those are `prefix sum` vector

|input              |Array               |is                 |vector                |nums n=5             |{0,0,1,0,0}        |
| ------------------|:------------------:|:-----------------:|:--------------------:|:-------------------:|:-----------------:|
|nums[0]=0          |nums[1]=0           |nums[2]=1          |nums[3]=0             |nums[4]=0            | x                 |
|nums_right[0]=0    |nums_right[1]=1     |nums_right[2]=2    |nums_right[3]=2       |nums_right[4]=3      |nums_right[5]=4    |
|nums_left[0]=1     |nums_left[1]=1      |nums_left[2]=1     |nums_left[3]=0        |nums_left[4]=0       |nums_left[5]=0     |
|score=1            |score=2             |score=3            |score=2               |score=3              |score=4            |
|score_index[1]={0} |score_index[2]={1} |score_index[3]={2}  |score_index[2]={1,3}  |score_index[3]={2,4} |score_index[4]={5} |

nums_right[5] = 4 is the case when numsRight = [00100] and nums_left[5]=0 is the case when numsLeft = [x]

nums_right[0] = 0 is the case when numsRight = [x] and nums_left[0]=1 is the case when numsLeft = [00100]

* `map` data structure to store the `score = nums_left + nums_right` at index: `map<int, vector<int>>score_index`: key = score, value = index
* the maxHarshMap will sort out based on key, lowest at beginning.
## Algorithm
Follow BSF Steps, use recursive BFS
1. Step 1: make nums_right[]
2. Step 2: make nums_left[]
3. Step 3.1: makes score, add score, index to map

## Complexity Analysis
For each step 1& 2, the complexity is O(n)
For step 3.1: STL map sort the key, the complexity is O(logN)
Total cost is O(3N + logN)

# Solution 3
* get the score and max score by traversing the input array
* score is compared to max score, if score >= max_score, push the index to result vector
* don't need to use map to keep track of `score_index` => no need for sorting.
* source:LeetCode user: coderaky https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/discuss/1730364/Easy-C%2B%2B-or-Keep-Track-of-rightOne-and-leftZero-or-O(n)
## Data Structure
* data structure to store result: `vector<int> result`
* ~~counter `nums_left` and `nums_right` to count the `0` and `1`~~
* ~~data structure to make `nums Right` from `nums`: `vector<int>nums_right_vector`~~
* ~~data structure `nums_right` & `nums_left` to keep track of the couting of  `0` and `1` in `nums Right` and `nums left` from `num`. Those are `prefix sum` vector~~
* counter `nums_left` and `nums_right` to count the `0` and `1`
## Algorithm

|input              |Array               |is                 |vector                |nums n=5             |{0,0,1,1,0}        |
| ------------------|:------------------:|:-----------------:|:--------------------:|:-------------------:|:-----------------:|
|                   |nums[0]=0           |nums[1]=1          |nums[2]=1             |nums[3]=0            |nums[4]=0          |
|nums_right[0]=0    |nums_right[1]=1     |nums_right[2]=2    |nums_right[3]=2       |nums_right[4]=2      |nums_right[5]=3    |
|nums_left[0]=2     |nums_left[1]=2      |nums_left[2]=2     |nums_left[3]=1        |nums_left[4]=0       |nums_left[5]=0     |
|score=2            |score=3             |score=4            |score=3               |score=2              |score=3            |
|index=0            |index=1             |index=2            |index=3               |index=4              |index=5            |

1. Step 1: get `nums_left` at index=0 by counting all `1`
2. Step 2.1: run for loop from index=0-> index<size, get `score`, compare with `maxScore`. Push index to `result` vector.
3. Step 2.2: update `nums_right` and `nums_left` to count `1` and `0`. *Notes*: `nums_left` max is from step 1, and decrease as `1` is encounter.
## Complexity Analysis