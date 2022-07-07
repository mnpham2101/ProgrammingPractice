#include<cassert>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>

using namespace std;
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;

const int maxn = 50*1000;
const int maxm = 20*1000;
const int max_h = 16;

int n, m, ne;
int eg[maxn][3];
int ch[maxm][4];
vector<vector<int> > dat;
int st[maxn], ed[maxn];
int h[maxn], tot[maxn], dist[maxn], pare[maxn];
int anc[maxn][max_h];
ll cA[maxn], cB[maxn];
int front, rear, qu[maxn];

class Sol {
    void init_graph() {
        dat.clear();
        FOR(i,0,n-1) {
            vector<int> elem(3);
            elem[0] = eg[i][0];
            elem[1] = eg[i][1];
            elem[2] = eg[i][2];
            dat.pb(elem);
            elem[0] = eg[i][1];
            elem[1] = eg[i][0];
            dat.pb(elem);
        }
        sort(dat.begin(), dat.end());
        ne = 2*(n-1);
        assert(ne == (int)dat.size());

        FOR(i,0,n) {
            st[i] = ne;
            ed[i] = -1;
            h[i] = tot[i] = dist[i] = 0;
            pare[i] = -1;
            cA[i] = cB[i] = 0;
        }

        FOR(i,0,ne) {
            int x = dat[i][0];
            st[x] = min(st[x], i);
            ed[x] = max(ed[x], i);
        }
        dfs(0);
        front = rear = 0;
        qu[rear++] = 0;
        for(;front < rear; front++) {
            int x = qu[front];
            for(int j = st[x]; j <= ed[x]; j++) {
                int y = dat[j][1];
                if(pare[x] == y) continue;
                ll d = dist[y];
                cA[y] = cA[x] + d;
                cB[y] = cB[x] + d * 2 * tot[y];
                qu[rear++] = y;
            }
        }
    }

    void dfs(int x) {
        tot[x] = 1;
        for(int j = st[x]; j <= ed[x]; j++) {
            int y = dat[j][1];
            if(pare[x] != y) {
                h[y] = h[x] + 1;
                pare[y] = x;
                dfs(y);
                tot[x] += tot[y];
            } else {
                dist[x] = dat[j][2];
            }
        }
    }

    ll compute() {
        init_graph();

        FOR(j,0,max_h) {
            FOR(i,0,n) {
                if(j == 0) anc[i][j] = pare[i];
                else {
                    int med = anc[i][j-1];
                    if(med == -1) anc[i][j] = -1;
                    else anc[i][j] = anc[med][j-1];
                }
            }
        }

        ll ans = 0;
        FOR(x,1,n) {
            ll tx = tot[x], d = dist[x];
            ans += tx * (n - tx) * d;
        }

        return ans;
    }

    int get_anc(int x, int diff) {
        FOR(j,0,max_h) {
            if(diff & (1<<j)) {
                diff -= (1<<j);
                x = anc[x][j];
            }
        }
        return x;
    }
    int find_lca(int x1, int x2) {
        if(h[x1] < h[x2]) {
            return find_lca(x2, x1);
        }
        if(h[x1] > h[x2]) {
            int diff = h[x1] - h[x2];
            FOR(j,0,max_h) {
                if(diff & (1<<j)) {
                    diff -= (1<<j);
                    x1 = anc[x1][j];
                }
            }
        }
        assert(h[x1] == h[x2]);
        if(x1 == x2) return x1;
        int l = 0, r = h[x1];
        while(l <= r) {
            int mid = (l+r)/2;
            int a1 = get_anc(x1, mid);
            int a2 = get_anc(x2, mid);
            if(a1 == a2) r = mid - 1;
            else l = mid+1;
        }
        int a1 = get_anc(x1, l);
        int a2 = get_anc(x2, l);
        assert(a1 == a2);
        return a1;
    }

    ll re_compute_fast(ll val, int idx, int x2, int y2, ll d2) {
        int x1 = eg[idx][0], y1 = eg[idx][1];
        if(pare[x1] == y1) { int tmp = x1; x1 = y1; y1 = tmp; }

        int px2 = find_lca(x2, y1);
        int py2 = find_lca(y2, y1);

        bool f1 = (px2 == y1), f2 = (py2 == y1);

        if(f1) { int tmp = x2; x2 = y2; y2 = tmp; }
        int xp = find_lca(x1, x2);

        ll d1 = eg[idx][2], ny = tot[y1], diff = 0;

        diff += (d2 - d1) * (n - ny);
        diff += (cB[x1] - cB[xp]) - (cA[x1] - cA[xp]) * (n + ny);
        diff += (cB[xp] - cB[x2]) - (cA[xp] - cA[x2]) * (n - ny);
        diff += (cA[y2] - cA[y1]) * (n - ny);

        val += diff * ny;
        val += (cB[y2] - cB[y1]) * (ny - n);

        return val;
    }
    public:
    void solve() {

        ll mini = 2147483647ll, maxi = -1;
        mini *= (mini+1);
        ll origi = compute();

        FOR(j,0,m) {
            ll val = re_compute_fast(origi, ch[j][0], ch[j][1], ch[j][2], ch[j][3]);

            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        printf("%lld %lld %lld\n", origi, mini, maxi);
    }
};

int main() {
    Sol* ins = new Sol();
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        FOR(i,0,n-1) {
            scanf("%d%d%d", &eg[i][0], &eg[i][1], &eg[i][2]);
            eg[i][0] --;
            eg[i][1] --;
        }
        FOR(i,0,m) {
            scanf("%d%d%d%d", &ch[i][0], &ch[i][1], &ch[i][2], &ch[i][3]);
            ch[i][0] --;
            ch[i][1] --;
            ch[i][2] --;
        }

        ins->solve();
    }
    return 0;
}