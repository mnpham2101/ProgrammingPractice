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

const int maxn = 262144, maxv = 1048576;
const ll MOD = 1000000000+7;
int n, v[maxn];
int cnt[maxv];
ll lt[maxn], rt[maxn];


class Sol {

  void preproc() {
    memset(cnt,0,sizeof(cnt));
    int j = 0;
    FOR(i,0,n) {
      while(j < n && cnt[v[j]] == 0) {
        cnt[v[j]]++;
        j++;
      }
      rt[i] = (j-i);
      cnt[v[i]]--;
    }
    memset(cnt,0,sizeof(cnt));
    j = n-1;
    for(int i = n-1; i >= 0; i--) {
      while(j >= 0 && cnt[v[j]] == 0) {
        cnt[v[j]]++;
        j--;
      }
      lt[i] = (i-j);
      cnt[v[i]]--;
    }
  }

  long long power(long long x, long long y, long long p)
  {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
  }


public:
  ll solve() {
    ll ans = 0;
    preproc();
    ans = lt[0] - 1 + rt[0] - 1;
    FOR(i,1,n) {
      ll r = i+1;
      ll m = lt[i];
      if (m > 1)
        ans = (ans + ((1 - power(r, m+1, MOD)) * power(1-r, MOD-2, MOD)) % MOD - 1 -r) % MOD;
      m = rt[i];
      if (m > 1)
        ans = (ans + ((1 - power(r, m+1, MOD)) * power(1-r, MOD-2, MOD)) % MOD - 1 -r) % MOD;
    }
    return ans;
  }
};

int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    FOR(i,0,n) scanf("%d", &v[i]);
    ll ans = ins->solve();
    printf("%lld\n", ans);
  }

    return 0;
}