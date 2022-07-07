#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

vector<int> possibleSum(12);            // there are only 12 possible sums

void getPossibleSum() {

    int num = 202002021;
    for (int i = 0; i < 10; ++i) {
        possibleSum[i] = num + (i * 10000);
    }

    possibleSum[10] = 202021;
    possibleSum[11] = 20202021;
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
    for (auto [number, occurrence ] : numbers) {
        for (int target : possibleSum) {
            auto otherNumber = numbers.find(target - number);
            if (otherNumber != numbers.end()) {
                ans += occurrence * otherNumber->second;         // ans = occurences of numberA * occurance of numberB
            }
        }
    }
    cout << ans / 2 << '\n';
}

int main() {

    getPossibleSum();
    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}