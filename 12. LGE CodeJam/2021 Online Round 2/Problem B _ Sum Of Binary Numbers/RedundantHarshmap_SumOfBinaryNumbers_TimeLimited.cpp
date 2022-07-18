#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
using namespace std;

int findBadBinarySum(long long int x, long long int y) {
    return x ^ y;
}

// void input(vector<long long int>& v, int& n, int& x) {
// }

int runLogic() {
    int n, x;
    cin >> n;
    cin >> x;
    vector<long long int> v(n);
    int value;
        
    // fill up data set and harshmap
    unordered_map<long long int, long long int> freqMap;
    unordered_set<int> matchQueue;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v[i] = value;
        freqMap[value]++;       // harshmap stores the frequency of an item in v.
        int potentialMatch = findBadBinarySum(v[i], x);
        matchQueue.insert(potentialMatch);
    }

    // check each element to see how many pair appear.
    int result = 0;
    if (x == 0) {
        for (auto current : freqMap) {
            result += current.second * (current.second - 1) / 2;
        }
        return result;
    }

    for (auto& current : freqMap) {
        int potentialMatch = findBadBinarySum(current.first, x);                   // find the potentialMatch
        auto potentialmatch_it = matchQueue.find(potentialMatch);
        if (potentialmatch_it != matchQueue.end()) {
            result += freqMap[current.first] * freqMap[potentialMatch];            // result += frequency of a * frequency of b
            matchQueue.erase(current.first);                                       // erase the match pair  ===> operation on matchQueue takes time!
            matchQueue.erase(potentialMatch);
        }
    }
    return result;
}

void output(int result) {
    cout << result << endl;
}

// void output(queue<int>&resultList){
//     while (resultList.size() !=0){
//         int testCaseResult = resultList.front();                    // first in first out
//         cout<<testCaseResult<<endl;
//         resultList.pop();
//     }
// }

void runTestCase() {
    int result = runLogic();
    output(result);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}