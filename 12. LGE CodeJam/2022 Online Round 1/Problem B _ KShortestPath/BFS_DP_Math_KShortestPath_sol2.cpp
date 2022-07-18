#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

#include <bits/stdc++.h>            // need this for code jam engine
using namespace std;

// MACRO
#define int long long

void solve() {
    int l, k, x, y;
    cin >> l >> k >> x >> y;

    int n = pow(10, l);

    // vertex
    vector<int> v(n);

    // edges
    vector<set<int>> e(n);                              // vector row = node; set<int> = list of neighbors

    // Step 1: create edges that connects each node (integer value) to a neighbor (integer value)
    for (int i = 0; i < n; i++) {                       // i = 0 , 1 .... 100, 101, .... 1000, 1001,.... 10000

        string v_str = to_string(i);                    // v_str = '0'
        int size = v_str.size();
        for (int j = 0; j < l - size; j++) {            // concatenate `0` to v_str,
            v_str = "0" + v_str;                        // if l==3 => add `00`, if l==4 => add `000`  , first `0` was initialized
        }

        // find neighbors for EVERY nodes in range 0 -> 99, or 999, or 9999 by using string concatenation
        // for every character in a string that represents a node, add a neighbor by adjusting ++ or --
        vector<string> neighbors;
        for (int j = 0; j < l; j++) {
            if (v_str[j] == '0') {                      // border case: if node == 00 => neighbor = 10 and 01
                string neighbor = v_str;
                neighbor[j]++;
                neighbors.push_back(neighbor);
            }
            else if (v_str[j] == '9') {                 // border case: if node == 99 => neighbor = 89 and 98
                string neighbor = v_str;
                neighbor[j]--;
                neighbors.push_back(neighbor);
            }
            else {
                string neighbor = v_str;
                neighbor[j]--;                          // normal case: if node == 22 => neighbor = 12 and 11
                neighbors.push_back(neighbor);

                neighbor[j] += 2;                       // normal case: if node == 22 => neighbor = 32 and 23    ; +2 is to compensate for earlier --
                neighbors.push_back(neighbor);
            }
        }

        // connect each node to neighbor
        for (auto neighbor : neighbors) {
            int neighbor_int = stoi(neighbor);
            // add neighbor 2 times
            e[i].insert(neighbor_int);                  // add neighbor of each node
            e[neighbor_int].insert(i);                  // add neighbor of neighbor
        }
    }

    // Step 2:
    // bfs to find SHORTEST distance from y to every other node
    /*
    dist[20]=4----dist[21]=3----dist[22]=2----dist[23]=1
    |             |             |             |
    |             |             |             |
    dist[30]=3----dist[31]=2----dist[32]=1----dist[33]=0
    */
    queue<int> q;                                       // bfs traversing: FIFO
    q.push(y);

    vector<int> dis(n, INT_MAX);                        // store distance from each node to very other nodes.
    dis[y] = 0;                                         // distance from the node to itself is zero
    while (!q.empty()) {
        int element = q.front();
        q.pop();                                        // bfs traversing: pop out the front node to process, process nodes and immediate neighbor at the same layer first.
        for (auto neighbor : e[element]) {
            if (dis[neighbor] == INT_MAX) {
                dis[neighbor] = dis[element] + 1;       // update the distance from a node a neighbor.
                                                        // distance from node to immediate neighbor = 1
                                                        //
                q.push(neighbor);                       // bfs traversing: push the neighbors of neighbors to back, process later by going to deeper layers
            }
        }
    }  // end bfs process => queue q is empty
    // dis[x] = shortest distance from y to x; for example x= 20, y=33 => dis[20] = shortest distance from 33 to 20 = 4

    // Step 3:
    // use bfs + dynamic programming approach to quickly find HOW MANY SHORTEST PATHS from y to x and MARK the Kth path.
    // to be optimized: marked the neighbor nodes as TRUE if the shortest path goes through them
    // to be optimized: only traverse bfs through the neighbors that are to be marked true
    // dp[x] stores the total paths that have shortest path from y to x
    /* sample case for path from 20 <-> 30
    * dp[20] = 4----dp[21] = 3----dp[22] = 2----dp[23] = 1
        |             |             |             |
        |             |             |             |
      dp[30] = 1----dp[31] = 1----dp[32] = 1----dp[33] = 1

      Notes that: path going throught 22, then down to 32 will be the 2nd path!
    */
    vector<int> dp(n, 0);
    dp[y] = 1;                                          // DP Base condition: there is one path to itself
    q.push(y);
    vector<bool> flag(n, false);
    flag[y] = true;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        for (auto neighbor : e[element]) {
            if (dis[neighbor] == dis[element] - 1) {    // backtracking: For example if dist[22] == dist[21] - 1   (22 and 21 are immediate neighbor
                dp[element] += dp[neighbor];            // then the path count dp[2] increases by 1
                                                        // path count is incremented by couting paths from elements to all of previous neighbors.

            // example: from 20 to
            }
            else if (flag[neighbor] == false) {
                q.push(neighbor);
                flag[neighbor] = true;
            }
        }
    }   // end bfs+dp process
    // if x = 20, y=33 => dp[x] = 4 => 4 paths from


    // Step 4: process answer
    // base case, quick answer, if the requested Kth path less than total shortest path from x -> y
    if (k > dp[x]) {
        cout << "NO" << endl;
        return;
    }

    int src = x;
    int dst = y;

    int stt = k;

    int count_log = 0;

    vector<string> ans;

    string v_str = to_string(src);
    int size = v_str.size();
    // concatenate `0` to v_str if its value doens't fit length. For example, if l = 3, source = 2. Then v_str = '003'
    for (int j = 0; j < l - size; j++) {
        v_str = "0" + v_str;
    }
    ans.push_back(v_str);

    // find the Kth path in ONE loop by processing neighbors of from source to destination
    while (src != dst) {
        int next_src;
        for (auto next_src : e[src]) {                      // start from source, process the neighbor of source.
            if (dis[next_src] != dis[src] - 1) {            // since dis is marked as distance from destination to source => only neighbor on path from source -> destination would be processed,
                continue;                                   // the rest is skipped. For example neighbor of 20 are {10, 21, 30} but only 21 and 30 are on path from 20 -> 33
            }
            count_log++;
            // consider if the next_src (neighbor of current node) is in the Kth path: path going throught 22, then down to 32 will be the 2nd path!
            /* dp[20] = 4----dp[21] = 3----dp[22] = 2----dp[23] = 1
                |             |             |             |
                |             |             |             |
               dp[30] = 1----dp[31] = 1----dp[32] = 1----dp[33] = 1
                */
            if (dp[next_src] < stt) {
                stt -= dp[next_src];
            }
            else {
                // get the next node
                src = next_src;
                // output the node in required format. If L = 3, node value = 5 ==> output 005
                string v_str = to_string(src);
                int size = v_str.size();
                for (int j = 0; j < l - size; j++) {
                    v_str = "0" + v_str;
                }
                ans.push_back(v_str);

                break;
            }
        }
    }

    for (auto s : ans) {
        cout << s << " ";
    }
    cout << endl;

}

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
