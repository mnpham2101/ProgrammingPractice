#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

int n, c[505][505], f[505][505];
long long sumPlus;
vector<int> adj[505];

inline void push_edge(int a, int b, int c1, int c2) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    c[a][b] += c1;
}

void init()
{
    int cnt, nxt, k;

    sumPlus = 0;

    cin >> n;

    for(int i=0; i<=n+1; ++i) adj[i].clear();
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));

    for(int i=1; i<=n; ++i) {
        cin >> k;
        if(k>0) {
            push_edge(0,i,k,0);
            sumPlus += k;
        }
        else push_edge(i,n+1,-k,0);
    }

    for(int i=1; i<=n; ++i) {
        cin >> cnt;
        while(cnt--) {
            cin >> nxt;
            push_edge(i,nxt,INF,0);
        }
    }
}

long long netFlow()
{
    long long tot = 0;
    int src = 0, snk = n+1;

    while(true) {
        vector<int> pre(n+2,-1);
        queue<int> q;

        q.push(src);
        while(!q.empty() && pre[snk] == -1) {
            int cur = q.front();
            q.pop();
            for(int nxt : adj[cur]) {
                if(c[cur][nxt]-f[cur][nxt]>0 && pre[nxt]==-1) {
                    q.push(nxt);
                    pre[nxt] = cur;
                    if(nxt == snk) break;
                }
            }
        }
        if(pre[snk] == -1) break;

        int flow = INF;
        for(int i=snk; i!=src; i=pre[i])
            flow = min(flow, c[pre[i]][i]-f[pre[i]][i]);
        for(int i=snk; i!=src; i=pre[i]) {
            f[pre[i]][i] += flow;
            f[i][pre[i]] -= flow;
        }
        tot += flow;
    }
    return tot;
}

long long solve()
{
    long long mxFlow = netFlow();
    return sumPlus - mxFlow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        init();
        cout << solve() << '\n';
    }
}