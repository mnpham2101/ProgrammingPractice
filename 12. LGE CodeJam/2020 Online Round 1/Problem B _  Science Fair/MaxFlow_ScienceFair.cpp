#include<set>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int av[1048576];
int n, c[3], m[3], cp[3];
int res[1048576], cnt;
vector<int> grp[8];
int idx[8];
const int SRC = 0, AA = 8, BB = 9, CC = 10, SNK = 11;
int ff[16][16], cc[16][16];
int qu[16],front,rear,vis[16], from[16];
void init() {
    for(int i = 1; i <= 7; i++) grp[i].clear();
    for(int i = 0; i < n; i++) {
        grp[av[i]].push_back(i);
    }
    memset(cc,0,sizeof(cc));
    memset(ff,0,sizeof(ff));
    for(int i = AA; i <= CC; i++) {
        cc[SRC][i] = c[i-AA];
    }
    for(int i = 1; i <= 7; i++) {
        cc[i][SNK] = (int) grp[i].size();
    }
    for(int i = 1; i <= 7; i++) {
        if(i & 1) cc[AA][i] = min(cc[SRC][AA], cc[i][SNK]);
        if(i & 2) cc[BB][i] = min(cc[SRC][BB], cc[i][SNK]);
        if(i & 4) cc[CC][i] = min(cc[SRC][CC], cc[i][SNK]);
    }
}
void post() {
    memset(res,-1,sizeof(res));
    memset(idx,0,sizeof(idx));
    for(int i = 1; i <= 7; i++) {
        for(int j = AA; j <= CC; j++)  {
            for(int k = 0; k < ff[j][i]; k++) {
                res[grp[i][idx[i]]] = j - AA;
                idx[i]++;
            }
        }
    }
}
int main() {
    int t;
    assert(1 == scanf("%d",&t));
    assert( 1 <= t && t <= 10);

    while(t--) {
        assert(1 == scanf("%d", &n));
        assert(1 <= n && n <= 10000);
        assert(3 == scanf("%d%d%d",&c[0],&c[1],&c[2]));
        assert(1 <= c[0] && c[0] <= n);
        assert(1 <= c[1] && c[1] <= n);
        assert(1 <= c[2] && c[2] <= n);
        memset(av,0,sizeof(av));
        memset(cp,0,sizeof(cp));
        memset(res,-1,sizeof(res));
        for(int j = 0; j < 3; j++) {
            assert(1 == scanf("%d", &m[j]));
            assert(0 <= m[j] && m[j] <= n);
            set<int> sanity;
            for(int k = 0; k < m[j]; k++ ){
                int x;
                assert(1 == scanf("%d",&x));
                assert(1 <= x && x <= n);
                sanity.insert(x);
                av[x-1] |= (1<<j);
            }
            assert( m[j] == ( (int)sanity.size()) );
        }
        init();
        cnt = 0;
        while(true) {
            front = rear = 0; qu[rear++] = SRC;
            memset(vis,0,sizeof(vis)); vis[SRC] = true;
            for(;front<rear;front++) {
                int x = qu[front];
                for(int y = 0; y <= SNK; y++) {
                    if(ff[x][y] < cc[x][y] && !vis[y]) {
                        from[y] = x;
                        qu[rear++] = y;
                        vis[y] = 1;
                    }
                }
            }
            if(!vis[SNK]) break;
            int x, y = SNK, inc = n+1;
            while(true) {
                x = from[y];
                inc = min(inc, cc[x][y] - ff[x][y]);
                if(x == 0) break;
                y = x;
            }
            y = SNK;
            while(true) {
                x = from[y];
                ff[x][y] += inc;
                ff[y][x] -= inc;
                if(x == 0) break;
                y = x;
            }
            cnt += inc;
        }
        post();
        printf("%d\n", cnt);
        for(int i = 0; i < n; i++)
            if(res[i] != -1)
                printf("%d %c\n", i+1,(res[i]+65));
    }
    return 0;
}