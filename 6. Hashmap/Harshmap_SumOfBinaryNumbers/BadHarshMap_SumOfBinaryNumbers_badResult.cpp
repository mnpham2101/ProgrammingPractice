#include<vector>
#include<map>
#include<iostream>
using namespace std;

int findBadBinarySum(long long int x, long long int y) {
    return x ^ y;
}

void input(vector<long long int>& v, int& n, int& x) {

}


int runLogic(vector<long long int> v, int& n, int& x) {
    int result = 0;
    cin >> n;
    cin >> x;
    int value;
    int potentialMatch = 0;                         // potentialMatch = v[i] ^ x 
    map<long long int, long long int> sumPair;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
        potentialMatch = findBadBinarySum(value, x);     // stored potential match of every input 
        sumPair[value] = potentialMatch;
    }
    // for every item in array, compared it with the potential match value of a key, which is previous item
    int current = v[0];
    for (int i = 1; i < n; i++) {
        auto current_it = sumPair.find(current);            
        if (current_it->second == v[i]) {
            result++;
        }
        current = v[i];                                // since current is continuously moved, it doesn't help for TC v={2, 3, 3, 2} x=2  , 
                                                       // wrong result =2, good result = 4
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
    vector<long long int> v;
    int n, x;
    input(v, n, x);
    int result = runLogic(v, n, x);
    output(result);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        runTestCase();
    }
}