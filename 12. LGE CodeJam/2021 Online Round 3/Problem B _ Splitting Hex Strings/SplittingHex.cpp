#include<cassert>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
typedef long long ll;


class P2 {
public:

  unordered_map<int, int> cnt;

  ll solve(vector<int>& dat, int x) {
    cnt.clear();
    FORE(it, dat) cnt[*it]++;
    ll ans = 0;
    FORE(it, cnt) {
      ll z = it->first;
      ll y = x ^ z;
      if(y > 2000000000ll) continue;
      ll a = it->second;
      if(cnt.find((int) y) != cnt.end()) {
        ll b = cnt[(int) y];
        if(z == y) {
          ans += a*(a-1)/2ll;
        } else if(z < y) {
          ans += a*b;
        }
      }
    }
    return ans;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  P2 *inst = new P2();
  while(t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> dat;
    dat.resize(n);
    FOR(i,0,n) scanf("%d", &dat[i]);
    printf("%lld\n", inst->solve(dat, x));
  }

  return 0;
}