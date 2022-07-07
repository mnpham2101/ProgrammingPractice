#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;

queue<bool> resultList;

void input() {

}

void runLogic(vector< unordered_map<char, int>> plateInfo) {
    int count = 0;
    for (auto firstPlate = plateInfo.begin(); firstPlate != plateInfo.end(); firstPlate++) {
        bool compare = true;
        for (auto secondPlate = plateInfo.begin(); secondPlate != plateInfo.end(); secondPlate++) {
            if (firstPlate == secondPlate) {
                compare = false;
                break;
            }
            else {
                // comparing - needs to make better time complexity here.
                for (auto character = firstPlate->begin(); character != firstPlate->end(); character++) {
                    if (secondPlate->find(character->first) == secondPlate->end()) {
                        compare = false;                        // needs to compare character->second
                    }
                }
            }
        }
        if (compare == true) count++;
    }
    cout << count << endl;
}

void output(queue<bool>& resultList) {
    while (!resultList.empty()) {
        bool testCaseResult = resultList.front();                    // first in first out
        if (testCaseResult == true) cout << "NOT CHEATER" << endl;
        else cout << "CHEATER" << endl;
        resultList.pop();
    }
}

void runTestCase() {
    int n, k;
    cin >> n >> k;
    string plate;
    plate.reserve(k);
    unordered_map<char, int> characterCount;
    vector< unordered_map<char, int> > plateInfo(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            char x;
            cin >> x;
            plate.push_back(x);                     // bad code:
                                                    // if n=2, k= 4
                                                    // "aaaa"   enter
                                                    // "aaaa"   enter
                                                    // plate will be a string of "aaaaaaaa" => its size increates to 8
            characterCount[plate[j]]++;             // characterCount = {'a', 8}
        }
        plateInfo.emplace_back(characterCount);     // plateInfo = {{}, {}, {'a',4}, {'a',4}}
                                                    // this causes unneccesasary comparison between {} and {}
    }
    runLogic(plateInfo);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
    output(resultList);
}