#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

vector<int> possibleSum;

void getPossibleSum() {
    possibleSum.push_back(202021);
    possibleSum.push_back(20202021);

    int num = 202002021;
    for (int i = 0; i < 10; ++i) {
        possibleSum.push_back(num + (i * 10000));
    }
}

void solve(int tc) {
    int n;
    cin >> n;

    int num;
    unordered_map<int, ll> numbers;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        numbers[num] += 1;
    }

    ll ans = 0;
    for (auto [k, v] : numbers) {
        for (int target : possibleSum) {
            auto otherIt = numbers.find(target - k);
            if (otherIt != numbers.end()) {
                ans += v * otherIt->second;
            }
        }
    }
    cout << ans / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getPossibleSum();
    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}