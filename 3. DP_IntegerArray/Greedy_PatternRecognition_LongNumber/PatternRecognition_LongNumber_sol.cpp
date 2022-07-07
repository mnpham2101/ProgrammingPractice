#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
typedef long long ll;




class P4 {
public:
    ll p10[20];
    ll lent(ll x) {
        ll ans = 0;
        while (x > 0) {
            ans++;
            x /= 10;
        }
        return ans;
    }

    ll get_len(ll x, ll b, ll a) {
        if (a == 0) a += b;
        if (x == b) return lent(x);
        ll xl = lent(x);

        // if(x == 5033165200ll) {
        //   printf("[x = %lld b = %lld a = %lld]:\n", x, b, a);
        // }
        ll ans = 0;
        for (ll len = 1; len <= xl; len++) {
            ll k1 = (p10[len - 1] - a + (b - 1)) / b;
            ll k2 = (p10[len] - 1 - a) / b;
            if (len == xl) {
                k2 = (x - a) / b;
            }
            ll x1 = a + k1 * b, x2 = a + k2 * b;
            if (k1 <= k2 && p10[len - 1] <= x1 && x2 < p10[len]) {
                ans += (k2 - k1 + 1) * len;
            }
            // if(x == 5033165200ll) {
            //   printf("\t(len = %lld k1 = %lld (x1 = %lld) k2 = %lld (x2 = %lld) and = %lld\n", len, k1, x1, k2, x2, ans);
            // }
        }
        // printf("\n");

        return ans;
    }

    ll total(ll a, ll b, ll k) {
        // x = a + b * k (k >= 0)
        ll x2 = a + b * k;
        ll v2 = get_len(x2, b, a % b);

        ll x1 = a - b;
        ll v1 = 0;
        if (x1 > 0) {
            v1 = get_len(x1, b, a % b);
        }
        // printf("a = %lld b = %lld k = %lld x2 = %lld (v2 = %lld) x1 = %lld (v1 = %lld)\n",
        // a, b, k, x2, v2, x1, v1);
        return v2 - v1;
    }
    void init() {
        p10[0] = 1;
        FOR(i, 1, 20) p10[i] = p10[i - 1] * 10ll;
    }

    int solve(ll a, ll b, ll c) { // 10^6 10^6 10^12?

        ll l = 0, r = 1;
        while (total(a, b, r) <= c) r *= 2;

        while (l <= r) {
            ll mid = (l + r) / 2;
            if (total(a, b, mid) >= c) r = mid - 1;
            else l = mid + 1;
        }
        ll x = a + b * l;
        // printf("number of interest: %lld\n", x);
        ll len = total(a, b, r); // < c
        char buff[128];
        printf(buff, "%lld", x);
        return buff[c - len - 1] - '0';
    }

};

int main() {
    int t;
    cin >> t;
    P4* inst = new P4();
    inst->init();
    while (t--) {
        ll a, b, c;
        
        cin >> a >> b >> c; 
        printf("%d\n", inst->solve(a, b, c));
    }

    return 0;
}