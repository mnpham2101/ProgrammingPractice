#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>

using namespace std;

vector<long long > Result;

// for each T, run a Test Case, accept inputs
void runTestCase() {
    // declare inputs as required by problem.
    string input;
    cin >> input;

    long long result = 0;

    int n = input.size();
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        if (input[i] == '6')
            num.push_back(9);
        else
            num.push_back(input[i] - '0');
    }

    sort(num.rbegin(), num.rend());
    //log sorted cards
    for (int i = 0; i < n; i++) {
        cout << " " << num[i];
    }
    cout << endl;
    long long  numberA = 0;
    long long  numberB = 0;
    long long  product = 0;
    vector<long long > productList;
    vector<long long > numberAList;
    vector<long long > numberBList;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        if (j < n) {
            for (j; j < n; j++) {
                numberB += num[j] * (pow(10, n - j - 1));
            }
            numberBList.push_back(numberB);
            numberB = 0;
        }
    }
    // //log
    // cout << "numberBlist: " << endl;
    // for (int i = 0; i < (n - 1); i++) {
    //     cout << numberBList[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n - 1; i++) {
        numberA *= 10;
        numberA += num[i];
        // cout<<i<<", numberA: "<<numberA<<endl;
        numberAList.push_back(numberA);
    }
    //log
    // cout << "numberAlist: " << endl;
    // for (int i = 0; i < n - 1; i++) {
    //     cout << numberAList[i] << " ";
    // }
    // cout << endl;
    // cout << "product: " << endl;;
    // for (int i = 0; i < n - 1; i++) {
    //     product = numberAList[i] * numberBList[i];
    //     productList.push_back(product);
    //     cout << product << " ";
    // }

    sort(productList.rbegin(), productList.rend());
    result = productList.front();
    Result.push_back(result);
}

// run result for all test cases
void printResult(vector<long long >Result) {
    cout << endl;
    cout << "Result: " << endl;
    for (long long& i : Result) {
        cout << i << " " << endl;
    }
}

// Solution
void TestCase(int testCase[10], int totalTestCase) {
    // run test case
    for (int i = 0; i < totalTestCase; i++) {
        runTestCase();
    }
    // print test case result
    printResult(Result);
}

int main() {
    int T;
    cin >> T;
    int testCase[10];
    TestCase(testCase, T);
    return 0;
}
/* end template part */