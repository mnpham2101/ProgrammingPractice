#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
 
long long best_team(int n, int k, vector<int> &a, vector<int> &b) {
        vector<int> r(n);                                           // sort array based on descending order of b-a
        iota(r.begin(), r.end(), 0);
        sort(r.begin(), r.end(), [&](int i, int j) {                // sorting
                int di = b[i] - a[i];
                int dj = b[j] - a[j];
                return di > dj;
        });
 
        long long ans = 0;
        int m = n - k;                                  // m is set at total of 2 teams if they have same number of members.                   
        if (m & 1)                                      // ??????????????????
                ++m, --k;
        m /= 2;
        for (int i = 0; i < m; ++i)                    // m is lower bound of team B: team B can have from m to m+K
                ans += b[r[i]];                                 
        for (int i = m; i < m + k; ++i)                 // for members in K range, we picked the candidate with higher skill sets from teamA and teamB
                ans += max(a[r[i]], b[r[i]]);
        for (int i = m + k; i < n; ++i)                 // m+K is higher bound of team A: team A can have from m to m+K. In term of indexing, i=m+k is lower boundary.
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