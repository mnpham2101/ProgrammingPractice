## Problem description 
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
## Solution with map
### Approach:
* use map to automatically sort distance and points. 
* get a map of key=distance and value=points
* while counter < k push the points to vector result
### Notes:
* points coordinates are in integer. Sqrt of integer returns irrational root, and thus cannot be used for distance comparison. ==> In this problem, suggest to use square of distance for comparison. 
* distance could be the same for multiple points ==> use multimap so that non-unique key could be used
### Complexity analysis

## Solution with map
Source: https://leetcode.com/problems/k-closest-points-to-origin/discuss/1647428/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-Friendly-with-detailed-explanations
### Approach:
### Complexity analysis
