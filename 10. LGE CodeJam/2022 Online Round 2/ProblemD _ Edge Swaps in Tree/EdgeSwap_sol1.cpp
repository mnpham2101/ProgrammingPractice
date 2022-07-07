#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> edges;
vector<int> val;
vector<int> par;
vector<int> cnt;
vector<vector<pii>> adj;
vector<int> depth(n + 1);
void dfs(int u) {
    int c = 1;
    for(auto& x : adj[u]) {
        if(x.F == par[u])
            continue;
        par[x.F] = u;
        val[x.F] = x.S;
        depth[x.F] = depth[u] + 1;
        dfs(x.F);
        c += cnt[x.F];
    }
    cnt[u] = c;
}
void test_case() {
    cin >> n >> m;
    val.clear();
    par.clear();
    cnt.clear();
    adj.clear();
    edges.clear();
    depth.clear();
    val= vector<int>(n + 1);
    par= vector<int>(n + 1);
    cnt= vector<int>(n + 1);
    adj= vector<vector<pii>>(n + 1);
    depth= vector<int>(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    ll ans = 0;

    dfs(1);
    for(int  i = 2; i <= n; ++i)
        ans += 1LL * cnt[i] * (n - cnt[i]) * val[i];
    ll T0 = ans;
    ll maxT = -1;
    ll minT = 1e18;
    for(int i = 0; i < m; ++i) {
        int a, u, v, z;
        cin >> a >> u >> v >> z;
        --a;
        int stop1 = edges[a][0];
        int stop2 = edges[a][1];
        if(stop2 == par[stop1])
            swap(stop1, stop2);
        bool ok = false;
        int cur = v;
        while(cur != 1) {
            if(cur == stop2) {
                ok = true;
                break;
            }
            cur = par[cur];
        }
        if(!ok)
            swap(u, v);
        int right = cnt[stop2];
        int left = n - right;
        ans = T0;
        ans -= 1LL * left * right * (val[stop2] - z);
        vector<int> right_path;
        while(v != stop2) {
            right_path.push_back(v);
            v = par[v];
        }
        for(int j = 0; j < (int)right_path.size(); ++j) {
            int x = right_path[j];
            int old = cnt[x];
            ans -= 1LL * old * (n - old) * val[x];
            int new_cnt = old + left;
            ans += 1LL * new_cnt * (n - new_cnt) * val[x];
        }
        right_path.clear();
        vector<int> left_path;
        while(depth[u] > depth[stop1]) {
            left_path.push_back(u);
            u = par[u];
        }
        while(depth[u] < depth[stop1]) {
            right_path.push_back(stop1);
            stop1 = par[stop1];
        }
        while(u != stop1) {
            left_path.push_back(u);
            u = par[u];
            right_path.push_back(stop1);
            stop1 = par[stop1];
        }
        for(int j = 0; j < (int)left_path.size(); ++j) {
            int x = left_path[j];
            int old = cnt[x];
            ans -= 1LL * old * (n - old) * val[x];
            int new_cnt = old + right;
            ans += 1LL * new_cnt * (n - new_cnt) * val[x];
        }
        for(int j = 0; j < (int)right_path.size(); ++j) {
            int x = right_path[j];
            int old = cnt[x];
            ans -= 1LL * old * (n - old) * val[x];
            int new_cnt = old - right;
            ans += 1LL * new_cnt * (n - new_cnt) * val[x];
        }
        minT = min(minT, ans);
        maxT = max(maxT, ans);
    }
    cout << T0 << " " << minT << " " << maxT << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) test_case();
    return 0;
}