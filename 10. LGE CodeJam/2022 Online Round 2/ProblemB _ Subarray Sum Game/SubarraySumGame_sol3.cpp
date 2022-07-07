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

const int mod = 1'000'000'007;
vector<int> fact;
void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    vector<int> tmp(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x>> y;
        tmp[--x]++;
        tmp[y]--;
    }
    vector<int> cnt(n);
    cnt[0] = tmp[0];
    for(int i = 1; i < n; ++i) {
        cnt[i] = cnt[i-1] + tmp[i];
    }
    sort(a.rbegin(), a.rend());
    sort(cnt.rbegin(), cnt.rend());

    unordered_map<int, vector<int>> cnt_to_num;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += cnt[i] * a[i];
        cnt_to_num[cnt[i]].push_back(a[i]);
    }
    int way = 1;
    for(auto& [key, val] : cnt_to_num) {
        int d = val.size();
        sort(val.begin(), val.end());
        int sum_tmp = fact[d];
        int cur = val[0];
        int cnt_cur = 1;
        for(int i = 1; i < val.size(); ++i) {
            if(cur != val[i]) {
                sum_tmp /= fact[cnt_cur];
                cnt_cur = 1;
                cur = val[i];
            }
            else
                ++cnt_cur;
        }
        way *= sum_tmp;
        way %= mod;
    }

    cout << sum << " " << way << endl;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact = vector<int>(50005, 1);

    for(int i = 2; i <= 50000; ++i) {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    int t;
    cin >> t;
    while(t--) test_case();
    return 0;
}