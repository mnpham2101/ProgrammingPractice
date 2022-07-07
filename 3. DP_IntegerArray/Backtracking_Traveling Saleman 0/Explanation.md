# Description:

Given a 2D array of size `nxn`. The value of `distance[i][j]` denote the distance between city `i` and city `j`. The distance between between city `i` and itself is `distance[i][i]=0` .

Find the shortest distance for a salemen to start from `starting city = 1` to visit all other city at least once and come back to the starting city.

See also similar problems:
1. Given `n` cities, and `distance[i][j]` to store a distance between city `i` and city `j`. Find a shortest path from `starting city = 1` to visit `m` cities where `m<n` and come back to city `1`.
2. Given `n` cities, and `distance[i][j]` to store a distance between city `i` and city `j`. Find a shortest path from `starting city = 1` to visit `m` cities where `m<n` and don't come back.
3. Given `n` cities, and `cost[i]` to store a cost to visit city `i`, and `value[i]` to store value earn from visiting a city `i`. Find the path to visit cities such that we get the most value while running only `c` cost.

# Solution 1: Brute Force - with backtracking to reduce search space.
- from starting city 1, calculate distance to all other cities => brute force approach.
- mark the city as visited so that the city will not be re-visited.
- use recursive call `try(city, accumuldatedDistance)` to add up accumulated distance.
- backtracking: after `try(city, accumuldatedDistance)` returns result, mark the city as unvisited so that it goes back to candidate list when considering other paths.
## Algorithm:
* backtracking algo follows 3 steps:
    1. Step 1: mark candidates as not visited
    2. Step 2: consider all cities as potential candidates
    * Step 2.1: check condition for next candidate city to visit
    * step 2.2: mark city as visited, count this distance from starting city to next candidate city
    3. Step 3: unmark city as unvisited so that after backtracking, we can put it back to candidate list
* code template:
```
// step 1: mark candidate
vector<bool> c (n, true);

void try(int i) {
    for (int v = 1; v <= n; ++v) {                                      // step 2:
        if (c[v]) {             // Step 2: if candidates are accepted/true, go on with backtracking
            x[i] = v;
            if (i == n)         // Step 3: Stop condition for backtracking
                print(x);
            else {
                c[v] = false;   // Step 2.1: mark candidate off the list of configuration
                try(i+1);       // Step 2.2:
                c[v] = true;    // Step 2.3: mark candidate on for other list of configuration after backtracking try returns result
            }
        }
    }
}
```
## Complexity:
* O(N!)  where n should be <14 to be do-able.