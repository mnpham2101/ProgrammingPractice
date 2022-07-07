#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int possible(string& str, int s, int e) {
    if (str[e] == ')' && (str[s] == '(' || str[s] == '*')) {
        return 2;
    } else if (str[e] == ']' &&(str[s] == '[' || str[s] == '*')) {
        return 2;
    } else if (str[e] == '}' &&(str[s] == '{' || str[s] == '*') ) {
        return 2;
    } else if (str[e] == '*' && (str[s] == '(' || str[s] == '[' || str[s] == '{' || str[s] == '*')) {
        return 2;
    }
    return 0;
}
void calc(string& str) {
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));    // dp is maximum number of matched characters
    for (int e = 1; e < n; e++) {
        for (int s = e - 1; s >= 0; s--) {
            int ret = 0;
            for (int k = s; k < e; k++)
                ret = max(ret, dp[s][k] + dp[k + 1][e]);
            ret = max(ret, possible(str, s, e) + (e - s > 2 ? dp[s + 1][e - 1] : 0));
            dp[s][e] = max(dp[s][e], ret);
        }
    }
    cout << str.length() - dp[0][str.length() - 1] << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        calc(str);
    }
    return 0;
}