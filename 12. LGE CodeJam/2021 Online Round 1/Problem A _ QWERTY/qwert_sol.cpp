#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> keys = {
    "QWERTYUIOP",
    "ASDFGHJKL",
    "ZXCVBNM" };

map<char, pair<int, int>> key_pos;

void solve(int c)
{
    string s;
    cin >> s;

    // result = length of string + distance between keys * 2seconds
    int result = s.size();

    char cur = s[0];
    pair<int, int> currentKeyPosition = key_pos[cur];

    for (int i = 1; i < s.size(); ++i)
    {
        char nextKey = s[i];
        pair<int, int> nextKeyPosition = key_pos[nextKey];

        int diff_row = nextKeyPosition.first - currentKeyPosition.first;
        int diff_column = nextKeyPosition.second - currentKeyPosition.second;

        // add distance between keys * 2 seconds
        result += max(abs(diff_row + diff_column), max(abs(diff_row), abs(diff_column))) * 2 ;
        currentKeyPosition = nextKeyPosition;
    }

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < keys.size(); ++i)
    {
        string line = keys[i];
        for (int j = 0; j < line.size(); ++j)
        {
            char key = line[j];
            key_pos[key] = make_pair(i, j);
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve(t);
    }

    return 0;
}
