#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//#include <bits/stdc++.h>

using namespace std;

int source = 0, sink = INT_MAX;

bool bfs(vector<vector<int>>& conn, vector<int>& parent) {
    int n = conn.size();
    vector<bool> visited(n, false);
    queue<int> travel;
    // step 1: pop front node from queue
    travel.push(source);
    visited[source] = true;
    while (!travel.empty()) {
        int node = travel.front();
        travel.pop();
        // Step 2: add neighbor node to to queue
        // neighbor nodes are those that conn[node][i] > 0 
        for (int i = 0; i < n; i++) {                                       // node 0 = source; node n+1= sink
            if (conn[node][i] == 0 || visited[i]) continue;         
            // Step 3: processing if the neighbor node should be in the path
            visited[i] = true;
            parent[i] = node;                                               // return the shortest path from source to sink
                                                                            // parent[childNode] = parent 
            if (i == sink) 
                return true;
            travel.push(i);
        }
    }
    return false;
}

int minFlow(vector<vector<int>>& conn) {
    int n = conn.size();
    vector<int> parent(n);
    int ret = 0;
    while (bfs(conn, parent)) {
        int curr = sink;
        int fl = INT_MAX;
        // Edmonds-Karp algorithm
        while (curr != source) {                                // search for the shortest capacity amoung the edges from source -> sink
            int par = parent[curr];
            fl = min(fl, conn[par][curr]);
            curr = par;
        }
        ret += fl;
        curr = sink;
        while (curr != source) {
            int par = parent[curr];
            conn[par][curr] -= fl;                              // update residual graph
            conn[curr][par] += fl;                              // update return edges
            curr = par;
        }
    }
    return ret;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        int n, m;                                               // n buildings
                                                                // m power lines connecting the buildings
        cin >> n >> m;
        sink = n + 1;
        vector<int> v(n);                                       // electricity surplus of n buildings
        vector<vector<int>> conn(n + 2, vector<int>(n + 2));    // electricity capacity of connection between buildings, buiildings & source/sink
                                                                // defines the edges.
                                                                // also defines adjacent neighbor list
        int total_source = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] > 0) {
                conn[source][i + 1] = v[i];                     // defining the flow graph: V[i]>0 ==> node is connected to source
                total_source += v[i];                           // total_source is defined as total positve from nodes that're connected to source
            }
            else {
                conn[i + 1][sink] = -v[i];                        // defining the flow graph: V[i]<0 ==> node is connected to sink
            }
        }
        for (int i = 0; i < m; i++) {                            // defining the flow graph: connection between buildings
            int x, y, z;
            cin >> x >> y >> z;
            conn[x][y] = z;
        }
        cout << total_source - minFlow(conn) << "\n";
    }
    return 0;
}
