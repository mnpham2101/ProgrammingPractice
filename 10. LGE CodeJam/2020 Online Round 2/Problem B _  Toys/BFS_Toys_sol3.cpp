#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T > 0) {
        int N = 0, M = 0;
        cin >> N >> M;

        vector<char> ally(N, 0);
        vector<vector<int>> enemy(N, vector<int>());
        queue<int> q;

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            a -= 1; b -= 1;

            enemy[a].push_back(b);
            enemy[b].push_back(a);
        }

        bool result = true;

        for (int i = 0; i < N; i++) {
            if (ally[i] > 0) continue;

            ally[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int here = q.front();
                q.pop();

                for (int there : enemy[here]) {
                    if (ally[there] == 0) {
                        q.push(there);
                        ally[there] = (ally[here] == 1) ? 2 : 1;
                    }
                    else if (ally[there] == ally[here]) {
                        result = false;
                        break;
                    }
                }

                if (result == false) break;
            }

            if (result == false) break;
        }

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;

        T -= 1;
    }

    return 0;
}