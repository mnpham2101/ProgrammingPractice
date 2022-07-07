#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> rnk;
    vector<int> dis;

    UnionFind(int n) {
        par.resize(n);
        rnk.resize(n, 0);
        dis.resize(n, -1);
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int find(int a) {
        if (par[a] == a) return a;
        par[a] = find(par[a]);
        return par[a];
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rnk[a] < rnk[b]) {
            par[a] = b;
        } else {
            par[b] = a;
            if (rnk[a] == rnk[b]) rnk[a] += 1;
        }
    }

    bool enemy(int a, int b) {
        if (find(a) == find(b)) return false;

        if (dis[a] < 0) {
            dis[a] = b;
        } else {
            merge(dis[a], b);
        }

        if (dis[b] < 0) {
            dis[b] = a;
        } else {
            merge(a, dis[b]);
        }
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    int x, y;
    bool ans = true;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        --x, --y;
        if (!uf.enemy(x, y)) ans = false;
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0) solve();
}