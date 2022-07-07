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

    map<string, int> candidateListID;               // this map stored candidate names and Id, same as Id of People in SortedPollResult

    // operator overload for SortedPollResult
    typedef struct People {
        string name;
        int ID;
        int score;
        // bool operator < (People people) {
        //     if(people.score == score) {
        //         return people.ID > ID;
        //     }
        //     return people.score < score;
        // }
    } People;

    vector <People> SortedPollResult;               // SortedPollResult[Id] give access to People, whose name, Id are in candidateListId

    // static function greater could be used for sort(SortedPollResult.begin(), SortedPollResult.end());
    // however, it is slower than
    static bool greater(const People& a, People& b)
    {
        if(a.score == b.score) {
            return a.ID > b.ID;
        }
        return a.score > b.score;
    }

    void Input() {
        cin >> N;

        SortedPollResult.resize(N);
        string name;
        int score;

        for (int i = 0; i < N; i++) {
            cin >> name;
            // use i as ID for candidates:
            candidateListID[name] = i;                // update ID to candidate name
            SortedPollResult[i].name = name;          // update name according to ID
            SortedPollResult[i].ID = i;             // also update ID of people for each name.
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> name >> score;
            // auto it = SortedPollResult.find(name);           // deprecated: SortedPollResult cannot find name but People
            // if (it != SortedPollResult.end()){
            auto it = candidateListID.find(name);
            if (it != candidateListID.end()) {
                int ID = it->second;
                // int ID = candidateListID[name];
                SortedPollResult[ID].score += score;
            }
        }
    }

    void Solve() {
        sort(SortedPollResult.begin(), SortedPollResult.end(), greater);
    }

    void Output() {
        for (int i = 0; i < 3; ++i) {
            cout << SortedPollResult[i].name << " " << SortedPollResult[i].score << endl;
        }
    }
};

int main() {
    Solution sol;
    sol.Input();
    sol.Solve();
    sol.Output();
}