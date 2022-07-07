#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string& str) {
    int n = str.length();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int y = 0; y < n; y++) {                   // right anchor
        dp[0][y] = 1;
        for (int x = y; x >= 0; x--) {              // left anchor for substr1, right anchor for substr2
            for (int i = 0; i < x; i++) {           // left anchor for substr2
                // Log: 2 substring are created based on x, y, i
                cout << "y: " << y << " x: " << x << " i: " << i << endl;
                cout << "substringLeft: "<< str.substr(x, y - x + 1) << endl;
                cout << "substringRight: "<< str.substr(i, x - i) << endl;
                if (dp[i][x - 1] > 0 && stoll(str.substr(x, y - x + 1), nullptr, 16) >= stoll(str.substr(i, x - i), nullptr, 16)) {
                    dp[x][y] += dp[i][x - 1];       // dp equation is incremented when substring hexadecimal value decreases
                                                    // but why x, y ?
                    // I draw table but still can't see the relation

                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += dp[i][n - 1];          // sum is added up by the last element of each row of the DP array. WHY???
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
}