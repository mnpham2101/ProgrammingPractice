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

const int maxn = 524288;
const ll MOD = 987654323;

int n, v[maxn];

// value-based
int heap[maxn], nh, where[maxn];

class Sol {
  vector<int> ans;
  int m, rem;

  void swap(int x, int y) {
    int tmp = heap[x]; heap[x] = heap[y]; heap[y] = tmp;
    where[heap[x]] = x;
    where[heap[y]] = y;
  }

  void down(int x) {
    while(x < nh) {
      int lf = x*2+1, rt = x*2+2, next = -1;
      if(lf < nh) next = lf;
      if(rt < nh &&
      (v[heap[rt]] > v[heap[next]] ||
       (v[heap[rt]] == v[heap[next]] && heap[rt] < heap[next]))) {
        next = rt;
      }
      if(next == -1 || v[heap[next]] < v[heap[x]]
        || (v[heap[next]] == v[heap[x]] && heap[next] > heap[x]))
        break;
      swap(x, next);
      x = next;
    }
  }

  void up(int x) {
    while(x > 0) {
      int p = (x-1)/2;
      if(v[heap[p]] < v[heap[x]] ||
        (v[heap[p]] == v[heap[x]] && heap[p] > heap[x])) {
          swap(x, p);
          x = p;
      }
      else break;
    }
  }

  void init_heap() {
    nh = 0;
    FOR(i,0,n) {
      heap[nh++] = i;
      where[i] = nh-1;
    }
    for(int i = nh-1; i >= 0; i--)
      down(i);
  }

  void test(int& next, int x) {
    if(x >= next) return;
    int next_max = v[x]-1;
    for(int i = 0; i < min(3,nh); i++) {
      if(heap[i] != x) {
        next_max = max(next_max, v[heap[i]]);
      }
    }

    if(2*next_max <= rem) {
      next = x;
    }
  }

public:
  vector<int> solve() {
    ans.clear();
    m = 0;
    int maxi = 0;
    FOR(i,0,n) {
      m += v[i];
      maxi = max(maxi, v[i]);
    }
    if(2 * maxi > m + 1) {
      return ans;
    }

    init_heap();

    int prev = -1, i1 = 0, i2 = 1, inf = -1;
    rem = m;
    FOR(x,0,m) {
      int next = n;
      while(i1 < n && v[i1] <= 0) i1++;
      if(i1 >= i2) i2 = i1+1;
      while(i2 < n && v[i2] <= 0) i2++;

      if(i1 != prev) test(next, i1);
      if(i2 != prev) test(next, i2);

      if(heap[0] != prev) test(next, heap[0]);
      if(nh>1 && heap[1] != prev) test(next, heap[1]);
      if(nh>2 && heap[2] != prev) test(next, heap[2]);

      assert(0 <= next);
      assert(next < n);
      assert(v[next] > 0);

      prev = next;
      ans.push_back(next);
      rem--;
      v[next]--;
      if(v[next] == 0) {
        v[next] = inf--;
      }
      down(where[next]);
      if(v[next] < 0) {
        int pos = where[next];
        nh--;
        swap(nh, where[next]);
        down(pos);
        up(pos);
      }
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

    vector<int> ans = ins->solve();
    if(ans.size() == 0) {
      printf("IMPOSSIBLE\n");
    } else {
      // FORE(it, ans) printf("%d ", *it);

      ll val = 0;
      for(int i = 0; i < ans.size(); i++) {
        ll v1 = i+1, v2 = ans[i]+1;
        val += (v1 * v2) % MOD;
        val %= MOD;
      }
      printf("%lld\n", val);
    }
  }
    return 0;
}