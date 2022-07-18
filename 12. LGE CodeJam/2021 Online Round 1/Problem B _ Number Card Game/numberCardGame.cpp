#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

long long solve(string& x) {
    int n = x.size();
    vector<int> num;
    for (int i = 0; i < n; i++) {
        if (x[i] == '6')
            num.push_back(9);
        else
            num.push_back(x[i] - '0');
    }
    sort(num.rbegin(), num.rend());
    long long ans = 0;
    for (int t = 0; t < (1 << n); t++) {
        long long v1 = 0, v2 = 0;
        for (int i = 0; i < n; i++) {
            if ((t & (1 << i)) == 0)
                v1 = v1 * 10ll + num[i];
            else
                v2 = v2 * 10ll + num[i];
        }
        ans = max(ans, v1 * v2);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    return 0;
}