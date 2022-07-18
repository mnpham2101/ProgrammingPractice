#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

long long best_team(int n, int k, vector<int> &a, vector<int> &b) {
        vector<int> r(n);
        iota(r.begin(), r.end(), 0);
        sort(r.begin(), r.end(), [&](int i, int j) {
                int di = b[i] - a[i];
                int dj = b[j] - a[j];
                return di > dj;
        });

        long long ans = 0;
        int m = n - k;
        if (m & 1)
                ++m, --k;
        m /= 2;
        for (int i = 0; i < m; ++i)
                ans += b[r[i]];
        for (int i = m; i < m + k; ++i)
                ans += max(a[r[i]], b[r[i]]);
        for (int i = m + k; i < n; ++i)
                ans += a[r[i]];
        return ans;
}

int main(void) {
        cout.sync_with_stdio(false);
        cin.tie(nullptr);
        int nTests;
        cin >> nTests;
        while (nTests--) {
                int n, k;
                cin >> n >> k;
                vector<int> a(n), b(n);
                for (int i = 0; i < n; ++i)
                        cin >> a[i];
                for (int i = 0; i < n; ++i)
                        cin >> b[i];
                cout << best_team(n, k, a, b) << '\n';
        }
        return 0;
}