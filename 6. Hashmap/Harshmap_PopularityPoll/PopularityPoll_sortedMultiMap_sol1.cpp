#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int N=0;              // registered candidates
    int M=0;              // participants

    map<string, int> PollResult;
    multimap<int, string, greater<int>> sortedPollResult;    // sorted the result in descending order of key = score by default
    void Input() {
        cin >> N;
        string name;
        for (int i = 0; i < N; i++) {
            cin >> name;
            PollResult.insert({ name, 0 });
        }

        cin >> M;
        int score;
        for (int i = 0; i < M; i++) {
            cin >> name;
            cin >> score;
            auto it = PollResult.find(name);
            if (it != PollResult.end()) {
                PollResult[name] += score;
            }
        }
    }

    // pass 6/10 test cases due to that solution checker differentiate the order by which candidates are input. Multimap slightly rearranges the order.
    void Solve() {
        for (auto& it : PollResult) {
            sortedPollResult.insert({ it.second, it.first });                           // time complexity: because of comparison, it could be O(log2(N)).
                                                                                        // ref: https://stackoverflow.com/questions/21740893/what-is-the-time-complexity-of-stdmap
        }
        // sort(sortedPullResult.begin(), sortedPullResult.end(), greater<int>());      // incorrect syntax
                                                                                        // fix by declaring multimap<int, string, greater<int>> sortedPullResult;
    }

    void Output(){
        auto it = sortedPollResult.begin();
        for (int i = 0; i < 3; i++) {
            cout << it->second << " " << it->first << endl;
            it++;
        }
    }
};

int main() {
    Solution sol;
    sol.Input();
    sol.Solve();
    sol.Output();
}