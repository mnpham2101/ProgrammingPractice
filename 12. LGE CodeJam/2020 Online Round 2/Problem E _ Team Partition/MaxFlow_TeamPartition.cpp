#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;
int const INF_FLOW = int(2e9);

/*
 * Getting maximum flow: Edmond-Karp based implementation - O(min(fE, VE^2))
 */
struct Maxflow {
    int ne;
    vector<int> par;
    vector<vector<int>> adj;
    vector<vector<int>> cap;
    vector<vector<int>> flow;
    int snd, tnd;

    Maxflow(int n) : ne(n) {
        par.resize(n);
        cap.resize(n, vector<int>(n, 0));
        flow.resize(n, vector<int>(n, 0));
        adj.resize(n, vector<int>(n, 0));
        snd = 0;
        tnd = n - 1;
    }

    void addEdge(int u, int v, int c) {
        adj[u][v] = 1;
        adj[v][u] = 1;
        cap[u][v] += c;
    }

    int bfs() {
        fill(par.begin(), par.end(), -1);
        par[snd] = -2;
        queue<pii> q;
        q.push({snd, INF_FLOW});
        while (!q.empty()) {
            int cur = q.front().first;
            int f = q.front().second;
            q.pop();

            for (int nxt = 0; nxt < ne; ++nxt) {
                if (adj[cur][nxt] == 0) continue;

                if (par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                    par[nxt] = cur;
                    int new_f = min(f, cap[cur][nxt] - flow[cur][nxt]);
                    if (nxt == tnd) return new_f;
                    q.push({nxt, new_f});
                }
            }
        }
        return 0;
    }

    int findMaxflow() {
        int totflow = 0;
        int f = 0;
        while ((f = bfs())) {
            totflow += f;
            int cur = tnd;
            while (cur != snd) {
                int prv = par[cur];
                flow[prv][cur] += f;
                flow[cur][prv] -= f;
                cur = prv;
            }
        }
        return totflow;
    }

    void getResidual(int nd, vector<bool>& vis) {
        vis[nd] = true;
        for (int i = 0; i < ne; ++i) {
            if (cap[nd][i] - flow[nd][i] && !vis[i]) getResidual(i, vis);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    // 0: source(attack)
    // [1,n]: employee
    // n+1: sink(defence)
    Maxflow mf(n + 2);
    int tot = 0;
    int atk, def;
    for (int i = 0; i < n; ++i) {
        cin >> atk >> def;
        mf.addEdge(0, i + 1, atk);
        mf.addEdge(i + 1, n + 1, def);
        tot += atk + def;
    }

    int num, s;
    for (int i = 0; i < m; ++i) {
        cin >> num >> s;
        vector<int> v(num);
        for (int j = 0; j < num; ++j) cin >> v[j];
        for (int j = 0; j < num; ++j) {
            for (int k = j + 1; k < num; ++k) {
                mf.addEdge(v[j], v[k], s);
                mf.addEdge(v[k], v[j], s);
            }
        }
    }

    cout << tot - mf.findMaxflow() << '\n';

    vector<bool> attackers(n + 2, false);
    vector<int> ans;
    mf.getResidual(0, attackers);
    for (int i = 1; i <= n; ++i) {
        if (attackers[i]) ans.push_back(i);
    }
    cout << ans.size();
    for (auto& each : ans) cout << " " << each;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0) solve();
}