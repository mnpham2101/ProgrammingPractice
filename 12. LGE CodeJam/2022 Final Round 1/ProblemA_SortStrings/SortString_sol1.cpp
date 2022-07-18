#include<set>
#include<map>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;

vector<pair<string, string>> dat;
char lookup[128];

class P2 {
public:

  void convert(string &x) {
    for(int i = 0; i < x.size(); i++)
      x[i] = lookup[(int)x[i]];
  }

  void solve() {
    sort(dat.begin(), dat.end());
  }
};

void init() {
  lookup[(int)' '] = ' ';
  lookup[(int)'-'] = ' ' + 1 + 52;
  for(char c = 'A'; c <= 'Z'; c++) {
    lookup[(int)c] = ' ' + 1 + (c - 'A') * 2;
  }
  for(char c = 'a'; c <= 'z'; c++) {
    lookup[(int)c] = ' ' + 1 + (c - 'a') * 2 + 1;
  }
}

int main() {
    int t;
    scanf("%d", &t);
    P2 *inst = new P2();

  init();

    while(t--) {
    int n;
    scanf("%d", &n);
    dat.resize(n);
    FOR(i,0,n) {
      char buff[1024];
      scanf("%s", buff);
      string org = string(buff), mod = string(buff);
      inst->convert(mod);
      dat[i] = make_pair(mod, org);
    }

    inst->solve();
    FOR(i,0,n)
      printf("%s\n", dat[i].second.c_str());
    }
  return 0;
}