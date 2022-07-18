#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
using namespace std;
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
typedef long long ll;

const int MAX_BIT = 25;
int n, q, sz;
int x[131072];
int y[131072][2];

struct Node{
  Node *ch[2];
};

Node *root;

class P6 {
public:

  int find_min(int x) {
    if(sz == 0) return -1;

    Node *v = root;
    int bit = 1<<MAX_BIT;
    int result = 0;
    while(bit > 0) {
      int flag = (x&bit)==0 ? 0 : 1;
      if(v->ch[flag] != NULL) {
        v = v->ch[flag];
      } else {
        result |= bit;
        v = v->ch[1-flag];
      }
      bit >>= 1;
    }

    return result;
  }
  int find_max(int x) {
    if(sz == 0) return -1;

    Node *v = root;
    int bit = 1<<MAX_BIT;
    int result = 0;
    while(bit > 0) {
      int flag = (x&bit)==0 ? 0 : 1;
      if(v->ch[1-flag] != NULL) {
        result |= bit;
        v = v->ch[1-flag];
      } else {
        v = v->ch[flag];
      }
      bit >>= 1;
    }

    return result;
  }

  bool add(int x) {
    Node *v = root;
    int bit = 1<<MAX_BIT;
    bool newNode = false;
    while(bit > 0) {
      int flag = (x&bit)==0 ? 0 : 1;
      if(v->ch[flag] == NULL) {
        v->ch[flag] = new Node();
        newNode = true;
      }
      v=v->ch[flag];
      bit >>= 1;
    }
    return newNode;
  }

  bool remove(Node *v, int x, int bit) {
    if(bit == 0) {
      delete v;
      return true;
    }
    int flag = (x&bit)==0 ? 0 : 1;
    if(v->ch[flag] == NULL) {
      assert(false);
    }
    if(remove(v->ch[flag], x, bit>>1))
      v->ch[flag] = NULL;
    if(v->ch[flag] == NULL && v->ch[1-flag] == NULL) {
      delete v;
      return true;
    }
    return false;
  }

  void clean(Node *x) {
    if(x->ch[0] != NULL) clean(x->ch[0]);
    if(x->ch[1] != NULL) clean(x->ch[1]);
    delete(x);
  }

  void solve() {
    sz = 0;
    root = new Node();
    root->ch[0] = root->ch[1] = NULL;
    for(int i = 0; i < n; i++) {
      if(add(x[i])) {
        sz++;
      }
    }
    for(int i = 0; i < q; i++) {
      int vv;
      switch(y[i][0]) {
        case 1:
        printf("%d\n", find_min(y[i][1]));
        break;

        case 2:
        printf("%d\n", find_max(y[i][1]));
        break;

        case 3:
        if(add(y[i][1]))
          sz++;
        printf("%d\n", sz);
        break;

        case 4:
        vv = find_min(0);
        printf("%d\n", vv);
        sz--;
        remove(root, vv, 1<<MAX_BIT);
        break;

        case 5:
        vv = find_max(0);
        printf("%d\n", vv);
        sz--;
        remove(root, vv, 1<<MAX_BIT);
        break;

        default:
        break;
      }
    }
    clean(root);
  }
};

int main() {
    int t;
    scanf("%d", &t);
    P6 *inst = new P6();
    while(t--) {
    sz = 0;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)
      scanf("%d", &x[i]);
    for(int i = 0; i < q; i++) {
      scanf("%d", &y[i][0]);
      if(y[i][0] <= 3) {
        scanf("%d", &y[i][1]);
      }
    }
    inst->solve();
    }
  return 0;
}