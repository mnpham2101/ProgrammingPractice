#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<queue>
using namespace std;

queue<int>resultList;

void input(vector<long long int>& v, int& n, int& x) {
}

void runLogic(vector<long long int>& v, int& n, int& x) {
    // Step1: fill up data set and harshmap
    unordered_map<long long int, int> freqMap;
    for (int i = 0; i < n; i++) {
        freqMap[v[i]]++;       // harshmap stores the frequency of an item in v.
    }

    // Step2: check each element to see how many pair appear.
    int result = 0;
    for (auto& current : freqMap) {
        long long int numberA = current.first;
        long long int numberB = x ^ numberA;
        int numberAFrequency = freqMap[numberA];
        int numberBFrequency = freqMap[numberB];
        // Special case
        if (x == 0) {
            result += numberAFrequency * (numberAFrequency - 1) / 2;
            // same as
            // result += current.second * (current.second - 1) / 2;
        }
        // Regular case
        else if (numberA < numberB) {
            result += numberAFrequency * numberBFrequency;
        }
    }
    resultList.push(result);
    // return result;
}

void output(int result) {
    cout << result << endl;
}

void output(queue<int>& resultList) {
    while (!resultList.empty()) {
        int testCaseResult = resultList.front();                    // first in first out
        cout << testCaseResult << endl;
        resultList.pop();
    }
}

void runTestCase() {
    int n, x;
    cin >> n;
    cin >> x;
    vector<long long int> v(n);
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        v[i] = value;
    }
    runLogic(v, n, x);

}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
    output(resultList);
}