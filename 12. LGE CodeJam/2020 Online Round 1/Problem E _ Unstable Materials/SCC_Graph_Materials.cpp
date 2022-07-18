#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MX_N = 100005;

int n, w[MX_N], q[MX_N], indeg[MX_N];
long long cache[MX_N][2];
vector<int> cld[MX_N];
vector<vector<int>> cycles;

void input_init()
{
    cin >> n;

    memset(cache, -1, sizeof(cache));
    memset(indeg, 0, sizeof(indeg));
    cycles.clear();

    for(int i=0; i<n; ++i) {
        cin >> w[i] >> q[i];
        q[i]--;
        indeg[q[i]]++;
        cld[i].clear();
    }
}

void treeMake()
{
    queue<int> qu;

    for(int i=0; i<n; ++i) {
        if(indeg[i] == 0) qu.push(i);
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        int v = q[u];

        cld[v].push_back(u);
        indeg[v]--;
        if(indeg[v] == 0) qu.push(v);
    }
}

void cycleFind()
{
    int cycleNo = 0;
    for(int i=0; i<n; ++i) {
        if(indeg[i]) {
            int u = i;
            cycles.push_back(vector<int>());
            do {
                cycles[cycleNo].push_back(u);
                indeg[u] = 0;
                u = q[u];
            } while(u != i);
            cycleNo++;
        }
    }

}

long long dp(int u, int isSelect)
{
    long long &ret = cache[u][isSelect];
    if(ret != -1) return ret;

    if(isSelect) {
        ret = w[u];
        for(int v : cld[u]) ret += dp(v, 0);
    }
    else {
        ret = 0;
        for(int v : cld[u]) ret += max(dp(v,1), dp(v,0));
    }

    return ret;
}

long long solve()
{
    long long ans = 0;
    for(vector<int> cycle : cycles) {
        int st = 0, en = cycle.size();
        long long tot;

        for(int u : cycle) {
            dp(u, 0);
            dp(u, 1);
        }

        long long totIn, totEx, tmpIn, tmpEx;

        totIn = dp(cycle[st], 0);
        totEx = dp(cycle[st], 0);
        for(int i=st+1; i<en; ++i) {
            tmpIn = totEx + dp(cycle[i], 1);
            tmpEx = max(totEx, totIn) + dp(cycle[i], 0);

            totIn = tmpIn;
            totEx = tmpEx;
        }
        tot = max(totIn, totEx);

        totIn = dp(cycle[en-1], 0);
        totEx = dp(cycle[en-1], 0);
        for(int i=en-2; i>=st; --i) {
            tmpIn = totEx + dp(cycle[i], 1);
            tmpEx = max(totEx, totIn) + dp(cycle[i], 0);

            totIn = tmpIn;
            totEx = tmpEx;
        }
        tot = max(tot, max(totIn, totEx));
        ans += tot;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        input_init();
        treeMake();
        cycleFind();
        cout << solve() << '\n';
    }
}