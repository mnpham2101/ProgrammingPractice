#include<string>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;

queue<int> resultList;

// void input() {

// }

// void runLogic() {
//     resultList.push(5);

// }

// void output(queue<bool>& resultList) {
//     while (!resultList.empty()) {
//         bool testCaseResult = resultList.front();                    // first in first out
//         if (testCaseResult == true) cout << "NOT CHEATER" << endl;
//         else cout << "CHEATER" << endl;
//         resultList.pop();
//     }
// }

void runTestCase() {
    
    int n, L, F;
    cin >> n >> L >> F;

    string str;
    vector<string> stringList(n);

    for (int i = 0; i < n; i++) {
        cin >> str;
        stringList[i] = str;
    }

    map<string, int> commonSubstring;

    for (int i = 0; i < n; i++) {                                              // O(n) where n = 500
        string potentialCommon = stringList[i].substr(L - F, F);
        commonSubstring[potentialCommon]++;
    }
    int ans = 0; 
    for (auto i = commonSubstring.begin(); i != commonSubstring.end(); i++) {   // O(n) where n = 500
        ans += i->second/2;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
    // output(resultList);
}