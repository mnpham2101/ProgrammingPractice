#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n, h[502], r[502];
vector<vector<int>> toys;
deque<int> ans_lf, ans_rt;
bool isVisited[2][2][502][502];

void input_init()
{
    cin >> n;
    for (int i=0; i<n; ++i) cin >> h[i];
    for (int i=0; i<n; ++i) cin >> r[i];
    toys = vector<vector<int>>();
    ans_lf = deque<int>();
    ans_rt = deque<int>();
    memset(isVisited, 0, sizeof(isVisited));
}

void makeToyData()
{
    for(int i=0; i<n; ++i) {
        toys.push_back({h[i], r[i], i});
    }
    // 높이 내림차순으로 정렬
    sort(toys.begin(), toys.end());
    reverse(toys.begin(), toys.end());
}

bool dp(int cur, bool up_lf, bool up_rt, int i_lf, int i_rt)
{
    if(cur >= n) {
        // i_lf와 i_rt가 모두 0일 경우
        // 1<k<n이라는 조건을 만족하지 않는다.
        return i_lf != 0 && i_rt != 0;
    }

    if (isVisited[up_lf][up_rt][i_lf][i_rt]) {
        return false;
    }
    // Same case (reverse)
    isVisited[up_lf][up_rt][i_lf][i_rt] = isVisited[up_rt][up_lf][i_rt][i_lf] = true;

    bool ret = false;

    // 현재 장난감을 왼쪽에 놓을 경우
    if (toys[cur][0] < toys[i_lf][0]) {
        // 왼쪽 장난감이 이전에 증가했었는지 감소했었는지 확인 후
        // 만족하는 경우에 한 해 현재 장난감을 왼쪽 배열에 넣고 진행한다.
        if (up_lf && toys[cur][1] > toys[i_lf][1])
            ret = dp(cur+1, false, up_rt, cur, i_rt);
        else if (!up_lf && toys[cur][1] < toys[i_lf][1])
            ret = dp(cur+1, true, up_rt, cur, i_rt);

        // 만족하는 경우가 있으면 현재 장난감의 index를 왼쪽 배열에 넣는다.
        if (ret) {
            ans_lf.push_back(toys[cur][2]+1);
            return true;
        }
    }

    // 현재 장난감을 오른쪽에 놓을 경우
    if (toys[cur][0] < toys[i_rt][0]) {
        if (up_rt && toys[cur][1] > toys[i_rt][1])
            ret = dp(cur+1, up_lf, false, i_lf, cur);
        else if (!up_rt && toys[cur][1] < toys[i_rt][1])
            ret = dp(cur+1, up_lf, true, i_lf, cur);
        if (ret) {
            ans_rt.push_front(toys[cur][2]+1);
            return true;
        }
    }
    return false;
}

void solve()
{
    input_init();
    makeToyData();

    string ans = "";
    if (dp(1, true, true, 0, 0) || dp(1, false, false, 0, 0)) {
        ans_lf.push_back(toys[0][2]+1);
        ans_lf.insert(ans_lf.end(), ans_rt.begin(), ans_rt.end());
    }
    else {
        ans_lf = {-1};
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        for(int a : ans_lf) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}