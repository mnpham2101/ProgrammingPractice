#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = ll(4e18) + 7;
const int MAXN = int(2e6);

void solve(int tc) {
    int N, Z;
    cin >> N >> Z;

    ll hs, ha, hb, hc;
    cin >> hs >> ha >> hb >> hc;

    ll ws, wa, wb, wc;
    cin >> ws >> wa >> wb >> wc;

    vector<ll> H(N, 0);
    vector<ll> W(N, 0);
    H[0] = hs % hc + 1;
    W[0] = ws % wc + 1;
    for (int i = 1; i < N; ++i) {
        H[i] = H[i - 1] + 1 + (H[i - 1] * ha + hb) % hc;
        W[i] = (W[i - 1] * wa + wb) % wc + 1;
    }

    deque<pll> dq;
    ll ans = -INF;
    int completed = 0;
    for (int i = 0; i < N - 1; ++i) {
        while (completed < N && H[completed] <= H[i] + Z) {
            while (!dq.empty() && dq.back().first <= H[completed] * W[completed]) {
                dq.pop_back();
            }
            dq.push_back({H[completed]*W[completed], completed});
            completed += 1;
        }

        ll poped = INF;
        while (!dq.empty()) {
            pll t = dq.front();
            if (t.second > i) {
                poped = t.first;
                break;
            } else {
                dq.pop_front();
            }
        }

        if (poped == INF) continue;
        ans = max(ans, (H[i] * W[i]) + poped);
    }

    if (ans == -INF) {
        ans = -1;
    }

    cout << ans << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}