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
 
const int maxn = 256;
 
void print(vector<int>& ans) {
    if(ans.size() == 0) printf("-1\n");
    else {
        FORE(it, ans) printf("%d ", *it);
        printf("\n");
    }
}
 
class P5 {
  int SRC, SNK;
    int n, m;
  vector<int> nei[maxn];
   
  int f[maxn][maxn], c[maxn][maxn], vis[maxn];
  int qu[maxn], fr[maxn], front, rear;
  int path[maxn], np, tot_flow;
   
  bool has_aug() {
    front = rear = 0;
    memset(vis, 0, sizeof(vis));
    fr[SRC] = -1; vis[SRC] = true;
    qu[rear++] = SRC;
     
    for(;front<rear;front++) {
      int x = qu[front];
      FORE(jt, nei[x]) {
        int y = *jt;
        if(!vis[y] && f[x][y] < c[x][y]) {
          vis[y] = true;
          fr[y] = x;
          qu[rear++] = y;
        }
      }
    }
     
    if(!vis[SNK]) return false;
     
    np = 0;
    int x = SNK, aug_val = 1048576;
    while(true) {
      path[np++] = x;
      int y = fr[x];
      if(y == -1) break;
      aug_val = min(aug_val, c[y][x] - f[y][x]);
      x = y;
    }
 
    tot_flow += aug_val;
     
    for(int i = 1; i < np; i++) {
      int y = path[i-1], x = path[i];
      f[x][y] += aug_val;
      f[y][x] -= aug_val;
    }
     
    return true;
  }
   
  void init(vector<int>& val, vector<vector<int>>& to) {
    sort(to.begin(), to.end());
 
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
 
 
    FOR(i,0,m) c[to[i][0]][to[i][1]] = to[i][2];
    FOR(i,0,n+2) nei[i].clear();
    FOR(i,0,n+2) {
      FOR(j,0,n+2) {
        if(c[i][j] > 0 || c[j][i] > 0) {
          nei[i].pb(j);
        }
      }
    }
  }
   
public:
  int solve(vector<int>& val, vector<vector<int>>& to) {
    n = val.size(); m = to.size();
    SRC = n; SNK = n+1;   
    init(val, to);
     
    int tot_pos = 0;
    FOR(i,0,n) {
      if(val[i] > 0) tot_pos += val[i];
    }
 
    tot_flow = 0;
    while(has_aug());
     
    return tot_pos - tot_flow;
     
  }
};
 
int main() {
    int t;
    scanf("%d", &t);
    P5* ins = new P5();
    while(t--) {
        int n, m;
    scanf("%d%d", &n, &m);
    vector<int> val; val.resize(n);
    FOR(i,0,n) scanf("%d", &val[i]);
 
    vector<vector<int>> to;
    FOR(i,0,m) {
      vector<int> edge; edge.resize(3);
      scanf("%d%d%d", &edge[0], &edge[1], &edge[2]);
      edge[0]--; edge[1]--;
      to.pb(edge);
    }
    const int SRC = n, SNK = n+1;
    FOR(i,0,n) {
      vector<int> edge; edge.resize(3);
      if(val[i] > 0) {
        edge[0] = SRC; edge[1] = i; edge[2] = val[i];
      } else {
        edge[0] = i; edge[1] = SNK; edge[2] = -val[i];
      }
      to.pb(edge);
    }
    printf("%d\n", ins->solve(val, to));
    }
 
    return 0;
}