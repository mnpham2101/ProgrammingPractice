#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int N = 0;              // registered candidatesf
    int M = 0;              // participants

    map<string, int> candidateList;

    vector <pair<string, int>> SortedPollResult;

    // operator overload for SortedPollResult
    static bool greater(pair<string, int>& a, pair<string, int>& b)
    {
        return a.second > b.second;
    }

    void Input() {
        cin >> N;
        string name;
        for (int i = 0; i < N; i++) {
            cin >> name;
            candidateList.insert({ name, 0 });
        }

        cin >> M;
        int score;
        for (int i = 0; i < M; i++) {
            cin >> name;
            cin >> score;
            auto it = candidateList.find(name);
            if (it != candidateList.end()) {
                // update accumulated score
                candidateList[name] += score;
                // SortedPollResult.push_back({ name, accumulatedScore });      // should push the final score to vector, if pushed like this,
                                                                                // vector SortedPollResult has multiple pairs of same names and different scores.
            }
        }
    }

    // pass 6/10 or 8/10 test cases due to that solution checker differentiates the order by which candidate is input
    void Solve() {
        SortedPollResult.resize(N);
        // copy to vector
        for (auto& it : candidateList) {                // space performance bug: both push_back and insert increase the size by 1. not suitable. Should use [] operator
            SortedPollResult.push_back(it);             // O(n) if reallocation occurs. O(1) if not. Resize() ensures no reallocation
        }

        sort(SortedPollResult.begin(), SortedPollResult.end(), greater);        // sort function only works for vector
    }

    void Output() {
        auto it = SortedPollResult.begin();
        for (int i = 0; i < 3; i++) {
            cout << it->first << " " << it->second << endl;
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