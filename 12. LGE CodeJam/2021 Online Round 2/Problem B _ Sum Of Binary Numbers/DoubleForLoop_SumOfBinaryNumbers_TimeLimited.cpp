#include<vector>
#include<iostream>
using namespace std;

void input(vector<long long int>& v, int& n, int& x) {

    cin >> n;
    cin >> x;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
}

int findBadBinarySum(long long int x, long long int y) {
    return x ^ y;
}

int runLogic(vector<long long int> v, int n, int x) {
    int result = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {`                    // O(n^2)  ==> time out
            sum = findBadBinarySum(v[i], v[j]);
            if (sum == x) {
                result++;
            }
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