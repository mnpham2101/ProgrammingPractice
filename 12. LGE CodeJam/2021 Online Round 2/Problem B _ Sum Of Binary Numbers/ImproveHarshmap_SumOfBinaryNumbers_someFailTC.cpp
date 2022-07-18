#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
using namespace std;

// int findBadBinarySum(long long int x, long long int y) {
//     return x ^ y;
// }

// void input(vector<long long int>& v, int& n, int& x) {
// }

int runLogic() {
    int n, x;
    cin >> n;
    cin >> x;
    vector<long long int> v(n);
    int value;
        
    // Step1: fill up data set and harshmap
    unordered_map<long long int, long long int> freqMap;
    
    for (int i = 0; i < n; i++) {
        cin >> value;
        v[i] = value;
        freqMap[value]++;       // harshmap stores the frequency of an item in v. 
    }

    // Step2: check each element to see how many pair appear.
    // Special case
    int result = 0;
    if (x == 0) {
        for (auto &current : freqMap) {
            result += current.second * (current.second - 1) / 2;
        }
        return result;
    }
    // Regular case
    unordered_set<int> matchQueue;                                                      
    for (auto& current : freqMap) {
        if (matchQueue.find(x ^ current.first) != matchQueue.end()) {                    
            result += freqMap[current.first] * freqMap[x ^ current.first];
        }
        else
        matchQueue.insert(current.first);                                               // improve time complexity but matchQueue stills takes time.          
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