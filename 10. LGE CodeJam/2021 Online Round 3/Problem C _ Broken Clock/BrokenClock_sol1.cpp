#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_SECOND  (60 * 60 * 24)
#define mod(x)      ((((long long)x) + MAX_SECOND) % MAX_SECOND)

vector<pair<int,int> > normalize(const vector<pair<int,int> > &line) {
        map<int,int> m;
        for (auto const &p : line) {
                int a = mod(p.first % MAX_SECOND);
                int b = mod(p.second % MAX_SECOND);
                if (!m.count(a)) {
                        m[a] = b;
                } else if (m[a] != b) {
                        return {};
                }
        }
        vector<pair<int,int> > ans;
        for (auto const &p : m)
                ans.emplace_back(p);
        return ans;
}

static inline int f(int x, int a, int b) {
        return mod(a * x + b);
}

bool intersected(int x, const vector<pair<int,int> > &lines) {
        int n = lines.size();
        if (n < 2)
                return false;

        int y0 = f(x, lines[0].first, lines[0].second);
        for (int i = 1; i < n; ++i) {
                int yi = f(x, lines[i].first, lines[i].second);
                if (y0 != yi)
                        return false;
        }
        return true;
}

/* @lines: y = ax + b */
int solve(vector<pair<int,int> > &lines) {
        const vector<pair<int,int> > &norm_lines = normalize(lines);
        if (norm_lines.empty())
                return 0;

        if (norm_lines.size() == 1)
                return lines.size() > 1 ? MAX_SECOND: 0;

        int ans = 0;
        for (int i = 0; i < MAX_SECOND; ++i)
                if (intersected(i, norm_lines))
                        ++ans;
        return ans;
}

int to_second(const string &s) {
        int hour = (s[0] - '0') * 10 + (s[1] - '0');
        int min = (s[3] - '0') * 10 + (s[4] - '0');
        int sec = (s[6] - '0') * 10 + (s[7] - '0');
        return hour * 60 * 60 + min * 60 + sec;
}

int main(void) {
        cout.sync_with_stdio(false);
        cin.tie(nullptr);
        int nTests;
        cin >> nTests;
        while (nTests--) {
                int n;
                cin >> n;
                vector<pair<int,int> > lines(n);
                for (int i = 0; i < n; ++i) {
                        string s;
                        cin >> s;
                        lines[i].second = to_second(s);
                }
                for (int i = 0; i < n; ++i)
                        cin >> lines[i].first;
                cout << solve(lines) << '\n';
        }
        return 0;
}