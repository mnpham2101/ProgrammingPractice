#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
#define ll long long
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int mod = 987'654'323;
struct myCompare
{
    bool operator()(pii x, pii y) {
        if(x.F == y.F)
            return x.S < y.S;
        return x.F < y.F;
    }
};
void test_case() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int sum = 0;
    int maxE = -1;
    priority_queue<pii, vector<pii>, myCompare> top;
    priority_queue<int, vector<int>, greater<int>> smallest;
    for(int i = 1; i <= n; ++i) {
        cin >> cnt[i];
        sum += cnt[i];
        maxE = max(maxE, cnt[i]);
        top.push({cnt[i], i});
        if(cnt[i] > 0)
            smallest.push(i);
    }
    vector<int> old_cnt = cnt;
    if(maxE > (sum - maxE + 1)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int i = 1;
    int ans = 0;
    int m = sum;
    vector<int> a(m + 1);
    while(1) {
        if(i == m + 1)
            break;
        pii p;
        while(1) {
            p = top.top();
            if(cnt[p.S] == p.F)
                break;
            if(cnt[p.S] != p.F) {
                top.pop();
                if(cnt[p.S] > 0)
                    top.push({cnt[p.S], p.S});
            }

        }
        if(p.F == (sum - p.F)) {
            int first = smallest.top();
            smallest.pop();
            int second = -1;
            if(!smallest.empty()) {
                second = smallest.top();
                smallest.pop();
            }
            if(second == -1) {
                ans += i * first;
                a[i] = first;
                ans %= mod;
                ++i;
                --sum;
                --cnt[first];
            }
            else {
                if(a[i-1] == first)
                    swap(first, second);
                ans += i * first;
                a[i] = first;
                ans %= mod;
                ++i;
                --sum;
                --cnt[first];
            }
            ans += i * p.S;
            a[i] = p.S;
            ++i;
            ans %= mod;
            break;
        }
        if(p.F == (sum - p.F + 1)) {
            ans += i * p.S;
            a[i] = p.S;
            ++i;
            ans %= mod;
            break;
        }
        int first = smallest.top();
        smallest.pop();
        int second = -1;
        if(!smallest.empty()) {
            second = smallest.top();
            smallest.pop();
        }
        if(second == -1) {
            ans += i * first;
            a[i] = first;
            ans %= mod;
            ++i;
            --sum;
        }
        else {
            if(a[i-1] == first)
                swap(first, second);
            ans += i * first;
            a[i] = first;
            ans %= mod;
            ++i;
            --sum;
            ans += i * second;
            a[i] = second;
            ans %= mod;
            ++i;
            --sum;
        }
        if(--cnt[first] > 0)
            smallest.push(first);
        if(second != -1 && --cnt[second] > 0)
            smallest.push(second);
    }

    if(!top.empty() && i != m) {
        auto p = top.top();
        int cur = 1;
        while(cur <= n) {
            if(cur == p.S) {
                ++cur;
                continue;
            }
            if(cnt[cur] == 0) {
                ++cur;
                continue;
            }
            if(a[i-1] == p.S) {
                ans += i * cur;
                --cnt[cur];
                ans %= mod;
                ans += (i + 1) * p.S;
                ans %= mod;
                a[i] = cur;
                a[i+1] = p.S;
                i += 2;
            }
            else if(a[i-1] == cur) {
                ans += i * p.S;
                ans %= mod;
                --cnt[cur];
                ans += (i + 1) * cur;
                ans %= mod;
                a[i] = p.S;
                a[i+1] = cur;
                i += 2;
            }
            else if(cur < p.S) {
                ans += i * cur;
                --cnt[cur];
                ans %= mod;
                ans += (i + 1) * p.S;
                ans %= mod;
                a[i] = cur;
                a[i+1] = p.S;
                i += 2;
            }
            else {
                ans += i * p.S;
                ans %= mod;
                --cnt[cur];
                ans += (i + 1) * cur;
                ans %= mod;
                a[i] = p.S;
                a[i+1] = cur;
                i += 2;
            }
        }
    }
    cout << ans << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) test_case();
    return 0;
}
S